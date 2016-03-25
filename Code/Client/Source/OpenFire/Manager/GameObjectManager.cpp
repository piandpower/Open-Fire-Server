#include "OpenFire.h"
#include "GameObjectManager.h"
#include "GameObject/StrongPoint/StrongPoint.h"

void GameObjectManager::Initialize(UWorld* world)
{
	this->world = world;
}

void GameObjectManager::OnUpdate()
{

}

void GameObjectManager::SpawnStrongPoint(int32 nodeID, FVector location)
{
	AStrongPoint* strongPoint = this->world->SpawnActor<AStrongPoint>(location, FRotator::ZeroRotator);
	strongPoint->Initialize(nodeID);

	this->strongPointMap.Add(nodeID, strongPoint);
}
