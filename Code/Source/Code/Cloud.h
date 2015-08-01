// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Cloud.generated.h"

UCLASS()
class CODE_API ACloud : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACloud();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
