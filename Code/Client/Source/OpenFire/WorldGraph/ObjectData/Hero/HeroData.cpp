// Free to use

#include "OpenFire.h"
#include "HeroData.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/StrongPointData.h"

void HeroData::OnUpdate()
{
	this->MoveToRandomNode();
}

void HeroData::MoveToRandomNode()
{
	TArray<StrongPointData*> nearbyNodes = WorldGraph::Instance()->GetNearbyNodes(this->strongPointID);
	if (nearbyNodes.Num() > 0)
	{
		const StrongPointData* randomNode = nearbyNodes[FMath::RandRange(0, nearbyNodes.Num() - 1)];

		WorldGraph::Instance()->MoveObject(this->objectID, randomNode->strongPointID);
	}
}
