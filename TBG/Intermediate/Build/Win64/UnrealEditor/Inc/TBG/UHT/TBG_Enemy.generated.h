// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TBG_Enemy.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TBG_TBG_Enemy_generated_h
#error "TBG_Enemy.generated.h already included, missing '#pragma once' in TBG_Enemy.h"
#endif
#define TBG_TBG_Enemy_generated_h

#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATBG_Enemy(); \
	friend struct Z_Construct_UClass_ATBG_Enemy_Statics; \
public: \
	DECLARE_CLASS(ATBG_Enemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TBG"), NO_API) \
	DECLARE_SERIALIZER(ATBG_Enemy)


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATBG_Enemy(ATBG_Enemy&&); \
	ATBG_Enemy(const ATBG_Enemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATBG_Enemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATBG_Enemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATBG_Enemy) \
	NO_API virtual ~ATBG_Enemy();


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_9_PROLOG
#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TBG_API UClass* StaticClass<class ATBG_Enemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
