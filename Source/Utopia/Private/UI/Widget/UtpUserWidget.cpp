// Copyright Confused Minds, Ltd. All Rights Reserved.


#include "UI/Widget/UtpUserWidget.h"

void UUtpUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	BP_WidgetControllerSet();
}
