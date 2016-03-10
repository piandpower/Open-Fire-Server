// Free to use

#include "OpenFire.h"
#include "WorkerData.h"
#include "WorldGraph/WorldGraph.h"

void WorkerData::OnUpdate()
{
	UE_LOG(LogTemp, Warning, TEXT("Worker nodeID: %d"), this->nodeID);

	TArray<WorldGraph::Node*> nearbyNodes = WorldGraph::Instance()->GetNearbyNodes(this->nodeID);
	const WorldGraph::Node* randomNode = nearbyNodes[FMath::RandRange(0, nearbyNodes.Num() - 1)];

	UE_LOG(LogTemp, Warning, TEXT("Worker random nodeID: %d"), randomNode->nodeID);
}
