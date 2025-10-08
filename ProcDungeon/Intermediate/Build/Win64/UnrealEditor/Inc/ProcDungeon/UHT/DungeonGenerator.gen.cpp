// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DungeonGenerator.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDungeonGenerator() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
PROCDUNGEON_API UClass* Z_Construct_UClass_ADungeonGenerator();
PROCDUNGEON_API UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProcDungeon();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ADungeonGenerator ********************************************************
void ADungeonGenerator::StaticRegisterNativesADungeonGenerator()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADungeonGenerator;
UClass* ADungeonGenerator::GetPrivateStaticClass()
{
	using TClass = ADungeonGenerator;
	if (!Z_Registration_Info_UClass_ADungeonGenerator.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DungeonGenerator"),
			Z_Registration_Info_UClass_ADungeonGenerator.InnerSingleton,
			StaticRegisterNativesADungeonGenerator,
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
	return Z_Registration_Info_UClass_ADungeonGenerator.InnerSingleton;
}
UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister()
{
	return ADungeonGenerator::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ADungeonGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DungeonGenerator.h" },
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[] = {
		{ "Category", "DungeonGenerator" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADungeonGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADungeonGenerator_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonGenerator, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComponent_MetaData), NewProp_MeshComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonGenerator_Statics::NewProp_MeshComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADungeonGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ProcDungeon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADungeonGenerator_Statics::ClassParams = {
	&ADungeonGenerator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_ADungeonGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADungeonGenerator()
{
	if (!Z_Registration_Info_UClass_ADungeonGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADungeonGenerator.OuterSingleton, Z_Construct_UClass_ADungeonGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADungeonGenerator.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADungeonGenerator);
ADungeonGenerator::~ADungeonGenerator() {}
// ********** End Class ADungeonGenerator **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h__Script_ProcDungeon_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADungeonGenerator, ADungeonGenerator::StaticClass, TEXT("ADungeonGenerator"), &Z_Registration_Info_UClass_ADungeonGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADungeonGenerator), 4145995340U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h__Script_ProcDungeon_3614252852(TEXT("/Script/ProcDungeon"),
	Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h__Script_ProcDungeon_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h__Script_ProcDungeon_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
