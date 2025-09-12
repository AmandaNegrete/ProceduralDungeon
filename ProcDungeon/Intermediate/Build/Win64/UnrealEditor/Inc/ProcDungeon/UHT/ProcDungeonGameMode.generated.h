// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProcDungeonGameMode.h"

#ifdef PROCDUNGEON_ProcDungeonGameMode_generated_h
#error "ProcDungeonGameMode.generated.h already included, missing '#pragma once' in ProcDungeonGameMode.h"
#endif
#define PROCDUNGEON_ProcDungeonGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AProcDungeonGameMode *****************************************************
PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonGameMode_NoRegister();

#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProcDungeonGameMode(); \
	friend struct Z_Construct_UClass_AProcDungeonGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AProcDungeonGameMode, AGameModeBase, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProcDungeon"), Z_Construct_UClass_AProcDungeonGameMode_NoRegister) \
	DECLARE_SERIALIZER(AProcDungeonGameMode)


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AProcDungeonGameMode(AProcDungeonGameMode&&) = delete; \
	AProcDungeonGameMode(const AProcDungeonGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcDungeonGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcDungeonGameMode); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AProcDungeonGameMode) \
	NO_API virtual ~AProcDungeonGameMode();


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h_12_PROLOG
#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AProcDungeonGameMode;

// ********** End Class AProcDungeonGameMode *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
