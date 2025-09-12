// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProcDungeonPlayerController.h"

#ifdef PROCDUNGEON_ProcDungeonPlayerController_generated_h
#error "ProcDungeonPlayerController.generated.h already included, missing '#pragma once' in ProcDungeonPlayerController.h"
#endif
#define PROCDUNGEON_ProcDungeonPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AProcDungeonPlayerController *********************************************
PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonPlayerController_NoRegister();

#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonPlayerController_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProcDungeonPlayerController(); \
	friend struct Z_Construct_UClass_AProcDungeonPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AProcDungeonPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProcDungeon"), Z_Construct_UClass_AProcDungeonPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AProcDungeonPlayerController)


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonPlayerController_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AProcDungeonPlayerController(AProcDungeonPlayerController&&) = delete; \
	AProcDungeonPlayerController(const AProcDungeonPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcDungeonPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcDungeonPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AProcDungeonPlayerController) \
	NO_API virtual ~AProcDungeonPlayerController();


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonPlayerController_h_17_PROLOG
#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonPlayerController_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonPlayerController_h_20_INCLASS_NO_PURE_DECLS \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonPlayerController_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AProcDungeonPlayerController;

// ********** End Class AProcDungeonPlayerController ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
