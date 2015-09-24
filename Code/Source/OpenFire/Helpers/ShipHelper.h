// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class AShip;

/**
 * 
 */
class OPENFIRE_API ShipHelper
{
public:
    static AShip* CreateShip(UWorld* pWorld, const TSharedPtr<FJsonValue>& pShipJsonValue);

private:
    static void AttachPartsByJson(UWorld* pWorld, AShip* pShip, const TSharedPtr<FJsonObject>& pShipPartsJsnoObject);
};
