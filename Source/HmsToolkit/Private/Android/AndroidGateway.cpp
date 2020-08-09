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

jmethodID FAndroidGateway::ReportAnalyticsEventMethod;

FAndroidGateway::FAndroidGateway()
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		ReportAnalyticsEventMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "reportHiAnalyticsEvent", "(Ljava/lang/String;Ljava/lang/String;)V", false);
	}
}

FAndroidGateway::~FAndroidGateway()
{
}

void FAndroidGateway::ReportAnalyticsEvent(FString eventId, FString jsonFormattedParams)
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jStringEventIdParam = Env->NewStringUTF((std::string(TCHAR_TO_UTF8(*eventId))).c_str());
		jstring jStringJsonFormattedParamsParam = Env->NewStringUTF((std::string(TCHAR_TO_UTF8(*jsonFormattedParams))).c_str());

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::ReportAnalyticsEventMethod, jStringEventIdParam, jStringJsonFormattedParamsParam);
	}
}