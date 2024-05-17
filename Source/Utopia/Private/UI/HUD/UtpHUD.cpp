// Copyright Confused Minds, Ltd. All Rights Reserved.

#include "UI/HUD/UtpHUD.h"

#include "UI/Widget/UtpUserWidget.h"

void AUtpHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
