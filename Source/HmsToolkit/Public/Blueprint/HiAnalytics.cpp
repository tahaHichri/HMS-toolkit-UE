/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#include "HiAnalytics.h"


UHiAnalytics* UHiAnalytics::GetInstance()
{
	static UHiAnalytics Inst;
	return &Inst;
}
