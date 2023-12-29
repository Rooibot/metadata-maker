// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Rooitools/Private/Animation/AnimationMetaSupport.h"
#include "../../Source/Runtime/Engine/Public/Animation/BoneReference.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimationMetaSupport() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FBoneReference();
	ROOITOOLS_API UClass* Z_Construct_UClass_UFloatArray();
	ROOITOOLS_API UClass* Z_Construct_UClass_UFloatArray_NoRegister();
	ROOITOOLS_API UEnum* Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType();
	ROOITOOLS_API UEnum* Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory();
	ROOITOOLS_API UEnum* Z_Construct_UEnum_Rooitools_EBoneCurveTrackType();
	ROOITOOLS_API UEnum* Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic();
	ROOITOOLS_API UEnum* Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode();
	ROOITOOLS_API UScriptStruct* Z_Construct_UScriptStruct_FAnimationBoneCurveTask();
	ROOITOOLS_API UScriptStruct* Z_Construct_UScriptStruct_FAnimationBoneTrackData();
	UPackage* Z_Construct_UPackage__Script_Rooitools();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMetadataGeneratorMode;
	static UEnum* EMetadataGeneratorMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EMetadataGeneratorMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EMetadataGeneratorMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode, (UObject*)Z_Construct_UPackage__Script_Rooitools(), TEXT("EMetadataGeneratorMode"));
		}
		return Z_Registration_Info_UEnum_EMetadataGeneratorMode.OuterSingleton;
	}
	template<> ROOITOOLS_API UEnum* StaticEnum<EMetadataGeneratorMode>()
	{
		return EMetadataGeneratorMode_StaticEnum();
	}
	struct Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics::Enumerators[] = {
		{ "EMetadataGeneratorMode::EMGM_Single", (int64)EMetadataGeneratorMode::EMGM_Single },
		{ "EMetadataGeneratorMode::EMGM_Batch", (int64)EMetadataGeneratorMode::EMGM_Batch },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics::Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** An enumerator describing the possible source-picker modes for the metadata generator. */" },
#endif
		{ "EMGM_Batch.DisplayName", "Batch Source Mode" },
		{ "EMGM_Batch.Name", "EMetadataGeneratorMode::EMGM_Batch" },
		{ "EMGM_Single.DisplayName", "Single Asset Mode" },
		{ "EMGM_Single.Name", "EMetadataGeneratorMode::EMGM_Single" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "An enumerator describing the possible source-picker modes for the metadata generator." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Rooitools,
		nullptr,
		"EMetadataGeneratorMode",
		"EMetadataGeneratorMode",
		Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode()
	{
		if (!Z_Registration_Info_UEnum_EMetadataGeneratorMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMetadataGeneratorMode.InnerSingleton, Z_Construct_UEnum_Rooitools_EMetadataGeneratorMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EMetadataGeneratorMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMetadataGeneratorFileLogic;
	static UEnum* EMetadataGeneratorFileLogic_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EMetadataGeneratorFileLogic.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EMetadataGeneratorFileLogic.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic, (UObject*)Z_Construct_UPackage__Script_Rooitools(), TEXT("EMetadataGeneratorFileLogic"));
		}
		return Z_Registration_Info_UEnum_EMetadataGeneratorFileLogic.OuterSingleton;
	}
	template<> ROOITOOLS_API UEnum* StaticEnum<EMetadataGeneratorFileLogic>()
	{
		return EMetadataGeneratorFileLogic_StaticEnum();
	}
	struct Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics::Enumerators[] = {
		{ "EMetadataGeneratorFileLogic::EMGFL_Preserve", (int64)EMetadataGeneratorFileLogic::EMGFL_Preserve },
		{ "EMetadataGeneratorFileLogic::EMGFL_Update", (int64)EMetadataGeneratorFileLogic::EMGFL_Update },
		{ "EMetadataGeneratorFileLogic::EMGFL_Overwrite", (int64)EMetadataGeneratorFileLogic::EMGFL_Overwrite },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics::Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** An enumerator describing the possible behaviors when encountering existing files. */" },
#endif
		{ "EMGFL_Overwrite.DisplayName", "Overwrite any existing files entirely." },
		{ "EMGFL_Overwrite.Name", "EMetadataGeneratorFileLogic::EMGFL_Overwrite" },
		{ "EMGFL_Preserve.DisplayName", "Do not overwrite or alter existing files." },
		{ "EMGFL_Preserve.Name", "EMetadataGeneratorFileLogic::EMGFL_Preserve" },
		{ "EMGFL_Update.DisplayName", "Update any existing files with new metadata." },
		{ "EMGFL_Update.Name", "EMetadataGeneratorFileLogic::EMGFL_Update" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "An enumerator describing the possible behaviors when encountering existing files." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Rooitools,
		nullptr,
		"EMetadataGeneratorFileLogic",
		"EMetadataGeneratorFileLogic",
		Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic()
	{
		if (!Z_Registration_Info_UEnum_EMetadataGeneratorFileLogic.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMetadataGeneratorFileLogic.InnerSingleton, Z_Construct_UEnum_Rooitools_EMetadataGeneratorFileLogic_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EMetadataGeneratorFileLogic.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAnimationMetadataTrackType;
	static UEnum* EAnimationMetadataTrackType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EAnimationMetadataTrackType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EAnimationMetadataTrackType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType, (UObject*)Z_Construct_UPackage__Script_Rooitools(), TEXT("EAnimationMetadataTrackType"));
		}
		return Z_Registration_Info_UEnum_EAnimationMetadataTrackType.OuterSingleton;
	}
	template<> ROOITOOLS_API UEnum* StaticEnum<EAnimationMetadataTrackType>()
	{
		return EAnimationMetadataTrackType_StaticEnum();
	}
	struct Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics::Enumerators[] = {
		{ "EAnimationMetadataTrackType::ETT_Curve", (int64)EAnimationMetadataTrackType::ETT_Curve },
		{ "EAnimationMetadataTrackType::ETT_Notification", (int64)EAnimationMetadataTrackType::ETT_Notification },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics::Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** An enumerator describing the possible types of animation metadata tracks. */" },
#endif
		{ "ETT_Curve.Name", "EAnimationMetadataTrackType::ETT_Curve" },
		{ "ETT_Notification.Name", "EAnimationMetadataTrackType::ETT_Notification" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "An enumerator describing the possible types of animation metadata tracks." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Rooitools,
		nullptr,
		"EAnimationMetadataTrackType",
		"EAnimationMetadataTrackType",
		Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType()
	{
		if (!Z_Registration_Info_UEnum_EAnimationMetadataTrackType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAnimationMetadataTrackType.InnerSingleton, Z_Construct_UEnum_Rooitools_EAnimationMetadataTrackType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EAnimationMetadataTrackType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBoneCurveMetadataCategory;
	static UEnum* EBoneCurveMetadataCategory_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EBoneCurveMetadataCategory.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EBoneCurveMetadataCategory.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory, (UObject*)Z_Construct_UPackage__Script_Rooitools(), TEXT("EBoneCurveMetadataCategory"));
		}
		return Z_Registration_Info_UEnum_EBoneCurveMetadataCategory.OuterSingleton;
	}
	template<> ROOITOOLS_API UEnum* StaticEnum<EBoneCurveMetadataCategory>()
	{
		return EBoneCurveMetadataCategory_StaticEnum();
	}
	struct Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics::Enumerators[] = {
		{ "EBoneCurveMetadataCategory::MovementSpeed", (int64)EBoneCurveMetadataCategory::MovementSpeed },
		{ "EBoneCurveMetadataCategory::DistanceMoved", (int64)EBoneCurveMetadataCategory::DistanceMoved },
		{ "EBoneCurveMetadataCategory::Forward", (int64)EBoneCurveMetadataCategory::Forward },
		{ "EBoneCurveMetadataCategory::Right", (int64)EBoneCurveMetadataCategory::Right },
		{ "EBoneCurveMetadataCategory::Up", (int64)EBoneCurveMetadataCategory::Up },
		{ "EBoneCurveMetadataCategory::Yaw", (int64)EBoneCurveMetadataCategory::Yaw },
		{ "EBoneCurveMetadataCategory::Pitch", (int64)EBoneCurveMetadataCategory::Pitch },
		{ "EBoneCurveMetadataCategory::Roll", (int64)EBoneCurveMetadataCategory::Roll },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics::Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** An enumerator describing what sort of metadata a given ETT_Curve track might contain. */" },
#endif
		{ "DistanceMoved.Name", "EBoneCurveMetadataCategory::DistanceMoved" },
		{ "Forward.Name", "EBoneCurveMetadataCategory::Forward" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
		{ "MovementSpeed.Comment", "// These are named without the standard enum prefixes because we use the value names to generate the track names.\n" },
		{ "MovementSpeed.Name", "EBoneCurveMetadataCategory::MovementSpeed" },
		{ "MovementSpeed.ToolTip", "These are named without the standard enum prefixes because we use the value names to generate the track names." },
		{ "Pitch.Name", "EBoneCurveMetadataCategory::Pitch" },
		{ "Right.Name", "EBoneCurveMetadataCategory::Right" },
		{ "Roll.Name", "EBoneCurveMetadataCategory::Roll" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "An enumerator describing what sort of metadata a given ETT_Curve track might contain." },
#endif
		{ "Up.Name", "EBoneCurveMetadataCategory::Up" },
		{ "Yaw.Name", "EBoneCurveMetadataCategory::Yaw" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Rooitools,
		nullptr,
		"EBoneCurveMetadataCategory",
		"EBoneCurveMetadataCategory",
		Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory()
	{
		if (!Z_Registration_Info_UEnum_EBoneCurveMetadataCategory.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBoneCurveMetadataCategory.InnerSingleton, Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EBoneCurveMetadataCategory.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBoneCurveTrackType;
	static UEnum* EBoneCurveTrackType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EBoneCurveTrackType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EBoneCurveTrackType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Rooitools_EBoneCurveTrackType, (UObject*)Z_Construct_UPackage__Script_Rooitools(), TEXT("EBoneCurveTrackType"));
		}
		return Z_Registration_Info_UEnum_EBoneCurveTrackType.OuterSingleton;
	}
	template<> ROOITOOLS_API UEnum* StaticEnum<EBoneCurveTrackType>()
	{
		return EBoneCurveTrackType_StaticEnum();
	}
	struct Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics::Enumerators[] = {
		{ "EBoneCurveTrackType::EBTT_Normal", (int64)EBoneCurveTrackType::EBTT_Normal },
		{ "EBoneCurveTrackType::EBTT_Alpha", (int64)EBoneCurveTrackType::EBTT_Alpha },
		{ "EBoneCurveTrackType::EBTT_Delta", (int64)EBoneCurveTrackType::EBTT_Delta },
		{ "EBoneCurveTrackType::EBTT_BreakRange", (int64)EBoneCurveTrackType::EBTT_BreakRange },
		{ "EBoneCurveTrackType::EBTT_MotionMatch", (int64)EBoneCurveTrackType::EBTT_MotionMatch },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics::Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * An enumerator describing what type of track this is. EBTT_Normal just tracks the cumulative value,\n * EBTT_Alpha tracks the value as a percentage of the range, EBTT_Delta tracks the change since the\n * previous frame. EBTT_BreakRange will take an array of values and separate the track into a set of\n * integer values matching which range the current value falls into (i.e., ALSv4 Gait tracks).\n */" },
#endif
		{ "EBTT_Alpha.Name", "EBoneCurveTrackType::EBTT_Alpha" },
		{ "EBTT_BreakRange.Name", "EBoneCurveTrackType::EBTT_BreakRange" },
		{ "EBTT_Delta.Name", "EBoneCurveTrackType::EBTT_Delta" },
		{ "EBTT_MotionMatch.Name", "EBoneCurveTrackType::EBTT_MotionMatch" },
		{ "EBTT_Normal.Name", "EBoneCurveTrackType::EBTT_Normal" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "An enumerator describing what type of track this is. EBTT_Normal just tracks the cumulative value,\nEBTT_Alpha tracks the value as a percentage of the range, EBTT_Delta tracks the change since the\nprevious frame. EBTT_BreakRange will take an array of values and separate the track into a set of\ninteger values matching which range the current value falls into (i.e., ALSv4 Gait tracks)." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Rooitools,
		nullptr,
		"EBoneCurveTrackType",
		"EBoneCurveTrackType",
		Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Rooitools_EBoneCurveTrackType()
	{
		if (!Z_Registration_Info_UEnum_EBoneCurveTrackType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBoneCurveTrackType.InnerSingleton, Z_Construct_UEnum_Rooitools_EBoneCurveTrackType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EBoneCurveTrackType.InnerSingleton;
	}
	void UFloatArray::StaticRegisterNativesUFloatArray()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFloatArray);
	UClass* Z_Construct_UClass_UFloatArray_NoRegister()
	{
		return UFloatArray::StaticClass();
	}
	struct Z_Construct_UClass_UFloatArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Array_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Array_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Array;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFloatArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Rooitools,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatArray_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFloatArray_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A simple wrapper class to allow float arrays to be included in a TMap. */" },
#endif
		{ "IncludePath", "Animation/AnimationMetaSupport.h" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple wrapper class to allow float arrays to be included in a TMap." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UFloatArray_Statics::NewProp_Array_Inner = { "Array", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFloatArray_Statics::NewProp_Array_MetaData[] = {
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFloatArray_Statics::NewProp_Array = { "Array", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFloatArray, Array), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatArray_Statics::NewProp_Array_MetaData), Z_Construct_UClass_UFloatArray_Statics::NewProp_Array_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFloatArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFloatArray_Statics::NewProp_Array_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFloatArray_Statics::NewProp_Array,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFloatArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFloatArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFloatArray_Statics::ClassParams = {
		&UFloatArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFloatArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFloatArray_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UFloatArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UFloatArray()
	{
		if (!Z_Registration_Info_UClass_UFloatArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFloatArray.OuterSingleton, Z_Construct_UClass_UFloatArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFloatArray.OuterSingleton;
	}
	template<> ROOITOOLS_API UClass* StaticClass<UFloatArray>()
	{
		return UFloatArray::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFloatArray);
	UFloatArray::~UFloatArray() {}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimationBoneTrackData;
class UScriptStruct* FAnimationBoneTrackData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimationBoneTrackData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimationBoneTrackData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimationBoneTrackData, (UObject*)Z_Construct_UPackage__Script_Rooitools(), TEXT("AnimationBoneTrackData"));
	}
	return Z_Registration_Info_UScriptStruct_AnimationBoneTrackData.OuterSingleton;
}
template<> ROOITOOLS_API UScriptStruct* StaticStruct<FAnimationBoneTrackData>()
{
	return FAnimationBoneTrackData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimationBoneTrackData>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Rooitools,
		nullptr,
		&NewStructOps,
		"AnimationBoneTrackData",
		nullptr,
		0,
		sizeof(FAnimationBoneTrackData),
		alignof(FAnimationBoneTrackData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAnimationBoneTrackData()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimationBoneTrackData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimationBoneTrackData.InnerSingleton, Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimationBoneTrackData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimationBoneCurveTask;
class UScriptStruct* FAnimationBoneCurveTask::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimationBoneCurveTask.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimationBoneCurveTask.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimationBoneCurveTask, (UObject*)Z_Construct_UPackage__Script_Rooitools(), TEXT("AnimationBoneCurveTask"));
	}
	return Z_Registration_Info_UScriptStruct_AnimationBoneCurveTask.OuterSingleton;
}
template<> ROOITOOLS_API UScriptStruct* StaticStruct<FAnimationBoneCurveTask>()
{
	return FAnimationBoneCurveTask::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCopyFromOther_MetaData[];
#endif
		static void NewProp_bCopyFromOther_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCopyFromOther;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SourceBone_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SourceBone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateForward_MetaData[];
#endif
		static void NewProp_bCreateForward_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateForward;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateRight_MetaData[];
#endif
		static void NewProp_bCreateRight_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateRight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateUp_MetaData[];
#endif
		static void NewProp_bCreateUp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateYaw_MetaData[];
#endif
		static void NewProp_bCreateYaw_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateYaw;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreatePitch_MetaData[];
#endif
		static void NewProp_bCreatePitch_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreatePitch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateRoll_MetaData[];
#endif
		static void NewProp_bCreateRoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateRoll;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateAlpha_MetaData[];
#endif
		static void NewProp_bCreateAlpha_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateAlpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateDelta_MetaData[];
#endif
		static void NewProp_bCreateDelta_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateDelta;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateDistance_MetaData[];
#endif
		static void NewProp_bCreateDistance_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateBreakPoints_MetaData[];
#endif
		static void NewProp_bCreateBreakPoints_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateBreakPoints;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BreakPoints_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_BreakPoints_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BreakPoints_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BreakPoints_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_BreakPoints;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A structure which describes the desired curve-generating operations for a given bone. */" },
#endif
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A structure which describes the desired curve-generating operations for a given bone." },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimationBoneCurveTask>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_Bone_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_Bone = { "Bone", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationBoneCurveTask, Bone), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_Bone_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_Bone_MetaData) }; // 1286936164
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCopyFromOther_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Overwrite from Bone" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we overwrite with values from another bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCopyFromOther_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCopyFromOther = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCopyFromOther = { "bCopyFromOther", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCopyFromOther_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCopyFromOther_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCopyFromOther_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_SourceBone_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Source Bone" },
		{ "EditCondition", "bCopyFromOther" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The bone to overwrite this with." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_SourceBone = { "SourceBone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationBoneCurveTask, SourceBone), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_SourceBone_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_SourceBone_MetaData) }; // 1286936164
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateForward_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Forward" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create a forward track for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateForward_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateForward = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateForward = { "bCreateForward", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateForward_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateForward_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateForward_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRight_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Right" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create a right track for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRight_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateRight = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRight = { "bCreateRight", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRight_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateUp_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Up" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create an up track for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateUp_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateUp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateUp = { "bCreateUp", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateUp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateUp_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateUp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateYaw_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Yaw" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create a yaw track for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateYaw_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateYaw = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateYaw = { "bCreateYaw", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateYaw_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateYaw_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateYaw_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreatePitch_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Pitch" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create a pitch track for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreatePitch_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreatePitch = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreatePitch = { "bCreatePitch", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreatePitch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreatePitch_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreatePitch_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRoll_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Roll" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create a roll track for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRoll_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateRoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRoll = { "bCreateRoll", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRoll_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRoll_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRoll_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateAlpha_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Alpha Track" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create alpha tracks for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateAlpha_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateAlpha = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateAlpha = { "bCreateAlpha", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateAlpha_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateAlpha_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateAlpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDelta_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Delta Track" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create delta tracks for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDelta_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateDelta = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDelta = { "bCreateDelta", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDelta_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDelta_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDelta_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDistance_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Distance Match" },
		{ "EditCondition", "false" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create a distance matching track for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDistance_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateDistance = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDistance = { "bCreateDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDistance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDistance_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateBreakPoints_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "BreakPoints Track" },
		{ "EditCondition", "false" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we create breakpoints track for this bone?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateBreakPoints_SetBit(void* Obj)
	{
		((FAnimationBoneCurveTask*)Obj)->bCreateBreakPoints = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateBreakPoints = { "bCreateBreakPoints", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimationBoneCurveTask), &Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateBreakPoints_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateBreakPoints_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateBreakPoints_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_ValueProp = { "BreakPoints", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UFloatArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_Key_KeyProp = { "BreakPoints_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_Rooitools_EBoneCurveMetadataCategory, METADATA_PARAMS(0, nullptr) }; // 3294465992
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_MetaData[] = {
		{ "Category", "AnimationBoneCurveTask" },
		{ "DisplayName", "Breaking Points" },
		{ "EditCondition", "bCreateBreakPoints" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Private/Animation/AnimationMetaSupport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What are our breakpoints?" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints = { "BreakPoints", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimationBoneCurveTask, BreakPoints), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_MetaData), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_MetaData) }; // 3294465992
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_Bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCopyFromOther,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_SourceBone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateForward,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateYaw,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreatePitch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateRoll,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateAlpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDelta,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_bCreateBreakPoints,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewProp_BreakPoints,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Rooitools,
		nullptr,
		&NewStructOps,
		"AnimationBoneCurveTask",
		Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::PropPointers),
		sizeof(FAnimationBoneCurveTask),
		alignof(FAnimationBoneCurveTask),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimationBoneCurveTask()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimationBoneCurveTask.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimationBoneCurveTask.InnerSingleton, Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimationBoneCurveTask.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::EnumInfo[] = {
		{ EMetadataGeneratorMode_StaticEnum, TEXT("EMetadataGeneratorMode"), &Z_Registration_Info_UEnum_EMetadataGeneratorMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3892284193U) },
		{ EMetadataGeneratorFileLogic_StaticEnum, TEXT("EMetadataGeneratorFileLogic"), &Z_Registration_Info_UEnum_EMetadataGeneratorFileLogic, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2574074453U) },
		{ EAnimationMetadataTrackType_StaticEnum, TEXT("EAnimationMetadataTrackType"), &Z_Registration_Info_UEnum_EAnimationMetadataTrackType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3591145827U) },
		{ EBoneCurveMetadataCategory_StaticEnum, TEXT("EBoneCurveMetadataCategory"), &Z_Registration_Info_UEnum_EBoneCurveMetadataCategory, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3294465992U) },
		{ EBoneCurveTrackType_StaticEnum, TEXT("EBoneCurveTrackType"), &Z_Registration_Info_UEnum_EBoneCurveTrackType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3954791363U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::ScriptStructInfo[] = {
		{ FAnimationBoneTrackData::StaticStruct, Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics::NewStructOps, TEXT("AnimationBoneTrackData"), &Z_Registration_Info_UScriptStruct_AnimationBoneTrackData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimationBoneTrackData), 2294970473U) },
		{ FAnimationBoneCurveTask::StaticStruct, Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics::NewStructOps, TEXT("AnimationBoneCurveTask"), &Z_Registration_Info_UScriptStruct_AnimationBoneCurveTask, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimationBoneCurveTask), 1553286052U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFloatArray, UFloatArray::StaticClass, TEXT("UFloatArray"), &Z_Registration_Info_UClass_UFloatArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFloatArray), 2675288504U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_2743035133(TEXT("/Script/Rooitools"),
		Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
