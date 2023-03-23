// Fill out your copyright notice in the Description page of Project Settings.


#include "CapturePoint.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Flag.h"
#include "CTFBR/TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "CTFBR/GameMode/CTFGameMode.h"


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

	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &ACapturePoint::OnBoxOverlapPlayer);
}

void ACapturePoint::OnBoxOverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerCharacter = Cast<ATP_ThirdPersonCharacter>(OtherActor);
	if (PlayerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapped with Player"));
		AttachFlagToPlayer(FlagInPlay);
	}
}

void ACapturePoint::AttachFlagToPlayer(class AFlag* FlagToAttach)
{
	//FlagToAttach = FlagInPlay;
	
	if (FlagToAttach->FlagState == EFlagState::EFS_Home)
	{
		UE_LOG(LogTemp, Warning, TEXT("AttachFlag called!!"));
		
		FlagToAttach->AttachToActor(PlayerCharacter, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
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
		FlagInPlay = FlagToSpawn;
	}
}

