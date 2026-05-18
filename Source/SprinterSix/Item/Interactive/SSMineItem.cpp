// Fill out your copyright notice in the Description page of Project Settings.


#include "SSMineItem.h"

#include "Actor/Character/SSCharacter.h"
#include "Components/SphereComponent.h"

// Sets default values
ASSMineItem::ASSMineItem()
{
	ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollision->InitSphereRadius(ExplosionRadius);
	ExplosionCollision->SetupAttachment(CollisionComp);
}

void ASSMineItem::Explode()
{
	// 오버랩 되는 액터를 담을 배열 선언
	TArray<AActor*> OverlappingActors;
	// 콜리전에 오버랩 되는 액터 중복검사하여 넣었다.
	ExplosionCollision->GetOverlappingActors(OverlappingActors, ASSCharacter::StaticClass());
	
	// 배열을 순회함
	for (AActor* Character : OverlappingActors)
	{
		// 해당 객체가 모두 유효하다면 디버그 메시지 띄움 ( 추후 데미지 계산식으로 변경 가능 )
		GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Red,
		                                 FString::Printf(TEXT("Player damaged %d by MineItem"),
		                                                 ExplosionDamage));
	}
	
	Destroy();
}

void ASSMineItem::Activate(ASSCharacter* Character)
{
	// 지연 폭발 실행. 딜레이 이후 폭발시 해당 콜리전에 닿는 객체에 explode 데미지 계산.
	GetWorld()->GetTimerManager().SetTimer(ExplosionTimerHandle, this, &ASSMineItem::Explode, ExplosionDelay);
}

void ASSMineItem::OnPostActivated()
{
}
