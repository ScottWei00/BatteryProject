// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectActor.h"

// Sets default values
ACollectActor::ACollectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//������̬���
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
	//Ĭ��trueΪ�ɱ�ʰȡ��
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

//���ؼ���״̬
bool ACollectActor::IsActive()
{
	return bIsActive;
}


//�ı伤��״̬
void ACollectActor::SetActive(bool NewPickupState)
{
	bIsActive = NewPickupState;
}
 

//����ʰȡ���ʱ���õķ���
void ACollectActor::WasCollected_Implementation()
{
	FString PickupDebugString = GetName();
	//UE_LOG(LogCLass, Log, TEXT("���ռ���%s"), *PickupDebugString);  
}

