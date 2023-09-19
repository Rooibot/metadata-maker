#include "BoneCurveTrack.h"

#include "AnimationMetaToolsTab.h"


FBoneCurveTrack::FBoneCurveTrack(const FBoneReference& BoneRef, EBoneCurveMetadataCategory MetaType, EBoneCurveTrackType TrackType, const FLinearColor& Color, const TArray<float>& BreakPoints)
{
	Bone = BoneRef;
	BoneMetadataType = MetaType;
	BoneTrackType = TrackType;

	TrackColor = Color;

	const UEnum* MetaEnum = FindFirstObjectSafe<UEnum>(TEXT("EBoneCurveMetadataCategory"));
	
	FString BuildTrackName = TEXT("");
	FString MetaTypeName = MetaEnum ? MetaEnum->GetNameStringByValue(static_cast<int16>(MetaType)) : TEXT("UNKNOWN");

	if (BoneRef.BoneName.ToString().ToLower() != "root")
	{
		BuildTrackName = BoneRef.BoneName.ToString() + "_";
	}

	BuildTrackName = BuildTrackName + MetaTypeName;

	switch (TrackType)
	{
		case EBoneCurveTrackType::EBTT_Normal:
			break;

		case EBoneCurveTrackType::EBTT_Alpha:
			BuildTrackName += "_Alpha";
			break;

		case EBoneCurveTrackType::EBTT_Delta:
			BuildTrackName += "_Delta";
			break;

		case EBoneCurveTrackType::EBTT_BreakRange:
			BuildTrackName += "_BreakPoints";
			break;

		case EBoneCurveTrackType::EBTT_MotionMatch:
			BuildTrackName += "_Match";
			break;
	}

	TrackBreakPoints = BreakPoints;

	Name = FName(BuildTrackName);

	CurrentTransform = FTransform();

	TrackMinValue = 0;
	TrackMaxValue = 0;
	LastKeyValue = 0;
	bHasData = false;
	
}

FName FBoneCurveTrack::GetName() const
{
	return Name;
}

void FBoneCurveTrack::OverrideName(const FName& NewName)
{
	Name = NewName;
}

void FBoneCurveTrack::SetTargetSkeleton(const USkeleton* NewSkeleton)
{
	Bone.Initialize(NewSkeleton);
}

const FBoneReference& FBoneCurveTrack::GetBone() const
{
	return Bone;
}


void FBoneCurveTrack::AddPoint(float KeyTime, float DeltaTime, const FTransform& Transform, bool bLastFrame)
{
	FAnimationBoneCurvePoint DataPoint;

	DataPoint.KeyTime = KeyTime;
	float KeyValue = 0.0;
	if (BoneMetadataType == EBoneCurveMetadataCategory::MovementSpeed)
	{
		if (DeltaTime > 0.f)
		{
			KeyValue = (CurrentTransform.GetTranslation() - Transform.GetTranslation()).Size() / DeltaTime;
			if (BoneTrackType == EBoneCurveTrackType::EBTT_Delta)
			{
				KeyValue -= LastKeyValue;
			}
		}
	}

	else if (BoneMetadataType == EBoneCurveMetadataCategory::DistanceMoved)
	{
		if (KeyTime == 0.f)
		{
			FirstPoint = Transform.GetTranslation();
			KeyValue = 0.f;
		}
		else
		{
			KeyValue = (Transform.GetTranslation() - FirstPoint).Length();
		}
	}
	
	else if (BoneMetadataType == EBoneCurveMetadataCategory::Forward)
	{
		KeyValue = CurrentTransform.GetTranslation().Y;
		if (BoneTrackType == EBoneCurveTrackType::EBTT_Delta)
		{
			KeyValue -= Transform.GetTranslation().Y;
		}
	}

	else if (BoneMetadataType == EBoneCurveMetadataCategory::Right)
	{
		KeyValue = CurrentTransform.GetTranslation().X * -1;
		if (BoneTrackType == EBoneCurveTrackType::EBTT_Delta)
		{
			KeyValue = (CurrentTransform.GetTranslation().X - Transform.GetTranslation().X) * -1; 
		}
	}

	else if (BoneMetadataType == EBoneCurveMetadataCategory::Up)
	{
		KeyValue = CurrentTransform.GetTranslation().Z;
		if (BoneTrackType == EBoneCurveTrackType::EBTT_Delta)
		{
			KeyValue = CurrentTransform.GetTranslation().Z - Transform.GetTranslation().Z;
		}
	}

	else if (BoneMetadataType == EBoneCurveMetadataCategory::Yaw)
	{
		KeyValue = CurrentTransform.GetRotation().GetNormalized().Euler().Z;
		if (BoneTrackType == EBoneCurveTrackType::EBTT_Delta)
		{
			KeyValue -= Transform.GetRotation().GetNormalized().Euler().Z;
		}
	}

	else if (BoneMetadataType == EBoneCurveMetadataCategory::Pitch)
	{
		KeyValue = CurrentTransform.GetRotation().GetNormalized().Euler().Y;
		if (BoneTrackType == EBoneCurveTrackType::EBTT_Delta)
		{
			KeyValue -= Transform.GetRotation().GetNormalized().Euler().Y;
		}
	}

	else if (BoneMetadataType == EBoneCurveMetadataCategory::Roll)
	{
		KeyValue = CurrentTransform.GetRotation().GetNormalized().Euler().X;
		if (BoneTrackType == EBoneCurveTrackType::EBTT_Delta)
		{
			KeyValue -= Transform.GetRotation().GetNormalized().Euler().X;
		}
	}

	if ((BoneTrackType == EBoneCurveTrackType::EBTT_Delta) && (KeyTime == 0.f))
	{
		KeyValue = 0.f;
	}
	
	if (BoneTrackType == EBoneCurveTrackType::EBTT_BreakRange)
	{
		if (KeyValue > 0)
		{
			float Mapped = 0;
			for (int i = TrackBreakPoints.Num() - 1; (i >= 0) && (Mapped == 0.f); i--)
			{
				float Lower = 0;
				const float Upper = TrackBreakPoints[i];
				if (i > 0)
				{
					Lower = TrackBreakPoints[i - 1];
				}
				
				if (KeyValue > Lower)
				{
					Mapped = FMath::GetMappedRangeValueClamped<float, float>({Lower, Upper}, {i * 1.f, (i + 1) * 1.f}, KeyValue);
					continue;
				}
			}
			KeyValue = Mapped;
		}
	}

	DataPoint.KeyValue = KeyValue;
	
	CurrentTransform = Transform;
	LastKeyValue = KeyValue;

	if (!bHasData)
	{
		TrackMinValue = KeyValue;
		TrackMaxValue = KeyValue;
		bHasData = true;

		if (DataPoint.KeyValue != 0)
			DataPoints.Add(DataPoint);
	}
	else
	{
		DataPoints.Add(DataPoint);
		
		if (KeyValue > TrackMaxValue)
		{
			TrackMaxValue = KeyValue;
		}

		if (KeyValue < TrackMinValue)
		{
			TrackMinValue = KeyValue;
		}
	}
	
}

void FBoneCurveTrack::PerformFinalPass()
{
	if (BoneTrackType != EBoneCurveTrackType::EBTT_Alpha && BoneTrackType != EBoneCurveTrackType::EBTT_MotionMatch) return;

    TrackMinValue = GetMinPoint();
    TrackMaxValue = GetMaxPoint();

	TArray<FAnimationBoneCurvePoint> NewPoints;
	
	for (const auto& [KeyTime, KeyValue] : DataPoints)
	{
		FAnimationBoneCurvePoint NewPoint;
		NewPoint.KeyTime = KeyTime;

		if (BoneTrackType == EBoneCurveTrackType::EBTT_Alpha)
		{
			if ((BoneMetadataType == EBoneCurveMetadataCategory::Yaw) ||
				(BoneMetadataType == EBoneCurveMetadataCategory::Pitch) ||
				(BoneMetadataType == EBoneCurveMetadataCategory::Roll)) 
			{
				float AbsValue = FMath::Abs(KeyValue);

				float AbsMin = FMath::Abs(TrackMinValue);
				float AbsMax = FMath::Abs(TrackMaxValue);

				if ((TrackMinValue < 0) && (TrackMaxValue > 0))
				{
					AbsMax += AbsMin;
					AbsValue += AbsMin;
					AbsMin = 0;
				}

				if ((AbsMax - AbsMin) == 0)
				{
					NewPoint.KeyValue = 0;
				}
				else
				{
					if (AbsMin > AbsMax)
					{
						const float Temp = AbsMin;
						AbsMin = AbsMax;
						AbsMax = Temp;
					}

					NewPoint.KeyValue = (AbsValue - AbsMin) / (AbsMax - AbsMin);
				}
			}
			else
			{
				if (TrackMaxValue - TrackMinValue == 0)
				{
					NewPoint.KeyValue = 0;
				}
				else
				{
					NewPoint.KeyValue  = (KeyValue - TrackMinValue) / (TrackMaxValue - TrackMinValue);
				}
			}
		}
		else if (BoneTrackType == EBoneCurveTrackType::EBTT_MotionMatch)
		{
			NewPoint.KeyValue = KeyValue - TrackMaxValue;
		}

		NewPoints.Add(NewPoint);
	}

	DataPoints = NewPoints;
}

void FBoneCurveTrack::GetDataPoints(TArray<FAnimationBoneCurvePoint>& Points) const
{
	Points = DataPoints;
}

float FBoneCurveTrack::GetMaxPoint() const
{
	float Result = 0;

	for (const auto& Point : DataPoints)
	{
		if (Point.KeyValue > Result)
			Result = Point.KeyValue;
	}

	return Result;
}

float FBoneCurveTrack::GetMinPoint() const
{
	if (DataPoints.Num() == 0) return 0.0;

	float Result = DataPoints[0].KeyValue;

	for (const auto& Point : DataPoints)
	{
		if (Point.KeyValue < Result)
			Result = Point.KeyValue;
	}

	return Result;
}

