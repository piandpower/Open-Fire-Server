// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Cannon.h"
#include "Bullets/Bullet.h"
#include "Parts/CannonAIController.h"

ACannon::ACannon()
{
	AIControllerClass = ACannonAIController::StaticClass();
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
}

void ACannon::Fire()
{
	FRotator ActorRotation = GetActorRotation();

	ABullet* Bullet = GetWorld()->SpawnActor<ABullet>(GetActorLocation() + (ActorRotation.Vector() * 100.0f), ActorRotation);
	Bullet->AddImpulse(InitialVelocity);
}
