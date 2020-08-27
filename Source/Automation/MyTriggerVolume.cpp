// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVolume.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyTriggerVolume::NotifyActorBeginOverlap(AActor * OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s entered me!"), *(OtherActor->GetName())));
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor * OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s left me!"), *(OtherActor->GetName())));
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

