#pragma once

#include "Engine/DataTable.h"
#include "ComponentData.generated.h"

USTRUCT(BlueprintType)
struct FComponentData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	FString type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	FString weapon_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	int32 mass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	int32 damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float fire_delay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float bullet_speed;
};