// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Animation/AnimationMetaSupport.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ROOITOOLS_AnimationMetaSupport_generated_h
#error "AnimationMetaSupport.generated.h already included, missing '#pragma once' in AnimationMetaSupport.h"
#endif
#define ROOITOOLS_AnimationMetaSupport_generated_h

#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_SPARSE_DATA
#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_ACCESSORS
#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFloatArray(); \
	friend struct Z_Construct_UClass_UFloatArray_Statics; \
public: \
	DECLARE_CLASS(UFloatArray, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Rooitools"), NO_API) \
	DECLARE_SERIALIZER(UFloatArray)


#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFloatArray(UFloatArray&&); \
	NO_API UFloatArray(const UFloatArray&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFloatArray); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFloatArray); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UFloatArray) \
	NO_API virtual ~UFloatArray();


#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_110_PROLOG
#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_SPARSE_DATA \
	FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_ACCESSORS \
	FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_113_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ROOITOOLS_API UClass* StaticClass<class UFloatArray>();

#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_138_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAnimationBoneTrackData_Statics; \
	ROOITOOLS_API static class UScriptStruct* StaticStruct();


template<> ROOITOOLS_API UScriptStruct* StaticStruct<struct FAnimationBoneTrackData>();

#define FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h_167_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAnimationBoneCurveTask_Statics; \
	ROOITOOLS_API static class UScriptStruct* StaticStruct();


template<> ROOITOOLS_API UScriptStruct* StaticStruct<struct FAnimationBoneCurveTask>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_Fortitude_w_umfpsv2_Plugins_Rooitools_metadata_maker_Source_Rooitools_Private_Animation_AnimationMetaSupport_h


#define FOREACH_ENUM_EMETADATAGENERATORMODE(op) \
	op(EMetadataGeneratorMode::EMGM_Single) \
	op(EMetadataGeneratorMode::EMGM_Batch) 

enum class EMetadataGeneratorMode : int16;
template<> struct TIsUEnumClass<EMetadataGeneratorMode> { enum { Value = true }; };
template<> ROOITOOLS_API UEnum* StaticEnum<EMetadataGeneratorMode>();

#define FOREACH_ENUM_EMETADATAGENERATORFILELOGIC(op) \
	op(EMetadataGeneratorFileLogic::EMGFL_Preserve) \
	op(EMetadataGeneratorFileLogic::EMGFL_Update) \
	op(EMetadataGeneratorFileLogic::EMGFL_Overwrite) 

enum class EMetadataGeneratorFileLogic : int16;
template<> struct TIsUEnumClass<EMetadataGeneratorFileLogic> { enum { Value = true }; };
template<> ROOITOOLS_API UEnum* StaticEnum<EMetadataGeneratorFileLogic>();

#define FOREACH_ENUM_EANIMATIONMETADATATRACKTYPE(op) \
	op(EAnimationMetadataTrackType::ETT_Curve) \
	op(EAnimationMetadataTrackType::ETT_Notification) 

enum class EAnimationMetadataTrackType;
template<> struct TIsUEnumClass<EAnimationMetadataTrackType> { enum { Value = true }; };
template<> ROOITOOLS_API UEnum* StaticEnum<EAnimationMetadataTrackType>();

#define FOREACH_ENUM_EBONECURVEMETADATACATEGORY(op) \
	op(EBoneCurveMetadataCategory::MovementSpeed) \
	op(EBoneCurveMetadataCategory::DistanceMoved) \
	op(EBoneCurveMetadataCategory::Forward) \
	op(EBoneCurveMetadataCategory::Right) \
	op(EBoneCurveMetadataCategory::Up) \
	op(EBoneCurveMetadataCategory::Yaw) \
	op(EBoneCurveMetadataCategory::Pitch) \
	op(EBoneCurveMetadataCategory::Roll) 

enum class EBoneCurveMetadataCategory;
template<> struct TIsUEnumClass<EBoneCurveMetadataCategory> { enum { Value = true }; };
template<> ROOITOOLS_API UEnum* StaticEnum<EBoneCurveMetadataCategory>();

#define FOREACH_ENUM_EBONECURVETRACKTYPE(op) \
	op(EBoneCurveTrackType::EBTT_Normal) \
	op(EBoneCurveTrackType::EBTT_Alpha) \
	op(EBoneCurveTrackType::EBTT_Delta) \
	op(EBoneCurveTrackType::EBTT_BreakRange) \
	op(EBoneCurveTrackType::EBTT_MotionMatch) 

enum class EBoneCurveTrackType;
template<> struct TIsUEnumClass<EBoneCurveTrackType> { enum { Value = true }; };
template<> ROOITOOLS_API UEnum* StaticEnum<EBoneCurveTrackType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
