// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryActor.h"

/// <summary>
/// �����������Ե�Ĭ��ֵ
/// </summary>
ABatteryActor::ABatteryActor()
{
	//��������״̬
	GetMesh()->SetSimulatePhysics(true);
}

/// <summary>
/// ��д����ʰȡ�ķ���
/// </summary>
void ABatteryActor::WasCollected_Implementation()
{
	//���ø�����ռ�����
	Super::WasCollected_Implementation();
	//���ٵ��
	Destroy();
}
