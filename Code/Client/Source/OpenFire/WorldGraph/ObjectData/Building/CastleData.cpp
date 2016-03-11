// Free to use

#include "OpenFire.h"
#include "CastleData.h"
#include "WorldGraph/WorldGraph.h"

const int32 maxWorkerCount = 3;

void CastleData::OnUpdate()
{
	if (this->CanSpawnWorker() == true)
	{
		this->SpawnWorker();
	}
}

bool CastleData::CanSpawnWorker()
{
	if (this->currentWorkerCount < maxWorkerCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CastleData::SpawnWorker()
{
	++this->currentWorkerCount;
	WorldGraph::Instance()->SpawnWorker(this->nodeID);
}
