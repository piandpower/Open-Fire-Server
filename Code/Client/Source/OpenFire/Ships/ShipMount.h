// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "Parts/ShipPart.h"
#include "ShipMount.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OPENFIRE_API UShipMount : public UArrowComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UShipMount();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "ShipPart Class"), Category = ShipMount)
	TSubclassOf<AShipPart> ShipPartClass;
};
