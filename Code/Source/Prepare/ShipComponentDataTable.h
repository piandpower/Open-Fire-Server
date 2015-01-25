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
	int32 index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	FString type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipComponentData)
	FString size;
};