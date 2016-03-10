// Free to use

#include "OpenFire.h"
#include "BuildingData.h"
#include "WorldGraph/WorldGraph.h"

void BuildingData::OnUpdate()
{
	WorldGraph::Instance()->SpawnWorker(this->nodeID);
}
