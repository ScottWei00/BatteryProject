// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectActor.h"

// Sets default values
ACollectActor::ACollectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//创建静态组件
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
	//默认true为可被拾取的
	bIsActive = true;

}

// Called when the game starts or when spawned
void ACollectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//返回激活状态
bool ACollectActor::IsActive()
{
	return bIsActive;
}


//改变激活状态
void ACollectActor::SetActive(bool NewPickupState)
{
	bIsActive = NewPickupState;
}
 

//基类拾取电池时调用的方法
void ACollectActor::WasCollected_Implementation()
{
	FString PickupDebugString = GetName();
	//UE_LOG(LogCLass, Log, TEXT("你收集了%s"), *PickupDebugString);  
}

