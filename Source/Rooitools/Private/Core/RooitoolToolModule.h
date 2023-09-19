#pragma once

class IRooitoolToolModule
{

public:
	virtual ~IRooitoolToolModule() = default;

	/**
	 * Override to provide a suitable FName for a menu section, or any other externally-created resource
	 * referring specifically to this module.
	 */
	virtual FName GetName() const { return FName("Base"); }
	
	/**
	 * Override to provide a tool module display name here. This should be short enough to be used as a
	 * menu section header.
	 */
	virtual FString GetDisplayName() const { return TEXT("Base Rooitool Module"); }

	/** Override to provide a version number here. */
	virtual FString GetVersion() const { return TEXT("0.0.0"); }
	
	/**
	 * Override if the Tool Module needs conditional logic to know if it should be loaded or not.
	 * For instance, if it relies on another plugin being loaded to function.
	 */
	virtual bool IsEnabled() const { return false; }

	// Actually handle all our UI glue.

	/** Called prior to CreateMenuEntries, in case any preparation needs to be done. */
	virtual void InitializeToolUI() {}
	
	/** Called when the plugin is setting up, allowing tool modules to add their menu entries. */
	virtual void CreateMenuEntries(FToolMenuSection& Section) {}

	/** Called when we're being unloaded and need to clean up after ourselves. */
	virtual void TeardownToolUI() {}
	
};
