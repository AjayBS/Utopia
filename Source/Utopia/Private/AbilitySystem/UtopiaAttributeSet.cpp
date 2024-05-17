// Copyright Confused Minds, Ltd. All Rights Reserved.


#include "AbilitySystem/UtopiaAttributeSet.h"

UUtopiaAttributeSet::UUtopiaAttributeSet()
{
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
}

void UUtopiaAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
}