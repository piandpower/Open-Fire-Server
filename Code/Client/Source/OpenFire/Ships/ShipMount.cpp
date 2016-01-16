// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "ShipMount.h"


// Sets default values for this component's properties
UShipMount::UShipMount()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UShipMount::BeginPlay()
{
	Super::BeginPlay();

	AShipPart* ShipPart = GetWorld()->SpawnActor<AShipPart>(ShipPartClass);
	ShipPart->AttachRootComponentTo(this);
}


// Called every frame
void UShipMount::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
