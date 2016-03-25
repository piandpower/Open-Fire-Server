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

public:
	AStrongPoint();

	void Initialize(int32 nodeID);

	UFUNCTION(Category = Default)
	void OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent);
};
