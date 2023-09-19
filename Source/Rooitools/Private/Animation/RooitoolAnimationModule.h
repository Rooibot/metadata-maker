#pragma once

#include "AnimationMetaToolsTab.h"
#include "Core/RooitoolToolModule.h"
#include "Core/RooitoolTab.h"

class FRooitoolAnimationModule : public IRooitoolToolModule
{
public:

	
	
	// Functionality required by IRooitoolToolModule
	virtual FName GetName() const override;
	virtual FString GetDisplayName() const override;
	virtual FString GetVersion() const override;
	virtual bool IsEnabled() const override;
	virtual void InitializeToolUI() override;
	virtual void CreateMenuEntries(FToolMenuSection& Section) override;
	virtual void TeardownToolUI() override;

	void OpenAnimationMetadataTab();
	
private:

	TSharedRef<class SDockTab> OnSpawnAnimationMetadataTab(const class FSpawnTabArgs& SpawnTabArgs);

	TSharedPtr<class FUICommandList> PluginCommands;

	TSharedPtr<FAnimationMetaToolsTab> AnimationMetaTab;
	
};
