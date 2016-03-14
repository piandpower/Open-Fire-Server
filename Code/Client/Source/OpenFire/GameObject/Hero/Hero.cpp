// Free to use

#include "OpenFire.h"
#include "Hero.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/WorldGraphNode.h"
#include "WorldGraph/ObjectData/ObjectData.h"

AHero::AHero()
{
	USkeletalMeshComponent* skeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = skeletalMeshComponent;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("/Game/Resource/Hero/SM_Hero"));
	if (skeletalMesh.Succeeded())
	{
		skeletalMeshComponent->SetSkeletalMesh(skeletalMesh.Object);
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
