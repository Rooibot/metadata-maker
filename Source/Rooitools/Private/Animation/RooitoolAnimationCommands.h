#pragma once

#include "CoreMinimal.h"
#include "RooitoolsStyle.h"

class FRooitoolAnimationCommands : public TCommands<FRooitoolAnimationCommands>
{
public:
	FRooitoolAnimationCommands()
		: TCommands<FRooitoolAnimationCommands>(TEXT("Rooitools"), NSLOCTEXT("Contexts", "RooiAnim", "Rooitools Animation System"), NAME_None, FRooitoolsStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenAnimationMetaTab;	
};
