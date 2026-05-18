// Fill out your copyright notice in the Description page of Project Settings.


#include "SSGameState.h"

ASSGameState::ASSGameState()
{
	Score = 0;
}

int32 ASSGameState::GetScore() const
{
	return Score;
}

void ASSGameState::AddScore(int32 Amount)
{
	Score += Amount;
	
	ChangedScoreDelegate.Broadcast(Score);
}
