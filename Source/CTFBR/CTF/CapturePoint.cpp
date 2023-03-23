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
	SetRootComponent(CapturePointBase);

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Box"));
	OverlapBox->SetupAttachment(RootComponent);

}


void ACapturePoint::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnFlag();

	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &ACapturePoint::OnBoxOverlapPlayer);
}

void ACapturePoint::OnBoxOverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATP_ThirdPersonCharacter* Player = Cast<ATP_ThirdPersonCharacter>(OtherActor);
	if (Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapped with Player"));
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
		
	}
}

