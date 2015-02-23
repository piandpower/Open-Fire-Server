#pragma once

#include "Engine/DataTable.h"
#include "ShipData.generated.h"

USTRUCT(BlueprintType)
struct FShipData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	int32 health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	int32 free_mass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float move_speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float rotate_speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float strafe_speed;
};