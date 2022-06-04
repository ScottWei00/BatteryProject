// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h" 
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//创建触发器盒子组件
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;
}

/// <summary>
/// 获取随机点的函数
/// </summary>
/// <returns></returns>
FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector SpawnOrign = WhereToSpawn->Bounds.Origin;//原点边界
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;//终点边界

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrign, SpawnExtent);//随即返回范围内的一个点
}

void ASpawnVolume::SpawnPickup()
{
	if (WhatToSpawn != NULL)
	{
		UWorld* const world = GetWorld();
		if (world)
		{
			//设置触发参数
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			//获取触发的随机位置
			FVector SpawnLocation = GetRandomPointInVolume();

			//获取触发物体的随即旋转
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.f;//y
			SpawnRotation.Pitch = FMath::FRand() * 360.f;//z
			SpawnRotation.Roll = FMath::FRand() * 360.f;//x

			//触发拾取
			ACollectActor* const SpawnedPickup = world->SpawnActor<ACollectActor>(WhatToSpawn, 
				SpawnLocation, SpawnRotation, SpawnParams);
		}
	}
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

