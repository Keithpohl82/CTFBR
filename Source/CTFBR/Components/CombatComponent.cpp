// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "CTFBR/Weapons/Weapon.h"
#include "CTFBR/Character/MasterCharacter.h"


UCombatComponent::UCombatComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCombatComponent::EquipWeapon(AWeapon* WeaponToEquip)
{
	if (MasterCharacter == nullptr || WeaponToEquip == nullptr) return;

	EquippedWeapon = WeaponToEquip;

	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped);

	const USkeletalMeshSocket* HandRSocket = MasterCharacter->GetMesh()->GetSocketByName(FName("RightHandSocket"));

	if (HandRSocket)
	{
		HandRSocket->AttachActor(EquippedWeapon, MasterCharacter->GetMesh());
	}
	EquippedWeapon->SetOwner(MasterCharacter);
	EquippedWeapon->ShowPickupWidget(false);
}

void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

