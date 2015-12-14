// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Cannon.h"
#include "Bullets/Bullet.h"

ACannon::ACannon()
{
	this->Barrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));
	this->Barrel->AttachTo(Body);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Engine/BasicShapes/Cube"));
	if (VisualAsset.Succeeded())
	{
		this->Barrel->SetStaticMesh(VisualAsset.Object);
		this->Barrel->SetRelativeScale3D(FVector(2.0f, 0.3f, 0.3f));
		this->Barrel->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	}
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
