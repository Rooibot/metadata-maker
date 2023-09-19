#include "RooitoolAnimationCommands.h"

#define LOCTEXT_NAMESPACE "Rooitools"

void FRooitoolAnimationCommands::RegisterCommands()
{
	UI_COMMAND(OpenAnimationMetaTab, "MetadataMaker", "Convert root motion animations into in-place, and add appropriate metadata curve tracks.", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE