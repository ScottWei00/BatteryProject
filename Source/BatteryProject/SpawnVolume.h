// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();
	//������������
	FORCEINLINE class UBoxComponent* GetWhereToSpawn()const { return WhereToSpawn; }
	 
	//��ȡ�����
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();

private:
	//������ʰȡ�¼�
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	class UBoxComponent* WhereToSpawn;

	//����һ���µĴ���ʰȡ
	void SpawnPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//���崥��ʰȡ
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class ACollectActor> WhatToSpawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
