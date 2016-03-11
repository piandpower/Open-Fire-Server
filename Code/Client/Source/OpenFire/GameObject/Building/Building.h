#pragma once

#include "GameObject/GameObject.h"
#include "Building.generated.h"

UCLASS()
class OPENFIRE_API ABuilding : public AGameObject
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuilding();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void CheckObjectState();
};
