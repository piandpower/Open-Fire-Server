// Free to use

#pragma once

#include "GameObject/GameObject.h"
#include "Hero.generated.h"

UCLASS()
class OPENFIRE_API AHero : public AGameObject
{
	GENERATED_BODY()
private:
	FVector targetLocation = FVector::ZeroVector;

public:
	AHero();

	virtual void BeginPlay() override;

	virtual void Tick(float deltaSeconds) override;

	virtual void CheckObjectData() override;
};
