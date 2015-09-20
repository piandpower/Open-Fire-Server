// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 *
 */
class OPENFIRE_API JsonHelper
{
public:
    static TSharedPtr<FJsonObject> GetJsonObject(const FString& FilePath);
};