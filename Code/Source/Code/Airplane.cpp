// Fill out your copyright notice in the Description page of Project Settings.

#include "Code.h"
#include "Airplane.h"


// Sets default values
AAirplane::AAirplane()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	RootComponent = StaticMeshComponent;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Game/Resources/Airplanes/OmegaFighter/SM_OmegaFighter"));
	if (VisualAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(VisualAsset.Object);
	}
}

// Called when the game starts or when spawned
void AAirplane::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAirplane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAirplane::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

