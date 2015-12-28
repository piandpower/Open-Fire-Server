// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Bullet.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UStaticMeshComponent"));
	this->StaticMeshComponent->SetSimulatePhysics(true);

	this->RootComponent = this->StaticMeshComponent;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABullet::SetVelocity(const FVector& Velocity)
{
	StaticMeshComponent->SetPhysicsLinearVelocity(Velocity);
}
