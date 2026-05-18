// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SSGameState.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangedScore, int32);


/**
 * 
 */
UCLASS()
class SPRINTERSIX_API ASSGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ASSGameState();

public:
	int32 GetScore() const;
	void AddScore(int32 Amount);

	// delegate
public:
	FOnChangedScore ChangedScoreDelegate;

protected:
	int32 Score;
};
