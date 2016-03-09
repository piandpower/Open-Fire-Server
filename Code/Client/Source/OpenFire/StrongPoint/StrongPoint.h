// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "StrongPoint.generated.h"

UCLASS()
class OPENFIRE_API AStrongPoint : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AStrongPoint();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(Category = Default)
	void OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent);
};
