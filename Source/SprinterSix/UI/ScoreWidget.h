// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CommonTextBlock.h"

#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPRINTERSIX_API UScoreWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void OnUpdateScore(int32 NewScore);
	
	FDelegateHandle DelegateHandle;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> ScoreText;
	
};
