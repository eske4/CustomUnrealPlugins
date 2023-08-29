// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlayerPhysicsManagerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerPhysicsManagerComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPhysicsHandleComponent_NoRegister();
	PHYSICSACTIONMANAGER_API UClass* Z_Construct_UClass_UPlayerPhysicsManagerComponent();
	PHYSICSACTIONMANAGER_API UClass* Z_Construct_UClass_UPlayerPhysicsManagerComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PhysicsActionManager();
// End Cross Module References
	void UPlayerPhysicsManagerComponent::StaticRegisterNativesUPlayerPhysicsManagerComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPlayerPhysicsManagerComponent);
	UClass* Z_Construct_UClass_UPlayerPhysicsManagerComponent_NoRegister()
	{
		return UPlayerPhysicsManagerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PhysicsHandle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsHandle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Reach_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Reach;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrowStrength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrowStrength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DistanceSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceSensitivity;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PhysicsActionManager,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "/**\n * Component that enables physics-based interactions with objects.\n */" },
		{ "IncludePath", "PlayerPhysicsManagerComponent.h" },
		{ "ModuleRelativePath", "Public/PlayerPhysicsManagerComponent.h" },
		{ "ToolTip", "Component that enables physics-based interactions with objects." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PhysicsHandle_MetaData[] = {
		{ "Comment", "// ==============================================\n// Components\n// ==============================================\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PlayerPhysicsManagerComponent.h" },
		{ "ToolTip", "Components" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PhysicsHandle = { "PhysicsHandle", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPlayerPhysicsManagerComponent, PhysicsHandle), Z_Construct_UClass_UPhysicsHandleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PhysicsHandle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PhysicsHandle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PlayerCamera_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PlayerPhysicsManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PlayerCamera = { "PlayerCamera", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPlayerPhysicsManagerComponent, PlayerCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PlayerCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PlayerCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_Reach_MetaData[] = {
		{ "Category", "Interaction Settings" },
		{ "Comment", "/** Max distance between player and object to be able to interact */" },
		{ "ModuleRelativePath", "Public/PlayerPhysicsManagerComponent.h" },
		{ "ToolTip", "Max distance between player and object to be able to interact" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_Reach = { "Reach", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPlayerPhysicsManagerComponent, Reach), METADATA_PARAMS(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_Reach_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_Reach_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_ThrowStrength_MetaData[] = {
		{ "Category", "Interaction Settings" },
		{ "Comment", "/** Magnitude of impulse applied to the object during the throw action */" },
		{ "ModuleRelativePath", "Public/PlayerPhysicsManagerComponent.h" },
		{ "ToolTip", "Magnitude of impulse applied to the object during the throw action" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_ThrowStrength = { "ThrowStrength", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPlayerPhysicsManagerComponent, ThrowStrength), METADATA_PARAMS(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_ThrowStrength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_ThrowStrength_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_DistanceSensitivity_MetaData[] = {
		{ "Category", "Interaction Settings" },
		{ "Comment", "/** Adjusts the sensitivity for moving the object closer or further away */" },
		{ "ModuleRelativePath", "Public/PlayerPhysicsManagerComponent.h" },
		{ "ToolTip", "Adjusts the sensitivity for moving the object closer or further away" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_DistanceSensitivity = { "DistanceSensitivity", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPlayerPhysicsManagerComponent, DistanceSensitivity), METADATA_PARAMS(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_DistanceSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_DistanceSensitivity_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PhysicsHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_PlayerCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_Reach,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_ThrowStrength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::NewProp_DistanceSensitivity,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerPhysicsManagerComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::ClassParams = {
		&UPlayerPhysicsManagerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPlayerPhysicsManagerComponent()
	{
		if (!Z_Registration_Info_UClass_UPlayerPhysicsManagerComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlayerPhysicsManagerComponent.OuterSingleton, Z_Construct_UClass_UPlayerPhysicsManagerComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPlayerPhysicsManagerComponent.OuterSingleton;
	}
	template<> PHYSICSACTIONMANAGER_API UClass* StaticClass<UPlayerPhysicsManagerComponent>()
	{
		return UPlayerPhysicsManagerComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerPhysicsManagerComponent);
	UPlayerPhysicsManagerComponent::~UPlayerPhysicsManagerComponent() {}
	struct Z_CompiledInDeferFile_FID_Engine_Plugins_PhysicsActionManager_Source_PhysicsActionManager_Public_PlayerPhysicsManagerComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Engine_Plugins_PhysicsActionManager_Source_PhysicsActionManager_Public_PlayerPhysicsManagerComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPlayerPhysicsManagerComponent, UPlayerPhysicsManagerComponent::StaticClass, TEXT("UPlayerPhysicsManagerComponent"), &Z_Registration_Info_UClass_UPlayerPhysicsManagerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayerPhysicsManagerComponent), 1339967928U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Engine_Plugins_PhysicsActionManager_Source_PhysicsActionManager_Public_PlayerPhysicsManagerComponent_h_3580816414(TEXT("/Script/PhysicsActionManager"),
		Z_CompiledInDeferFile_FID_Engine_Plugins_PhysicsActionManager_Source_PhysicsActionManager_Public_PlayerPhysicsManagerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Engine_Plugins_PhysicsActionManager_Source_PhysicsActionManager_Public_PlayerPhysicsManagerComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
