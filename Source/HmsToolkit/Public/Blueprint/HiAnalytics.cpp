/**
* !Created By Taha HICHRI
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/

#include "HiAnalytics.h"
#include "Json.h"
#include "Dom/JsonObject.h"

UHiAnalytics *UHiAnalytics::GetInstance()
{
	static UHiAnalytics Inst;
	return &Inst;
}

void UHiAnalytics::setUserProfile(FString name, FString value)
{
	//
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->SetHiAnalyticsUserProfile(name, value);
#endif
}

void UHiAnalytics::setUserId(FString userId)
{
	//
#if PLATFORM_ANDROID
	//return TaDispatcher::Get().GetAndroidGatewayInterface()->ScanByCharacteristic(scanTimeout, serviceUUID, deviceAddress);
#endif
	//return false;
}

void UHiAnalytics::setAnalyticsEnabled(bool enabled)
{
	//
#if PLATFORM_ANDROID
	//return TaDispatcher::Get().GetAndroidGatewayInterface()->ScanByCharacteristic(scanTimeout, serviceUUID, deviceAddress);
#endif
	//return false;
}

void UHiAnalytics::reportEvent(FString eventId, TMap<FString, FString> params)
{
#if PLATFORM_ANDROID

	// Create a Json Object from TMap to be passed as string to JAVA

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	for (const TPair<FString, FString> &pair : params)
	{
		JsonObject->SetStringField(pair.Key, pair.Value);
	}

	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	UE_LOG(LogTemp, Warning, TEXT("resulting jsonString -> %s"), *OutputString);

	return TaDispatcher::Get().GetAndroidGatewayInterface()->ReportAnalyticsEvent(eventId, OutputString);
#endif
}

void UHiAnalytics::clearCachedData()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->ClearCachedData();
#endif
}

void UHiAnalytics::setSessionDuration(int32 milliseconds)
{
#if PLATFORM_ANDROID
	//return TaDispatcher::Get().GetAndroidGatewayInterface()->ScanByCharacteristic(scanTimeout, serviceUUID, deviceAddress);
#endif
}
