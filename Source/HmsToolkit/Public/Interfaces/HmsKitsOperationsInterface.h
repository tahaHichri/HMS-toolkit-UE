/**
* !Created By Taha HICHRI
* @project    HMS Toolkit for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/

#pragma once

#include "Core.h"
#include "EngineMinimal.h"

class IHmsKitsOperationsInterface
{
  public:
	virtual void ReportAnalyticsEvent(FString eventId, FString jsonFormattedParams) = 0;

	virtual void SetHiAnalyticsUserProfile(FString name, FString value) = 0;

	virtual void SetHiAnalyticsEnabled(bool enabled) = 0;

	virtual void SetHiUserId(FString userId) = 0;

	virtual void SetHiSessionDuration(int32 milliseconds) = 0;

	virtual void ClearCachedData() = 0;

	virtual bool IsHuaweiMobileServicesAvailable() = 0;
};
