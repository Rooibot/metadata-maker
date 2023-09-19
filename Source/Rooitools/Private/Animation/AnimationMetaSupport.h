#pragma once
#include "AnimationMetaSupport.generated.h"

// I love Rider, but... the fact that enum prefixes are flagged as an Unreal style violation...
//
// ReSharper disable CppUE4CodingStandardNamingViolationWarning
// ReSharper disable IdentifierTypo

/** An enumerator describing the possible source-picker modes for the metadata generator. */
UENUM()
enum class EMetadataGeneratorMode : int16
{
	EMGM_Single = 0		UMETA(DisplayName="Single Asset Mode"),
	EMGM_Batch = 1		UMETA(DisplayName="Batch Source Mode")
};

/** An enumerator describing the possible behaviors when encountering existing files. */
UENUM()
enum class EMetadataGeneratorFileLogic : int16
{
	EMGFL_Preserve = 0		UMETA(DisplayName="Do not overwrite or alter existing files."),
	EMGFL_Update = 1		UMETA(DisplayName="Update any existing files with new metadata."),
	EMGFL_Overwrite = 2		UMETA(DisplayName="Overwrite any existing files entirely."),
};

/** An enumerator describing the possible types of animation metadata tracks. */
UENUM()
enum class EAnimationMetadataTrackType
{
	ETT_Curve,
	ETT_Notification
};

/** An enumerator describing what sort of metadata a given ETT_Curve track might contain. */
UENUM()
enum class EBoneCurveMetadataCategory
{
	// These are named without the standard enum prefixes because we use the value names to generate the track names.
	
	MovementSpeed,
	DistanceMoved,
	Forward,
	Right,
	Up,
	Yaw,
	Pitch,
	Roll
};

/**
 * An enumerator describing what type of track this is. EBTT_Normal just tracks the cumulative value,
 * EBTT_Alpha tracks the value as a percentage of the range, EBTT_Delta tracks the change since the
 * previous frame. EBTT_BreakRange will take an array of values and separate the track into a set of
 * integer values matching which range the current value falls into (i.e., ALSv4 Gait tracks).
 */
UENUM()
enum class EBoneCurveTrackType
{
	EBTT_Normal,
	EBTT_Alpha,
	EBTT_Delta,
	EBTT_BreakRange,
	EBTT_MotionMatch
};

/** Data structure for holding a single curve data point. */
struct FAnimationBoneCurvePoint
{
	float KeyTime;
	float KeyValue;
};

/**
 * An interface for displaying status during a metadata generation operation.
 */
class IAnimationMetadataStatus
{

public:
	virtual ~IAnimationMetadataStatus() {}

	/**
	 * @brief Displays a status message without ending the task for the given item.
	 * This function can be called to update the status line beneath the progress bar, to add a line to the
	 * output log, or both. It will not update the overall progress percentage.
	 * @param Item The source item we're working on. Used to add a prefix of the asset name or item #, if appropriate.
	 * @param Message The message to display.
	 * @param ShowWithProgress If true, the Message should be shown in the line beneath the progress bar.
	 * @param AddToLog If true, this message should be added to the running logfile in the metadata generator window.
	 * @param MsgLogLevel If set to ELogVerbosity::Warning or ELogVerbosity::Error, will also be added to the Unreal
	 *		log as well with the given verbosity level.
	 */
	virtual void ProgressMessageForItem(const FAssetData& Item, FText Message, bool ShowWithProgress = false,
		bool AddToLog = true, ELogVerbosity::Type MsgLogLevel = ELogVerbosity::Log) {}

	/**
	 * @brief Marks all work completed for the given item.
	 * When a worker is done with its asset -- whether successfully or an error -- this function *must* be called
	 * in order to inform the metadata generator that all tasks for the asset are done. This will also update
	 * the overall progress meter.
	 * @param Item The source item we're working on.
	 * @param ErrorMessage If empty, this was a successful operation. If non-empty, the contents will be treated as
	 *		an error message and added to both the visible log in the metadata generator UI *and* the Unreal log.
	 */
	virtual void MarkItemCompleted(const FAssetData &Item, FText ErrorMessage) {} 
	
};

/** A simple wrapper class to allow float arrays to be included in a TMap. */
UCLASS()
class UFloatArray final : public UObject
{
	GENERATED_BODY()
public:
	explicit UFloatArray() : UObject() {}

	UPROPERTY()
	TArray<float> Array;

	void SetArrayValues(const TArray<float>& Other)
	{
		Array.Empty();
		Array.Append(Other);
	}

	TArray<float> AsArray() const
	{
		return Array;
	}

	explicit operator const TArray<float>() { return Array; }

};

USTRUCT()
struct FAnimationBoneTrackData
{
	GENERATED_BODY()
public:

	FAnimationBoneTrackData() {};
	FAnimationBoneTrackData(const FAnimationBoneTrackData& Other);
	
	bool IsValid(const bool bBoneOnly = false) const { return SourceBone.BoneName != NAME_None && TargetBone.BoneName != NAME_None &&
			bBoneOnly ? true : (
				BoneLocationKeys.Num() > 0 &&
				BoneLocationKeys.Num() == BoneRotationKeys.Num() &&
				BoneScaleKeys.Num() == BoneLocationKeys.Num()); }

	void AddTransform(const FTransform& RelativeTransform);

	FBoneReference SourceBone;
	FBoneReference TargetBone;

	FBoneReference TargetParentBone;
	
	TArray<FVector3f> BoneLocationKeys;
	TArray<FQuat4f> BoneRotationKeys;
	TArray<FVector3f> BoneScaleKeys;
};

/** A structure which describes the desired curve-generating operations for a given bone. */
USTRUCT()
struct FAnimationBoneCurveTask
{

	GENERATED_BODY()

public:

	FAnimationBoneCurveTask();
	explicit FAnimationBoneCurveTask(const FObjectInitializer& Initializer);
	
	UPROPERTY(VisibleAnywhere)
	FBoneReference Bone;

	UPROPERTY(EditAnywhere, DisplayName="Overwrite from Bone", meta=(ToolTip = "Should we overwrite with values from another bone?"))
	bool bCopyFromOther;

	UPROPERTY(EditAnywhere, DisplayName="Source Bone", meta=(ToolTip = "The bone to overwrite this with.", EditCondition="bCopyFromOther", EditConditionHides));
	FBoneReference SourceBone;
	
	UPROPERTY(EditAnywhere, DisplayName="Forward", meta=(ToolTip = "Should we create a forward track for this bone?"))
	bool bCreateForward;

	UPROPERTY(EditAnywhere, DisplayName="Right", meta=(ToolTip = "Should we create a right track for this bone?"))
	bool bCreateRight;
	
	UPROPERTY(EditAnywhere, DisplayName="Up", meta=(ToolTip = "Should we create an up track for this bone?"))
	bool bCreateUp;

	UPROPERTY(EditAnywhere, DisplayName="Yaw", meta=(ToolTip = "Should we create a yaw track for this bone?"))
	bool bCreateYaw;

	UPROPERTY(EditAnywhere, DisplayName="Pitch", meta=(ToolTip = "Should we create a pitch track for this bone?"))
	bool bCreatePitch;
	
	UPROPERTY(EditAnywhere, DisplayName="Roll", meta=(ToolTip = "Should we create a roll track for this bone?"))
	bool bCreateRoll;

	UPROPERTY(EditAnywhere, DisplayName="Alpha Track", meta=(ToolTip = "Should we create alpha tracks for this bone?"))
	bool bCreateAlpha;

	UPROPERTY(EditAnywhere, DisplayName="Delta Track", meta=(ToolTip = "Should we create delta tracks for this bone?"))
	bool bCreateDelta;

	UPROPERTY(EditAnywhere, DisplayName="Distance Match", meta=(ToolTip = "Should we create a distance matching track for this bone?", EditCondition = "false", EditConditionHides))
	bool bCreateDistance;
	
	UPROPERTY(EditAnywhere, DisplayName="BreakPoints Track", meta=(ToolTip = "Should we create breakpoints track for this bone?", EditCondition = "false", EditConditionHides))
	bool bCreateBreakPoints;

	UPROPERTY(EditAnywhere, DisplayName="Breaking Points", meta=(ToolTip = "What are our breakpoints?", EditCondition = "bCreateBreakPoints", EditConditionHides))
	TMap<EBoneCurveMetadataCategory,UFloatArray*> BreakPoints;

};

/** A class which contains the overall configuration for a given run of the metadata generator. */
class FAnimationMetaConfig
{
public:
	FAnimationMetaConfig()
	{
		bForceRootMotion = false;
		bConvertTarget = true;
		ExistingFileLogic = EMetadataGeneratorFileLogic::EMGFL_Preserve;
		bIncludeAlpha = true;
		bIncludeDelta = false;
		bIncludeGait = false;
		bEraseTargetTracks = false;
		GaitBreakPoints = TArray<float>();
		bIncludeDistance = false;
		bRerootOutput = false;
	}

	FAnimationMetaConfig(FAnimationMetaConfig& Other);

	FString SourcePath;
	FString TargetPath;

	bool bForceRootMotion;
	bool bConvertTarget;
	bool bEraseTargetTracks;

	bool bIncludeAlpha;
	bool bIncludeDelta;

	bool bIncludeGait;
	TArray<float> GaitBreakPoints;

	bool bIncludeDistance;
	
	EMetadataGeneratorFileLogic ExistingFileLogic;

	TArray<FAnimationBoneCurveTask*> ExtraBones;

	bool bRerootOutput;
	FBoneReference RerootBone;

	TMap<FName, FName> NameOverrides;
	TArray<FName> ExcludedTracks;
};

/**
 * @brief A class which contains the data describing a specific job to run.
 * A given "job" within the metadata system is the set of operations to perform on a specific asset;
 * there is a 1:1 mapping of jobs to source animation assets.
 */
class FAnimationJobData
{
public:
	FAnimationJobData();
	FAnimationJobData(const FAnimationJobData& Other);

	/** The animation asset this job is for. */
	FAssetData WorkItem;

	/** The path for the asset we're writing out. */
	FString DestinationAssetPath;

	/** The configuration for this overall metadata generator run. */
	FAnimationMetaConfig Config;

	/** Any extra bone-specific tasks to run on this asset. */
	TArray<FAnimationBoneCurveTask> Bones;

	/** The interface we can use to output status messages. */
	IAnimationMetadataStatus* Status;
};

