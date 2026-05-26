// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TBG_Player.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
#ifdef TBG_TBG_Player_generated_h
#error "TBG_Player.generated.h already included, missing '#pragma once' in TBG_Player.h"
#endif
#define TBG_TBG_Player_generated_h

#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAttackEnd);


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATBG_Player(); \
	friend struct Z_Construct_UClass_ATBG_Player_Statics; \
public: \
	DECLARE_CLASS(ATBG_Player, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TBG"), NO_API) \
	DECLARE_SERIALIZER(ATBG_Player)


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATBG_Player(ATBG_Player&&); \
	ATBG_Player(const ATBG_Player&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATBG_Player); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATBG_Player); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATBG_Player) \
	NO_API virtual ~ATBG_Player();


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_16_PROLOG
#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TBG_API UClass* StaticClass<class ATBG_Player>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
