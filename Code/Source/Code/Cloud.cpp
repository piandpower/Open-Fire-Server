// Fill out your copyright notice in the Description page of Project Settings.

#include "Code.h"
#include "Cloud.h"


// Sets default values
ACloud::ACloud()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UParticleSystemComponent* ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("RootComponent"));
	RootComponent = ParticleSystemComponent;
	static ConstructorHelpers::FObjectFinder<UParticleSystem> VisualAsset(TEXT("/Game/Resources/Clouds/PS_Cloud"));
	if (VisualAsset.Succeeded())
	{
		ParticleSystemComponent->SetTemplate(VisualAsset.Object);
	}
}

// Called when the game starts or when spawned
void ACloud::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

