// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectActor.generated.h"

UCLASS()
class BATTERYPROJECT_API ACollectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectActor();

private:
	//定义拾取的静态物体
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//是否可以被拾取，可拾取为true
	bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//返回拾取的物体
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	//返回是否拾取的状态
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	//改变激活状态
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool NewPickupState);

	/// <summary>
	/// 当拾取物体被收集时调用此方法
	/// BlueprintNativeEvent可以被蓝图执行
	/// </summary>
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();
};
