// Free to use

#include "OpenFire.h"
#include "HeroData.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/WorldGraphNode.h"

void HeroData::OnUpdate()
{
	this->MoveToRandomNode();
}

void HeroData::MoveToRandomNode()
{
	TArray<WorldGraphNode*> nearbyNodes = WorldGraph::Instance()->GetNearbyNodes(this->nodeID);
	if (nearbyNodes.Num() > 0)
	{
		const WorldGraphNode* randomNode = nearbyNodes[FMath::RandRange(0, nearbyNodes.Num() - 1)];

		WorldGraph::Instance()->MoveObject(this->objectID, randomNode->nodeID);
	}
}
