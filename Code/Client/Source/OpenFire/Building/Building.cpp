#include "OpenFire.h"
#include "Building.h"


// Sets default values
ABuilding::ABuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/StaticMesh/Building"));
	if (StaticMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
		StaticMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Game/Resource/Material/Green"));
	if (Material.Succeeded())
	{
		StaticMeshComponent->SetMaterial(0, Material.Object);
	}
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABuilding::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
