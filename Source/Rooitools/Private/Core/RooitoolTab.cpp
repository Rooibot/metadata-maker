// Copyright 2022 Rooibot Games


#include "RooitoolTab.h"
#include "RooitoolsStyle.h"

#define LOCTEXT_NAMESPACE "FRooitoolsModule"

void FRooitoolTab::SetupDefaults()
{
	DefaultIcon = FRooitoolsStyle::Get().GetBrush("Rooitools.Rooi");
	TabState = RTState_None;
}

TSharedRef<SDockTab> FRooitoolTab::PrepareTab(const class FSpawnTabArgs& SpawnTabArgs)
{	
	FText WidgetText = LOCTEXT("WindowWidgetText", "Somehow, you managed to instanciate the base Rooitools ToolTab. This shouldn't happen; close the tab and back away slowly.");
	
	auto TabRef = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];

	TabRef->SetTabIcon(DefaultIcon);
	SlateTab = TabRef;
	
	TabState = RTState_Initialized;

	return TabRef;
}

void FRooitoolTab::OnTabClosed(TSharedRef<SDockTab> TabBeingClosed)
{
	if (!SlateTab.IsValid() || SlateTab->GetId() != TabBeingClosed->GetId()) return;
	
	StopTick();
	Cleanup();

	TabState = RTState_Configured;
	SlateTab.Reset();
}

void FRooitoolTab::SetupTab(TSharedRef<SDockTab>& Tab)
{
	Tab->SetOnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FRooitoolTab::OnTabClosed));
	SlateTab = Tab;
}

void FRooitoolTab::StartTick()
{
	if (TickDelegate.IsBound())
		return;
	
	TickDelegate = FTickerDelegate::CreateRaw(this, &FRooitoolTab::TickInternal);
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(TickDelegate);
}


void FRooitoolTab::StopTick()
{
	if (!TickDelegate.IsBound())
		return;
	
	FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
	TickDelegate.Unbind();
}


#undef LOCTEXT_NAMESPACE
