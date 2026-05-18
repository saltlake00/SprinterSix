// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SSBaseItem.generated.h"

class ASSCharacter;
class USphereComponent;

UCLASS()
class SPRINTERSIX_API ASSBaseItem : public AActor
{
	GENERATED_BODY()

public:
	ASSBaseItem();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Activate(ASSCharacter* Character);
	virtual void OnPostActivated();

public:
	UFUNCTION()
	virtual void OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                                     UPrimitiveComponent* OtherComp,
	                                     int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:

protected:
	// 루트 컴포넌트 콜리전으로 변경
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item | Component")
	TObjectPtr<USphereComponent> CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item | Component")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;
};
