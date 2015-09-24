// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "JsonHelper.h"

TSharedPtr<FJsonObject> JsonHelper::LoadJsonObject(const FString& FilePath)
{
    FString FullFilePath = FPaths::GameContentDir() + FilePath;

    FString JsonStr;
    FFileHelper::LoadFileToString(JsonStr, *FullFilePath);

    TSharedRef<TJsonReader<>> JsonReader = FJsonStringReader::Create(JsonStr);

    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    FJsonSerializer::Deserialize(JsonReader, JsonObject);

    return JsonObject;
}

FVector JsonHelper::GetVector(const TSharedPtr<FJsonObject>& JsonObject)
{
    double X, Y, Z;
    check(JsonObject->TryGetNumberField("X", X));
    check(JsonObject->TryGetNumberField("Y", Y));
    check(JsonObject->TryGetNumberField("Z", Z));
    return FVector(static_cast<float>(X), static_cast<float>(Y), static_cast<float>(Z));
}

FRotator JsonHelper::GetRotator(const TSharedPtr<FJsonObject>& JsonObject)
{
    double Pitch, Yaw, Roll;
    check(JsonObject->TryGetNumberField("Pitch", Pitch));
    check(JsonObject->TryGetNumberField("Yaw", Yaw));
    check(JsonObject->TryGetNumberField("Roll", Roll));
    return FRotator(static_cast<float>(Pitch), static_cast<float>(Yaw), static_cast<float>(Roll));
}