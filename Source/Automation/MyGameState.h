// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyGameState.generated.h"

/**
 * 
 */
UCLASS()
class AUTOMATION_API AMyGameState : public AGameState
{
	GENERATED_BODY()
public:
	AMyGameState();

	UFUNCTION()
		int32 GetScore();
	UFUNCTION()
		void SetScore(uint32 NewScore);

private:
	UPROPERTY()
		int32 CurrentScore;

	
};
