// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SSBaseItem.generated.h"

class USphereComponent;

DECLARE_MULTICAST_DELEGATE(FOnItemActivated);


UCLASS()
class SPRINTERSIX_API ASSBaseItem : public AActor
{
	GENERATED_BODY()

public:
	ASSBaseItem();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Interface 상속 함수
public:
	virtual void OnItemOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                           int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	FOnItemActivated ItemActivated;

	// 값 복사 (call by value)
	void Foo(FOnItemActivated ItemActivated);
	// 참조 - 복사 x 전달 / call by reference
	void FooBar(FOnItemActivated& ItemActivated);

	// 주소 복사 (call by pointer)
	void Bar(FOnItemActivated* ItemActivated);

protected:
	// 루트 컴포넌트 콜리전으로 변경
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item | Component")
	TObjectPtr<USphereComponent> CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item | Component")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;


	UStaticMeshComponent& StaticMeshCompRef;
	// null x
};
