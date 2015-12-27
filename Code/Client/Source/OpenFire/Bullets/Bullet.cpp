// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Bullet.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UStaticMeshComponent"));
	this->StaticMeshComponent->SetSimulatePhysics(true);
	this->StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);


//, CollisionEnabled = QueryOnly, ObjectTypeName = "WorldDynamic", CustomResponses = ((Channel = "WorldStatic", Response = ECR_Overlap), (Channel = "Pawn", Response = ECR_Overlap), (Channel = "Visibility", Response = ECR_Ignore), (Channel = "WorldDynamic", Response = ECR_Overlap), (Channel = "Camera", Response = ECR_Overlap), (Channel = "PhysicsBody", Response = ECR_Overlap), (Channel = "Vehicle", Response = ECR_Overlap), (Channel = "Destructible", Response = ECR_Overlap)), HelpMessage = "WorldDynamic object that is used for trigger. All other channels will be set to default.", bCanModify = False)

	this->RootComponent = this->StaticMeshComponent;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABullet::SetVelocity(const FVector& Velocity)
{
	StaticMeshComponent->SetPhysicsLinearVelocity(Velocity);
}
