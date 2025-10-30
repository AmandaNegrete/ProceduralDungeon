// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DungeonGenerator.h"

#ifdef PROCDUNGEON_DungeonGenerator_generated_h
#error "DungeonGenerator.generated.h already included, missing '#pragma once' in DungeonGenerator.h"
#endif
#define PROCDUNGEON_DungeonGenerator_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ADungeonGenerator ********************************************************
#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRegenerateDungeon);


PROCDUNGEON_API UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister();

#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADungeonGenerator(); \
	friend struct Z_Construct_UClass_ADungeonGenerator_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROCDUNGEON_API UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister(); \
public: \
	DECLARE_CLASS2(ADungeonGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProcDungeon"), Z_Construct_UClass_ADungeonGenerator_NoRegister) \
	DECLARE_SERIALIZER(ADungeonGenerator)


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h_14_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADungeonGenerator(ADungeonGenerator&&) = delete; \
	ADungeonGenerator(const ADungeonGenerator&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADungeonGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADungeonGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADungeonGenerator) \
	NO_API virtual ~ADungeonGenerator();


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h_11_PROLOG
#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADungeonGenerator;

// ********** End Class ADungeonGenerator **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_Public_DungeonGenerator_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
