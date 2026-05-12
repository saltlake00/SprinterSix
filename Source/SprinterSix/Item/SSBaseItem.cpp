// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBaseItem.h"

#include "Components/SphereComponent.h"

ASSBaseItem::ASSBaseItem()
{
	// 틱 사용 하지 않을 예정이므로 false로 틱 사용 꺼줌
	PrimaryActorTick.bCanEverTick = false;
	
	//scene 컴포넌트(트랜스폼 데이터) 추가후 루트로 설정
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);
	
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Collision->SetupAttachment(Scene);
}

void ASSBaseItem::OnItemOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
                                bFromSweep, const FHitResult& SweepResult)
{
	// 오버랩 이벤트 -> 자식 클래스에서 구현
}

void ASSBaseItem::OnItemEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// 오버랩 벗어나면 이벤트
}

void ASSBaseItem::ActivateItem(AActor* Activator)
{
	// 사용시 이벤트
}

FName ASSBaseItem::GetItemType() const
{
	// void가 아닌 FName 타입 함수라 자료형 멤버변수 그대로 리턴
	return ItemType;
}

void ASSBaseItem::DestroyItem()
{
	// 소멸자 호출, 추가로 이펙트 등 구현가능
	Destroy();
}
