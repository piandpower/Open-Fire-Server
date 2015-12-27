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

	ABullet* Bullet = GetWorld()->SpawnActor<ABullet>(BulletClass, GetActorLocation() + (ForwardVector * 100.0f), Rotation);

	Bullet->SetVelocity(ForwardVector * this->BulletSpeed);
}

void ACannon::RotateBarrel(float DeltaSeconds)
{
	FRotator Rotation = Barrel->RelativeRotation;
	if (Rotation.Pitch > this->TargetPitch)
	{
		Rotation.Pitch -= (DeltaSeconds * this->PitchSpeed);
	}
	else
	{
		Rotation.Pitch += (DeltaSeconds * this->PitchSpeed);
	}

	Barrel->SetRelativeRotation(Rotation);
}

void ACannon::RotateBody(float DeltaSeconds)
{
	FRotator Rotation = Body->RelativeRotation;
	if (Rotation.Yaw > this->TargetYaw)
	{
		Rotation.Yaw -= (DeltaSeconds * this->YawSpeed);
	}
	else
	{
		Rotation.Yaw += (DeltaSeconds * this->YawSpeed);
	}

	Body->SetRelativeRotation(Rotation);
}

const float& ACannon::GetBulletSpeed()
{
	return this->BulletSpeed;
}
