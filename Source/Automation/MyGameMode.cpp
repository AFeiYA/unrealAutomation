// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
//#include "Warrior.h"

void AMyGameMode::BeginPlay() {
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Actor Spawning!"));
	
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<AWarrior>(AWarrior::StaticClass(), SpawnLocation);
	//
	//FTimerHandle Timer;
	//GetWorldTimerManager().SetTimer(Timer, this, &AMyGameMode::DestroyActorFunction,5);


}



void AMyGameMode::DestroyActorFunction()
{
	if (SpawnedActor != nullptr) {
		SpawnedActor->Destroy();
	}
}
