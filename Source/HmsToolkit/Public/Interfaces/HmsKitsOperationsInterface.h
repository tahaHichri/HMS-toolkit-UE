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

};

