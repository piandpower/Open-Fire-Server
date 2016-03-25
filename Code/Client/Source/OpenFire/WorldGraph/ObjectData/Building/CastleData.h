// Free to use

#pragma once

#include "WorldGraph/ObjectData/Building/BuildingData.h"

class OPENFIRE_API CastleData : public BuildingData
{
private:
	int32 currentWorkerCount = 0;

public:
	CastleData();

	virtual void OnUpdate() override;

private:
	bool CanSpawnWorker();
	void SpawnWorker();
};
