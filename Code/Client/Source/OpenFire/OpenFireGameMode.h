#pragma once

#include "GameFramework/GameMode.h"
#include "OpenFireGameMode.generated.h"

class StrongPointGraph;

UCLASS()
class OPENFIRE_API AOpenFireGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AOpenFireGameMode();

private:
	StrongPointGraph* StrongPointGraphInstance;

public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

private:
	void SpawnStrongPoint(FVector Location);
	void SpawnStrongPointEdge(FVector Location);
};
