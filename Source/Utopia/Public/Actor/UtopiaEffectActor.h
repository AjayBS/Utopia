// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UtopiaEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class UTOPIA_API AUtopiaEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AUtopiaEffectActor();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

};
