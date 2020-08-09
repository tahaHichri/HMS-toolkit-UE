/**
* !Created By Taha HICHRI
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/

#pragma once

#include "CoreMinimal.h"
#include "HiAnalytics.generated.h"

UCLASS(Blueprintable)
class UHiAnalytics : public UObject
{

	GENERATED_BODY()

  public:
	static UHiAnalytics *GetInstance();

	UFUNCTION(BlueprintCallable, Category = "HmsToolkit")
	void setUserProfile(FString name, FString value);

	UFUNCTION(BlueprintCallable, Category = "HmsToolkit")
	void setUserId(FString userId);

	UFUNCTION(BlueprintCallable, Category = "HmsToolkit")
	void setAnalyticsEnabled(bool enabled);

	UFUNCTION(BlueprintCallable, Category = "HmsToolkit")
	void reportEvent(FString eventId, TMap<FString, FString> params);

	UFUNCTION(BlueprintCallable, Category = "HmsToolkit")
	void clearCachedData();

	UFUNCTION(BlueprintCallable, Category = "HmsToolkit")
	void setSessionDuration(int32 milliseconds);
};
