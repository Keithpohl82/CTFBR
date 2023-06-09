// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


class AWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CTFBR_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	friend class AMasterCharacter;

	UCombatComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void EquipWeapon(AWeapon* WeaponToEquip);
protected:
	virtual void BeginPlay() override;


private:
	
	UPROPERTY(Replicated)
	class AWeapon* EquippedWeapon;

	class AMasterCharacter* MasterCharacter;

	bool bAiming;


public:	

	
};
