#include "AnimationMetaSupport.h"

#include "AnimationMetaToolsTab.h"
#include "Core/RooiEnumHelper.h"

FAnimationBoneTrackData::FAnimationBoneTrackData(const FAnimationBoneTrackData& Other)
{
	SourceBone = Other.SourceBone;
	TargetBone = Other.TargetBone;
	TargetParentBone = Other.TargetParentBone;
	
	BoneLocationKeys = Other.BoneLocationKeys;
	BoneRotationKeys = Other.BoneRotationKeys;
	BoneScaleKeys = Other.BoneScaleKeys;
}

void FAnimationBoneTrackData::AddTransform(const FTransform& RelativeTransform)
{
	const FVector RelativeLocation = RelativeTransform.GetLocation();
	const FQuat RelativeRotation = RelativeTransform.GetRotation();
	const FVector RelativeScale = RelativeTransform.GetScale3D();

	const FVector3f Location = FVector3f(RelativeLocation.X, RelativeLocation.Y, RelativeLocation.Z);
	const FVector3f Scale = FVector3f(RelativeScale.X, RelativeScale.Y, RelativeScale.Z);
	const FQuat4f Rotation = FQuat4f(RelativeRotation.X, RelativeRotation.Y, RelativeRotation.Z, RelativeRotation.W);

	BoneLocationKeys.Add(Location);
	BoneRotationKeys.Add(Rotation);
	BoneScaleKeys.Add(Scale);
}

FAnimationBoneCurveTask::FAnimationBoneCurveTask()
{
	bCreateForward = bCreateRight = bCreateUp = bCreatePitch = bCreateYaw = bCreateRoll = bCreateAlpha = bCreateDelta = false;
	bCreateBreakPoints = false;
	bCopyFromOther = false;
}

FAnimationBoneCurveTask::FAnimationBoneCurveTask(const FObjectInitializer& Initializer)
{
	bCreateForward = bCreateRight = bCreateUp = bCreatePitch = bCreateYaw = bCreateRoll = bCreateAlpha = bCreateDelta = false;
	bCreateBreakPoints = false;
	bCopyFromOther = false;
}

FAnimationMetaConfig::FAnimationMetaConfig(FAnimationMetaConfig& Other)
{
	TargetPath = Other.TargetPath;
	ExistingFileLogic = Other.ExistingFileLogic;
	ExtraBones = Other.ExtraBones;
	bConvertTarget = Other.bConvertTarget;
	bForceRootMotion = Other.bForceRootMotion;
	bEraseTargetTracks = Other.bEraseTargetTracks;
	bIncludeAlpha = Other.bIncludeAlpha;
	bIncludeDelta = Other.bIncludeDelta;
	bIncludeGait = Other.bIncludeGait;
	GaitBreakPoints = Other.GaitBreakPoints;
}

FAnimationJobData::FAnimationJobData()
{
	Status = nullptr;
}

FAnimationJobData::FAnimationJobData(const FAnimationJobData& Other)
{
	Status = Other.Status;
	Config = Other.Config;
	WorkItem = Other.WorkItem;
	DestinationAssetPath = Other.DestinationAssetPath;
	Bones = Other.Bones;
}

