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
jmethodID FAndroidGateway::SetHiAnalyticsUserProfileMethod;
jmethodID FAndroidGateway::ClearCachedDataMethod;

FAndroidGateway::FAndroidGateway()
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		ReportAnalyticsEventMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "reportHiAnalyticsEvent", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		SetHiAnalyticsUserProfileMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHiAnalyticsUserProfile", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		ClearCachedDataMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "clearCachedData", "()V", false);
	}
}

FAndroidGateway::~FAndroidGateway()
{
}

void FAndroidGateway::SetHiAnalyticsUserProfile(FString name, FString value)
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jStringNameParam = Env->NewStringUTF((std::string(TCHAR_TO_UTF8(*name))).c_str());
		jstring jStringValueParam = Env->NewStringUTF((std::string(TCHAR_TO_UTF8(*value))).c_str());

		if (!jStringNameParam || !jStringValueParam)
		{
			UE_LOG(LogTemp, Fatal, TEXT("Could Not generate jstring SetHiAnalyticsUserProfile"));
		}

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::SetHiAnalyticsUserProfileMethod, jStringNameParam, jStringValueParam);

		Env->DeleteLocalRef(jStringNameParam);
		Env->DeleteLocalRef(jStringValueParam);
	}
}

void FAndroidGateway::ReportAnalyticsEvent(FString eventId, FString jsonFormattedParams)
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jStringEventIdParam = Env->NewStringUTF((std::string(TCHAR_TO_UTF8(*eventId))).c_str());
		jstring jStringJsonFormattedParamsParam = Env->NewStringUTF((std::string(TCHAR_TO_UTF8(*jsonFormattedParams))).c_str());

		if (!jStringEventIdParam || !jStringJsonFormattedParamsParam)
		{
			UE_LOG(LogTemp, Fatal, TEXT("Could Not generate jstring FOR reportHiAnalyticsEvent"));
		}

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::ReportAnalyticsEventMethod, jStringEventIdParam, jStringJsonFormattedParamsParam);

		Env->DeleteLocalRef(jStringEventIdParam);
		Env->DeleteLocalRef(jStringJsonFormattedParamsParam);
	}
}

void FAndroidGateway::ClearCachedData()
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::ClearCachedDataMethod);
	}
}