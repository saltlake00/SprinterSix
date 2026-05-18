// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "Core/SSGameState.h"
#include "GameFramework/GameState.h"

void UScoreWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 델리게이트가 들어있는 클래스 가져오기
	ASSGameState* GameState = GetWorld()->GetGameState<ASSGameState>();
	if (GameState == nullptr)
	{
		return;
	}

	// 클래스에서 델리게이트 찾은다음 구독목록에 추가(add 생성- remove제거 쌍으로 실행)
	DelegateHandle = GameState->ChangedScoreDelegate.AddUObject(this, &ThisClass::OnUpdateScore);
}

void UScoreWidget::NativeDestruct()
{
	Super::NativeDestruct();
	
	// 월드체크 (게임 종료시 월드가 사라질수있음)
	UWorld* World = GetWorld();
	if (World == nullptr)
	{
		return;
	}
	
	ASSGameState* GameState = World->GetGameState<ASSGameState>();
	if (GameState == nullptr)
	{
		return;
	}
	
	//델리게이트 구독목록에서 제거 (add 후 reamove 쌍으로 실행)
	GameState->ChangedScoreDelegate.Remove(DelegateHandle);
}

void UScoreWidget::OnUpdateScore(int32 NewScore)
{
	ScoreText->SetText(FText::AsNumber(NewScore));
}
