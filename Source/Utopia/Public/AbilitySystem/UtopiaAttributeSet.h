// Copyright Confused Minds Ltd, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "UtopiaAttributeSet.generated.h"

 #define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class UTOPIA_API UUtopiaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UUtopiaAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	UPROPERTY(BlueprintReadOnly, Category ="Vital Attributes")
	FGameplayAttributeData Vision;
	ATTRIBUTE_ACCESSORS(UUtopiaAttributeSet, Vision);

	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxVision;
	ATTRIBUTE_ACCESSORS(UUtopiaAttributeSet, MaxVision);
};
