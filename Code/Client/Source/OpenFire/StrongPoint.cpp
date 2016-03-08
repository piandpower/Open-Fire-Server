// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "StrongPoint.h"


// Sets default values
AStrongPoint::AStrongPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
