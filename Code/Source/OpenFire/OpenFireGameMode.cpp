// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "Helpers/JsonHelper.h"

void AOpenFireGameMode::StartPlay()
{
    TSharedPtr<FJsonObject> defaultDataJsonObject = JsonHelper::GetJsonObject("Datas/DefaultData.json");

    TSharedPtr<FJsonObject> ShipObjects = defaultDataJsonObject->GetObjectField("Ships");
    for (const auto& ShipObject : ShipObjects->Values)
    {
        TSharedPtr<FJsonObject> ShipPart = defaultDataJsonObject->GetObjectField("Ships");
    }
}