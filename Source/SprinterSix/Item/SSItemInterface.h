// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SSItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USSItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPRINTERSIX_API ISSItemInterface
{
	GENERATED_BODY()

	// 인터페이스 구현을 위한 순수가상함수 구현 (자식객체에서 오버라이드를 반드시 해야함)
public:
	virtual void OnItemOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	                           bool bFromSweep, const FHitResult& SweepResult) = 0;
	virtual void OnItemEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) = 0;
	virtual void ActivateItem(AActor* Activator) = 0;
	virtual FName GetItemType() const = 0;
};
