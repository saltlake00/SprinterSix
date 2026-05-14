// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBaseItem.h"

#include "Components/SphereComponent.h"

ASSBaseItem::ASSBaseItem()
{
	// 틱 사용 하지 않을 예정이므로 false로 틱 사용 꺼줌
	PrimaryActorTick.bCanEverTick = false;
	
	// 루트을 콜리전으로 변경
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	CollisionComp->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = CollisionComp;
	
}

void ASSBaseItem::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &)
}

void ASSBaseItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ASSBaseItem::OnItemOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
                                bFromSweep, const FHitResult& SweepResult)
{
	// 오버랩 이벤트 -> 자식 클래스에서 구현
}

void ASSBaseItem::Foo(FOnItemActivated ItemActivated)
{
	ItemActivated.Broadcast();
}

void ASSBaseItem::FooBar(FOnItemActivated& ItemActivated)
{
	ItemActivated.Broadcast();
}

void ASSBaseItem::Bar(FOnItemActivated* ItemActivated)
{
	ItemActivated->Broadcast();
}

