// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "StrongPointEdge.h"


// Sets default values
AStrongPointEdge::AStrongPointEdge()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AStrongPointEdge::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStrongPointEdge::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
