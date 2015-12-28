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

void ACannonAIController::Aim(AShipPart* Target)
{
	FVector TargetVector = Target->GetActorLocation() - this->OwnerCannon->GetActorLocation();

	this->AimYaw(TargetVector);
	this->AimPitch(TargetVector);
}

void ACannonAIController::AimYaw(const FVector& TargetVector)
{
	const FRotator LookRotation = TargetVector.Rotation();

	this->OwnerCannon->SetBodyTargetYaw(LookRotation.Yaw);
}

void ACannonAIController::AimPitch(const FVector& TargetVector)
{
	const float TargetDistance = sqrt(pow(TargetVector.X, 2) + pow(TargetVector.Y, 2));
	const float TargetHeight = TargetVector.Z;
	const float PitchAngle = this->GetPitchAngle(OwnerCannon->GetBulletSpeed(), TargetDistance, TargetHeight);

	this->OwnerCannon->SetBarrelTargetPitch(PitchAngle);
}

float ACannonAIController::GetPitchAngle(const float& Speed, const float& TargetDistance, const float& TargetHeight)
{
	const float Gravity = -GetWorld()->GetGravityZ();

	float InRoot = pow(Speed, 4) - (Gravity * ((Gravity * pow(TargetDistance, 2)) + (2 * TargetHeight * pow(Speed, 2))));
	if (InRoot < 0.0f)
	{
		// NOTE: out of range
		return 45.0f;
	}

	float SqrtRoot = sqrt(InRoot);

	float TangetAngleDegrees = ((pow(Speed, 2) - SqrtRoot) / (Gravity * TargetDistance));
	return FMath::RadiansToDegrees(atan(TangetAngleDegrees));
}
