// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseAttribute.generated.h"

/**
 * Паттерн Компоновщик. В данном случае мы реализовали древовидную систему аттрибутов
 * Аттрибуты могу силиваться различными бонусами
 * Бонусы могут быть как в виде абсолютных цифр, так и в виде процентов
 * Бонусы могут накладываться комплексно
 * В качестве базового используется класс UBaseAttribute. От котого наследуются RawBonus и FinalBonus
 * Оба этих класса являются листьями дерева
 * В качестве ветвей будут выступать экземпляры класса ContainerAttribute
 */
UCLASS()
class PATTERNSPROJECT_API UBaseAttribute : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = Attribute)
	void SetBaseValue(float Value);

	UFUNCTION(BlueprintCallable, Category = Attribute)
	float GetBaseValue();

	UFUNCTION(BlueprintCallable, Category = Attribute)
	void SetBaseMultiplier(float Value);

	UFUNCTION(BlueprintCallable, Category = Attribute)
	float GetBaseMultiplier();

	UFUNCTION(BlueprintCallable, Category = Attribute)
	virtual void SetParent(UBaseAttribute* NewParent);

	virtual void CalculateValue();

	virtual void Recalculate();

	float GetFinalValue();

protected:

	UPROPERTY(EditAnywhere, Category = Attribute)
	float BaseValue;

	UPROPERTY(EditAnywhere, Category = Attribute)
	float BaseMultiplier;

	float FinalValue;

	UBaseAttribute* Parent;
};
