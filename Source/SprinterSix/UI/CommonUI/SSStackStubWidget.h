// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SSStackStubWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPRINTERSIX_API USSStackStubWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;
	
	// 부모에 const가 있으면 상속받을때 함수명 뒤에 const를 반드시 붙여야 하는 이유?
	// -> const까지가 함수의 시그니처라서 const가 빠지면 다른함수로 취급함
	
};
