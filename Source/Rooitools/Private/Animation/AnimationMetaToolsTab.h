#pragma once

#include "Core/RooitoolTab.h"
#include "Widgets/Layout/SScrollBox.h"
#include "AnimationMetaSupport.h"
#include "AnimationMetaWorker.h"
#include "AnimationMetadataSettings.h"

DECLARE_LOG_CATEGORY_EXTERN(LogRooitoolsAnimation, Log, All)

class FAnimationMetaToolsTab : public FRooitoolTab, public IAnimationMetadataStatus, public FNotifyHook
{

public:
	FAnimationMetaToolsTab();
	virtual ~FAnimationMetaToolsTab() override;

	virtual void SetupDefaults() override;
	virtual TSharedRef<SDockTab> PrepareTab(const class FSpawnTabArgs& SpawnTabArgs) override;
	virtual bool Tick(float DeltaTime) override;
	virtual void Cleanup() override;

	// Implement our 'update task status' interface, so that the worker tasks can give us status updates.
	virtual void ProgressMessageForItem(const FAssetData& Item, FText Message, bool ShowWithProgress = false,
		bool AddToLog = true, ELogVerbosity::Type MsgLogLevel = ELogVerbosity::Log) override;
	virtual void MarkItemCompleted(const FAssetData &Item, FText ErrorMessage) override;

	// Handle property changes that should update things -- such as changing the reference skeleton or active bones.
	virtual void NotifyPreChange( FProperty* PropertyAboutToChange ) override {}
	virtual void NotifyPostChange( const FPropertyChangedEvent& PropertyChangedEvent, FProperty* PropertyThatChanged ) override;

	void HandleUserScrolled(float ScrollOffset);
	
private:

	// Settings helpers
	void SetMode(EMetadataGeneratorMode NewMode);
	void SetFileBehavior(EMetadataGeneratorFileLogic NewBehavior);

	// Useful tools for building the various jobs we dispatch
	void PopulateConfiguration(FAnimationMetaConfig& Config);
	void PopulateJobData(FAnimationJobData& Job, const FAssetData& Data, FString Destination);
	FString RelativePathForAsset(const FAssetData& Item) const;

	// Useful functions for displaying status of running jobs.
	FString StatusPrefix() const;
	void Log(ELogVerbosity::Type LogMsgLevel, const FString LogLine);

	TArray<FAssetData> GetAnimationAssets(FString SearchPath);
	
	// Widget functionality
	void BatchModeChanged(ECheckBoxState NewState);
	ECheckBoxState IsBatchMode() const { return (Settings->SourceMode == EMetadataGeneratorMode::EMGM_Batch) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; }
	FReply OnBatchSourceButton();

	void SingleModeChanged(ECheckBoxState NewState);
	ECheckBoxState IsSingleMode() const { return (Settings->SourceMode == EMetadataGeneratorMode::EMGM_Single) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; }

	void SelectedSingleAssetChanged(const FAssetData& AssetData);

	FReply OnTargetButton();

	FReply OnBuildButton();
	
	FText GetLogText() const;
	
	// Content widgets
	TSharedPtr<SWidgetSwitcher> SourceTypeSwitcher;

	TSharedPtr<SScrollBox> OutputScrollBox;
	bool bShouldAutoscroll;
	
	FText GetBatchSource() const;
	FText GetTarget() const;

	FString GetSourceAssetName() const;

	FText GetBuildButtonText() const;

	bool CanBuild() const;
	
	TOptional<float> GetProgress() const;
	FText GetProgressDescription() const;
	
	// Layout widgets
	TSharedPtr<IDetailsView> DetailsView;

	// State
	bool IsRunning() const;
	bool CanConfigure() const { return !IsRunning(); }

	void ClearProgressState(bool bWipePercentage, FText EndMessage);
	void UpdateBuildPercentage();
	
	FAnimationMetaWorker *AnimationWorker;

	UAnimationMetadataSettings *Settings;

	FAssetData SourceAsset;
	FString SourcePath;
	FString TargetPath;

	TArray<FAssetData> AssetWorkSet;

	float BuildProgressPercent;
	FText BuildProgressDescription;
	
	FText OutputLogText;
	
};
