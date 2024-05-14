// // Copyright Confused Minds, Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/UtpGameplayEffectInterface.h"
#include "UtpAIBaseActor.generated.h"

UCLASS()
class UTOPIA_API AUtpAIBaseActor : public AActor, public IUtpGameplayEffectInterface
{
	GENERATED_BODY()
	
public:	
	AUtpAIBaseActor();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	virtual void BeginPlay() override;
	//virtual void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass, AActor* OwningActor) override;
	virtual void ApplyEffectToTarget_Implementation(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass) override;
	
};
