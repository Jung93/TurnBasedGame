// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TBG/TBG_Player.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTBG_Player() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
TBG_API UClass* Z_Construct_UClass_ATBG_Player();
TBG_API UClass* Z_Construct_UClass_ATBG_Player_NoRegister();
TBG_API UClass* Z_Construct_UClass_UTBG_AnimInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_TBG();
// End Cross Module References

// Begin Class ATBG_Player Function AttackEnd
struct Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics
{
	struct TBG_Player_eventAttackEnd_Parms
	{
		UAnimMontage* Montage;
		bool bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TBG_Player.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static void NewProp_bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TBG_Player_eventAttackEnd_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::NewProp_bInterrupted_SetBit(void* Obj)
{
	((TBG_Player_eventAttackEnd_Parms*)Obj)->bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::NewProp_bInterrupted = { "bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TBG_Player_eventAttackEnd_Parms), &Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::NewProp_bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATBG_Player, nullptr, "AttackEnd", nullptr, nullptr, Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::TBG_Player_eventAttackEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::TBG_Player_eventAttackEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATBG_Player_AttackEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATBG_Player_AttackEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATBG_Player::execAttackEnd)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_UBOOL(Z_Param_bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttackEnd(Z_Param_Montage,Z_Param_bInterrupted);
	P_NATIVE_END;
}
// End Class ATBG_Player Function AttackEnd

// Begin Class ATBG_Player
void ATBG_Player::StaticRegisterNativesATBG_Player()
{
	UClass* Class = ATBG_Player::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AttackEnd", &ATBG_Player::execAttackEnd },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATBG_Player);
UClass* Z_Construct_UClass_ATBG_Player_NoRegister()
{
	return ATBG_Player::StaticClass();
}
struct Z_Construct_UClass_ATBG_Player_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TBG_Player.h" },
		{ "ModuleRelativePath", "TBG_Player.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TBG_Player.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TBG_Player.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstance_MetaData[] = {
		{ "ModuleRelativePath", "TBG_Player.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsAttack_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "TBG_Player.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleLevelName_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Battle" },
		{ "ModuleRelativePath", "TBG_Player.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimInstance;
	static void NewProp_IsAttack_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsAttack;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_BattleLevelName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATBG_Player_AttackEnd, "AttackEnd" }, // 3519399105
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATBG_Player>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATBG_Player_Statics::NewProp_CameraArm = { "CameraArm", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATBG_Player, CameraArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraArm_MetaData), NewProp_CameraArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATBG_Player_Statics::NewProp_PlayerCamera = { "PlayerCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATBG_Player, PlayerCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCamera_MetaData), NewProp_PlayerCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATBG_Player_Statics::NewProp_AnimInstance = { "AnimInstance", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATBG_Player, AnimInstance), Z_Construct_UClass_UTBG_AnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimInstance_MetaData), NewProp_AnimInstance_MetaData) };
void Z_Construct_UClass_ATBG_Player_Statics::NewProp_IsAttack_SetBit(void* Obj)
{
	((ATBG_Player*)Obj)->IsAttack = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATBG_Player_Statics::NewProp_IsAttack = { "IsAttack", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATBG_Player), &Z_Construct_UClass_ATBG_Player_Statics::NewProp_IsAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsAttack_MetaData), NewProp_IsAttack_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_ATBG_Player_Statics::NewProp_BattleLevelName = { "BattleLevelName", nullptr, (EPropertyFlags)0x0044000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATBG_Player, BattleLevelName), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleLevelName_MetaData), NewProp_BattleLevelName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATBG_Player_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_Player_Statics::NewProp_CameraArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_Player_Statics::NewProp_PlayerCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_Player_Statics::NewProp_AnimInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_Player_Statics::NewProp_IsAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_Player_Statics::NewProp_BattleLevelName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_Player_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATBG_Player_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_TBG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_Player_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATBG_Player_Statics::ClassParams = {
	&ATBG_Player::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ATBG_Player_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_Player_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_Player_Statics::Class_MetaDataParams), Z_Construct_UClass_ATBG_Player_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATBG_Player()
{
	if (!Z_Registration_Info_UClass_ATBG_Player.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATBG_Player.OuterSingleton, Z_Construct_UClass_ATBG_Player_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATBG_Player.OuterSingleton;
}
template<> TBG_API UClass* StaticClass<ATBG_Player>()
{
	return ATBG_Player::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATBG_Player);
ATBG_Player::~ATBG_Player() {}
// End Class ATBG_Player

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATBG_Player, ATBG_Player::StaticClass, TEXT("ATBG_Player"), &Z_Registration_Info_UClass_ATBG_Player, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATBG_Player), 3704464123U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_2712974010(TEXT("/Script/TBG"),
	Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Player_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
