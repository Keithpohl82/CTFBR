// Fill out your copyright notice in the Description page of Project Settings.


#include "CapturePoint.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Flag.h"
#include "CTFBR/TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "CTFBR/GameMode/CTFGameMode.h"
#include "CTFBR/PlayerState/CTFBRPlayerState.h"


ACapturePoint::ACapturePoint()
{
 
	PrimaryActorTick.bCanEverTick = true;

	CapturePointBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Capture Point Base"));

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Box"));
	SetRootComponent(OverlapBox);

}


void ACapturePoint::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnFlag();

}

void ACapturePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACapturePoint::SpawnFlag()
{
	CTFGameMode = CTFGameMode == nullptr ? GetWorld()->GetAuthGameMode<ACTFGameMode>() : CTFGameMode;

	UWorld* World = GetWorld();
	
	if (CTFGameMode && StartingFlag && World)
	{
		AFlag* FlagToSpawn = World->SpawnActor<AFlag>(StartingFlag, GetActorTransform());
		FlagToSpawn->SetTeam(Team);
	}
}

