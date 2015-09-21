// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "JsonHelper.h"

TSharedPtr<FJsonObject> JsonHelper::GetJsonObject(const FString& FilePath)
{
    FString FullFilePath = FPaths::GameContentDir() + FilePath;

    FString JsonStr;
    FFileHelper::LoadFileToString(JsonStr, *FullFilePath);

    TSharedRef<TJsonReader<>> JsonReader = FJsonStringReader::Create(JsonStr);

    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    FJsonSerializer::Deserialize(JsonReader, JsonObject);

    return JsonObject;
}

FVector JsonHelper::GetVector(FJsonObject Object)
{
    double X, Y, Z;
    check(Object.TryGetNumberField("X", X));
    check(Object.TryGetNumberField("Y", Y));
    check(Object.TryGetNumberField("Z", Z));
    return FVector(static_cast<float>(X), static_cast<float>(Y), static_cast<float>(Z));
}

FRotator JsonHelper::GetRotator(FJsonObject Object)
{
    double Pitch, Yaw, Roll;
    check(Object.TryGetNumberField("Y", Pitch));
    check(Object.TryGetNumberField("Z", Yaw));
    check(Object.TryGetNumberField("X", Roll));
    return FRotator(static_cast<float>(Pitch), static_cast<float>(Yaw), static_cast<float>(Roll));
}