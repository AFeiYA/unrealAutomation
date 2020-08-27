// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Warrior.h"
#include "Components/PointLightComponent.h"
#include "MyGameMode.generated.h"
/**
 * 
 */

DECLARE_DELEGATE(FStandardDelegateSingature)

UCLASS()
class AUTOMATION_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	FStandardDelegateSingature MyStandardDelegate;
	UFUNCTION()
		void EnableLight();
	
	UPROPERTY()
		UPointLightComponent*  PointLight;
	UPROPERTY()
		AWarrior* SpawnedActor;
	UFUNCTION()
		void DestroyActorFunction();
};
