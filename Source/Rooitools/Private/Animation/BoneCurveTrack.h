#pragma once

#include "CoreMinimal.h"
#include "AnimationMetaSupport.h"

class FBoneCurveTrack
{

public:

	FBoneCurveTrack(const FBoneReference& BoneRef, EBoneCurveMetadataCategory MetaType, EBoneCurveTrackType TrackType, const FLinearColor& Color, const TArray<float>& BreakPoints = TArray<float>());

	FLinearColor GetTrackColor() const { return TrackColor; }
	
	FName GetName() const;

	void OverrideName(const FName& NewName);

	void SetTargetSkeleton(const USkeleton *NewSkeleton);

	void SetTrackName(const FSmartName& NewCurveName) { TrackName = NewCurveName; }
	const FSmartName& GetTrackName() const { return TrackName; }

	const FBoneReference& GetBone() const;
	
	void AddPoint(float KeyTime, float DeltaTime, const FTransform& Transform, bool bLastFrame = false);
	void AddProcessedPoint(float KeyTime, float DeltaTime, const FTransform& Transform, bool bLastFrame = false);

	void PerformFinalPass();
	
	void GetDataPoints(TArray<FAnimationBoneCurvePoint> &Points) const;
	float GetMaxPoint() const;
	float GetMinPoint() const;
	
private:

	FName Name;
	FBoneReference Bone;

	FSmartName TrackName;

	FLinearColor TrackColor;

	EBoneCurveMetadataCategory BoneMetadataType;
	EBoneCurveTrackType BoneTrackType;

	TArray<float> TrackBreakPoints;

	float TrackMinValue;
	float TrackMaxValue;

	FVector FirstPoint;
	
	float LastKeyValue;
	
	bool bHasData;

	TArray<FAnimationBoneCurvePoint> DataPoints;

	FTransform CurrentTransform;
	
};