// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProcDungeonCharacter.h"

#ifdef PROCDUNGEON_ProcDungeonCharacter_generated_h
#error "ProcDungeonCharacter.generated.h already included, missing '#pragma once' in ProcDungeonCharacter.h"
#endif
#define PROCDUNGEON_ProcDungeonCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AProcDungeonCharacter ****************************************************
#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoMove); \
	DECLARE_FUNCTION(execDoAim);


PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonCharacter_NoRegister();

#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProcDungeonCharacter(); \
	friend struct Z_Construct_UClass_AProcDungeonCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AProcDungeonCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProcDungeon"), Z_Construct_UClass_AProcDungeonCharacter_NoRegister) \
	DECLARE_SERIALIZER(AProcDungeonCharacter)


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AProcDungeonCharacter(AProcDungeonCharacter&&) = delete; \
	AProcDungeonCharacter(const AProcDungeonCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcDungeonCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcDungeonCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AProcDungeonCharacter) \
	NO_API virtual ~AProcDungeonCharacter();


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h_21_PROLOG
#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AProcDungeonCharacter;

// ********** End Class AProcDungeonCharacter ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
