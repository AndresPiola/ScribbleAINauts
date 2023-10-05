// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpConnectComponent.h"

#include "HttpModule.h"
#include "GenericPlatform/GenericPlatformHttp.h"
#include "Interfaces/IHttpResponse.h"


// Sets default values for this component's properties
UHttpConnectComponent::UHttpConnectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHttpConnectComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHttpConnectComponent::OnProcessRequestComplete(TSharedPtr<IHttpRequest> HttpRequest, TSharedPtr<IHttpResponse> HttpResponse, bool bArg)
{
	if (HttpResponse.IsValid())
	{
		const int32 ResponseCode = HttpResponse->GetResponseCode();
		//UE_LOG(LogTemp, Log, TEXT("Response code %d"), ResponseCode);
		const FString ContentString = HttpResponse.Get()->GetContentAsString();
		//UE_LOG(LogTemp, Log, TEXT("GetContentAsString  %s"), *ContentString);
		const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(ContentString);

		TSharedPtr<FJsonObject> JsonObjectResult;
		FJsonSerializer::Deserialize(JsonReader, JsonObjectResult);
		if (!JsonObjectResult.IsValid())
		{
			OnRequestReady.Broadcast(false, {});
			return;
		}

		TArray<TSharedPtr<FJsonValue>> Results = JsonObjectResult->GetArrayField(TEXT("results"));
		TArray<FQueryResults> QueryResults;

		for (const TSharedPtr<FJsonValue> JsonValue : Results)
		{
			const TSharedPtr<FJsonObject> JsonObject = JsonValue->AsObject();
			FQueryResults QueryResult = FQueryResults(JsonObject->GetStringField("Title"), JsonObject->GetStringField("Download"));
			QueryResults.Add(QueryResult);
		}
		OnRequestReady.Broadcast(true, QueryResults);
	}
	OnRequestReady.Broadcast(false, {});
}


// Called every frame
void UHttpConnectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHttpConnectComponent::MakeRequest(const FString& Keyword)
{
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	const FString QueryUrl = RequestURL + FGenericPlatformHttp::UrlEncode(Keyword);
	UE_LOG(LogTemp, Log, TEXT("QueryURl %s"), * QueryUrl);
	Request->SetURL(QueryUrl);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader("X-Auth-Token", RequestApiKey);
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnProcessRequestComplete);
	Request->ProcessRequest();
	// ...
}