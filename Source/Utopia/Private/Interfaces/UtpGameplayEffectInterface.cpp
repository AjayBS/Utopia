// Copyright Confused Minds, Ltd. All Rights Reserved.

#include "Interfaces/UtpGameplayEffectInterface.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

void IUtpGameplayEffectInterface::ApplyEffectToTarget_Implementation(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass, AActor* OwningActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);

	if (IsValid(TargetASC))
	{
		check(GameplayEffectClass);
		FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
		EffectContextHandle.AddSourceObject(OwningActor);
		const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);
		TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}
