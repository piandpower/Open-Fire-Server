// Free to use

#include "OpenFire.h"
#include "Hero.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/WorldGraphNode.h"
#include "WorldGraph/ObjectData/ObjectData.h"

AHero::AHero()
{
	UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/StaticMesh/Hero"));
	if (StaticMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
		StaticMeshComponent->SetWorldScale3D(FVector(1.0f, 1.0f, 2.0f));
		StaticMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	}
}

void AHero::BeginPlay()
{
	this->targetLocation = this->GetActorLocation();
}

void AHero::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	auto currentLocation = this->GetActorLocation();

	this->SetActorLocation(FMath::VInterpTo(currentLocation, this->targetLocation, deltaSeconds, 1.0f));
}

void AHero::CheckObjectData()
{
	ObjectData* objectData = WorldGraph::Instance()->GetObject(this->objectID);
	WorldGraphNode* node = WorldGraph::Instance()->GetNode(objectData->nodeID);
	this->targetLocation = node->location;
}
