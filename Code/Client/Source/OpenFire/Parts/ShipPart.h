// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ShipPart.generated.h"

UENUM(BlueprintType)
enum class EIFF: uint8
{
	Undefined,
	Friend,
	Foe
};

UCLASS()
class OPENFIRE_API AShipPart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShipPart();

private:
	void InitializeDefaults();

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

public:
	float Hp;
	float Force;
	float Torque;
	float Mass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
	EIFF IFF;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
	UStaticMeshComponent* Body = nullptr;
};
