// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TBG/System/TBG_BattleGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTBG_BattleGameModeBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
TBG_API UClass* Z_Construct_UClass_ATBG_BattleGameModeBase();
TBG_API UClass* Z_Construct_UClass_ATBG_BattleGameModeBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_TBG();
// End Cross Module References

// Begin Class ATBG_BattleGameModeBase
void ATBG_BattleGameModeBase::StaticRegisterNativesATBG_BattleGameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATBG_BattleGameModeBase);
UClass* Z_Construct_UClass_ATBG_BattleGameModeBase_NoRegister()
{
	return ATBG_BattleGameModeBase::StaticClass();
}
struct Z_Construct_UClass_ATBG_BattleGameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "System/TBG_BattleGameModeBase.h" },
		{ "ModuleRelativePath", "System/TBG_BattleGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstMove_MetaData[] = {
		{ "ModuleRelativePath", "System/TBG_BattleGameModeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleOrder_MetaData[] = {
		{ "ModuleRelativePath", "System/TBG_BattleGameModeBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FirstMove_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FirstMove;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BattleOrder_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_BattleOrder;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATBG_BattleGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::NewProp_FirstMove_Inner = { "FirstMove", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::NewProp_FirstMove = { "FirstMove", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATBG_BattleGameModeBase, FirstMove), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstMove_MetaData), NewProp_FirstMove_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::NewProp_BattleOrder_Inner = { "BattleOrder", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::NewProp_BattleOrder = { "BattleOrder", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATBG_BattleGameModeBase, BattleOrder), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleOrder_MetaData), NewProp_BattleOrder_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::NewProp_FirstMove_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::NewProp_FirstMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::NewProp_BattleOrder_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::NewProp_BattleOrder,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_TBG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::ClassParams = {
	&ATBG_BattleGameModeBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATBG_BattleGameModeBase()
{
	if (!Z_Registration_Info_UClass_ATBG_BattleGameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATBG_BattleGameModeBase.OuterSingleton, Z_Construct_UClass_ATBG_BattleGameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATBG_BattleGameModeBase.OuterSingleton;
}
template<> TBG_API UClass* StaticClass<ATBG_BattleGameModeBase>()
{
	return ATBG_BattleGameModeBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATBG_BattleGameModeBase);
ATBG_BattleGameModeBase::~ATBG_BattleGameModeBase() {}
// End Class ATBG_BattleGameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_System_TBG_BattleGameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATBG_BattleGameModeBase, ATBG_BattleGameModeBase::StaticClass, TEXT("ATBG_BattleGameModeBase"), &Z_Registration_Info_UClass_ATBG_BattleGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATBG_BattleGameModeBase), 3651091001U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_System_TBG_BattleGameModeBase_h_1440322990(TEXT("/Script/TBG"),
	Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_System_TBG_BattleGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_System_TBG_BattleGameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
