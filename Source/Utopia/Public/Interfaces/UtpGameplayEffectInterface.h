// // Copyright Confused Minds, Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UtpGameplayEffectInterface.generated.h"

class UGameplayEffect;

// This class does not need to be modified.
UINTERFACE(Blueprintable, MinimalAPI)
class UUtpGameplayEffectInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UTOPIA_API IUtpGameplayEffectInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass, AActor* OwningActor);
	virtual void ApplyEffectToTarget_Implementation(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass, AActor* OwningActor);
};
