// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameMode.h"
#include "DelegateListener.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(true);
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();
	UWorld* TheWorld = GetWorld();
	if (ensure(GetWorld())) {
		AGameMode* GameMode = (AGameMode*)UGameplayStatics::GetGameMode(TheWorld);
		AMyGameMode* MyGameMode = Cast<AMyGameMode>(GameMode);
		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight);
		}
	}

	
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

