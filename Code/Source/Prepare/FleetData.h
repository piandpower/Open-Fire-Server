#pragma once

#include "Engine/DataTable.h"
#include "FleetData.generated.h"

USTRUCT(BlueprintType)
struct FFleetData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float posX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float posY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float posZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float rotX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float rotY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipData)
	float rotZ;
};