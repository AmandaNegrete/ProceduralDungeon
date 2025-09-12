// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProcDungeonGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeProcDungeonGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonGameMode();
PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProcDungeon();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AProcDungeonGameMode *****************************************************
void AProcDungeonGameMode::StaticRegisterNativesAProcDungeonGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AProcDungeonGameMode;
UClass* AProcDungeonGameMode::GetPrivateStaticClass()
{
	using TClass = AProcDungeonGameMode;
	if (!Z_Registration_Info_UClass_AProcDungeonGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ProcDungeonGameMode"),
			Z_Registration_Info_UClass_AProcDungeonGameMode.InnerSingleton,
			StaticRegisterNativesAProcDungeonGameMode,
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
	return Z_Registration_Info_UClass_AProcDungeonGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AProcDungeonGameMode_NoRegister()
{
	return AProcDungeonGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AProcDungeonGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ProcDungeonGameMode.h" },
		{ "ModuleRelativePath", "ProcDungeonGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProcDungeonGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AProcDungeonGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ProcDungeon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProcDungeonGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AProcDungeonGameMode_Statics::ClassParams = {
	&AProcDungeonGameMode::StaticClass,
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
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProcDungeonGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AProcDungeonGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AProcDungeonGameMode()
{
	if (!Z_Registration_Info_UClass_AProcDungeonGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AProcDungeonGameMode.OuterSingleton, Z_Construct_UClass_AProcDungeonGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AProcDungeonGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AProcDungeonGameMode);
AProcDungeonGameMode::~AProcDungeonGameMode() {}
// ********** End Class AProcDungeonGameMode *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h__Script_ProcDungeon_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AProcDungeonGameMode, AProcDungeonGameMode::StaticClass, TEXT("AProcDungeonGameMode"), &Z_Registration_Info_UClass_AProcDungeonGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AProcDungeonGameMode), 1437989147U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h__Script_ProcDungeon_11382326(TEXT("/Script/ProcDungeon"),
	Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h__Script_ProcDungeon_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h__Script_ProcDungeon_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
