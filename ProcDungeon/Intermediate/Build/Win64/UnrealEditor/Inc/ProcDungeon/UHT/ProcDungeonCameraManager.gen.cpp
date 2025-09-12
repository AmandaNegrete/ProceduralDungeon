// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProcDungeonCameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeProcDungeonCameraManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonCameraManager();
PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonCameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProcDungeon();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AProcDungeonCameraManager ************************************************
void AProcDungeonCameraManager::StaticRegisterNativesAProcDungeonCameraManager()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AProcDungeonCameraManager;
UClass* AProcDungeonCameraManager::GetPrivateStaticClass()
{
	using TClass = AProcDungeonCameraManager;
	if (!Z_Registration_Info_UClass_AProcDungeonCameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ProcDungeonCameraManager"),
			Z_Registration_Info_UClass_AProcDungeonCameraManager.InnerSingleton,
			StaticRegisterNativesAProcDungeonCameraManager,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AProcDungeonCameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AProcDungeonCameraManager_NoRegister()
{
	return AProcDungeonCameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AProcDungeonCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "ProcDungeonCameraManager.h" },
		{ "ModuleRelativePath", "ProcDungeonCameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProcDungeonCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AProcDungeonCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_ProcDungeon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProcDungeonCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AProcDungeonCameraManager_Statics::ClassParams = {
	&AProcDungeonCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProcDungeonCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AProcDungeonCameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AProcDungeonCameraManager()
{
	if (!Z_Registration_Info_UClass_AProcDungeonCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AProcDungeonCameraManager.OuterSingleton, Z_Construct_UClass_AProcDungeonCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AProcDungeonCameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AProcDungeonCameraManager);
AProcDungeonCameraManager::~AProcDungeonCameraManager() {}
// ********** End Class AProcDungeonCameraManager **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h__Script_ProcDungeon_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AProcDungeonCameraManager, AProcDungeonCameraManager::StaticClass, TEXT("AProcDungeonCameraManager"), &Z_Registration_Info_UClass_AProcDungeonCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AProcDungeonCameraManager), 2230134676U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h__Script_ProcDungeon_1239002099(TEXT("/Script/ProcDungeon"),
	Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h__Script_ProcDungeon_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h__Script_ProcDungeon_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
