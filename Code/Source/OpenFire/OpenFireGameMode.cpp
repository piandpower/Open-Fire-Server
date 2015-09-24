// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "Helpers/JsonHelper.h"
#include "Helpers/ShipHelper.h"

void AOpenFireGameMode::StartPlay()
{
    TSharedPtr<FJsonObject> defaultDataJsonObject = JsonHelper::LoadJsonObject("Datas/DefaultData.json");

    const TSharedPtr<FJsonObject>& ShipsJsonObject = defaultDataJsonObject->GetObjectField("Ships");

    for (const auto& ShipPair : ShipsJsonObject->Values)
    {
        ShipHelper::CreateShip(GetWorld(), ShipPair.Value);
    }
}