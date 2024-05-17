// Copyright Confused Minds, Ltd. All Rights Reserved.


#include "UI/WidgetController/UtpWidgetController.h"

void UUtpWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}
