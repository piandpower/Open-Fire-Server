// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObject/GameObject.h"
#include "StrongPoint.generated.h"

class UStaticMeshComponent;
enum class WorldGraphNodeType;

UCLASS()
class OPENFIRE_API AStrongPoint : public AGameObject
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* staticMeshComponent = nullptr;

	int32 nodeID = -1;
	FLinearColor color = FLinearColor::Red;

public:
	// Sets default values for this actor's properties
	AStrongPoint();

	void Initialize(int32 nodeID, WorldGraphNodeType type);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(Category = Default)
	void OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent);

private:
	void SetMaterial(FLinearColor color);
};
