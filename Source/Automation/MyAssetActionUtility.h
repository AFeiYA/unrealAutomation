// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"

#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "Sound/SoundWave.h"
#include "Blueprint/UserWidget.h"
#include "Animation/MorphTarget.h"
#include "Components/SkeletalMeshComponent.h"


#include "MyAssetActionUtility.generated.h"

/**
 * 
 */
UCLASS()
class AUTOMATION_API UMyAssetActionUtility : public UAssetActionUtility
{
	GENERATED_BODY()

public:
	/**
	*Rename the selected assets.
	*@param SearchPattern 
	*@param ReplacePattern 
	*@param SearchCase 
	**/
	UFUNCTION(CallInEditor)
		void RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase);
	/**
	*Check if a texture is power of two .
	**/
	UFUNCTION(CallInEditor)
		void CheckPowerOfTwo();

	/**
	*Add prefix for selected assets.
	**/
	UFUNCTION(CallInEditor)
		void AddPrefix();

	/**
	*Auto create folders for selected assets.
	**/
	UFUNCTION(CallInEditor)
		void CleanupFolder(FString ParentFolder = FString("/Game"));

private:
	const TMap<UClass*, FString> PrefixMap = {
		{UBlueprint::StaticClass(), TEXT("BP_")},
		{UStaticMesh::StaticClass(), TEXT("SM_")},
		{UMaterial::StaticClass(), TEXT("M_")},
		{UMaterialInstance::StaticClass(), TEXT("MI_")},
		{UMaterialFunctionInterface::StaticClass(), TEXT("MF_")},
		{UParticleSystem::StaticClass(), TEXT("PS_")},
		{USoundCue::StaticClass(), TEXT("SC_")},
		{USoundWave::StaticClass(), TEXT("S_")},
		{UTexture::StaticClass(), TEXT("T_")},
		{UTexture2D::StaticClass(),TEXT("T_")},
		{UUserWidget::StaticClass(),TEXT("WBP_")},
		{UMorphTarget::StaticClass(),TEXT("MT_")},
		{USkeletalMeshComponent::StaticClass(), TEXT("SK_")}
	};


	bool IsPowerOfTwo(int32 NumberToCheck);
	void PrintToScreen(FString Message, FColor Color);
	void GiveFeedBack(FString Method , uint32 Counter);
};
