/**
* !Created By Taha HICHRI
* @project    HMS Toolkit for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/

#pragma once

#include "Interfaces/HmsKitsOperationsInterface.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include <android_native_app_glue.h>
#include "EngineMinimal.h"
#include "Core.h"
#include <string>

class FAndroidGateway : public IHmsKitsOperationsInterface
{
  public:
	FAndroidGateway();
	virtual ~FAndroidGateway();

	virtual void ReportAnalyticsEvent(FString eventId, FString jsonFormattedParams) override;
	virtual void SetHiAnalyticsUserProfile(FString name, FString value) override;
	virtual void ClearCachedData() override;

	virtual void SetHiAnalyticsEnabled(bool enabled) override;
	virtual void SetHiUserId(FString userId) override;
	virtual void SetHiSessionDuration(int32 milliseconds) override;
	virtual bool IsHuaweiMobileServicesAvailable() override;

	// JNI Methods
	static jmethodID ReportAnalyticsEventMethod;
	static jmethodID SetHiAnalyticsUserProfileMethod;
	static jmethodID ClearCachedDataMethod;

	static jmethodID SetHiAnalyticsEnabledMethod;
	static jmethodID SetHiUserIdMethod;
	static jmethodID SetHiSessionDurationMethod;
	static jmethodID IsHuaweiMobileServicesAvailableMethod;
};