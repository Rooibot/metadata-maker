#pragma once

#include "Core/RooitoolWorker.h"
#include "AnimationMetaSupport.h"
#include "BoneCurveTrack.h"

class FAnimationMetaTask final : public FRooitoolTask<class FAnimationJobData>
{
public:
	explicit FAnimationMetaTask(FAnimationJobData Data);
	virtual ~FAnimationMetaTask() override {};

	virtual void PerformTask() override;

private:
	bool AssetDataForPath(const FString& Path, FAssetData& Data) const;
	
	UAnimSequence* LoadSequenceFromAsset(const FAssetData& AssetData) const;
	UAnimSequence* LoadSequenceFromPath(const FString& Path) const;
	UAnimSequence* DuplicateSequenceToPath(UAnimSequence *SourceAnimation, FString TargetPath) const;

	void BuildBoneTracks();

	void IterateAnimation(const UAnimSequence *Sequence);
	void WriteOutputTracks(UAnimSequence *Target);
	
	void BuildTracksForBone(const FBoneReference& Bone, EBoneCurveMetadataCategory MetadataType, bool bCreateAlpha = false, bool bCreateDelta = false, bool bCreateDistanceMatch = false, bool bCreateBreakPoints = false, const TArray<float>& BreakPoints = TArray<float>(), const TMap<FName, FName>& NameOverrides = TMap<FName, FName>());

	static bool GetBoneTransformAtTime(const UAnimSequence *Sequence, const FBoneReference& Bone, float Time, FTransform& Transform, bool bWalkParents = true);
	
	TArray<FBoneCurveTrack> Tracks;

	TMap<FName, FName> CopyBoneSources;
	
	TArray<FAnimationBoneTrackData> CopyBoneData;


};

class FAnimationMetaWorker final : public FRooitoolWorker<class FAnimationMetaTask, class FAnimationJobData, 1>
{
public:
	FAnimationMetaWorker() : FRooitoolWorker<class FAnimationMetaTask, class FAnimationJobData>() {}
	FAnimationMetaWorker(const FAnimationMetaWorker& Other) { FAnimationMetaWorker(); }
	virtual ~FAnimationMetaWorker() override {};
};
