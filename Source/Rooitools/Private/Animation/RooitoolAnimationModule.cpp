#include "RooitoolAnimationModule.h"

#include "RooitoolAnimationCommands.h"
#include "ToolMenuSection.h"

#define LOCTEXT_NAMESPACE "FRooitoolsModule"

DEFINE_LOG_CATEGORY(LogRooitoolsAnimation)

const FName RooitoolAnimMetaTabName = FName(TEXT("RooiAnimMeta"));

FName FRooitoolAnimationModule::GetName() const
{
	return FName("Animation");
}

FString FRooitoolAnimationModule::GetDisplayName() const
{
	return TEXT("Animation");
}

FString FRooitoolAnimationModule::GetVersion() const
{
	return TEXT("1.0.0");
}

bool FRooitoolAnimationModule::IsEnabled() const
{
	return true;
}

void FRooitoolAnimationModule::InitializeToolUI()
{
	FRooitoolAnimationCommands::Register();
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FRooitoolAnimationCommands::Get().OpenAnimationMetaTab,
		FExecuteAction::CreateRaw(this, &FRooitoolAnimationModule::OpenAnimationMetadataTab),
		FCanExecuteAction());
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(RooitoolAnimMetaTabName, FOnSpawnTab::CreateRaw(this, &FRooitoolAnimationModule::OnSpawnAnimationMetadataTab))
		.SetDisplayName(LOCTEXT("FRooitoolAnimMetaTitle", "MetadataMaker"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	AnimationMetaTab = MakeShareable(new FAnimationMetaToolsTab());
	AnimationMetaTab->SetupDefaults();
}

void FRooitoolAnimationModule::TeardownToolUI()
{
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(RooitoolAnimMetaTabName);
	FRooitoolAnimationCommands::Unregister();
}


void FRooitoolAnimationModule::CreateMenuEntries(FToolMenuSection& Section)
{
	Section.AddMenuEntryWithCommandList(FRooitoolAnimationCommands::Get().OpenAnimationMetaTab, PluginCommands,
		TAttribute<FText>(), TAttribute<FText>());
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void FRooitoolAnimationModule::OpenAnimationMetadataTab()
{
	FGlobalTabmanager::Get()->TryInvokeTab(RooitoolAnimMetaTabName);
}

// ReSharper disable once CppMemberFunctionMayBeConst
TSharedRef<SDockTab> FRooitoolAnimationModule::OnSpawnAnimationMetadataTab(const FSpawnTabArgs& SpawnTabArgs)
{
	return AnimationMetaTab->PrepareTab(SpawnTabArgs);
}




#undef LOCTEXT_NAMESPACE
