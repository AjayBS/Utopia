// Copyright Confused Minds, Ltd. All Rights Reserved.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/UtopiaAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UUtopiaAttributeSet* UtpAttributeSet = CastChecked<UUtopiaAttributeSet>(AttributeSet);

	OnVisionChanged.Broadcast(UtpAttributeSet->GetVision());
	OnMaxVisionChanged.Broadcast(UtpAttributeSet->GetMaxVision());
}
