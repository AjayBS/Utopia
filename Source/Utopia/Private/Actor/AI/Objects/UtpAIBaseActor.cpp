// Copyright Confused Minds, Ltd. All Rights Reserved.


#include "Actor/AI/Objects/UtpAIBaseActor.h"


#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

AUtpAIBaseActor::AUtpAIBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

// Called when the game starts or when spawned
void AUtpAIBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUtpAIBaseActor::ApplyEffectToTarget_Implementation(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if (IsValid(TargetASC))
	{
		check(GameplayEffectClass);
		FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
		EffectContextHandle.AddSourceObject(this);
		const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);
		TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}
