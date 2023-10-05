// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/IHttpRequest.h"
#include "HttpConnectComponent.generated.h"

USTRUCT(BlueprintType)
struct FQueryResults
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FString Title;

	UPROPERTY(BlueprintReadOnly)
	FString ModelUrl;

	FQueryResults(): Title(""), ModelUrl("") {}

	FQueryResults(const FString& Title, const FString& ModelUrl)
		: Title(Title),
		  ModelUrl(ModelUrl) {}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNotifyRequestReady, bool, bSucess, TArray<FQueryResults>, Results);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SCRIBBLEAINAUTS_API UHttpConnectComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHttpConnectComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OnProcessRequestComplete(TSharedPtr<IHttpRequest> HttpRequest, TSharedPtr<IHttpResponse> HttpResponse, bool bArg);

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintCallable)
	void MakeRequest(const FString& Keyword);

public:
	UPROPERTY(BlueprintAssignable)
	FNotifyRequestReady OnRequestReady;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString RequestURL = "https://api.poly.pizza/v1/search/";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString RequestApiKey = "3478733645d9495e9ec1b0700f10cd0f";
};