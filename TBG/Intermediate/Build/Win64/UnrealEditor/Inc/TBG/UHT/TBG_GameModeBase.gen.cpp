// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TBG/System/TBG_GameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTBG_GameModeBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
TBG_API UClass* Z_Construct_UClass_ATBG_GameModeBase();
TBG_API UClass* Z_Construct_UClass_ATBG_GameModeBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_TBG();
// End Cross Module References

// Begin Class ATBG_GameModeBase
void ATBG_GameModeBase::StaticRegisterNativesATBG_GameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATBG_GameModeBase);
UClass* Z_Construct_UClass_ATBG_GameModeBase_NoRegister()
{
	return ATBG_GameModeBase::StaticClass();
}
struct Z_Construct_UClass_ATBG_GameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "System/TBG_GameModeBase.h" },
		{ "ModuleRelativePath", "System/TBG_GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATBG_GameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATBG_GameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_TBG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_GameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATBG_GameModeBase_Statics::ClassParams = {
	&ATBG_GameModeBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATBG_GameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ATBG_GameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATBG_GameModeBase()
{
	if (!Z_Registration_Info_UClass_ATBG_GameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATBG_GameModeBase.OuterSingleton, Z_Construct_UClass_ATBG_GameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATBG_GameModeBase.OuterSingleton;
}
template<> TBG_API UClass* StaticClass<ATBG_GameModeBase>()
{
	return ATBG_GameModeBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATBG_GameModeBase);
ATBG_GameModeBase::~ATBG_GameModeBase() {}
// End Class ATBG_GameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_System_TBG_GameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATBG_GameModeBase, ATBG_GameModeBase::StaticClass, TEXT("ATBG_GameModeBase"), &Z_Registration_Info_UClass_ATBG_GameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATBG_GameModeBase), 700558621U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_System_TBG_GameModeBase_h_3190672125(TEXT("/Script/TBG"),
	Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_System_TBG_GameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Unreal_Turn_Based_Game_TurnBasedGame_TBG_Source_TBG_System_TBG_GameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
