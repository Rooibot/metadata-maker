// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

/**  */
class FRooitoolsStyle
{
public:

	static void Initialize();

	static void Shutdown();

	/** reloads textures used by slate renderer */
	static void ReloadTextures();

	/** @return The Slate style set for the Shooter game */
	static const ISlateStyle& Get();

	static FName GetStyleSetName();

	static FMargin GetWidgetMargin()
	{
		static FMargin WidgetMargin = FMargin(3.0, 2.0, 3.0, 2.0);
		return WidgetMargin;
	}

private:

	static TSharedRef< class FSlateStyleSet > Create();

	static TSharedPtr< class FSlateStyleSet > StyleInstance;

};