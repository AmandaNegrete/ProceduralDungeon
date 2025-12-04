// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProcDungeonCameraManager.h"

#ifdef PROCDUNGEON_ProcDungeonCameraManager_generated_h
#error "ProcDungeonCameraManager.generated.h already included, missing '#pragma once' in ProcDungeonCameraManager.h"
#endif
#define PROCDUNGEON_ProcDungeonCameraManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AProcDungeonCameraManager ************************************************
PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonCameraManager_NoRegister();

#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProcDungeonCameraManager(); \
	friend struct Z_Construct_UClass_AProcDungeonCameraManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROCDUNGEON_API UClass* Z_Construct_UClass_AProcDungeonCameraManager_NoRegister(); \
public: \
	DECLARE_CLASS2(AProcDungeonCameraManager, APlayerCameraManager, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProcDungeon"), Z_Construct_UClass_AProcDungeonCameraManager_NoRegister) \
	DECLARE_SERIALIZER(AProcDungeonCameraManager)


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AProcDungeonCameraManager(AProcDungeonCameraManager&&) = delete; \
	AProcDungeonCameraManager(const AProcDungeonCameraManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcDungeonCameraManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcDungeonCameraManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProcDungeonCameraManager) \
	NO_API virtual ~AProcDungeonCameraManager();


#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h_13_PROLOG
#define FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AProcDungeonCameraManager;

// ********** End Class AProcDungeonCameraManager **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_amand_ProceduralDungeon_ProcDungeon_Source_ProcDungeon_ProcDungeonCameraManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
