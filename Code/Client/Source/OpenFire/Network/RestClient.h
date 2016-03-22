// Free to use

#pragma once

#include "Object.h"
#include <functional>
#include "Runtime/Online/HTTP/Public/Http.h"

class OPENFIRE_API URestClient: public UObject
{
	void Request(const FString& url, const FString& verb, const FString& data, std::function<void()>);

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
