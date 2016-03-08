// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "StrongPoint.h"

// Sets default values
AStrongPoint::AStrongPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));

	UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	StaticMeshComponent->AttachTo(this->RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/StaticMesh/Cube"));
	if (StaticMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Game/Resource/Material/Gray"));
	if (Material.Succeeded())
	{
		StaticMeshComponent->SetMaterial(0, Material.Object);
	}
}

// Called when the game starts or when spawned
void AStrongPoint::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStrongPoint::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
