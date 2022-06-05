// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryActor.h"

/// <summary>
/// 设置物体属性的默认值
/// </summary>
ABatteryActor::ABatteryActor()
{
	//设置物理状态
	GetMesh()->SetSimulatePhysics(true);
}

/// <summary>
/// 重写基类拾取的方法
/// </summary>
void ABatteryActor::WasCollected_Implementation()
{
	//调用父类的收集方法
	Super::WasCollected_Implementation();
	//销毁电池
	Destroy();
}
