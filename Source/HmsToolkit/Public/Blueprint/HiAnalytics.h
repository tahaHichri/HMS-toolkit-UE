/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#pragma once

#include "CoreMinimal.h"
#include "HiAnalytics.generated.h"

UCLASS(Blueprintable)
class UHiAnalytics : public UObject
{

	GENERATED_BODY()
	
public:
	static UHiAnalytics* GetInstance();



	
};
