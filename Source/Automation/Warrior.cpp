// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FString AWarrior::ToString()
{
	return FString("What's the fuck!!"+ Name);
}

