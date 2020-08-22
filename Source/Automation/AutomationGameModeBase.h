// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UserProfile.h"
#include "AutomationGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class AUTOMATION_API AAutomationGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNames)
	TSubclassOf<UUserProfile> UPBlueprintClassName;


};
