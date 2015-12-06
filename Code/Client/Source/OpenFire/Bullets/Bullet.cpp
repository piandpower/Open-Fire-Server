// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Bullet.h"


// Sets default values
ABullet::ABullet()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    pUSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Proximity Sphere"));
    pUSphereComponent->AttachTo(RootComponent);
    pUSphereComponent->SetSphereRadius(50.0f);
    pUSphereComponent->SetSimulatePhysics(true);

    UStaticMeshComponent* pUStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UStaticMeshComponent"));
    pUStaticMeshComponent->AttachTo(pUSphereComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Engine/BasicShapes/Sphere"));
    if (VisualAsset.Succeeded())
    {
        pUStaticMeshComponent->SetStaticMesh(VisualAsset.Object);
    }
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

void ABullet::AddImpulse(const FVector& Impulse)
{
    pUSphereComponent->AddImpulse(Impulse);
}