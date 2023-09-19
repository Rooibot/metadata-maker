#include "AnimationMetaToolsTab.h"

#include "EditorStyleSet.h"
#include "PropertyCustomizationHelpers.h"
#include "Rooitools.h"
#include "RooitoolsStyle.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Dialogs/DlgPickPath.h"
#include "Widgets/Layout/SScrollBorder.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Widgets/Notifications/SProgressBar.h"
#include "Widgets/Text/SMultiLineEditableText.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "Rooitools"

FAnimationMetaToolsTab::FAnimationMetaToolsTab() : FRooitoolTab()
{
	AnimationWorker = new FAnimationMetaWorker();
	Settings = GetMutableDefault<UAnimationMetadataSettings>();
	Settings->AddToRoot();
}

FAnimationMetaToolsTab::~FAnimationMetaToolsTab()
{
	
}

void FAnimationMetaToolsTab::SetMode(EMetadataGeneratorMode NewMode)
{
	Settings->SourceMode = NewMode;
	Settings->SaveConfig();
}

void FAnimationMetaToolsTab::SetFileBehavior(EMetadataGeneratorFileLogic NewLogic)
{
	Settings->FileMode = NewLogic;
	Settings->SaveConfig();
}

void FAnimationMetaToolsTab::SetupDefaults()
{
	OutputLogText = FText::FromString("");

	// Get defaults
	Settings->LoadConfig();
	ClearProgressState(true, FText());
	bShouldAutoscroll = true;
	
	FRooitoolTab::SetupDefaults();
}

TSharedRef<SDockTab> FAnimationMetaToolsTab::PrepareTab(const class FSpawnTabArgs& SpawnTabArgs)
{
	FText InformationText = LOCTEXT("AnimMetadataInfo", "When choosing a source, the animations being used must be root-motion animations, and configured as such; the metadata generator will skip any that aren't.");

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs ViewArgs;
	ViewArgs.bAllowSearch = false;
	ViewArgs.bHideSelectionTip = false;
	ViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	ViewArgs.NotifyHook = this;

	// We need the TSharedRef to pass into Slate.
	const auto PropertyView = PropertyModule.CreateDetailView(ViewArgs);
	PropertyView->SetObject(Settings);

	// But we need to store it off as a TSharedPtr.
	DetailsView = PropertyView;
	
	auto NewTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SSplitter)
			.Orientation(Orient_Horizontal)

			+ SSplitter::Slot()
			.Resizable(true)
			.Value(1)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(4))
				[
					SNew(SBorder)
					.Padding(FMargin(3))
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.Padding(FMargin(4))
							.AutoWidth()
							[
								SNew(STextBlock)
								.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
								.Text(LOCTEXT("Section.AnimSource", "ANIMATION SOURCES"))
							]

							+ SHorizontalBox::Slot()
							.FillWidth(0.9)
							.Padding(FMargin(14, 0, 0, 0))
							.VAlign(VAlign_Center)
							.HAlign(HAlign_Fill)
							[
								SNew(SSeparator)
								.Orientation(Orient_Horizontal)
								.Thickness(1.0f)
							]
						]

						+ SVerticalBox::Slot()
						.Padding(124, 4, 4, 4)
						.AutoHeight()
						[
							SNew(SWrapBox)
							.Orientation(Orient_Horizontal)
							.UseAllottedSize(true)
							.InnerSlotPadding(FVector2D(4, 4))

							+ SWrapBox::Slot()
							[
								SNew(SCheckBox)
								.Style(FAppStyle::Get(), "DetailsView.SectionButton")
								.OnCheckStateChanged_Raw(this, &FAnimationMetaToolsTab::BatchModeChanged).IsChecked(ECheckBoxState::Checked)
								.IsChecked_Raw(this, &FAnimationMetaToolsTab::IsBatchMode)
								.IsEnabled_Raw(this, &FAnimationMetaToolsTab::CanConfigure)
								[
									SNew(STextBlock)
									.TextStyle(FAppStyle::Get(), "SmallText")
									.Text(LOCTEXT("AnimMetaOption.Batch", "Batch"))
								]
							]

							+ SWrapBox::Slot()
							[
								SNew(SCheckBox)
								.Style(FAppStyle::Get(), "DetailsView.SectionButton")
								.OnCheckStateChanged_Raw(this, &FAnimationMetaToolsTab::SingleModeChanged).IsChecked(ECheckBoxState::Checked)
								.IsChecked_Raw(this, &FAnimationMetaToolsTab::IsSingleMode)
								.IsEnabled_Raw(this, &FAnimationMetaToolsTab::CanConfigure)
								[
									SNew(STextBlock)
									.TextStyle(FAppStyle::Get(), "SmallText")
									.Text(LOCTEXT("AnimMetaOption.Single", "Single"))
								]
							]							
						]

						+SVerticalBox::Slot()
						.AutoHeight()
						[
							SAssignNew(SourceTypeSwitcher, SWidgetSwitcher)
							+ SWidgetSwitcher::Slot()
							[
								SNew(SVerticalBox)
								+ SVerticalBox::Slot()
								.MaxHeight(30)
								[
									SNew(SHorizontalBox)
									+ SHorizontalBox::Slot()
									.AutoWidth()
									[
										SNew(SBox)
										.WidthOverride(120)
										.Padding(FMargin(4))
										[
											SNew(STextBlock)
											.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
											.Text(LOCTEXT("Sources.Folder", "Source Folder:"))
										]
									]

									+ SHorizontalBox::Slot()
									.FillWidth(0.9)
									[
										SNew(SBorder)
										.HAlign(HAlign_Fill)
										.VAlign(VAlign_Center)
										.Padding(FMargin(0))
										.BorderImage(FRooitoolsStyle::Get().GetBrush("Box.RoundedBorder"))
										[
											SNew(SBox)
											.VAlign(VAlign_Center)
											.HAlign(HAlign_Fill)
											.HeightOverride(22)
											.Padding(FMargin(0))
											[
												SNew(SBox)
												.Padding(FMargin(0))
												.VAlign(VAlign_Center)
												[
													SNew(STextBlock)
													.Margin(FMargin(6,0))
													.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
													.Text_Raw(this, &FAnimationMetaToolsTab::GetBatchSource)
												]
											]
										]
									]

									+ SHorizontalBox::Slot()
									.AutoWidth()
									.VAlign(VAlign_Center)
									[
										SNew(SButton)
										.Text(LOCTEXT("Buttons.Browse", "Browse"))
										.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
										.IsEnabled_Raw(this, &FAnimationMetaToolsTab::CanConfigure)
										.OnClicked_Raw(this, &FAnimationMetaToolsTab::OnBatchSourceButton)
									]
								]
							]

							+ SWidgetSwitcher::Slot()
							[
								SNew(SVerticalBox)
								+ SVerticalBox::Slot()
								[
									SNew(SHorizontalBox)
									+ SHorizontalBox::Slot()
									.AutoWidth()
									[
										SNew(SBox)
										.WidthOverride(120)
										.Padding(FMargin(4))
										[
											SNew(STextBlock)
											.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
											.Text(LOCTEXT("Sources.Item", "Source Asset:"))
										]
									]

									+ SHorizontalBox::Slot()
									.FillWidth(0.9)
									.Padding(FMargin(0,0,7,0))
									[
										SNew(SObjectPropertyEntryBox)
										.AllowedClass(UAnimSequence::StaticClass())
										.ObjectPath_Raw(this, &FAnimationMetaToolsTab::GetSourceAssetName)
										.OnObjectChanged_Raw(this, &FAnimationMetaToolsTab::SelectedSingleAssetChanged)
										.IsEnabled_Raw(this, &FAnimationMetaToolsTab::CanConfigure)
									]
								]
							]
						]

						+ SVerticalBox::Slot()
						.MaxHeight(30)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SBox)
								.WidthOverride(120)
								.Padding(FMargin(4))
								[
									SNew(STextBlock)
									.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
									.Text(LOCTEXT("Target.Folder", "Output Folder:"))
								]
							]

							+ SHorizontalBox::Slot()
							.FillWidth(0.9)
							[
								SNew(SBorder)
								.HAlign(HAlign_Fill)
								.VAlign(VAlign_Center)
								.Padding(FMargin(0))
								.BorderImage(FRooitoolsStyle::Get().GetBrush("Box.RoundedBorder"))
								[
									SNew(SBox)
									.VAlign(VAlign_Center)
									.HAlign(HAlign_Fill)
									.HeightOverride(22)
									.Padding(FMargin(0))
									[
										SNew(SBox)
										.VAlign(VAlign_Center)
										.Padding(FMargin(0))
										[
											SNew(STextBlock)
											.Margin(FMargin(6,0))
											.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
											.Text_Raw(this, &FAnimationMetaToolsTab::GetTarget)
										]
									]
								]
							]

							+ SHorizontalBox::Slot()
							.AutoWidth()
							.VAlign(VAlign_Center)
							[
								SNew(SButton)
								.Text(LOCTEXT("Buttons.Browse", "Browse"))
								.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
								.OnClicked_Raw(this, &FAnimationMetaToolsTab::OnTargetButton)
								.IsEnabled_Raw(this, &FAnimationMetaToolsTab::CanConfigure)
							]
						]
														
						+ SVerticalBox::Slot()
						.AutoHeight()
						.Padding(FMargin(4, 8, 4, 4))
						[
							SNew(STextBlock)
							.AutoWrapText(true)
							.Font(FAppStyle::GetFontStyle("PropertyWindow.NormalFont"))
							.Text(InformationText)
						]
					]
				]

				+ SVerticalBox::Slot()
				.Padding(FMargin(4,6,4, 4))
				.FillHeight(0.9)
				[
					SNew(SBorder)
					.Padding(FMargin(3))
					.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.Padding(FMargin(4))
							.AutoWidth()
							[
								SNew(STextBlock)
								.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
								.Text(LOCTEXT("Section.Config", "CONFIGURATION"))
							]

							+ SHorizontalBox::Slot()
							.FillWidth(0.9)
							.Padding(FMargin(14, 0, 0, 0))
							.VAlign(VAlign_Center)
							.HAlign(HAlign_Fill)
							[
								SNew(SSeparator)
								.Orientation(Orient_Horizontal)
								.Thickness(1.0f)
							]
						]

						+ SVerticalBox::Slot()
						.FillHeight(0.9)
						.VAlign(VAlign_Fill)
						[
							PropertyView
						]
					]
				]
			]

			+ SSplitter::Slot()
			.Value(3)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.Padding(FMargin(0,0,6,0))
				.AutoHeight()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(3)
					[
						SNew(SButton)
						.Text_Raw(this, &FAnimationMetaToolsTab::GetBuildButtonText)
						.VAlign(VAlign_Center)
						.OnClicked_Raw(this, &FAnimationMetaToolsTab::OnBuildButton)
						.IsEnabled_Raw(this, &FAnimationMetaToolsTab::CanBuild)
					]

					+SHorizontalBox::Slot()
					.FillWidth(1)
					.Padding(3)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						[
							SNew(SProgressBar)
							.Percent_Raw(this, &FAnimationMetaToolsTab::GetProgress)
						]
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.TextStyle(FRooitoolsStyle::Get(), "Text.Normal")
							.Text_Raw(this, &FAnimationMetaToolsTab::GetProgressDescription)
						]
					]
				
				]

				+ SVerticalBox::Slot()
				.FillHeight(0.9)
				.Padding(FMargin(6))
				[
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					.FillHeight(0.9)
					[
						SNew(SBorder)
						[
							SAssignNew(OutputScrollBox, SScrollBox)
							.OnUserScrolled_Raw(this, &FAnimationMetaToolsTab::HandleUserScrolled)
							+ SScrollBox::Slot()
							[
								SNew(SMultiLineEditableText)
								.Margin(FMargin(6))
								.TextStyle(FRooitoolsStyle::Get(), "Text.Mono")
								.AutoWrapText(true)
								.Text_Raw(this, &FAnimationMetaToolsTab::GetLogText)
							]
						]
					]
				]
			]
			
		];

	NewTab->SetTabIcon(DefaultIcon);
	SourceTypeSwitcher->SetActiveWidgetIndex(Settings->SourceMode == EMetadataGeneratorMode::EMGM_Batch ? 0 : 1);

	// Call our parent setup.
	SetupTab(NewTab);

	return NewTab;
}

bool FAnimationMetaToolsTab::Tick(float DeltaTime)
{
	if (AnimationWorker->IsFinished())
	{
		ClearProgressState(true, LOCTEXT("Status.MetadataDone", "All metadata built!"));
		return true;
	}
	
	AnimationWorker->TryStartNextTask();
	return true;
}

void FAnimationMetaToolsTab::UpdateBuildPercentage()
{
	FText Title = LOCTEXT("Title.MetadataMaker", "MetadataMaker");
	
	if (AnimationWorker->IsFinished())
	{
		BuildProgressPercent = 0.0;
		SlateTab->SetLabel(Title);
		return;
	}

	int32 TotalTasks, FinishedTasks, RunningTasks, PendingTasks;
	AnimationWorker->GetTaskCount(TotalTasks, FinishedTasks, RunningTasks, PendingTasks);

	// Append our current percentage.
	BuildProgressPercent = (FinishedTasks * 1.0) / TotalTasks;
	const FString TabLabel = Title.ToString() + FString::Printf(TEXT(" [%02d%%]"), static_cast<int>(trunc(BuildProgressPercent * 100)));
	SlateTab->SetLabel(FText::FromString(TabLabel));
}


void FAnimationMetaToolsTab::Cleanup()
{
	FRooitoolTab::Cleanup();
}

void FAnimationMetaToolsTab::ProgressMessageForItem(const FAssetData& Item, FText Message, bool ShowWithProgress, bool AddToLog, ELogVerbosity::Type MsgLogLevel)
{
	FString Prefix = StatusPrefix();
	const FString FullMessage = RelativePathForAsset(Item) + TEXT(": ") + Message.ToString();
	
	if (AddToLog)
	{
		Log(MsgLogLevel, FullMessage);
	}

	if (ShowWithProgress)
	{
		BuildProgressDescription = FText::FromString(Prefix + FullMessage);
	}

}

void FAnimationMetaToolsTab::MarkItemCompleted(const FAssetData& Item, FText ErrorMessage)
{
	if (!ErrorMessage.IsEmpty())
	{
		Log(ELogVerbosity::Error, TEXT("ERROR (") + RelativePathForAsset(Item) + "): " + ErrorMessage.ToString());
	}
	else
	{
		const FText CompletedMsg = LOCTEXT("Info.Completed", "Tasks completed!");
		const FString FinishedString = RelativePathForAsset(Item) + TEXT(": ") + CompletedMsg.ToString();
		Log(ELogVerbosity::Log, FinishedString);
	}

	Log(ELogVerbosity::Log, TEXT("------------"));

	UpdateBuildPercentage();

	// If we're entirely done, our next Tick() will take care of that.
}

void FAnimationMetaToolsTab::NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent,
	FProperty* PropertyThatChanged)
{
	Settings->SaveConfig();
}

void FAnimationMetaToolsTab::HandleUserScrolled(float ScrollOffset)
{
	bShouldAutoscroll = ScrollOffset == OutputScrollBox->GetScrollOffsetOfEnd();
}


void FAnimationMetaToolsTab::ClearProgressState(bool bClearPercentage, FText EndMessage)
{
	StopTick();
	AnimationWorker->Cancel();
	if (DetailsView.IsValid())
		DetailsView->SetEnabled(true);
	
	if (bClearPercentage)
		BuildProgressPercent = 0.0;

	BuildProgressDescription = EndMessage;
	if (!EndMessage.IsEmpty())
	{
		Log(ELogVerbosity::Log, EndMessage.ToString());
	}

	if (SlateTab.IsValid())
		SlateTab->SetLabel(LOCTEXT("Title.MetadataMaker", "MetadataMaker"));
	
	AssetWorkSet.Empty();
}

FString FAnimationMetaToolsTab::StatusPrefix() const
{
	int32 TotalTasks, FinishedTasks, RunningTasks, PendingTasks;
	AnimationWorker->GetTaskCount(TotalTasks, FinishedTasks, RunningTasks, PendingTasks);

	if (TotalTasks == 0)
	{
		return TEXT("");
	}

	// I hate everything about how Unreal templates everything and then refuses to take parameters of
	// the appropriate type, leading to shameful bits like this.
	if (TotalTasks >= 1000)
	{
		// *quiet screaming*
		return FString::Printf(TEXT("[%04d/%04d] "), FinishedTasks, TotalTasks);
	}
	else if (TotalTasks >= 100)
	{
		return FString::Printf(TEXT("[%03d/%03d] "), FinishedTasks, TotalTasks);
	}

	return FString::Printf(TEXT("[%02d/%02d] "), FinishedTasks, TotalTasks);
}

void FAnimationMetaToolsTab::PopulateConfiguration(FAnimationMetaConfig& Config)
{
	Config.SourcePath = SourcePath;
	Config.TargetPath = TargetPath;
	Config.ExistingFileLogic = Settings->FileMode;
	Config.bForceRootMotion = Settings->bForceRootMotion;

	if (Settings->bCreateDistanceTrack)
	{
		Config.NameOverrides.Add(FName(TEXT("DistanceMoved_Match")), FName(TEXT("Distance")));
		Config.NameOverrides.Add(FName(TEXT("Yaw_Match")), FName(TEXT("YawRemaining")));

		Config.ExcludedTracks.Add(FName("DistanceMoved"));
		Config.ExcludedTracks.Add(FName("DistanceMoved_Alpha"));
		Config.ExcludedTracks.Add(FName("DistanceMoved_Delta"));
		Config.ExcludedTracks.Add(FName("MovementSpeed_Match"));
		Config.ExcludedTracks.Add(FName("Forward_Match"));
		Config.ExcludedTracks.Add(FName("Right_Match"));
		Config.ExcludedTracks.Add(FName("Up_Match"));
		Config.ExcludedTracks.Add(FName("Pitch_Match"));
		Config.ExcludedTracks.Add(FName("Roll_Match"));
	}
	
	if (Settings->bCreateALS)
	{
		// Change a few Rooibot-style track names to their ALSv4 equivalents.
		Config.NameOverrides.Add(FName(TEXT("MovementSpeed_BreakPoints")), FName(TEXT("Gait")));
		Config.NameOverrides.Add(FName(TEXT("Yaw_Delta")), FName(TEXT("RotationAmount")));

		// Since we turned on break-points, let's make sure we aren't generating ones we don't want.
		Config.ExcludedTracks.Append({
			FName(TEXT("Forward_BreakPoints")),
			FName(TEXT("Right_BreakPoints")),
			FName(TEXT("Up_BreakPoints")),
			FName(TEXT("Yaw_BreakPoints")),
			FName(TEXT("Pitch_BreakPoints")),
			FName(TEXT("Roll_BreakPoints"))
		});

		// Likewise if we forced delta tracks on.
		if (!Settings->bCreateDeltaTracks)
		{
			Config.ExcludedTracks.Append({
				FName(TEXT("MovementSpeed_Delta")),
				FName(TEXT("Forward_Delta")),
				FName(TEXT("Right_Delta")),
				FName(TEXT("Up_Delta")),
				FName(TEXT("Pitch_Delta")),
				FName(TEXT("Roll_Delta"))
			});
		}
	}
}

FString FAnimationMetaToolsTab::RelativePathForAsset(const FAssetData& Item) const
{
	FString RelativePath = Item.AssetName.ToString();

	if (Settings->SourceMode == EMetadataGeneratorMode::EMGM_Batch)
	{
		RelativePath = Item.GetObjectPathString();
		if (RelativePath.StartsWith(SourcePath))
		{
			RelativePath = RelativePath.Right(RelativePath.Len() - (SourcePath.Len() + 1));
		}

		int32 Index;
		if (RelativePath.FindLastChar(L'.', Index))
		{
			RelativePath = RelativePath.Left(Index);
		}
	}

	return RelativePath;
}

void FAnimationMetaToolsTab::PopulateJobData(FAnimationJobData& Job, const FAssetData& Data, FString Destination)
{
	Job.Status = this;
	Job.WorkItem = Data;
	Job.DestinationAssetPath = Destination;

	PopulateConfiguration(Job.Config);
}

TArray<FAssetData> FAnimationMetaToolsTab::GetAnimationAssets(FString SearchPath)
{
	TArray<FAssetData> WorkingSet;
	TArray<FAssetData> Result;

	const FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	const auto AnimClass = UAnimSequence::StaticClass();
	
	// Need to do this if running in the editor with -game to make sure that the assets in the following path are available
	TArray<FString> PathsToScan;
	PathsToScan.Add(SearchPath);
	AssetRegistry.ScanPathsSynchronous(PathsToScan);

	AssetRegistry.GetAssetsByPath(FName(SearchPath), WorkingSet, true);

	for (auto& Asset : WorkingSet)
	{
		if (Asset.GetClass()->IsChildOf(AnimClass))
			Result.Add(Asset);
	}
	
	return Result;
}

void FAnimationMetaToolsTab::BatchModeChanged(ECheckBoxState NewState)
{
	if (NewState == ECheckBoxState::Checked)
	{
		SetMode(EMetadataGeneratorMode::EMGM_Batch);
		
		if (SourceTypeSwitcher.IsValid())
		{
			SourceTypeSwitcher->SetActiveWidgetIndex(0);
		}
	}
}

void FAnimationMetaToolsTab::SingleModeChanged(ECheckBoxState NewState)
{
	if (NewState == ECheckBoxState::Checked)
	{
		SetMode(EMetadataGeneratorMode::EMGM_Single);
		
		if (SourceTypeSwitcher.IsValid())
		{
			SourceTypeSwitcher->SetActiveWidgetIndex(1);
		}
	}
}

FReply FAnimationMetaToolsTab::OnBatchSourceButton()
{
	TSharedPtr<SDlgPickPath> PickAssetPathWidget = SNew(SDlgPickPath).Title(FText::FromString("Select source directory"));

	if (EAppReturnType::Ok == PickAssetPathWidget->ShowModal())
	{
		SourcePath = PickAssetPathWidget->GetPath().ToString();
		Log(ELogVerbosity::Log, FString::Printf(TEXT("Source directory set: %ls"), *SourcePath));
	}
	return FReply::Handled();
}

void FAnimationMetaToolsTab::SelectedSingleAssetChanged(const FAssetData& AssetData)
{
	if (!AssetData.IsValid())
	{
		FString Error = FString::Printf(TEXT("Invalid source asset: %ls"), *AssetData.GetObjectPathString());
		Log(ELogVerbosity::Error, Error);
		return;
	}

	SourceAsset = AssetData;
}

FReply FAnimationMetaToolsTab::OnTargetButton()
{
	TSharedPtr<SDlgPickPath> PickAssetPathWidget = SNew(SDlgPickPath).Title(FText::FromString("Select target directory"));

	if (EAppReturnType::Ok == PickAssetPathWidget->ShowModal())
	{
		TargetPath = PickAssetPathWidget->GetPath().ToString();
		Log(ELogVerbosity::Log, FString::Printf(TEXT("Target directory set: %ls"), *TargetPath));
	}
	return FReply::Handled();
}

FReply FAnimationMetaToolsTab::OnBuildButton()
{
	if (IsRunning())
	{
		ClearProgressState(true, LOCTEXT("Status.UserCancelled", "Build cancelled by user."));
		return FReply::Handled();
	}

	OutputLogText = FText::FromString("");

	// Create an image of current configuration.
	FAnimationMetaConfig TaskConfig;
	PopulateConfiguration(TaskConfig);

	// Build our root bone task.
	FAnimationBoneCurveTask RootTask;
	bool bError;
	RootTask.Bone.BoneName = FName("root");
	RootTask.Bone.Initialize(Settings->GetSkeleton(bError, nullptr));

	// These are always true for the root bone.
	RootTask.bCreateForward = true;
	RootTask.bCreateRight = true;
	RootTask.bCreateYaw = true;
	RootTask.bCreateUp = Settings->bIncludeVertical;
	RootTask.bCreatePitch = RootTask.bCreateRoll = Settings->bIncludeAllRotations;

	RootTask.bCreateDistance = Settings->bCreateDistanceTrack;

	RootTask.bCreateAlpha = Settings->bCreateAlphaTracks;
	RootTask.bCreateDelta = Settings->bCreateALS || Settings->bCreateDeltaTracks;
	RootTask.bCreateBreakPoints = Settings->bCreateALS;

	if (Settings->bCreateALS)
	{
		TArray<float> GaitArray = {Settings->WalkSpeed, Settings->RunSpeed, Settings->SprintSpeed};

		auto RealArray = NewObject<UFloatArray>();
		RealArray->SetArrayValues(GaitArray);
		
		RootTask.bCreateBreakPoints = true;
		RootTask.BreakPoints.Add(EBoneCurveMetadataCategory::MovementSpeed, RealArray);
	}

	TArray<FAnimationBoneCurveTask> BoneTasks;
	BoneTasks.Add(RootTask);
	BoneTasks.Append(Settings->ExtraBones);
	
	if (Settings->SourceMode == EMetadataGeneratorMode::EMGM_Batch)
	{
		const FString BuildMessage = FString::Printf(TEXT("Collecting files from '%ls'..."), *SourcePath);
		BuildProgressDescription = FText::FromString(BuildMessage);
		Log(ELogVerbosity::Log, BuildMessage);

		auto Assets = GetAnimationAssets(SourcePath);
		if (Assets.Num() == 0)
		{
			const auto ErrorMsg = FString::Printf(TEXT("Build aborted; no animation assets found in '%ls'."), *SourcePath);
			Log(ELogVerbosity::Error, ErrorMsg);
			BuildProgressDescription = FText::FromString(ErrorMsg);
			BuildProgressPercent = 0;
			return FReply::Handled();
		}

		Log(ELogVerbosity::Log, FString::Printf(TEXT("Found %d animation assets."), Assets.Num()));
		BuildProgressPercent = 0;

		// Create our working queue.
		AssetWorkSet = Assets;
		for (const auto& Asset : Assets)
		{
			const FString RelativePath = RelativePathForAsset(Asset);
			const FString DestinationPath = TargetPath + TEXT("/") + RelativePath;
			
			FAnimationJobData Job;
			PopulateJobData(Job, Asset, DestinationPath);
			Job.Bones = BoneTasks;

			AnimationWorker->QueueJob(Job);
		}
	}
	else if (Settings->SourceMode == EMetadataGeneratorMode::EMGM_Single)
	{
		const FString Destination = TargetPath + TEXT("/") + RelativePathForAsset(SourceAsset);
		FAnimationJobData Job;
		PopulateJobData(Job, SourceAsset, Destination);
		Job.Bones = BoneTasks;

		AnimationWorker->QueueJob(Job);
	}
	DetailsView->SetEnabled(false);
	Log(ELogVerbosity::Log, TEXT("------------"));
	StartTick();
	return FReply::Handled();
}

void FAnimationMetaToolsTab::Log(ELogVerbosity::Type LogMsgLevel, const FString LogLine)
{
	if (LogLine.IsEmpty()) return;

	// Update our actual output log.
	const FString NewString = OutputLogText.ToString() + LogLine + "\n";
	OutputLogText = FText::FromString(NewString);	

	// Log to Unreal log as well, if it's a Warning or Error.
	// It is obnoxious that there's seemingly no way to pass in a loglevel to the macro.
	switch (LogMsgLevel)
	{
		case ELogVerbosity::Warning:
			UE_LOG(LogRooitoolsAnimation, Warning, TEXT("%ls"), *LogLine);
			break;

		case ELogVerbosity::Error:
			UE_LOG(LogRooitoolsAnimation, Error, TEXT("%ls"), *LogLine);
			break;

		default:
			break;
	}

	if (bShouldAutoscroll)
	{
		FFunctionGraphTask::CreateAndDispatchWhenReady([this]()
		{
			OutputScrollBox->ScrollToEnd();			
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	}

}

bool FAnimationMetaToolsTab::IsRunning() const
{
	int32 TotalTasks, FinishedTasks, RunningTasks, PendingTasks;
	AnimationWorker->GetTaskCount(TotalTasks, FinishedTasks, RunningTasks, PendingTasks);

	return (FinishedTasks != TotalTasks);
}

FText FAnimationMetaToolsTab::GetBatchSource() const
{
	return FText::FromString(SourcePath);
}

FText FAnimationMetaToolsTab::GetTarget() const
{
	return FText::FromString(TargetPath);
}

FString FAnimationMetaToolsTab::GetSourceAssetName() const
{
	if (SourceAsset.IsValid())
	{
		return SourceAsset.GetObjectPathString();
	}

	return TEXT("");
}

FText FAnimationMetaToolsTab::GetBuildButtonText() const
{
	FText Result;
	if (IsRunning())
	{
		Result = LOCTEXT("Button.Cancel", "Cancel");
	}
	else
	{
		Result = LOCTEXT("Button.Build", "Build");
	}

	return Result;
}

bool FAnimationMetaToolsTab::CanBuild() const
{
	if (IsRunning()) return true;
	
	if (TargetPath.IsEmpty())
	{
		return false;
	}

	if (Settings->SourceMode == EMetadataGeneratorMode::EMGM_Batch && SourcePath.IsEmpty())
	{
		return false;
	}
	else if ((Settings->SourceMode == EMetadataGeneratorMode::EMGM_Single) && !SourceAsset.IsValid())
	{
		return false;
	}

	return true;
}

TOptional<float> FAnimationMetaToolsTab::GetProgress() const
{
	return BuildProgressPercent;
}

FText FAnimationMetaToolsTab::GetProgressDescription() const
{
	return BuildProgressDescription;
}

FText FAnimationMetaToolsTab::GetLogText() const
{
	return OutputLogText;
}


#undef LOCTEXT_NAMESPACE
