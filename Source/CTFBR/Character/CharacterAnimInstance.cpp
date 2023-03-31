// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "CTFBR/Character/MasterCharacter.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	MasterCharacter = Cast<AMasterCharacter>(TryGetPawnOwner());
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MasterCharacter == nullptr)
	{
		MasterCharacter = Cast<AMasterCharacter>(TryGetPawnOwner());
	}
	if (MasterCharacter == nullptr) return;

	FVector Velocity = MasterCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = MasterCharacter->GetCharacterMovement()->IsFalling();

	bIsAccelerating = MasterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;

	bWeaponEquipped = MasterCharacter->IsWeaponEquipped();

	bIsCrouched = MasterCharacter->bIsCrouched;
}
