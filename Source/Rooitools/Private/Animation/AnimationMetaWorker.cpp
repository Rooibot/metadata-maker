#include "AnimationMetaWorker.h"

#include <ThirdParty/hlslcc/hlslcc/src/hlslcc_lib/ir.h>

#include "AnimationMetaToolsTab.h"
#include "AssetToolsModule.h"
#include "ObjectTools.h"
#include "Animation/MirrorDataTable.h"
#include "AnimationBlueprintLibrary/Public/AnimationBlueprintLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/ConstructorHelpers.h"

#define LOCTEXT_NAMESPACE "Rooitools"

FAnimationMetaTask::FAnimationMetaTask(FAnimationJobData Data) :
	FRooitoolTask<FAnimationJobData>(Data)
{
	CopyBoneSources = TMap<FName, FName>();
}

void FAnimationMetaTask::PerformTask()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	IAssetRegistry& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry")).Get();
	
	const auto Tab = TaskData.Status;
	const auto Config = TaskData.Config;
	const auto Asset = TaskData.WorkItem;
	auto Destination = TaskData.DestinationAssetPath;
	UAnimSequence* TargetAnimation = nullptr;

	// Make certain we can load our source animation.
	auto SourceAnimation = LoadSequenceFromAsset(Asset);
	if (nullptr == SourceAnimation)
	{
		// Welp.
		Tab->MarkItemCompleted(Asset, LOCTEXT("Error.NoValidAnimation", "No valid source animation sequence found."));
		return;
	}

	// Check to make sure root motion is enabled.
	if (!SourceAnimation->bEnableRootMotion)
	{
		// If we aren't set up to force root motion, skip the file.
		if (!Config.bForceRootMotion)
		{
			Tab->MarkItemCompleted(Asset, LOCTEXT("Error.NotRootMotion", "Animation is not using root motion, skipped."));
			return;
		}
		else
		{
			Tab->ProgressMessageForItem(Asset, LOCTEXT("Warning.ForcedRootMotion", "Source animation is not using root motion; enabling it manually."), false, true, ELogVerbosity::Warning);
			SourceAnimation->bEnableRootMotion = true;
		}
	}

	// See if our target animation already exists or not.
	if (FAssetData DestinationData; AssetDataForPath(Destination, DestinationData))
	{
		TArray<FAssetData> Victims;
		
		switch (Config.ExistingFileLogic)
		{
			case EMetadataGeneratorFileLogic::EMGFL_Preserve:
				Tab->MarkItemCompleted(Asset, LOCTEXT("Error.WontOverwrite", "Target animation already exists, skipping."));
				return;

			case EMetadataGeneratorFileLogic::EMGFL_Overwrite:
				Victims.Add(DestinationData);
				ObjectTools::DeleteAssets(Victims);
				break;

			case EMetadataGeneratorFileLogic::EMGFL_Update:
				TargetAnimation = LoadSequenceFromAsset(DestinationData);
				if (nullptr == TargetAnimation)
				{
					Tab->MarkItemCompleted(Asset, LOCTEXT("Error.Corrupted", "Target animation could not be updated; data may be corrupted."));
					return;
				}
				break;
		}
	}

	if (nullptr == TargetAnimation)
	{
		TargetAnimation = DuplicateSequenceToPath(SourceAnimation, Destination);
	}

	if (nullptr == TargetAnimation)
	{
		// Okay, that's not great...
		Tab->MarkItemCompleted(Asset, LOCTEXT("Error.Corrupted", "Target animation could not be updated; data may be corrupted."));
		return;
	}

	BuildBoneTracks();

	IterateAnimation(SourceAnimation);

	WriteOutputTracks(TargetAnimation);

	Tab->MarkItemCompleted(TaskData.WorkItem, FText());
}

#define CHECK_NAME_OVERRIDE(Track, Overrides) \
	if (Overrides.Contains(Track.GetName())) { Track.OverrideName(Overrides[Track.GetName()]); } 

void FAnimationMetaTask::BuildTracksForBone(const FBoneReference& Bone, EBoneCurveMetadataCategory MetadataType, bool bCreateAlpha, bool bCreateDelta, bool bCreateDistance, bool bCreateBreakPoints, const TArray<float>& BreakPoints, const TMap<FName, FName>& NameOverrides)
{
	FLinearColor Color;
	if (Bone.BoneIndex == 0)
	{
		Color = FLinearColor::Yellow;
	}
	else
	{
		Color = FLinearColor::MakeRandomColor();
	}
	
	FBoneCurveTrack NewTrack(Bone, MetadataType, EBoneCurveTrackType::EBTT_Normal, Color);

	CHECK_NAME_OVERRIDE(NewTrack, NameOverrides)

	if (!TaskData.Config.ExcludedTracks.Contains(NewTrack.GetName()))
		Tracks.Add(NewTrack);

	
	if (bCreateAlpha)
	{
		FBoneCurveTrack AlphaTrack(Bone, MetadataType, EBoneCurveTrackType::EBTT_Alpha, Color);

		CHECK_NAME_OVERRIDE(AlphaTrack, NameOverrides);
		if (!TaskData.Config.ExcludedTracks.Contains(AlphaTrack.GetName()))
			Tracks.Add(AlphaTrack);
	}

	if (bCreateDelta)
	{
		FBoneCurveTrack DeltaTrack(Bone, MetadataType, EBoneCurveTrackType::EBTT_Delta, Color);
		
		CHECK_NAME_OVERRIDE(DeltaTrack, NameOverrides);
		if (!TaskData.Config.ExcludedTracks.Contains(DeltaTrack.GetName()))
			Tracks.Add(DeltaTrack);
	
	}

	if (bCreateDistance)
	{
		FBoneCurveTrack DistanceTrack(Bone, MetadataType, EBoneCurveTrackType::EBTT_MotionMatch, Color);

		CHECK_NAME_OVERRIDE(DistanceTrack, NameOverrides);
		if (!TaskData.Config.ExcludedTracks.Contains(DistanceTrack.GetName()))
			Tracks.Add(DistanceTrack);
	}

	if (bCreateBreakPoints)
	{
		FBoneCurveTrack BreakPointTrack(Bone, MetadataType, EBoneCurveTrackType::EBTT_BreakRange, Color, BreakPoints);
		
		CHECK_NAME_OVERRIDE(BreakPointTrack, NameOverrides);
		if (!TaskData.Config.ExcludedTracks.Contains(BreakPointTrack.GetName()))
			Tracks.Add(BreakPointTrack);
	}
}

bool FAnimationMetaTask::GetBoneTransformAtTime(const UAnimSequence* Sequence, const FBoneReference& InputBone, float Time,
	FTransform& Transform, bool bWalkParents)
{
	if (nullptr == Sequence) return false;

	USkeleton *AnimSkeleton = Sequence->GetSkeleton();
	
	if (InputBone.BoneName.ToString().ToLower() != "root")
	{
		FTransform Result = FTransform();
		FBoneReference Bone = InputBone;
		Bone.Initialize(AnimSkeleton);
		
		int32 CurrentBoneIndex = Bone.BoneIndex;
		while (CurrentBoneIndex > 0)
		{
			FTransform OutTransform = FTransform();
			FTransform ParentTransform = FTransform();

			FSkeletonPoseBoneIndex BoneIndex = FSkeletonPoseBoneIndex(CurrentBoneIndex);
			Sequence->GetBoneTransform(OutTransform, BoneIndex, Time, true);
			
			// const int32 TrackIndex = AnimSkeleton->GetRawAnimationTrackIndex(CurrentBoneIndex, Sequence);
			// Sequence->GetBoneTransform(OutTransform, TrackIndex, Time, true);
			
			if (!bWalkParents)
			{
				Transform = OutTransform;
				return true;
			}

			FVector AccumulatedLocation = Result.GetLocation() + OutTransform.GetLocation();
			CurrentBoneIndex = AnimSkeleton->GetReferenceSkeleton().GetParentIndex(CurrentBoneIndex);
			// const int32 ParentTrackIndex = AnimSkeleton->GetRawAnimationTrackIndex(CurrentBoneIndex, Sequence);
			const FSkeletonPoseBoneIndex ParentBoneIndex = FSkeletonPoseBoneIndex(CurrentBoneIndex);
			
			Sequence->GetBoneTransform(ParentTransform, ParentBoneIndex, Time, true);
			AccumulatedLocation = ParentTransform.Rotator().RotateVector(AccumulatedLocation);
			Result.SetLocation(AccumulatedLocation);
			Result.SetRotation(OutTransform.GetRotation() * Result.GetRotation());
		}

		Transform = Result;
		return true;
	}
	else
	{
		if (Sequence->HasRootMotion())
		{
			Transform = Sequence->ExtractRootMotionFromRange(0.0f, Time);
			return true;
		}

		return false;
	}
}

bool FAnimationMetaTask::AssetDataForPath(const FString& Path, FAssetData &Data) const
{
	IAssetRegistry& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry")).Get();

	FString ParentPath = Path;
	int32 Index;
	if (ParentPath.FindLastChar(L'/', Index))
	{
		ParentPath = ParentPath.Left(Index);
	}

	TArray<FString> Paths;
	Paths.Add(ParentPath);
	AssetRegistryModule.ScanPathsSynchronous(Paths);
	Data = AssetRegistryModule.GetAssetByObjectPath(FSoftObjectPath(Path));

	return Data.IsValid();
}

UAnimSequence* FAnimationMetaTask::LoadSequenceFromAsset(const FAssetData& AssetData) const
{
	// Hop to the game thread briefly to load our asset.
	UAnimSequence *Animation;
	const FGraphEventRef LoadAnimation = FFunctionGraphTask::CreateAndDispatchWhenReady([this, &Animation, &AssetData]() {
		Animation = Cast<UAnimSequence>(AssetData.GetAsset());

		// We are getting the skeleton (and dropping the result) to ensure it is loaded.
		// To keep ReSharper or Rider from whining, let's add a note here.
		//
		// ReSharper disable once CppExpressionWithoutSideEffects
		Animation->GetSkeleton();
		
	}, TStatId(), nullptr, ENamedThreads::GameThread);
	FTaskGraphInterface::Get().WaitUntilTaskCompletes(LoadAnimation);

	return Animation;
}


UAnimSequence* FAnimationMetaTask::LoadSequenceFromPath(const FString& Path) const
{
	if (FAssetData Data; AssetDataForPath(Path, Data))
	{
		return LoadSequenceFromAsset(Data);
	}

	return nullptr;
}

UAnimSequence* FAnimationMetaTask::DuplicateSequenceToPath(UAnimSequence *SourceAnimation,
	FString TargetPath) const
{

	UAnimSequence *NewAnimation;
	const FGraphEventRef CopyAnimation = FFunctionGraphTask::CreateAndDispatchWhenReady([this, &NewAnimation, &SourceAnimation, &TargetPath]() {

		IAssetRegistry& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry")).Get();
		FString TargetName = TEXT("");
		int32 Index;
		if (TargetPath.FindLastChar(L'/', Index))
		{
			TargetName = TargetPath.Right(TargetPath.Len() - (Index + 1));
			TargetPath = TargetPath.Left(Index);
			if (TargetName.FindLastChar(L'.', Index))
			{
				TargetName = TargetName.Left(Index);
			}

			TargetPath.Append(TEXT("/") + TargetName);
		}
		
		UPackage* Package = CreatePackage(*TargetPath);
		NewAnimation = DuplicateObject(SourceAnimation, Package, *TargetName);
		if (nullptr != NewAnimation)
		{
			NewAnimation->SetFlags(RF_Public | RF_Standalone);
			NewAnimation->PostLoad();

			// Don't need the result, ReSharper/Rider, so don't complain.
			//
			// ReSharper disable once CppExpressionWithoutSideEffects
			NewAnimation->MarkPackageDirty();

			AssetRegistryModule.AssetCreated(NewAnimation);
		}

	}, TStatId(), nullptr, ENamedThreads::GameThread);
	FTaskGraphInterface::Get().WaitUntilTaskCompletes(CopyAnimation);

	return NewAnimation;
}

#define BONE_TRACK(Task, Category) \
		TArray<float> BreakPoints = TArray<float>(); \
		if (Task.BreakPoints.Contains(Category)) { \
			BreakPoints = Task.BreakPoints[Category]->AsArray(); \
		} \
		BuildTracksForBone(Task.Bone, Category, Task.bCreateAlpha, Task.bCreateDelta, Task.bCreateDistance, \
			Task.bCreateBreakPoints, BreakPoints, TaskData.Config.NameOverrides)

void FAnimationMetaTask::BuildBoneTracks()
{
	TaskData.Status->ProgressMessageForItem(TaskData.WorkItem, LOCTEXT("Info.CreateTracks", "Generating bone curve tasks..."), true, true);

	// Create our actual track tasks.
	for (const auto& BoneTask : TaskData.Bones)
	{
		if (BoneTask.Bone.BoneName.ToString().ToLower() == "root")
		{
			BONE_TRACK(BoneTask, EBoneCurveMetadataCategory::MovementSpeed);
		}

		if (BoneTask.bCreateForward)
		{
			BONE_TRACK(BoneTask, EBoneCurveMetadataCategory::Forward);
		}
		if (BoneTask.bCreateRight)
		{
			BONE_TRACK(BoneTask, EBoneCurveMetadataCategory::Right);
		}
		if (BoneTask.bCreateUp)
		{
			BONE_TRACK(BoneTask, EBoneCurveMetadataCategory::Up);
		}

		if (BoneTask.bCreateYaw)
		{
			BONE_TRACK(BoneTask, EBoneCurveMetadataCategory::Yaw);
		}
		if (BoneTask.bCreatePitch)
		{
			BONE_TRACK(BoneTask, EBoneCurveMetadataCategory::Pitch);
		}
		if (BoneTask.bCreateRoll)
		{
			BONE_TRACK(BoneTask, EBoneCurveMetadataCategory::Roll);
		}
		
		if (BoneTask.bCreateDistance)
		{
			BONE_TRACK(BoneTask, EBoneCurveMetadataCategory::DistanceMoved);
		}

		if (BoneTask.bCopyFromOther)
		{
			FAnimationBoneTrackData Data;

			Data.SourceBone = FBoneReference(BoneTask.SourceBone);
			Data.TargetBone = FBoneReference(BoneTask.Bone);

			CopyBoneData.Add(Data);
			// CopyBoneSources[CopyTemp(Data.TargetBone.BoneName)] = CopyTemp(Data.SourceBone.BoneName);
		}
	}
	
}

void FAnimationMetaTask::IterateAnimation(const UAnimSequence *Sequence)
{
	if (nullptr == Sequence) return;
	
	float SourceLength;
	int32 SourceFrames;

	UAnimationBlueprintLibrary::GetSequenceLength(Sequence, SourceLength);
	UAnimationBlueprintLibrary::GetNumFrames(Sequence, SourceFrames);

	const float DeltaFrame = (SourceLength / SourceFrames);
	float LastTime = 0;

	USkeleton *AnimSkeleton = Sequence->GetSkeleton();

	for (auto& CopyBone : CopyBoneData)
	{
		CopyBone.SourceBone.Initialize(AnimSkeleton);
		CopyBone.TargetBone.Initialize(AnimSkeleton);

		if (const int32 ParentBone = AnimSkeleton->GetReferenceSkeleton().GetParentIndex(CopyBone.TargetBone.BoneIndex); ParentBone > 0)
		{
			CopyBone.TargetParentBone.BoneName = AnimSkeleton->GetReferenceSkeleton().GetBoneName(ParentBone);
			CopyBone.TargetParentBone.Initialize(AnimSkeleton);
		}
		else
		{
			CopyBone.TargetParentBone.BoneName = NAME_None;
			CopyBone.TargetParentBone.BoneIndex = INDEX_NONE;
		}
		
	}

	TaskData.Status->ProgressMessageForItem(TaskData.WorkItem, LOCTEXT("Info.ProcessingAnimSeq", "Processing animation sequence..."), true, true);
	for (int i = 0; i <= SourceFrames; ++i)
	{
		const float CurrentTime = i * DeltaFrame;

		for (auto& BoneTrack : Tracks)
		{
			// The TMap<> variant of this causes exceptions, so...
			FBoneReference SourceBone = BoneTrack.GetBone();
			for (const auto &CopyBone : CopyBoneData)
			{
				if (CopyBone.TargetBone.BoneName == SourceBone.BoneName)
				{
					SourceBone = CopyBone.SourceBone;
				}
			}
			
			FTransform Transform;
			if (!GetBoneTransformAtTime(Sequence, SourceBone, CurrentTime, Transform)) continue;

			BoneTrack.AddPoint(CurrentTime, CurrentTime - LastTime, Transform, i == SourceFrames);
		}
		LastTime = CurrentTime;


		// Get Root Motion transform.
		FBoneReference RootBone;
		RootBone.BoneName = TEXT("root");
		FTransform RootTransform;
		if (!GetBoneTransformAtTime(Sequence, RootBone, CurrentTime, RootTransform)) continue;
		FTransform RootRotationTransform;
		RootRotationTransform.SetRotation(RootTransform.GetRotation());

		for (auto& CopyBone : CopyBoneData)
		{
			if (!CopyBone.TargetBone.BoneName.ToString().ToLower().StartsWith(TEXT("ik_"))) continue;
			if (!CopyBone.IsValid(true /* bBoneOnly - don't check for non-zero data sets */)) continue;
			
			FTransform WorldTransform;
			FTransform LocalTransform;
			if (!GetBoneTransformAtTime(Sequence, CopyBone.SourceBone, CurrentTime, WorldTransform)) continue;
			if (!GetBoneTransformAtTime(Sequence, CopyBone.SourceBone, CurrentTime, LocalTransform, false /* bWalkParents */)) continue;

			FVector Location = WorldTransform.GetLocation();
			FQuat Rotation = WorldTransform.GetRotation();
			FVector Scale = WorldTransform.GetScale3D();

			FTransform ParentTransform = RootTransform;
			Location = RootRotationTransform.InverseTransformVector(Location);
			
			
			if (CopyBone.TargetParentBone.BoneIndex != -1)
			{
				GetBoneTransformAtTime(Sequence, CopyBone.TargetParentBone, CurrentTime, ParentTransform, false);
			}

			Location = ParentTransform.InverseTransformPositionNoScale(Location);
			Rotation = ParentTransform.InverseTransformRotation(Rotation);

			FTransform RelativeTransform;
			RelativeTransform.SetLocation(Location);
			RelativeTransform.SetRotation(Rotation);
			RelativeTransform.SetScale3D(Scale);

			CopyBone.AddTransform(RelativeTransform);
		}
		
	}

	TaskData.Status->ProgressMessageForItem(TaskData.WorkItem, LOCTEXT("Info.ProcessingPass2", "Performing second pass..."), true, true);
	for (auto& BoneTrack : Tracks)
	{
		BoneTrack.PerformFinalPass();
	}
	
}

void FAnimationMetaTask::WriteOutputTracks(UAnimSequence *Target)
{
	TaskData.Status->ProgressMessageForItem(TaskData.WorkItem, LOCTEXT("Info.PreparingCurves", "Preparing target curve tracks..."), true, true);
	FGraphEventRef AsyncTask = FFunctionGraphTask::CreateAndDispatchWhenReady([this, Target]()
	{
		if (TaskData.Config.bConvertTarget)
		{
			// Convert our target animation to in-place.
			Target->bEnableRootMotion = false;
			Target->bForceRootLock = true;
		}

		IAnimationDataController& Controller = Target->GetController();
		Controller.OpenBracket(FText::FromString(TEXT("MetadataMaker_Write")), false);
		
		USkeleton *AnimSkeleton = Target->GetSkeleton();

		// Create or retrieve our curve names.
		auto Mapping = AnimSkeleton->GetSmartNameContainer(USkeleton::AnimCurveMappingName);
		for (auto& BoneTrack : Tracks)
		{
			FSmartName Name;
			if (!Mapping->FindSmartName(BoneTrack.GetName(), Name))
			{
				AnimSkeleton->AddSmartNameAndModify(USkeleton::AnimCurveMappingName, BoneTrack.GetName(), Name);;
			}
			BoneTrack.SetTrackName(Name);
		}

		// ReSharper disable once CppExpressionWithoutSideEffects
		AnimSkeleton->MarkPackageDirty();

		if (TaskData.Config.bEraseTargetTracks)
		{
			// Until my reported issue is fixed, this takes an *eternity* to run.
			Controller.RemoveAllCurvesOfType(ERawCurveTrackTypes::RCT_Float);
		}

		for (const auto& CopyBone : this->CopyBoneData)
		{
			if (!CopyBone.IsValid(false /* bBoneOnly -- check if we have non-zero key sets as well. */)) continue;

			FText StatusLine = LOCTEXT("Info.WriteBoneTrack", "Writing bone track \"{TrackName}\"...");
			FFormatNamedArguments StatusArg;
			StatusArg.Add(TEXT("TrackName"), FText::FromString(CopyBone.TargetBone.BoneName.ToString()));

			TaskData.Status->ProgressMessageForItem(TaskData.WorkItem, FText::Format(StatusLine, StatusArg),
				true, true);
			
			Controller.SetBoneTrackKeys(CopyBone.TargetBone.BoneName,
				CopyBone.BoneLocationKeys, CopyBone.BoneRotationKeys, CopyBone.BoneScaleKeys);
		}

		// Update/Add curve data for any curves we have.
		for (const auto& BoneTrack : this->Tracks)
		{
			FAnimationCurveIdentifier CurveUID = FAnimationCurveIdentifier(
				BoneTrack.GetTrackName(), ERawCurveTrackTypes::RCT_Float);

			// Delete any previous curve.
			if (Controller.GetModel()->FindCurve(CurveUID) != nullptr)
			{
				Controller.RemoveCurve(CurveUID, false);
			}
			if (!Controller.AddCurve(CurveUID))
			{
				FText LogLine = LOCTEXT("Error.CurveTrackFailure", "Could not generate curve track for \"{TrackName}\"");
				FFormatNamedArguments Args;
				Args.Add(TEXT("TrackName"), FText::FromString(BoneTrack.GetName().ToString()));
				
				TaskData.Status->ProgressMessageForItem(TaskData.WorkItem,
				                                     FText::Format(LogLine, Args), true, true, ELogVerbosity::Error);
				continue;
			}

			FText StatusLine = LOCTEXT("Info.WriteCurveTrack", "Writing curve track \"{TrackName}\"...");
			FFormatNamedArguments StatusArg;
			StatusArg.Add(TEXT("TrackName"), FText::FromString(BoneTrack.GetName().ToString()));

			TaskData.Status->ProgressMessageForItem(TaskData.WorkItem, FText::Format(StatusLine, StatusArg));

			TArray<FAnimationBoneCurvePoint> DataPoints;
			BoneTrack.GetDataPoints(DataPoints);

			TArray<FRichCurveKey> KeyArray;
			for (const auto& [KeyTime, KeyValue] : DataPoints)
			{
				FRichCurveKey Key = FRichCurveKey();
				Key.Time = KeyTime;
				Key.Value = KeyValue;
				KeyArray.Add(Key);
			}
			Controller.SetCurveKeys(CurveUID, KeyArray);
		}

		// Save changes.
		Controller.CloseBracket(false);
		Target->PostEditChange();
		Target->GetSkeleton()->PostEditChange();

		// ReSharper disable once CppExpressionWithoutSideEffects
		Target->MarkPackageDirty();

		// ReSharper disable once CppExpressionWithoutSideEffects
		Target->GetSkeleton()->MarkPackageDirty();
		
	}, GetStatId(), nullptr, ENamedThreads::GameThread);
	FTaskGraphInterface::Get().WaitUntilTaskCompletes(AsyncTask);
}

#undef LOCTEXT_NAMESPACE