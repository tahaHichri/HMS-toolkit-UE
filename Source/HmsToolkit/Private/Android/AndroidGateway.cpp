/**
* !Created By Taha HICHRI
* @project    HMS Toolkit for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/

#pragma once
//
#include "AndroidGateway.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

// jmethodID FAndroidGateway::IsEnabledMethod;

FAndroidGateway::FAndroidGateway()
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		IsEnabledMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isBluetoothEnabled", "()Z", false);
	}
}

FAndroidGateway::~FAndroidGateway()
{
}

// bool FAndroidGateway::IsEnabled()
// {
// 	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
// 	{
// 		return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::IsEnabledMethod);
// 	}
// 	return false;
// }