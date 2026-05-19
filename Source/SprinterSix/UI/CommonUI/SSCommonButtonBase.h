// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CommonTextBlock.h"
#include "SSCommonButtonBase.generated.h"

/**
 * 
 */
UCLASS()
class SPRINTERSIX_API USSCommonButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;

public:
	virtual void NativeConstruct() override;

	virtual void UpdateUI();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Text;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> ButtonText;
};
