// Copyright Confused Minds, Ltd. All Rights Reserved.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/UtopiaAttributeSet.h"
#include "GameplayEffectTypes.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UUtopiaAttributeSet* UtpAttributeSet = CastChecked<UUtopiaAttributeSet>(AttributeSet);

	OnVisionChanged.Broadcast(UtpAttributeSet->GetVision());
	OnMaxVisionChanged.Broadcast(UtpAttributeSet->GetMaxVision());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UUtopiaAttributeSet* UtpAttributeSet = CastChecked<UUtopiaAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		UtpAttributeSet->GetVisionAttribute()).AddUObject(
		this, &UOverlayWidgetController::VisionChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		UtpAttributeSet->GetMaxVisionAttribute()).AddUObject(
			this, &UOverlayWidgetController::MaxVisionChanged);
}

void UOverlayWidgetController::VisionChanged(const FOnAttributeChangeData& Data) const
{
	OnVisionChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxVisionChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxVisionChanged.Broadcast(Data.NewValue);
}
