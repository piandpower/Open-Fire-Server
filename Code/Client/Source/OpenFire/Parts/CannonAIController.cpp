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

TArray<AShipPart*> ACannonAIController::Search()
{
	static FName SphereOverlapComponentsName(TEXT("CannonSphereOverlapComponents"));
	FCollisionQueryParams Params(SphereOverlapComponentsName, false);
	Params.bTraceAsyncScene = true;
	TArray<FOverlapResult> Overlaps;

	FCollisionObjectQueryParams ObjectParams = FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn);

	this->GetWorld()->OverlapMultiByObjectType(Overlaps, OwnerCannon->GetActorLocation(), FQuat::Identity, ObjectParams, FCollisionShape::MakeSphere(1000000.0f), Params);

	TArray<AShipPart*> ShipParts;
	for (const FOverlapResult& OverlapResult : Overlaps)
	{
		if (OverlapResult.GetActor()->IsA(AShipPart::StaticClass()))
		{
			AShipPart* Target = Cast<AShipPart>(OverlapResult.GetActor());
			if (OwnerCannon->IFF != Target->IFF)
			{
				ShipParts.Add(Target);
			}
		}
	}

	return ShipParts;
}

AShipPart* ACannonAIController::SelectTarget(const TArray<AShipPart*>& Targets)
{
	return Targets[0];
}

void ACannonAIController::Aim(const FVector& TargetLocation)
{

}
