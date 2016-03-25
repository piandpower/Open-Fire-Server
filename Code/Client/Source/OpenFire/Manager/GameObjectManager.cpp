#include "OpenFire.h"
#include "GameObjectManager.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/StrongPointData.h"
#include "GameObject/StrongPoint/StrongPoint.h"
#include "WorldGraph/ObjectData/ObjectData.h"

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

void GameObjectManager::SpawnObject(int32 objectID, int32 strongPointID, ObjectDataType type)
{

}

void GameObjectManager::UpdateStrongPoints()
{
	for (const StrongPointData* strongPointData : WorldGraph::Instance()->GetStrongPointDatas())
	{
		if (this->strongPointMap.Find(strongPointData->strongPointID) == nullptr)
		{
			this->SpawnStrongPoint(strongPointData->strongPointID, strongPointData->location);
		}
	}
}

void GameObjectManager::UpdateGameObjects()
{
	for (const ObjectData* objectData : WorldGraph::Instance()->GetObjectDatas())
	{
		if (this->gameObjectMap.Find(objectData->objectID) == nullptr)
		{
			this->SpawnObject(objectData->objectID, objectData->strongPointID, objectData->type);
		}
	}
}
