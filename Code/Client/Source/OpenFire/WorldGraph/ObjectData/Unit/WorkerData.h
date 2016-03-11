// Free to use

#pragma once

#include "WorldGraph/ObjectData/ObjectData.h"

class OPENFIRE_API WorkerData : public ObjectData
{
public:
	virtual void OnUpdate() override;

private:
	void MoveToRandomNode();
};
