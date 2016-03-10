// Free to use

#pragma once

#include "GameFramework/Actor.h"
#include "GameObject.generated.h"

UCLASS()
class OPENFIRE_API AGameObject : public AActor
{
	GENERATED_BODY()

private:
	int32 objectID = -1;

	float accumulatedSeconds = 0.0f;

public:
	// Sets default values for this actor's properties
	AGameObject();

	void Initialize(int32 objectID);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void CheckObjectState();
};
