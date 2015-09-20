// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Ship.h"
#include "Parts/ShipPart.h"


// Sets default values
AShip::AShip()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    UStaticMeshComponent* pUStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UStaticMeshComponent"));
    pUStaticMeshComponent->AttachTo(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Engine/BasicShapes/Cube"));
    if (SphereVisualAsset.Succeeded())
    {
        pUStaticMeshComponent->SetStaticMesh(SphereVisualAsset.Object);
        pUStaticMeshComponent->SetRelativeScale3D(FVector(3.0f, 3.0f, 1.0f));
    }
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AShip::AttachPart(AShipPart* pAShipPart, FRotator rotation, FVector location)
{
    Hp      += pAShipPart->Hp;
    Force   += pAShipPart->Force;
    Torque  += pAShipPart->Torque;
    Mass    += pAShipPart->Mass;

    ShipParts.Add(pAShipPart);

    pAShipPart->SetActorRotation(rotation);
    pAShipPart->SetActorLocation(location);
    pAShipPart->AttachRootComponentToActor(this);
}
