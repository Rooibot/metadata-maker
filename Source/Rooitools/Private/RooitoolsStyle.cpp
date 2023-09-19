// Copyright Epic Games, Inc. All Rights Reserved.

#include "RooitoolsStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"
#include "Styling/StyleColors.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FRooitoolsStyle::StyleInstance = nullptr;

void FRooitoolsStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FRooitoolsStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FRooitoolsStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("RooitoolsStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FRooitoolsStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("RooitoolsStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("Rooitools")->GetBaseDir() / TEXT("Resources"));

	// Our cute little mascot
	Style->Set("Rooitools.Rooi", new IMAGE_BRUSH_SVG(TEXT("Rooi"), CoreStyleConstants::Icon128x128));
	Style->Set("Rooitools.RooiSmall", new IMAGE_BRUSH_SVG(TEXT("Rooi"), Icon20x20));

	auto NormalFont = FAppStyle::GetFontStyle("PropertyWindow.NormalFont");
	auto BoldFont = FAppStyle::GetFontStyle("PropertyWindow.BoldFont");

	const auto NormalStyle = FTextBlockStyle()
		.SetFont(NormalFont)
		.SetColorAndOpacity(FSlateColor::UseForeground())
		.SetShadowOffset(FVector2D::ZeroVector)
		.SetShadowColorAndOpacity(FLinearColor::Black);
	Style->Set("Text.Normal", NormalStyle);

	const auto WarningStyle = FTextBlockStyle()
		.SetFont(NormalFont)
		.SetColorAndOpacity(FSlateColor::UseForeground())
		.SetShadowOffset(FVector2D::ZeroVector)
		.SetShadowColorAndOpacity(FLinearColor::Yellow);
	Style->Set("Text.Warning", NormalStyle);

	const auto ErrorStyle = FTextBlockStyle()
		.SetFont(NormalFont)
		.SetColorAndOpacity(FSlateColor::UseForeground())
		.SetShadowOffset(FVector2D::ZeroVector)
		.SetShadowColorAndOpacity(FLinearColor::Red);
	Style->Set("Text.Error", NormalStyle);
	
	
	const auto BoldStyle = FTextBlockStyle()
		.SetFont(BoldFont)
		.SetColorAndOpacity(FSlateColor::UseForeground())
		.SetShadowOffset(FVector2D::ZeroVector)
		.SetShadowColorAndOpacity(FLinearColor::Black);
	Style->Set("Text.Bold", BoldStyle);

	auto HeaderFont = FSlateFontInfo(NormalFont);
	HeaderFont.Size = NormalFont.Size * 2;
	const auto HeaderStyle = FTextBlockStyle()
		.SetFont(HeaderFont)
		.SetColorAndOpacity(FSlateColor::UseForeground())
		.SetShadowOffset(FVector2D(1.0, 1.0))
		.SetShadowColorAndOpacity(FLinearColor::Black);
	Style->Set("Text.Header", HeaderStyle);

	auto MonoFont = DEFAULT_FONT("Mono", 9);
	const auto MonoStyle = FTextBlockStyle()
		.SetFont(MonoFont)
		.SetColorAndOpacity(FSlateColor::UseForeground())
		.SetShadowOffset(FVector2D::ZeroVector)
		.SetShadowColorAndOpacity(FLinearColor::Black);
	Style->Set("Text.Mono", MonoStyle);
	
	auto RoundedBorder = new FSlateRoundedBoxBrush(FStyleColors::Input, 4.0f, FStyleColors::InputOutline, 1.0f);
	Style->Set("Box.RoundedBorder", RoundedBorder);
	
	return Style;
}

void FRooitoolsStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FRooitoolsStyle::Get()
{
	return *StyleInstance;
}
