// Copyright Confused Minds, Ltd. All Rights Reserved.

#include "UI/HUD/UtpHUD.h"

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "UI/Widget/UtpUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AUtpHUD::GetOverlayWidgetController()
{
	return OverlayWidgetController;
}

UOverlayWidgetController* AUtpHUD::SetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}

	return OverlayWidgetController;
}

void AUtpHUD::InitOverlay(APlayerController* PC, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay widget class uninitialized. Please fill out BP_UtpHUD data"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay widget controller class uninitialized. Please fill out BP_UtpHUD data"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UUtpUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, ASC, AS);
	
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController();
	if (WidgetController == nullptr)
	{
		WidgetController = SetOverlayWidgetController(WidgetControllerParams);
	}

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();

	Widget->AddToViewport();
}
