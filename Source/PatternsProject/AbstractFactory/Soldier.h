// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Soldier.generated.h"

/*
* ������� ����� ��� ���� ����� ������
* � �������� ������� ���� ������� �����
* ���������� ������� ����� ���������� � �������-�����������
*/
UCLASS()
class PATTERNSPROJECT_API ASoldier : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASoldier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Attack() PURE_VIRTUAL(ASoldier::Attack, return;);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

/*
* ������� ����� �������� �������, ��������� �������� �������
* ���������� �� �������� ������� �������� ����������� �����
* ���������� ����������� ����� ���������� � �������-�����������
*/
UCLASS()
class PATTERNSPROJECT_API AEliteSoldier : public ASoldier
{
	GENERATED_BODY()

public:

	AEliteSoldier();

protected:

	virtual void SpecialAttack() PURE_VIRTUAL(AEliteSoldier::SpecialAttack, return;);
};

/*
* ����� �������-���������
* 
*/
UCLASS()
class PATTERNSPROJECT_API AMilitiaSoldier : public ASoldier
{
	GENERATED_BODY()

public:

	AMilitiaSoldier();

protected:

	virtual void Attack() override;
};

/*
* ����� �������� �������-���������
* 
*/
UCLASS()
class PATTERNSPROJECT_API AEliteMilitiaSoldier : public AEliteSoldier
{
	GENERATED_BODY()

public:

	AEliteMilitiaSoldier();

protected:

	virtual void Attack() override;

	virtual void SpecialAttack() override;
};

/*
* ����� ������������ �������
* 
*/
UCLASS()
class PATTERNSPROJECT_API ACrownSoldier : public ASoldier
{
	GENERATED_BODY()

public:

	ACrownSoldier();

protected:

	virtual void Attack() override;
};

/*
* ����� �������� ������������ �������
* 
*/
UCLASS()
class PATTERNSPROJECT_API AEliteCrownSoldier : public AEliteSoldier
{
	GENERATED_BODY()

public:

	AEliteCrownSoldier();

protected:

	virtual void Attack() override;

	virtual void SpecialAttack() override;
};