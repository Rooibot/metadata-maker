// Copyright Rooibot Games

// ROOIBOT TOOLBOX PLUGIN
// Animation Metadata System
//
// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationMetaSupport.h"
#include "Interfaces/Interface_BoneReferenceSkeletonProvider.h"
#include "AnimationMetadataSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Rooitools, DefaultConfig)
class UAnimationMetadataSettings : public UObject, public IBoneReferenceSkeletonProvider
{
	GENERATED_BODY()
public:
	explicit UAnimationMetadataSettings(const FObjectInitializer& Initializer);

	// ---- SOURCE- AND TARGET-RELATED SETTINGS ----

	/**
	 * Which mode the metadata generator source picker should operate in. EMGM_Single will have an asset picker for the
	 * source line, while EMGM_Batch will instead have a 'Browse' button to pick the source directory. (As the metadata
	 * generator tab has its own UI for this, we hide it from the property editor.)
	 */
	UPROPERTY(Config, EditAnywhere, DisplayName = "Source Picker Mode", meta=(EditCondition = "false", EditConditionHides))
	EMetadataGeneratorMode SourceMode;
	
	/**
	 * Determines the behavior of the metadata generator when encountering a target file that already exists.
	 * EMGFL_Preserve will refuse to alter existing files. EMGFL_Update will update existing files, preserving all
	 * existing tracks (save those we need to rewrite). EMGFL_Overwrite will just delete and create new files atop
	 * any existing ones.
	 */
	UPROPERTY(Config, EditAnywhere, DisplayName = "File Behavior", Category="Target Settings", meta=(ToolTip = "What should we do upon encountering an existing file as our target?"))
	EMetadataGeneratorFileLogic FileMode;
	
	/** If true, target files will be written with root locking enabled, to force them into in-place animations. */
	UPROPERTY(Config, EditAnywhere, DisplayName = "Convert Targets to In-Place", Category="Target Settings", meta=(ToolTip = "Should the target files be output as in-place animations, as well as adding the metadata?"))
	bool bConvertTarget;

	UPROPERTY(Config, EditAnywhere, DisplayName = "Erase all Target Curves", Category="Target Settings", meta=(ToolTip = "Should we ensure our target has only our generated metadata curves?"));
	bool bEraseCurves;

	// ---- INPUT SETTINGS ----
	
	/**
	 * If true, any source file we encounter that does not have root motion enabled will have the flag forced on
	 * before we process it.
	 */
	UPROPERTY(Config, EditAnywhere, DisplayName = "Force Root-Motion on Source", Category="Input Settings", meta=(ToolTip = "Should we force root-motion on for source files not using root-motion?"))
	bool bForceRootMotion;

	/** If true, the "up" vector will be processed for base model motion, as well as the "forward" and "right" vectors. */
	UPROPERTY(Config, EditAnywhere, DisplayName = "Include Vertical Movement", Category="Input Settings", meta=(ToolTip = "Should we include vertical movement tracks, as well as Forward and Right?"))
	bool bIncludeVertical;

	/** If true, pitch and roll will be processed for base model motion, as well as yaw. */
	UPROPERTY(Config, EditAnywhere, DisplayName = "Include Pitch and Roll", Category="Input Settings", meta=(ToolTip = "Should we include the Pitch and Roll data as well as Yaw?"))
	bool bIncludeAllRotations;

	// ---- OUTPUT SETTINGS ----

	/**
	 * If true, an additional track will be generated for any base model track; this will have values between 0 and
	 * 1.0, representing the range of minimum and maximum motion in the file. For instance, the "Yaw_Alpha" track for a
	 * "rotate 90 degrees" animation sequence would have 0.0 for "no rotation yet", while 1.0 would be "we have rotated
	 * 90 degrees". This value can be used identically to the rotation alpha track in Epic's own Windwalker Echo project.
	 */
	UPROPERTY(Config, EditAnywhere, DisplayName = "Create Alpha Tracks", Category="Output Settings", meta=(ToolTip = "Should we include not just movement tracks, but also the alpha between minimum and maximum?"))
	bool bCreateAlphaTracks;

	/**
	 * If true, an additional track will be generated for any base model track; this will have each frame be the change
	 * since the previous frame. For instance, if frame 3 had turned 2.7 degrees from where frame 2 was, the value in
	 * frame 3 for the "Yaw_Delta" track would be 2.7. This can be used identically to the turn tracks in ALSv4.
	 */
	UPROPERTY(Config, EditAnywhere, DisplayName = "Create Delta Tracks", Category="Output Settings", meta=(ToolTip = "Should we include not just movement tracks, but also the delta between a given frame and the previous?"))
	bool bCreateDeltaTracks;

	UPROPERTY(Config, EditAnywhere, DisplayName = "Create Distance Matching Track", Category="Output Settings", meta=(ToolTip = "Should we create a Lyra-style distance matching track?"))
	bool bCreateDistanceTrack;
	
	UPROPERTY(Config, EditAnywhere, DisplayName = "Create ALSv4 Data", Category="Output Settings", meta=(ToolTip = "Should we create tracks appropriate for the community edition of ALSv4?"))
	// ReSharper disable once CppUE4CodingStandardNamingViolationWarning
	bool bCreateALS;

	UPROPERTY(Config, EditAnywhere, DisplayName = "Walk Speed (ALSv4)", Category="Output Settings|ALSv4", meta=(ToolTip = "What should our maximum 'walk' speed be?", EditCondition = "bCreateALS", EditConditionHides))
	float WalkSpeed;
	
	UPROPERTY(Config, EditAnywhere, DisplayName = "Run Speed (ALSv4)", Category="Output Settings|ALSv4", meta=(ToolTip = "What should our maximum 'run' speed be?", EditCondition = "bCreateALS", EditConditionHides))
	float RunSpeed;

	UPROPERTY(Config, EditAnywhere, DisplayName = "Sprint Speed (ALSv4)", Category="Output Settings|ALSv4", meta=(ToolTip = "What should our maximum 'sprint' speed be?", EditCondition = "bCreateALS", EditConditionHides))
	float SprintSpeed;

	// ---- BONE-SPECIFIC TASKS ----

	/**
	 * A reference skeleton to use for picking bones in the UI. Bones will be stored as names, however, and
	 * resolved for each animation sequence -- this way, you can convert animation sequences using multiple
	 * different skeletons all at once.
	 */
	UPROPERTY(EditAnywhere, DisplayName = "Reference Skeleton", Category="Additional Bones", meta=(ToolTip = "What skeleton should we use as a reference to find bones?"))
	USkeleton *ReferenceSkeleton;

	/** Path for the reference skeleton. This is used to persist settings to disk, since we can't save the skeleton itself. */
	UPROPERTY(Config, meta=(EditCondition = "false", EditConditionHides))
	FString ReferenceSkeletonPath;

	/** Additional bone-specific tasks to run in addition. */
	UPROPERTY(EditAnywhere, DisplayName = "Bone Curve Tasks", Category="Additional Bones", meta=(ToolTip = "What additional bone data should we record?", EditCondition = "ReferenceSkeleton != nullptr"))
	TArray<FAnimationBoneCurveTask> ExtraBones;
	
	// Helpers -- this way we can set the path for the skeleton along the way, and get the already-loaded asset if needed.

	/**
	 * @brief Sets the reference skeleton from an asset data reference.
	 * This is a convenience function which, given an FAssetData object, will set the ReferenceSkeleton and
	 * ReferenceSkeletonPath variables. Used to ensure we have both values set for purposes of persisting
	 * to disk.
	 */
	void SetSkeleton(FAssetData& Data);

	// Implementation for IBoneReferenceSkeletonProvider, so that the skeleton shows up in a property editor.
	virtual USkeleton *GetSkeleton(bool& bInvalidSkeletonIsError, const class IPropertyHandle* PropertyHandle) override;

	// We want to override this so that when the skeleton changes, we make sure the bones we have
	// set up are still valid.
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	
private:

	/**
	 * @brief Convenience function to load the skeleton from the given asset data.
	 * This convenience function will ensure the asset represented by the asset data is
	 * loaded into memory, including jumping to the game thread temporarily to load it if
	 * required.
	 * @param Data An asset data record for the skeleton we want to load.
	 * @return The skeleton represented by the data asset, or nullptr on error.
	 */
	USkeleton* LoadSkeletonForAsset(FAssetData& Data) const;
	
};