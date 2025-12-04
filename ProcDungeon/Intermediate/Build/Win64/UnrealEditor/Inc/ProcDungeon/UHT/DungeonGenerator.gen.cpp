// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DungeonGenerator.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDungeonGenerator() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
PROCDUNGEON_API UClass* Z_Construct_UClass_ADungeonGenerator();
PROCDUNGEON_API UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProcDungeon();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ADungeonGenerator Function OverlapExit ***********************************
struct Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics
{
	struct DungeonGenerator_eventOverlapExit_Parms
	{
		UPrimitiveComponent* obj;
		AActor* actor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// from example found in the \n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "from example found in the" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_obj_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_obj;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_obj = { "obj", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventOverlapExit_Parms, obj), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_obj_MetaData), NewProp_obj_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventOverlapExit_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventOverlapExit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventOverlapExit_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((DungeonGenerator_eventOverlapExit_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DungeonGenerator_eventOverlapExit_Parms), &Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventOverlapExit_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 267591329
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_obj,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ADungeonGenerator, nullptr, "OverlapExit", Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::DungeonGenerator_eventOverlapExit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::DungeonGenerator_eventOverlapExit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonGenerator_OverlapExit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonGenerator_OverlapExit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonGenerator::execOverlapExit)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_obj);
	P_GET_OBJECT(AActor,Z_Param_actor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OverlapExit(Z_Param_obj,Z_Param_actor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class ADungeonGenerator Function OverlapExit *************************************

// ********** Begin Class ADungeonGenerator Function RegenerateDungeon *****************************
struct Z_Construct_UFunction_ADungeonGenerator_RegenerateDungeon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon" },
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonGenerator_RegenerateDungeon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ADungeonGenerator, nullptr, "RegenerateDungeon", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_RegenerateDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonGenerator_RegenerateDungeon_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ADungeonGenerator_RegenerateDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonGenerator_RegenerateDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonGenerator::execRegenerateDungeon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegenerateDungeon();
	P_NATIVE_END;
}
// ********** End Class ADungeonGenerator Function RegenerateDungeon *******************************

// ********** Begin Class ADungeonGenerator ********************************************************
void ADungeonGenerator::StaticRegisterNativesADungeonGenerator()
{
	UClass* Class = ADungeonGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OverlapExit", &ADungeonGenerator::execOverlapExit },
		{ "RegenerateDungeon", &ADungeonGenerator::execRegenerateDungeon },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADungeonGenerator_OverlapExit, "OverlapExit" }, // 3919747325
		{ &Z_Construct_UFunction_ADungeonGenerator_RegenerateDungeon, "RegenerateDungeon" }, // 4192954770
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
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
	FuncInfo,
	Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
		{ Z_Construct_UClass_ADungeonGenerator, ADungeonGenerator::StaticClass, TEXT("ADungeonGenerator"), &Z_Registration_Info_UClass_ADungeonGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADungeonGenerator), 2754407353U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h__Script_ProcDungeon_1449617385(TEXT("/Script/ProcDungeon"),
	Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h__Script_ProcDungeon_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h__Script_ProcDungeon_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
