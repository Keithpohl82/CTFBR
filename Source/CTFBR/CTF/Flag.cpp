// Fill out your copyright notice in the Description page of Project Settings.


#include "Flag.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "CapturePoint.h"
#include "Net/UnrealNetwork.h"
#include "CTFBR/TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "CTFBR/GameMode/CTFGameMode.h"
#include "CTFBR/PlayerState/CTFBRPlayerState.h"

// Sets default values
AFlag::AFlag()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	SetReplicateMovement(true);

	FlagMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flag Mesh"));
	SetRootComponent(FlagMesh);

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Box"));
	OverlapBox->SetupAttachment(RootComponent);
}

void AFlag::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

// Called when the game starts or when spawned
void AFlag::BeginPlay()
{
	Super::BeginPlay();
	FlagState = EFlagState::EFS_Home;
	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &AFlag::OnFlagOverlap);
}

void AFlag::OnFlagOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerCharacter = Cast<ATP_ThirdPersonCharacter>(OtherActor);

	if (PlayerCharacter && PlayerCharacter->GetTeam() != Team)
	{
		UE_LOG(LogTemp, Warning, TEXT("Flag Overlapped with Player"));
		AttachFlagToPlayer(PlayerCharacter);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("You can not pick up your own flag."));
	}
}

void AFlag::AttachFlagToPlayer(class ATP_ThirdPersonCharacter* Player)
{

	this->AttachToActor(Player, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	OverlapBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	FlagState = EFlagState::EFS_Stolen; 
}

// Called every frame
void AFlag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlag::SetTeam(ETeam TeamToSet)
{
	Team = TeamToSet;
}


