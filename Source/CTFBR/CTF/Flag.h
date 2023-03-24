// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTFBR/TypeClasses/Teams.h"

#include "Flag.generated.h"

UENUM(BlueprintType)
enum class EFlagState :uint8
{
	EFS_Home UMETA(DisplayName = "Home"),
	EFS_Dropped UMETA(DisplayName = "Dropped"),
	EFS_Stolen UMETA(DisplayName = "Stolen"),

	EFS_DefaultMAX UMETA(DisplayName = "DefaultMAX"),
};


UCLASS()
class CTFBR_API AFlag : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlag();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY()
	EFlagState FlagState;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnFlagOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void AttachFlagToPlayer(class ATP_ThirdPersonCharacter* Player);


private:

	UPROPERTY(VisibleAnywhere)
	ETeam Team;

	class ATP_ThirdPersonCharacter* PlayerCharacter;

	class ACTFGameMode* CTFGameMode;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* FlagMesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* OverlapBox;

	ETeam GetTeam();

	void SetTeam(ETeam TeamToSet);
};
