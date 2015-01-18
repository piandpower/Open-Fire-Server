#pragma once

#include "Engine/DataTable.h"
#include "ShipComponentDataTable.generated.h"

USTRUCT(BlueprintType)
struct FShipComponentDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	FString ship_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	FString type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	float position_x;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	float position_y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	float position_z;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	float rotation_x;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	float rotation_y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	float rotation_z;
};