// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBaseItem.h"

#include "Actor/Character/SSCharacter.h"
#include "Components/SphereComponent.h"

ASSBaseItem::ASSBaseItem()
{
	// 틱 사용 하지 않을 예정이므로 false로 틱 사용 꺼줌
	PrimaryActorTick.bCanEverTick = false;

	// 루트을 콜리전으로 변경
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	CollisionComp->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = CollisionComp;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetCollisionProfileName(TEXT("NoCollision"));
	StaticMeshComp->SetupAttachment(CollisionComp);
}

void ASSBaseItem::BeginPlay()
{
	Super::BeginPlay();

	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnCollisionBeginOverlap);
}

void ASSBaseItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	CollisionComp->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnCollisionBeginOverlap);
}

void ASSBaseItem::Activate(ASSCharacter* Character)
{
}

void ASSBaseItem::OnPostActivated()
{
	Destroy();
}

void ASSBaseItem::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
                                          bFromSweep, const FHitResult& SweepResult)
{
	// 오버랩 이벤트 -> 자식 클래스에서 구현
	ASSCharacter* Character = Cast<ASSCharacter>(OtherActor);
	if (Character == nullptr)
	{
		return;
	}

	Activate(Character);

	OnPostActivated();
}
