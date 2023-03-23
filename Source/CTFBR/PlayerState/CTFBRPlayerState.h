// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CTFBR/TypeClasses/Teams.h"

#include "CTFBRPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class CTFBR_API ACTFBRPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:


private:
	
	UPROPERTY()
	class ATP_ThirdPersonCharacter* Player;

	UPROPERTY()
	class ACTFBRPlayerController* Controller;

	UPROPERTY(EditAnywhere)
	ETeam Team = ETeam::ET_Spectator;

protected:


public:

	FORCEINLINE ETeam GetTeam() const { return Team; }

	void SetTeam(ETeam TeamToSet);
};
