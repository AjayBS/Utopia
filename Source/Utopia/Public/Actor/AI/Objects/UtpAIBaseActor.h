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
	virtual void BeginPlay() override;


};
