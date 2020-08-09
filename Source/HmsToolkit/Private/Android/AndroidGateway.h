/**
* !Created By Taha HICHRI
* @project    HMS Toolkit for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/

#pragma once

#include "Interfaces/BluetoothOperationsInterface.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include <android_native_app_glue.h>
#include "EngineMinimal.h"
#include "Core.h"
#include <string>

#include "Async.h"

class FAndroidGateway : public IBluetoothOperationsInterface
{
  public:
	FAndroidGateway();
	virtual ~FAndroidGateway();

	// virtual bool IsEnabled() override;

	// // JNI Methods
	// static jmethodID IsEnabledMethod;
};