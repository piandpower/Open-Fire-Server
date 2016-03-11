// Free to use

#include "OpenFire.h"
#include "WorkerData.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/WorldGraphNode.h"

void WorkerData::OnUpdate()
{
	TArray<WorldGraphNode*> nearbyNodes = WorldGraph::Instance()->GetNearbyNodes(this->nodeID);
	const WorldGraphNode* randomNode = nearbyNodes[FMath::RandRange(0, nearbyNodes.Num() - 1)];

	WorldGraph::Instance()->MoveObject(this->objectID, randomNode->nodeID);
}
