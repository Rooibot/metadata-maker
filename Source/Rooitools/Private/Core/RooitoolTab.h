// Copyright 2022 Rooibot Games

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Docking/SDockTab.h"

UENUM()
enum ERooitoolTabState
{
	RTState_None		UMETA(DisplayName="Uninitialized", ToolTip="This tab has not yet even been configured."),
	RTState_Configured  UMETA(DisplayName="Configured", ToolTip="This tab has been configured, but isn't yet ready"),
	RTState_Initialized UMETA(DisplayName="Initialized", ToolTip="This tab has been initialized and is ready for use."),
	RTState_Visible		UMETA(DisplayName="Visible", ToolTip="This tab is visible and docked somewhere in the engine UI."),
	RTState_Working		UMETA(DisplayName="Working", ToolTip="This tab is actively processing a task of some form.")
};

/**
 * @brief The base URooitoolTab class provides a common interface for some of the more general dockable tab functions.
 *
 * When creating a new ToolTab subclass, the child is responsible for providing an appropriate "Configure" function;
 * as subclasses will likely accept a wide range of configuration parameters or structures, the base class does not
 * provide an implementation to override.
 *
 * Once the factory has produced a new ToolTab, the flow is something like this:
 *   STATE: RTState_None
 *   - SetupDefaults()
 *   - Configure (with subclass-appropriate parameters)
 *   STATE: Configured
 *   - PrepareTab
 *   STATE: Initialized
 *   - tab is docked somewhere in the editor
 *   STATE: Visible
 *   - normal Slate widget functionality here
 *   - eventually the ToolTab begins working on a task
 *   STATE: Working
 *   - tab finishes task
 *   STATE: Visible
 *   - tab is closed
 *   - resources freed
 */
class ROOITOOLS_API FRooitoolTab
{
public:
	FRooitoolTab() { }
	virtual ~FRooitoolTab() = default;

	/**
	 * Sets up any default values. This is the ToolTab equivalent of BeginPlay(), and if a ToolTab subclass overrides
	 * this, it must call the SetupDefaults() of its superclass as part of its own implementation. This should be
	 * done at the *end* of the overridden function.
	 */
	virtual void SetupDefaults();
	
	/** Gets the current state of this ToolTab. */
	ERooitoolTabState GetTabState() const { return TabState; }

	/**
	 * If the ToolTab is in the Configured state, this can be called to create the actual tab. Subclasses should
	 * override this with their actual tab logic. If tab preparation is successful, this should return true, and
	 * the ToolTab's state should be set to Initialized.
	 * @return true if the tab could be prepared, otherwise false
	 */
	virtual TSharedRef<SDockTab> PrepareTab(const class FSpawnTabArgs& SpawnTabArgs);

	/**
	 * If the ToolTab wants to perform any periodic processing, this function should be overridden, and bWantsTick
	 * set to true in SetupDefaults *before* calling the superclass SetupDefaults() implementation.
	 */
	virtual bool Tick(float DeltaTime) { return false; };

	/**
	 * When a Slate tab is closed, this function will be called to allow a ToolTab a chance to clean up any resources
	 * before it gets deallocated.
	 */
	virtual void Cleanup() {};

private:

	// We start our timer pointing to this, and then call the overridable method.
	bool TickInternal(float DeltaTime) { return Tick(DeltaTime); }

	/**
	 * Called by Slate itself when a ToolTab's actual Slate tab is closed in the editor UI. Subclasses should not try
	 * to override this; the base implementation will call Cleanup(), which is where custom cleanup logic should go.
	 */
	void OnTabClosed( TSharedRef<SDockTab> TabBeingClosed);
	
protected:

	/** Prepares any aspects of the tab necessary for the ToolTab functionality to work. Call this from PrepareTab before returning the result. */
	void SetupTab(TSharedRef<SDockTab>& Tab);

	/** Starts our internal "tick". */
	void StartTick();

	/** Stops our internal "tick". */
	void StopTick();

	/** The current state of this ToolTab. */
	ERooitoolTabState TabState;
	
	/** It's Rooi! A cute little robot teacup! (Default tab icon.) */
	const FSlateBrush* DefaultIcon;
	
	/** The actual Slate tab which this ToolTab is responsible for. */
	TSharedPtr<SDockTab> SlateTab;

	/** Used if this ToolTab wants to have Tick() called. */
	FTickerDelegate TickDelegate;

	/** Used if this ToolTab wants to have Tick() called. */
	FTSTicker::FDelegateHandle TickDelegateHandle;
	
};
