// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h" 
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "CollectActor.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//�����������������
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	//����ʱ����ӳ�����
	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 4.5f;
}

/// <summary>
/// ��ȡ�����ĺ���
/// </summary>
/// <returns></returns>
FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector SpawnOrign = WhereToSpawn->Bounds.Origin;//ԭ��߽�
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;//�յ�߽�

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrign, SpawnExtent);//�漴���ط�Χ�ڵ�һ����
}

void ASpawnVolume::SpawnPickup()
{
	if (WhatToSpawn != NULL)
	{
		UWorld* const world = GetWorld();
		if (world)
		{
			//���ô�������
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			//��ȡ���������λ��
			FVector SpawnLocation = GetRandomPointInVolume();

			//��ȡ����������漴��ת
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.f;//y
			SpawnRotation.Pitch = FMath::FRand() * 360.f;//z
			SpawnRotation.Roll = FMath::FRand() * 360.f;//x

			//����ʰȡ
			ACollectActor* const SpawnedPickup = world->SpawnActor<ACollectActor>(WhatToSpawn, 
				SpawnLocation, SpawnRotation, SpawnParams);

			//�󶨷�����ȫ�ֶ�ʱ��
			SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
		}
	}
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

