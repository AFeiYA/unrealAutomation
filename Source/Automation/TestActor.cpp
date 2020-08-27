// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Create objects
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	ChildSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");
	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object!=nullptr) {
		BoxOne->SetStaticMesh(MeshAsset.Object);
		//BoxOne->SetCollisionProfileName();

		BoxTwo->SetStaticMesh(MeshAsset.Object);
	}

	//Setup hierarchy.

	RootComponent = Root;
	ChildSceneComponent->AttachTo(Root);
	BoxOne->AttachTo(Root);
	BoxTwo->AttachTo(ChildSceneComponent);
	ChildSceneComponent->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(200, 0, 0), FVector(1.2)));




}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(5);
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay!!!!"));
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

