// Copyright Epic Games, Inc. All Rights Reserved.

#include "Rooitools.h"

#include "ISettingsModule.h"
#include "RooitoolsStyle.h"
#include "Animation/RooitoolAnimationModule.h"
#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "FRooitoolsModule"

void FRooitoolsModule::StartupModule()
{
	const FString ProjectResourceDir = FPaths::ProjectPluginsDir() / TEXT("Rooitools/Resources");
	const FString EngineResourceDir = FPaths::EnginePluginsDir() / TEXT("Rooitools/Resources");
	
	FRooitoolsStyle::Initialize();
	FRooitoolsStyle::ReloadTextures();

	auto AnimModule = new FRooitoolAnimationModule();
	auto Module = static_cast<IRooitoolToolModule*>(AnimModule);
	if (nullptr != Module)
	{
		if (Module->IsEnabled())
		{
			RegisteredModules.Add(Module);
			Module->InitializeToolUI();
		}
		else
		{
			delete AnimModule;
		}
	}
	
	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FRooitoolsModule::RegisterMenus));

}

void FRooitoolsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	GConfig->Flush(false, TEXT("Rooitools"));
	
	for (auto& Module : RegisteredModules)
	{
		if (Module->IsEnabled())
			Module->TeardownToolUI();
	}
	RegisteredModules.Empty();

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);
	
	FRooitoolsStyle::Shutdown();

}

void FRooitoolsModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("MainFrame.MainMenu");
		{
			FToolMenuSection& BaseSection = Menu->FindOrAddSection(NAME_None);
			FToolMenuEntry& RooitoolsMenuEntry = BaseSection.AddSubMenu("Rooitools",
				LOCTEXT("RooitoolsMenu", "Rooitools"),
				LOCTEXT("RooitoolsMenuInfo", "Rooibot Utilities"),
				FNewToolMenuChoice());

			RooitoolsMenuEntry.InsertPosition = FToolMenuInsert("Help", EToolMenuInsertType::After);

			UToolMenu *RooitoolsMenu = UToolMenus::Get()->ExtendMenu("MainFrame.MainMenu.Rooitools");
			
			for (auto& ToolModule : RegisteredModules)
			{
				if (ToolModule->IsEnabled())
				{
					FText DisplayName = FText::FromString(ToolModule->GetDisplayName());
					FToolMenuSection& ModuleSection = RooitoolsMenu->AddSection(ToolModule->GetName(), DisplayName);
					ToolModule->CreateMenuEntries(ModuleSection);
				}
			}
		}
	}

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRooitoolsModule, Rooitools)