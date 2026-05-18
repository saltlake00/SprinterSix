// Fill out your copyright notice in the Description page of Project Settings.


#include "SSCoinItem.h"
#include "Engine/World.h"
#include "Core/SSGameState.h"


// Sets default values
ASSCoinItem::ASSCoinItem()
{
}

void ASSCoinItem::Activate(ASSCharacter* Character)
{
	// 게임스테이트 널체크 - 월드에 SSGameState가 제대로 들어왔는지 체크
	ASSGameState* GameState = GetWorld()->GetGameState<ASSGameState>();

	if (GameState == nullptr)
	{
		return;
	}

	// 게임스테이트가 제대로 널체크 통과했으면 pointvalue 만큼 addscore 함수 실행
	GameState->AddScore(PointValue);

	int32 Score = GameState->GetScore();
	UE_LOG(LogTemp, Warning, TEXT("Score %d"),Score);

	if (Score > 100)
	{
		UE_LOG(LogTemp,Warning, TEXT("Score 100 over"));
	}
	
	// 점수 획득 후 destroy 함수 호출
	OnPostActivated();
}
