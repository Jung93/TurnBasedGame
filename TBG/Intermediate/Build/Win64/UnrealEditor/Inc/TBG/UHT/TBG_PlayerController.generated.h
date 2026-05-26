// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Controller/TBG_PlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TBG_TBG_PlayerController_generated_h
#error "TBG_PlayerController.generated.h already included, missing '#pragma once' in TBG_PlayerController.h"
#endif
#define TBG_TBG_PlayerController_generated_h

#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_Controller_TBG_PlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATBG_PlayerController(); \
	friend struct Z_Construct_UClass_ATBG_PlayerController_Statics; \
public: \
	DECLARE_CLASS(ATBG_PlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TBG"), NO_API) \
	DECLARE_SERIALIZER(ATBG_PlayerController)


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_Controller_TBG_PlayerController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATBG_PlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATBG_PlayerController(ATBG_PlayerController&&); \
	ATBG_PlayerController(const ATBG_PlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATBG_PlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATBG_PlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATBG_PlayerController) \
	NO_API virtual ~ATBG_PlayerController();


#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_Controller_TBG_PlayerController_h_12_PROLOG
#define FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_Controller_TBG_PlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_Controller_TBG_PlayerController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_Controller_TBG_PlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TBG_API UClass* StaticClass<class ATBG_PlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_Controller_TBG_PlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
