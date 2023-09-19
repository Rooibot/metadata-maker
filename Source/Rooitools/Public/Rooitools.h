// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Core/RooitoolToolModule.h"

class FToolBarBuilder;
class FMenuBuilder;

class FRooitoolsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
private:
	
	void RegisterMenus();

	TArray<IRooitoolToolModule*> RegisteredModules;

};
