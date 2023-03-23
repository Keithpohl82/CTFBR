// Fill out your copyright notice in the Description page of Project Settings.


#include "Flag.h"
#include "Components/StaticMeshComponent.h"
#include "CapturePoint.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AFlag::AFlag()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	SetReplicateMovement(true);

	FlagMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flag Mesh"));
}

void AFlag::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

// Called when the game starts or when spawned
void AFlag::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

