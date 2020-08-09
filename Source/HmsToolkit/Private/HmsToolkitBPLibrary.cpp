/**
* !Created By Taha HICHRI
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/

#include "HmsToolkitBPLibrary.h"
#include "HmsToolkit.h"

static UHiAnalytics *HiAnalyticsIns;

UHmsToolkitBPLibrary::UHmsToolkitBPLibrary(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	HiAnalyticsIns = NewObject<UHiAnalytics>();
}

UHiAnalytics *UHmsToolkitBPLibrary::GetHiAnalytics()
{
	return HiAnalyticsIns;
}

bool UHmsToolkitBPLibrary::isHuaweiMobileServicesAvailable()
{
#if PLATFORM_ANDROID
	return true;
#endif
	return false;
}
