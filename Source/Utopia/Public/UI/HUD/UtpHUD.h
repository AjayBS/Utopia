// Copyright Confused Minds, Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UtpHUD.generated.h"

class UUtpUserWidget;

/**
 * 
 */
UCLASS()
class UTOPIA_API AUtpHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UUtpUserWidget> OverlayWidget;

protected:
	virtual void BeginPlay();

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUtpUserWidget> OverlayWidgetClass;

};
