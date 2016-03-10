// Free to use

#include "OpenFire.h"
#include "Object.h"

Object::Object(int32 nodeID)
{
	this->nodeID = nodeID;
}

void Object::SetNodeID(int32 nodeID)
{
	this->nodeID = nodeID;
}

void Object::OnUpdate()
{
	UE_LOG(LogTemp, Warning, TEXT("nodeID: %d"), this->nodeID);
}
