// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TBG_AnimInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TBG_TBG_AnimInstance_generated_h
#error "TBG_AnimInstance.generated.h already included, missing '#pragma once' in TBG_AnimInstance.h"
#endif
#define TBG_TBG_AnimInstance_generated_h

#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAnimNotify_FieldAttack); \
	DECLARE_FUNCTION(execAnimNotify_Dead); \
	DECLARE_FUNCTION(execAnimNotify_Attack_Hit); \
	DECLARE_FUNCTION(execPlayFieldAttackMontage); \
	DECLARE_FUNCTION(execPlayAttackMontage);


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTBG_AnimInstance(); \
	friend struct Z_Construct_UClass_UTBG_AnimInstance_Statics; \
public: \
	DECLARE_CLASS(UTBG_AnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TBG"), NO_API) \
	DECLARE_SERIALIZER(UTBG_AnimInstance)


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UTBG_AnimInstance(UTBG_AnimInstance&&); \
	UTBG_AnimInstance(const UTBG_AnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTBG_AnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTBG_AnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTBG_AnimInstance) \
	NO_API virtual ~UTBG_AnimInstance();


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h_17_PROLOG
#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h_20_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TBG_API UClass* StaticClass<class UTBG_AnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_AnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
