// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Ship.generated.h"

class AShipPart;
class UShipMount;

UCLASS()
class OPENFIRE_API AShip : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void AttachPart(AShipPart* pAShipPart, FRotator rotation, FVector location);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ship)
	UStaticMeshComponent* Hull = nullptr;

private:
	TArray<AShipPart*> ShipParts;

	float Hp = 0.0f;
	float Force = 0.0f;
	float Torque = 0.0f;
	float Mass = 0.0f;
};
