// Free to use

#include "OpenFire.h"
#include "ObjectData.h"
#include "WorldGraph/WorldGraph.h"

ObjectData::ObjectData(int32 objectID, int32 nodeID)
{
	this->objectID = objectID;
	this->nodeID = nodeID;
}

void ObjectData::SetNodeID(int32 nodeID)
{
	this->nodeID = nodeID;
}

void ObjectData::OnUpdate()
{
	auto node = WorldGraph::Instance()->GetNode(this->nodeID);
	UE_LOG(LogTemp, Warning, TEXT("nodeID: %d"), node->nodeID);

	auto nearbyNodes = WorldGraph::Instance()->GetNearbyNodes(this->nodeID);
	for (auto node : nearbyNodes)
	{
		UE_LOG(LogTemp, Warning, TEXT("nearby nodeID: %d"), node->nodeID);
	}
}
