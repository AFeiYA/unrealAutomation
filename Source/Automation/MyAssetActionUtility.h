// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
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

private:
	bool IsPowerOfTwo(int32 NumberToCheck);
	void PrintToScreen(FString Message, FColor Color);
	void GiveFeedBack(FString Method , uint32 Counter);
};
