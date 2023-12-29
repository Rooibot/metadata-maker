// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Rooitools/Private/Core/RooitoolTab.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRooitoolTab() {}
// Cross Module References
	ROOITOOLS_API UEnum* Z_Construct_UEnum_Rooitools_ERooitoolTabState();
	UPackage* Z_Construct_UPackage__Script_Rooitools();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERooitoolTabState;
	static UEnum* ERooitoolTabState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERooitoolTabState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERooitoolTabState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Rooitools_ERooitoolTabState, (UObject*)Z_Construct_UPackage__Script_Rooitools(), TEXT("ERooitoolTabState"));
		}
		return Z_Registration_Info_UEnum_ERooitoolTabState.OuterSingleton;
	}
	template<> ROOITOOLS_API UEnum* StaticEnum<ERooitoolTabState>()
	{
		return ERooitoolTabState_StaticEnum();
	}
	struct Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics::Enumerators[] = {
		{ "RTState_None", (int64)RTState_None },
		{ "RTState_Configured", (int64)RTState_Configured },
		{ "RTState_Initialized", (int64)RTState_Initialized },
		{ "RTState_Visible", (int64)RTState_Visible },
		{ "RTState_Working", (int64)RTState_Working },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics::Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Core/RooitoolTab.h" },
		{ "RTState_Configured.DisplayName", "Configured" },
		{ "RTState_Configured.Name", "RTState_Configured" },
		{ "RTState_Configured.ToolTip", "This tab has been configured, but isn't yet ready" },
		{ "RTState_Initialized.DisplayName", "Initialized" },
		{ "RTState_Initialized.Name", "RTState_Initialized" },
		{ "RTState_Initialized.ToolTip", "This tab has been initialized and is ready for use." },
		{ "RTState_None.DisplayName", "Uninitialized" },
		{ "RTState_None.Name", "RTState_None" },
		{ "RTState_None.ToolTip", "This tab has not yet even been configured." },
		{ "RTState_Visible.DisplayName", "Visible" },
		{ "RTState_Visible.Name", "RTState_Visible" },
		{ "RTState_Visible.ToolTip", "This tab is visible and docked somewhere in the engine UI." },
		{ "RTState_Working.DisplayName", "Working" },
		{ "RTState_Working.Name", "RTState_Working" },
		{ "RTState_Working.ToolTip", "This tab is actively processing a task of some form." },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Rooitools,
		nullptr,
		"ERooitoolTabState",
		"ERooitoolTabState",
		Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Rooitools_ERooitoolTabState()
	{
		if (!Z_Registration_Info_UEnum_ERooitoolTabState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERooitoolTabState.InnerSingleton, Z_Construct_UEnum_Rooitools_ERooitoolTabState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERooitoolTabState.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Core_RooitoolTab_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Core_RooitoolTab_h_Statics::EnumInfo[] = {
		{ ERooitoolTabState_StaticEnum, TEXT("ERooitoolTabState"), &Z_Registration_Info_UEnum_ERooitoolTabState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4087859318U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Core_RooitoolTab_h_2886057408(TEXT("/Script/Rooitools"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Core_RooitoolTab_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Core_RooitoolTab_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
