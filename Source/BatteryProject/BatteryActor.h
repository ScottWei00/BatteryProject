// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectActor.h"
#include "BatteryActor.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYPROJECT_API ABatteryActor : public ACollectActor
{
	GENERATED_BODY()

public:
	//设置物体属性的默认值
	ABatteryActor();
	
};
