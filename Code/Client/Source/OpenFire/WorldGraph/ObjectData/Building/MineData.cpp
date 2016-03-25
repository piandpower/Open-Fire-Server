// Free to use

#include "OpenFire.h"
#include "MineData.h"
#include "WorldGraph/WorldGraph.h"

void MineData::OnUpdate()
{
	WorldGraph::Instance()->SpawnGold(this->strongPointID);
}
