// Copyright Confused Minds, Ltd. All Rights Reserved.


#include "AbilitySystem/UtopiaAttributeSet.h"

UUtopiaAttributeSet::UUtopiaAttributeSet()
{
	InitVision(0.f);
	InitMaxVision(100.0f);
}

void UUtopiaAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetVisionAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxVision());
	}
}