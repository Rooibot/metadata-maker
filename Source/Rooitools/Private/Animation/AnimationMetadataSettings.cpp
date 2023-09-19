// Copyright 2022 Rooibot Games


#include "AnimationMetadataSettings.h"

#include "AnimationMetaToolsTab.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/IAssetRegistry.h"

UAnimationMetadataSettings::UAnimationMetadataSettings(const FObjectInitializer& Initializer)
{
	SourceMode = EMetadataGeneratorMode::EMGM_Batch;
	FileMode = EMetadataGeneratorFileLogic::EMGFL_Preserve;
	bConvertTarget = true;
	bForceRootMotion = false;
	bCreateAlphaTracks = true;
	bCreateDeltaTracks = false;
	bIncludeVertical = false;
	bCreateDistanceTrack = false;
	bIncludeAllRotations = false;
	bEraseCurves = false;
}

void UAnimationMetadataSettings::SetSkeleton(FAssetData& Data)
{
	ReferenceSkeleton = LoadSkeletonForAsset(Data);
	ReferenceSkeletonPath = Data.GetObjectPathString();
}

USkeleton* UAnimationMetadataSettings::GetSkeleton(bool& bInvalidSkeletonIsError, const class IPropertyHandle* PropertyHandle)
{
	bInvalidSkeletonIsError = true;
		
	if (nullptr == ReferenceSkeleton && !ReferenceSkeletonPath.IsEmpty())
	{
		IAssetRegistry& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry")).Get();

		FString ParentPath = ReferenceSkeletonPath;
		int32 Index;
		if (ParentPath.FindLastChar(L'/', Index))
		{
			ParentPath = ParentPath.Left(Index);
		}

		FAssetData Data;
		
		TArray<FString> Paths;
		Paths.Add(ParentPath);
		AssetRegistryModule.ScanPathsSynchronous(Paths);
		Data = AssetRegistryModule.GetAssetByObjectPath(FSoftObjectPath(ReferenceSkeletonPath));

		ReferenceSkeleton = LoadSkeletonForAsset(Data);
	}

	return ReferenceSkeleton;
}

void UAnimationMetadataSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UObject::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UAnimationMetadataSettings, ReferenceSkeleton))
	{
		for (auto& Bone : ExtraBones)
		{
			Bone.Bone.Initialize(ReferenceSkeleton);
		}
	}
	else if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UAnimationMetadataSettings, ExtraBones))
	{
		for (auto& Bone : ExtraBones)
		{
			UE_LOG(LogRooitoolsAnimation, Log, TEXT("Reinitializing bone %s..."), *(Bone.Bone.BoneName.ToString()));
			Bone.Bone.Initialize(ReferenceSkeleton);
		}
	}
}

USkeleton* UAnimationMetadataSettings::LoadSkeletonForAsset(FAssetData& Data) const
{
	USkeleton *Result = nullptr;
	if (Data.IsValid())
	{
		// This must be done on the game thread.
		const FGraphEventRef LoadSkeleton = FFunctionGraphTask::CreateAndDispatchWhenReady([this, &Result, &Data]() {
			Result = Cast<USkeleton>(Data.GetAsset());
		}, TStatId(), nullptr, ENamedThreads::GameThread);
		FTaskGraphInterface::Get().WaitUntilTaskCompletes(LoadSkeleton);
	}

	return Result;
}
