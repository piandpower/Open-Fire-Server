#include "OpenFire.h"
#include "StrongPoint.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/WorldGraphNode.h"
#include "Type/ColorType.h"

// Sets default values
AStrongPoint::AStrongPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = this->staticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/StaticMesh/StrongPoint"));
	if (StaticMesh.Succeeded())
	{
		this->staticMeshComponent->SetStaticMesh(StaticMesh.Object);
		this->staticMeshComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));
		this->staticMeshComponent->OnInputTouchBegin.AddDynamic(this, &AStrongPoint::OnInputTouchBegin);
	}
}

void AStrongPoint::Initialize(int32 nodeID, WorldGraphNodeType type)
{
	this->nodeID = nodeID;

	switch (type)
	{
	case WorldGraphNodeType::Grass:
		this->color = ColorType::Grass;
		break;
	case WorldGraphNodeType::Stone:
		this->color = ColorType::Stone;
		break;
	case WorldGraphNodeType::Desert:
		this->color = ColorType::Desert;
		break;
	default:
		this->color = ColorType::Cyan;
		break;
	}
}

void AStrongPoint::BeginPlay()
{
	Super::BeginPlay();

	this->SetMaterial(this->color);
}

void AStrongPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStrongPoint::OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent)
{
	WorldGraph::Instance()->SpawnCastle(this->nodeID);
}

void AStrongPoint::SetMaterial(FLinearColor color)
{
	UMaterialInstanceDynamic* materialInstanceDynamic = UMaterialInstanceDynamic::Create(this->staticMeshComponent->GetMaterial(0), this);
	materialInstanceDynamic->SetVectorParameterValue("Color", color);
	this->staticMeshComponent->SetMaterial(0, materialInstanceDynamic);
}
