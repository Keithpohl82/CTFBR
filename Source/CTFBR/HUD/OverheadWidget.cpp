// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "CTFBR/PlayerState/CTFBRPlayerState.h"
#include "GameFramework/PlayerState.h"
#include "CTFBR/Character/MasterCharacter.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();

	FString Role;
	switch (LocalRole)
	{
	case ENetRole::ROLE_None:
		Role = FString("None");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("SimulatedProxy");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("AutonomousProxy");
		break;
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_MAX:
		Role = FString("MAX");
		break;
	default:
		break;
	}
	FString LocalRoleString = FString::Printf(TEXT("Local Role: %s"), *Role);
	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	APlayerState* PlayerState = InPawn->GetPlayerState();

	FString PlayerName = FString("");
	if (PlayerState)
	{
		PlayerName = PlayerState->GetPlayerName();
		SetDisplayText(PlayerName);
	}
	
}

void UOverheadWidget::NativeDestruct()
{

	RemoveFromParent();

	Super::NativeDestruct();
}
