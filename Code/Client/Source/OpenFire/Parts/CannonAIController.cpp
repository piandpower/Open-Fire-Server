// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "CannonAIController.h"
#include "Parts/ShipPart.h"
#include "Parts/Cannon.h"

void ACannonAIController::Possess(APawn* InPawn)
{
	AAIController::Possess(InPawn);

	OwnerCannon = Cast<ACannon>(InPawn);
}

void ACannonAIController::Search(AActor*& OutActor)
{
	static FName SphereOverlapComponentsName(TEXT("CannonSphereOverlapComponents"));
	FCollisionQueryParams Params(SphereOverlapComponentsName, false);
	Params.bTraceAsyncScene = true;
	TArray<FOverlapResult> Overlaps;

	FCollisionObjectQueryParams ObjectParams = FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn);

	this->GetWorld()->OverlapMultiByObjectType(Overlaps, OwnerCannon->GetActorLocation(), FQuat::Identity, ObjectParams, FCollisionShape::MakeSphere(1000000.0f), Params);

	for (int32 OverlapIdx = 0; OverlapIdx < Overlaps.Num(); ++OverlapIdx)
	{
		FOverlapResult const& O = Overlaps[OverlapIdx];
		if (O.GetActor()->IsA(AShipPart::StaticClass()))
		{
			OutActor = O.GetActor();
			break;
		}
	}
}
