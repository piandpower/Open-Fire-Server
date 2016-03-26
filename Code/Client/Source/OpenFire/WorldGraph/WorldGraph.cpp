#include "OpenFire.h"
#include "WorldGraph.h"
#include "Network/RestClient.h"
#include "Network/DTO/StrongPointDTO.h"
#include "Type/MissionType.h"
#include "GameObject/Building/Mine.h"
#include "WorldGraph/ObjectData/Building/MineData.h"
#include "GameObject/Building/Farm.h"
#include "WorldGraph/ObjectData/Building/FarmData.h"
#include "GameObject/Building/Castle.h"
#include "WorldGraph/ObjectData/Building/CastleData.h"
#include "GameObject/Unit/Worker.h"
#include "WorldGraph/ObjectData/Unit/WorkerData.h"
#include "GameObject/Hero/Hero.h"
#include "WorldGraph/ObjectData/Hero/HeroData.h"
#include "GameObject/Resource/Gold.h"
#include "WorldGraph/ObjectData/Resource/GoldData.h"

void WorldGraph::Initialize(UWorld* world)
{
	this->world = world;
	this->strongPointDatas.Empty();
	this->objectDatas.Empty();
}

void WorldGraph::OnUpdate()
{
	URestClient::Instance()->Get("http://localhost:5000/apis/strongpoints", "", [this](const FString& string)
	{
		StrongPointDTO strongPointDTO = StrongPointDTO(string);

		for (const StrongPointDTO::Data& data : strongPointDTO.datas)
		{
			this->InsertUpdateStrongPointData(data.strongPointID, data.location);
		}
	});
}

ObjectData* WorldGraph::GetObject(int32 objectID)
{
	for (ObjectData* object : this->objectDatas)
	{
		if (object->objectID == objectID)
		{
			return object;
		}
	}

	return nullptr;
}

StrongPointData* WorldGraph::GetNode(int32 nodeID)
{
	for (StrongPointData& node : this->strongPointDatas)
	{
		if (node.strongPointID == nodeID)
		{
			return &node;
		}
	}

	return nullptr;
}

const TArray<StrongPointData>& WorldGraph::GetStrongPointDatas()
{
	return this->strongPointDatas;
}

const TArray<ObjectData*> WorldGraph::GetObjectDatas()
{
	return this->objectDatas;
}

void WorldGraph::InsertUpdateStrongPointData(int32 id, FVector location)
{
	for (StrongPointData& strongpoint : this->strongPointDatas)
	{
		if (strongpoint.strongPointID == id)
		{
			strongpoint.location = location;
			return;
		}
	}

	this->strongPointDatas.Add(StrongPointData(id, location));
}

void WorldGraph::AddObject(int32 objectID, int32 strongPointID, ObjectDataType type)
{
	ObjectData* objectData = new ObjectData();
	objectData->Initialize(objectID, strongPointID, type);
	this->objectDatas.Add(objectData);
}
