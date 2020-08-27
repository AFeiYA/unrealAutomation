// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MyTriggerVolume.generated.h"

UCLASS()
class AUTOMATION_API AMyTriggerVolume : public ATriggerBox
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerVolume();
	UFUNCTION()
		virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UFUNCTION()
		virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
