// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "ShipHelper.h"
#include "JsonHelper.h"
#include "Ships/Ship.h"
#include "Parts/ShipPart.h"

AShip* ShipHelper::CreateShip(UWorld* pWorld, const TSharedPtr<FJsonValue>& pShipJsonValue)
{
    FVector Location = JsonHelper::GetVector(pShipJsonValue->AsObject()->GetObjectField("Location"));
    FRotator Rotation = JsonHelper::GetRotator(pShipJsonValue->AsObject()->GetObjectField("Rotation"));

    AShip* pShip = pWorld->SpawnActor<AShip>(Location, Rotation);

    AttachPartsByJson(pWorld, pShip, pShipJsonValue->AsObject()->GetObjectField("Parts"));

    return pShip;
}

void ShipHelper::AttachPartsByJson(UWorld* pWorld, AShip* pShip, const TSharedPtr<FJsonObject>& pShipPartsJsnoObject)
{
    for (const auto& ShipPartPair : pShipPartsJsnoObject->Values)
    {
        AShipPart* pShipPart = pWorld->SpawnActor<AShipPart>();
        auto ShipPartObject = ShipPartPair.Value->AsObject();

        FRotator Rotation = JsonHelper::GetRotator(ShipPartObject->GetObjectField("Rotation"));
        FVector Location = JsonHelper::GetVector(ShipPartObject->GetObjectField("Location"));

        pShip->AttachPart(pShipPart, Rotation, Location);
    }
}