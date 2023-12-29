// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Rooitools/Private/Animation/AnimationMetadataSettings.h"
#include "Rooitools/Private/Animation/AnimationMetaSupport.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimationMetadataSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UBoneReferenceSkeletonProvider_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeleton_NoRegister();
	ROOITOOLS_API UClass* Z_Construct_UClass_UAnimationMetadataSettings();
	ROOITOOLS_API UClass* Z_Construct_UClass_UAnimationMetadataSettings_NoRegister();
	ROOITOOLS_API UEnum* Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic();
	ROOITOOLS_API UEnum* Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode();
	ROOITOOLS_API UScriptStruct* Z_Construct_UScriptStruct_FAnimationBoneCurveTask();
	UPackage* Z_Construct_UPackage__Script_Rooitools();
// End Cross Module References
	void UAnimationMetadataSettings::StaticRegisterNativesUAnimationMetadataSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimationMetadataSettings);
	UClass* Z_Construct_UClass_UAnimationMetadataSettings_NoRegister()
	{
		return UAnimationMetadataSettings::StaticClass();
	}
	struct Z_Construct_UClass_UAnimationMetadataSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FInt16PropertyParams NewProp_SourceMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SourceMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SourceMode;
		static const UECodeGen_Private::FInt16PropertyParams NewProp_FileMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FileMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_FileMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bConvertTarget_MetaData[];
#endif
		static void NewProp_bConvertTarget_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bConvertTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEraseCurves_MetaData[];
#endif
		static void NewProp_bEraseCurves_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEraseCurves;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bForceRootMotion_MetaData[];
#endif
		static void NewProp_bForceRootMotion_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceRootMotion;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeVertical_MetaData[];
#endif
		static void NewProp_bIncludeVertical_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeVertical;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeAllRotations_MetaData[];
#endif
		static void NewProp_bIncludeAllRotations_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeAllRotations;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateAlphaTracks_MetaData[];
#endif
		static void NewProp_bCreateAlphaTracks_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateAlphaTracks;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateDeltaTracks_MetaData[];
#endif
		static void NewProp_bCreateDeltaTracks_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateDeltaTracks;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateDistanceTrack_MetaData[];
#endif
		static void NewProp_bCreateDistanceTrack_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateDistanceTrack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateALS_MetaData[];
#endif
		static void NewProp_bCreateALS_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateALS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RunSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RunSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReferenceSkeleton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReferenceSkeleton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReferenceSkeletonPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReferenceSkeletonPath;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ExtraBones_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExtraBones_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ExtraBones;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimationMetadataSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Rooitools,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Animation/AnimationMetadataSettings.h" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const UECodeGen_Private::FInt16PropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SourceMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int16, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SourceMode_MetaData[] = {
		{ "Category", "AnimationMetadataSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Which mode the metadata generator source picker should operate in. EMGM_Single will have an asset picker for the\n\x09 * source line, while EMGM_Batch will instead have a 'Browse' button to pick the source directory. (As the metadata\n\x09 * generator tab has its own UI for this, we hide it from the property editor.)\n\x09 */" },
#endif
		{ "DisplayName", "Source Picker Mode" },
		{ "EditCondition", "false" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Which mode the metadata generator source picker should operate in. EMGM_Single will have an asset picker for the\nsource line, while EMGM_Batch will instead have a 'Browse' button to pick the source directory. (As the metadata\ngenerator tab has its own UI for this, we hide it from the property editor.)" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SourceMode = { "SourceMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimationMetadataSettings, SourceMode), Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SourceMode_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SourceMode_MetaData) }; // 3892284193
	const UECodeGen_Private::FInt16PropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_FileMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int16, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_FileMode_MetaData[] = {
		{ "Category", "Target Settings" },
		{ "DisplayName", "File Behavior" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What should we do upon encountering an existing file as our target?" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_FileMode = { "FileMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimationMetadataSettings, FileMode), Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_FileMode_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_FileMode_MetaData) }; // 2574074453
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bConvertTarget_MetaData[] = {
		{ "Category", "Target Settings" },
		{ "DisplayName", "Convert Targets to In-Place" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should the target files be output as in-place animations, as well as adding the metadata?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bConvertTarget_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bConvertTarget = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bConvertTarget = { "bConvertTarget", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bConvertTarget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bConvertTarget_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bConvertTarget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bEraseCurves_MetaData[] = {
		{ "Category", "Target Settings" },
		{ "DisplayName", "Erase all Target Curves" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we ensure our target has only our generated metadata curves?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bEraseCurves_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bEraseCurves = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bEraseCurves = { "bEraseCurves", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bEraseCurves_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bEraseCurves_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bEraseCurves_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bForceRootMotion_MetaData[] = {
		{ "Category", "Input Settings" },
		{ "DisplayName", "Force Root-Motion on Source" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we force root-motion on for source files not using root-motion?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bForceRootMotion_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bForceRootMotion = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bForceRootMotion = { "bForceRootMotion", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bForceRootMotion_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bForceRootMotion_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bForceRootMotion_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeVertical_MetaData[] = {
		{ "Category", "Input Settings" },
		{ "DisplayName", "Include Vertical Movement" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we include vertical movement tracks, as well as Forward and Right?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeVertical_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bIncludeVertical = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeVertical = { "bIncludeVertical", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeVertical_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeVertical_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeVertical_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeAllRotations_MetaData[] = {
		{ "Category", "Input Settings" },
		{ "DisplayName", "Include Pitch and Roll" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we include the Pitch and Roll data as well as Yaw?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeAllRotations_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bIncludeAllRotations = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeAllRotations = { "bIncludeAllRotations", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeAllRotations_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeAllRotations_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeAllRotations_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateAlphaTracks_MetaData[] = {
		{ "Category", "Output Settings" },
		{ "DisplayName", "Create Alpha Tracks" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we include not just movement tracks, but also the alpha between minimum and maximum?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateAlphaTracks_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bCreateAlphaTracks = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateAlphaTracks = { "bCreateAlphaTracks", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateAlphaTracks_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateAlphaTracks_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateAlphaTracks_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDeltaTracks_MetaData[] = {
		{ "Category", "Output Settings" },
		{ "DisplayName", "Create Delta Tracks" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we include not just movement tracks, but also the delta between a given frame and the previous?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDeltaTracks_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bCreateDeltaTracks = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDeltaTracks = { "bCreateDeltaTracks", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDeltaTracks_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDeltaTracks_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDeltaTracks_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDistanceTrack_MetaData[] = {
		{ "Category", "Output Settings" },
		{ "DisplayName", "Create Distance Matching Track" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create a Lyra-style distance matching track?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDistanceTrack_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bCreateDistanceTrack = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDistanceTrack = { "bCreateDistanceTrack", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDistanceTrack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDistanceTrack_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDistanceTrack_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateALS_MetaData[] = {
		{ "Category", "Output Settings" },
		{ "DisplayName", "Create ALSv4 Data" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create tracks appropriate for the community edition of ALSv4?" },
#endif
	};
#endif
	void Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateALS_SetBit(void* Obj)
	{
		((UAnimationMetadataSettings*)Obj)->bCreateALS = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateALS = { "bCreateALS", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAnimationMetadataSettings), &Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateALS_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateALS_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateALS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Output Settings|ALSv4" },
		{ "DisplayName", "Walk Speed (ALSv4)" },
		{ "EditCondition", "bCreateALS" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What should our maximum 'walk' speed be?" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimationMetadataSettings, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_WalkSpeed_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_WalkSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_RunSpeed_MetaData[] = {
		{ "Category", "Output Settings|ALSv4" },
		{ "DisplayName", "Run Speed (ALSv4)" },
		{ "EditCondition", "bCreateALS" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What should our maximum 'run' speed be?" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_RunSpeed = { "RunSpeed", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimationMetadataSettings, RunSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_RunSpeed_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_RunSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Output Settings|ALSv4" },
		{ "DisplayName", "Sprint Speed (ALSv4)" },
		{ "EditCondition", "bCreateALS" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What should our maximum 'sprint' speed be?" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimationMetadataSettings, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SprintSpeed_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SprintSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeleton_MetaData[] = {
		{ "Category", "Additional Bones" },
		{ "DisplayName", "Reference Skeleton" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What skeleton should we use as a reference to find bones?" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeleton = { "ReferenceSkeleton", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimationMetadataSettings, ReferenceSkeleton), Z_Construct_UClass_USkeleton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeleton_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeleton_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeletonPath_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Path for the reference skeleton. This is used to persist settings to disk, since we can't save the skeleton itself. */" },
#endif
		{ "EditCondition", "false" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Path for the reference skeleton. This is used to persist settings to disk, since we can't save the skeleton itself." },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeletonPath = { "ReferenceSkeletonPath", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimationMetadataSettings, ReferenceSkeletonPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeletonPath_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeletonPath_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ExtraBones_Inner = { "ExtraBones", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAnimationBoneCurveTask, METADATA_PARAMS(0, nullptr) }; // 1553286052
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ExtraBones_MetaData[] = {
		{ "Category", "Additional Bones" },
		{ "DisplayName", "Bone Curve Tasks" },
		{ "EditCondition", "ReferenceSkeleton != nullptr" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetadataSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What additional bone data should we record?" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ExtraBones = { "ExtraBones", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimationMetadataSettings, ExtraBones), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ExtraBones_MetaData), Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ExtraBones_MetaData) }; // 1553286052
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAnimationMetadataSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SourceMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SourceMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_FileMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_FileMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bConvertTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bEraseCurves,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bForceRootMotion,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeVertical,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bIncludeAllRotations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateAlphaTracks,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDeltaTracks,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateDistanceTrack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_bCreateALS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_WalkSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_RunSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_SprintSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeleton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ReferenceSkeletonPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ExtraBones_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimationMetadataSettings_Statics::NewProp_ExtraBones,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UBoneReferenceSkeletonProvider_NoRegister, (int32)VTABLE_OFFSET(UAnimationMetadataSettings, IBoneReferenceSkeletonProvider), false },  // 307433809
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimationMetadataSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimationMetadataSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimationMetadataSettings_Statics::ClassParams = {
		&UAnimationMetadataSettings::StaticClass,
		"Rooitools",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAnimationMetadataSettings_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x000000A6u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UAnimationMetadataSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimationMetadataSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UAnimationMetadataSettings()
	{
		if (!Z_Registration_Info_UClass_UAnimationMetadataSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimationMetadataSettings.OuterSingleton, Z_Construct_UClass_UAnimationMetadataSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAnimationMetadataSettings.OuterSingleton;
	}
	template<> ROOITOOLS_API UClass* StaticClass<UAnimationMetadataSettings>()
	{
		return UAnimationMetadataSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimationMetadataSettings);
	UAnimationMetadataSettings::~UAnimationMetadataSettings() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetadataSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetadataSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAnimationMetadataSettings, UAnimationMetadataSettings::StaticClass, TEXT("UAnimationMetadataSettings"), &Z_Registration_Info_UClass_UAnimationMetadataSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimationMetadataSettings), 4075244055U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetadataSettings_h_766430147(TEXT("/Script/Rooitools"),
		Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetadataSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetadataSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
