// Fill out your copyright notice in the Description page of Project Settings.


#include "CapturePoint.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Flag.h"

// Sets default values
ACapturePoint::ACapturePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapturePointBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Capture Point Base"));
	SetRootComponent(CapturePointBase);

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Box"));
	OverlapBox->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACapturePoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapturePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

