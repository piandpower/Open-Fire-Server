#pragma once

#include "Framework/Singleton.h"

class ANode;
class AGameObject;

class OPENFIRE_API GameObjectManager : public Singleton<GameObjectManager>
{
private:
	UWorld* world = nullptr;

	TArray<ANode*> nodes;
	TArray<AGameObject*> gameObjects;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

private:
	void SpawnNode(int32 nodeID, FVector location);
};
