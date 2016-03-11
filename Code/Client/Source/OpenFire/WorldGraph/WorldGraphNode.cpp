// Free to use

#include "OpenFire.h"
#include "WorldGraphNode.h"

TMap<int32, ObjectData*> WorldGraphNode::GetObjects()
{
	return this->objectDataMap;
}

void WorldGraphNode::AddObject(int32 objectID, ObjectData* objectData)
{
	this->objectDataMap.Add(objectID, objectData);
}

void WorldGraphNode::RemoveObject(int32 objectID)
{
	this->objectDataMap.Remove(objectID);
}
