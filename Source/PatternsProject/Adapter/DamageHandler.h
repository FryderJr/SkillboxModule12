// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageHandler.generated.h"


/*
* ������� �������. � ������ ����� ���������� ����� ��������� ��������� �����. 
* ��� ������� ���������� � ������ UDestructionComponentAdapter � ������������
* ������������� ����� - DamageComponent, ������� ����� ��������� � ������ ��������
* ������� ��������� ������� ��������� � ����������� �� ���� ����������� �����: �� ������� ��� �����������
* � �� ��������������� �����������
*/
enum DamageType
{
	Kinetic,
	Explosion,
	Energy
};

struct DamageInfo {
	AActor* DamageCauser;
	DamageType Type;
	float DamageAmount;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageHandler : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PATTERNSPROJECT_API IDamageHandler
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void DealDamage(DamageInfo Info) PURE_VIRTUAL(IDamageHandler::DealDamage, return;);
};
