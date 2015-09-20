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