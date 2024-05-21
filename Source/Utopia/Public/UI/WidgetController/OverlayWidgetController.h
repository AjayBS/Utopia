// Copyright Confused Minds, Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/UtpWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVisionChangedSignature, float, NewVision);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxVisionChangedSignature, float, MaxVision);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UTOPIA_API UOverlayWidgetController : public UUtpWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnVisionChangedSignature OnVisionChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxVisionChangedSignature OnMaxVisionChanged;
};
