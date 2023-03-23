// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTFBR/TypeClasses/Teams.h"

#include "CapturePoint.generated.h"

UCLASS()
class CTFBR_API ACapturePoint : public AActor
{
	GENERATED_BODY()
	
public:	

	ACapturePoint();

	virtual void Tick(float DeltaTime) override;

	void SpawnFlag();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnBoxOverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void AttachFlagToPlayer(class AFlag* FlagToAttach);


private:

	UPROPERTY(EditAnywhere)
	ETeam Team;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AFlag> StartingFlag;

	AFlag* FlagInPlay;

	class ATP_ThirdPersonCharacter* PlayerCharacter;
	
	class ACTFGameMode* CTFGameMode;


public:	
	
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* OverlapBox;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* CapturePointBase;

};
