// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Bullet.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Proximity Sphere"));
	RootComponent = SphereComponent;
	SphereComponent->SetSphereRadius(20.0f);
	SphereComponent->SetSimulatePhysics(true);

	UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UStaticMeshComponent"));
	StaticMeshComponent->AttachTo(SphereComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Engine/BasicShapes/Sphere"));
	if (VisualAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(VisualAsset.Object);
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
	SphereComponent->AddImpulse(Impulse);
}
