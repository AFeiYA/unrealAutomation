// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "MyAssetsActionUtility.generated.h"

/**
 * 
 */
UCLASS()
class AUTOMATION_API UMyAssetsActionUtility : public UAssetActionUtility
{
	GENERATED_BODY()
public:
	/**
	*Rename the selected assets.
	*@param SearchPattern -- The pattern to search for
	*@param ReplacePattern -- The pattern to replace with
	*@param SearchCase -- Should the case be ingored ?
	**/
	UFUNCTION(CallInEditor)
	void RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase);

private:
	void PrintToScreen(FString Message, FColor Color);

	void GiveFeedBack(FString Method, uint32 Counter);

};
