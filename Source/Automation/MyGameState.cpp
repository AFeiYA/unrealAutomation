// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameState.h"

AMyGameState::AMyGameState()
{
	CurrentScore = 0;
}


int32 AMyGameState::GetScore()
{
	return CurrentScore;
}

void AMyGameState::SetScore(uint32 NewScore)
{
	CurrentScore = NewScore;
}
