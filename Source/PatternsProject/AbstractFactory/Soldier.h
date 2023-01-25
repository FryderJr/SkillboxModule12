// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Soldier.generated.h"

/*
* Базовый класс для всех типов солдат
* У обычного солдата есть базовая атака
* Реализация базовой атаки происходит в классах-наследниках
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
* Базовый класс элитного солдата, наследник обычного солдата
* Отличается от обычного солдата наличием специальной атаки
* Реализация специальной атаки происходит в классах-наследниках
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
* Класс солдата-ополченца
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
* Класс элитного солдата-ополченца
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
* Класс королевского солдата
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
* Класс элитного королевского солдата
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