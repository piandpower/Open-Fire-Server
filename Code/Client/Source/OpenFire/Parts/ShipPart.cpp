// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "ShipPart.h"

// Sets default values
AShipPart::AShipPart()
{
	InitializeDefaults();

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));

	this->RootComponent = this->Body;
}

void AShipPart::InitializeDefaults()
{
	Hp = 0.0f;
	Force = 0.0f;
	Torque = 0.0f;
	Mass = 0.0f;
	IFF = EIFF::Undefined;
}

// Called when the game starts or when spawned
void AShipPart::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AShipPart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
