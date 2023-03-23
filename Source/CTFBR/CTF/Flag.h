// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* FlagMesh;
};
