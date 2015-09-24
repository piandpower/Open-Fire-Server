// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 *
 */
class OPENFIRE_API JsonHelper
{
public:
    static TSharedPtr<FJsonObject> LoadJsonObject(const FString& FilePath);

    static FVector GetVector(const TSharedPtr<FJsonObject>& JsonObject);

    static FRotator GetRotator(const TSharedPtr<FJsonObject>& JsonObject);
};