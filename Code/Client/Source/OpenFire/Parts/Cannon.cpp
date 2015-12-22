// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Cannon.h"
#include "Bullets/Bullet.h"

ACannon::ACannon()
{
	this->Barrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));
	this->Barrel->AttachTo(Body);
}

void ACannon::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ReloadTime += DeltaSeconds;
	if (ReloadTime >= FireDelay)
	{
		ReloadTime -= FireDelay;
		Fire();
	}

	this->RotateBarrel(DeltaSeconds);
	this->RotateBody(DeltaSeconds);
}

void ACannon::SetBarrelTargetPitch(const float& TargetPitch)
{
	this->TargetPitch = TargetPitch;
}

void ACannon::SetBodyTargetYaw(const float& TargetYaw)
{
	this->TargetYaw = TargetYaw;
}

void ACannon::Fire()
{
	FVector ForwardVector = Barrel->GetForwardVector();
	FRotator Rotation = Barrel->GetComponentRotation();

	ABullet* Bullet = GetWorld()->SpawnActor<ABullet>(GetActorLocation() + (ForwardVector * 100.0f), Rotation);
	Bullet->AddImpulse(ForwardVector * this->BulletSpeed);
}

void ACannon::RotateBarrel(float DeltaSeconds)
{
	FRotator CurrentRotation = Barrel->RelativeRotation;
	if (CurrentRotation.Pitch > this->TargetPitch)
	{
		CurrentRotation.Pitch -= (DeltaSeconds * this->PitchSpeed);
	}
	else
	{
		CurrentRotation.Pitch += (DeltaSeconds * this->PitchSpeed);
	}

	Barrel->SetRelativeLocationAndRotation(Barrel->RelativeLocation, CurrentRotation);
}

void ACannon::RotateBody(float DeltaSeconds)
{
	FRotator CurrentRotation = Body->RelativeRotation;
	if (CurrentRotation.Yaw > this->TargetYaw)
	{
		CurrentRotation.Yaw -= (DeltaSeconds * this->YawSpeed);
	}
	else
	{
		CurrentRotation.Yaw += (DeltaSeconds * this->YawSpeed);
	}

	Body->SetRelativeLocationAndRotation(Body->RelativeLocation, CurrentRotation);
}
