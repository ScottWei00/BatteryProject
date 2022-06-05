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
	//����ʰȡ�ľ�̬����
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//�Ƿ���Ա�ʰȡ����ʰȡΪtrue
	bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//����ʰȡ������
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	//�����Ƿ�ʰȡ��״̬
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	//�ı伤��״̬
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool NewPickupState);

	/// <summary>
	/// ��ʰȡ���屻�ռ�ʱ���ô˷���
	/// BlueprintNativeEvent���Ա���ͼִ��
	/// </summary>
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();
};
