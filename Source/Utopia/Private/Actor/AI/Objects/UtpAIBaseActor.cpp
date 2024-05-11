// // Copyright Confused Minds, Ltd. All Rights Reserved.


#include "Actor/AI/Objects/UtpAIBaseActor.h"

// Sets default values
AUtpAIBaseActor::AUtpAIBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AUtpAIBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}
