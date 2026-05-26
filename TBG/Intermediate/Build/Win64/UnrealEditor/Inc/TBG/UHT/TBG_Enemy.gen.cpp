// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TBG/TBG_Enemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTBG_Enemy() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
TBG_API UClass* Z_Construct_UClass_ATBG_Enemy();
TBG_API UClass* Z_Construct_UClass_ATBG_Enemy_NoRegister();
UPackage* Z_Construct_UPackage__Script_TBG();
// End Cross Module References

// Begin Class ATBG_Enemy
void ATBG_Enemy::StaticRegisterNativesATBG_Enemy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATBG_Enemy);
UClass* Z_Construct_UClass_ATBG_Enemy_NoRegister()
{
	return ATBG_Enemy::StaticClass();
}
struct Z_Construct_UClass_ATBG_Enemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TBG_Enemy.h" },
		{ "ModuleRelativePath", "TBG_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyInfos_MetaData[] = {
		{ "Category", "EnemyInfos" },
		{ "ModuleRelativePath", "TBG_Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_EnemyInfos_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_EnemyInfos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATBG_Enemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATBG_Enemy_Statics::NewProp_EnemyInfos_Inner = { "EnemyInfos", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_ATBG_Enemy_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATBG_Enemy_Statics::NewProp_EnemyInfos = { "EnemyInfos", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATBG_Enemy, EnemyInfos), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyInfos_MetaData), NewProp_EnemyInfos_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATBG_Enemy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_Enemy_Statics::NewProp_EnemyInfos_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATBG_Enemy_Statics::NewProp_EnemyInfos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_Enemy_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATBG_Enemy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_TBG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_Enemy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATBG_Enemy_Statics::ClassParams = {
	&ATBG_Enemy::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATBG_Enemy_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_Enemy_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_Enemy_Statics::Class_MetaDataParams), Z_Construct_UClass_ATBG_Enemy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATBG_Enemy()
{
	if (!Z_Registration_Info_UClass_ATBG_Enemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATBG_Enemy.OuterSingleton, Z_Construct_UClass_ATBG_Enemy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATBG_Enemy.OuterSingleton;
}
template<> TBG_API UClass* StaticClass<ATBG_Enemy>()
{
	return ATBG_Enemy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATBG_Enemy);
ATBG_Enemy::~ATBG_Enemy() {}
// End Class ATBG_Enemy

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATBG_Enemy, ATBG_Enemy::StaticClass, TEXT("ATBG_Enemy"), &Z_Registration_Info_UClass_ATBG_Enemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATBG_Enemy), 197450994U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_704454029(TEXT("/Script/TBG"),
	Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_TBG_Enemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
