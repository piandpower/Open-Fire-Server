#include "OpenFire.h"
#include "GameObjectManager.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/StrongPointData.h"
#include "GameObject/StrongPoint/StrongPoint.h"

void GameObjectManager::Initialize(UWorld* world)
{
	this->world = world;
}

void GameObjectManager::OnUpdate()
{
	this->UpdateStrongPoints();
}

void GameObjectManager::SpawnStrongPoint(int32 nodeID, FVector location)
{
	AStrongPoint* strongPoint = this->world->SpawnActor<AStrongPoint>(location, FRotator::ZeroRotator);
	strongPoint->Initialize(nodeID);

	this->strongPointMap.Add(nodeID, strongPoint);
}

void GameObjectManager::UpdateStrongPoints()
{
	for (const StrongPointData* strongPointData : WorldGraph::Instance()->GetStrongPointDatas())
	{
		if (this->strongPointMap.Find(strongPointData->nodeID) == nullptr)
		{
			this->SpawnStrongPoint(strongPointData->nodeID, strongPointData->location);
		}
	}
}
