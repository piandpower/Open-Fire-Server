// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "ShipPart.h"
#include "Types/IFF.h"


// Sets default values
AShipPart::AShipPart()
{
	InitializeDefaults();

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UArrowComponent* pArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("UArrowComponent"));
	pArrow->AttachTo(RootComponent);

	UStaticMeshComponent* pUStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UStaticMeshComponent"));
	pUStaticMeshComponent->AttachTo(pArrow);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Engine/BasicShapes/Sphere"));
	if (VisualAsset.Succeeded())
	{
		pUStaticMeshComponent->SetStaticMesh(VisualAsset.Object);
	}
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
