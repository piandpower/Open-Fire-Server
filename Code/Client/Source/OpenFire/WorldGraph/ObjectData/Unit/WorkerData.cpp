// Free to use

#include "OpenFire.h"
#include "WorkerData.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/StrongPointData.h"

void WorkerData::OnUpdate()
{
	StrongPointData* node = WorldGraph::Instance()->GetNode(this->strongPointID);
	if (node->HasBuilding() == false)
	{
		WorldGraph::Instance()->SpawnMine(this->strongPointID);
	}
	else
	{
		this->MoveToRandomNode();
	}
}

void WorkerData::MoveToRandomNode()
{
	TArray<StrongPointData*> nearbyNodes = WorldGraph::Instance()->GetNearbyNodes(this->strongPointID);
	const StrongPointData* randomNode = nearbyNodes[FMath::RandRange(0, nearbyNodes.Num() - 1)];

	WorldGraph::Instance()->MoveObject(this->objectID, randomNode->strongPointID);
}
