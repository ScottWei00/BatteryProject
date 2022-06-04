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
	//触发返回物体
	FORCEINLINE class UBoxComponent* GetWhereToSpawn()const { return WhereToSpawn; }
	 
	//获取随机点
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();

private:
	//触发可拾取事件
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	class UBoxComponent* WhereToSpawn;

	//管理一个新的触发拾取
	void SpawnPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//定义触发拾取
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class ACollectActor> WhatToSpawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
