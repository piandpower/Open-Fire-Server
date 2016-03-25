// Free to use

#include "OpenFire.h"
#include "WorkerData.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/StrongPointData.h"

void WorkerData::OnUpdate()
{
	StrongPointData* node = WorldGraph::Instance()->GetNode(this->nodeID);
	if (node->HasBuilding() == false)
	{
		WorldGraph::Instance()->SpawnMine(this->nodeID);
	}
	else
	{
		this->MoveToRandomNode();
	}
}

void WorkerData::MoveToRandomNode()
{
	TArray<StrongPointData*> nearbyNodes = WorldGraph::Instance()->GetNearbyNodes(this->nodeID);
	const StrongPointData* randomNode = nearbyNodes[FMath::RandRange(0, nearbyNodes.Num() - 1)];

	WorldGraph::Instance()->MoveObject(this->objectID, randomNode->nodeID);
}
