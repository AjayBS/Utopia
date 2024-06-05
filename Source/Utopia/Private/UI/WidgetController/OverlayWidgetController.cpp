// Copyright Confused Minds, Ltd. All Rights Reserved.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/UtopiaAttributeSet.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystem/UtopiaAbilitySystemComponent.h"

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

	Cast<UUtopiaAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}

void UOverlayWidgetController::VisionChanged(const FOnAttributeChangeData& Data) const
{
	OnVisionChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxVisionChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxVisionChanged.Broadcast(Data.NewValue);
}
