// Free to use

#include "OpenFire.h"
#include "RestClient.h"

URestClient* URestClient::instance = nullptr;

URestClient* URestClient::Instance()
{
	return NewObject<URestClient>(URestClient::StaticClass());
}

void URestClient::Request(const FString& url, const FString& verb, const FString& data, std::function<void()> endFunction)
{
	TSharedRef<IHttpRequest> httpRequest = FHttpModule::Get().CreateRequest();

	httpRequest->OnProcessRequestComplete().BindUObject(this, &URestClient::OnResponseReceived);

	httpRequest->SetURL(url);
	httpRequest->SetVerb(verb);
	httpRequest->SetHeader("Content-Type", TEXT("application/json"));

	httpRequest->ProcessRequest();

	this->endFunction = endFunction;
}

void URestClient::OnResponseReceived(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	this->endFunction();
	this->endFunction = nullptr;
}
