// Free to use

#include "OpenFire.h"
#include "RestClient.h"

void URestClient::Request(const FString& url, const FString& verb, const FString& data, std::function<void()>)
{
	TSharedRef<IHttpRequest> httpRequest = FHttpModule::Get().CreateRequest();

	httpRequest->OnProcessRequestComplete().BindUObject(this, &URestClient::OnResponseReceived);

	httpRequest->SetURL(url);
	httpRequest->SetVerb(verb);
	httpRequest->SetHeader("Content-Type", TEXT("application/json"));

	httpRequest->ProcessRequest();
}

void URestClient::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{

}
