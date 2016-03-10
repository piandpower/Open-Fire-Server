// Free to use

#include "OpenFire.h"
#include "Object.h"
#include "WorldGraph/WorldGraph.h"

Object::Object(int32 objectID, int32 nodeID)
{
	this->objectID = objectID;
	this->nodeID = nodeID;
}

void Object::SetNodeID(int32 nodeID)
{
	this->nodeID = nodeID;
}

void Object::OnUpdate()
{
	auto node = WorldGraph::Instance()->GetNode(this->nodeID);
	UE_LOG(LogTemp, Warning, TEXT("nodeID: %d"), node->id);

	auto nearbyNodes = WorldGraph::Instance()->GetNearbyNodes(this->nodeID);
	for (auto node : nearbyNodes)
	{
		UE_LOG(LogTemp, Warning, TEXT("nearby nodeID: %d"), node->id);
	}
}
