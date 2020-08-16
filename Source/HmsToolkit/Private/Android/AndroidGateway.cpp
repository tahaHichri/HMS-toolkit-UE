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

jmethodID FAndroidGateway::SetHiAnalyticsEnabledMethod;
jmethodID FAndroidGateway::SetHiUserIdMethod;
jmethodID FAndroidGateway::SetHiSessionDurationMethod;
jmethodID FAndroidGateway::IsHuaweiMobileServicesAvailableMethod;

FAndroidGateway::FAndroidGateway()
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		ReportAnalyticsEventMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "reportHiAnalyticsEvent", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		SetHiAnalyticsUserProfileMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHiAnalyticsUserProfile", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		ClearCachedDataMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "clearHiCachedData", "()V", false);
		SetHiAnalyticsEnabledMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHiAnalyticsEnabled", "(Z)V", false);
		SetHiUserIdMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHiAnalyticsUserId", "(Ljava/lang/String;)V", false);
		SetHiSessionDurationMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHiSessionDuration", "(I)V", false);
		IsHuaweiMobileServicesAvailableMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "hmstlkt_isHuaweiMobileServicesAvailable", "()Z", false);
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

void FAndroidGateway::SetHiUserId(FString userId)
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jStringUserId = Env->NewStringUTF((std::string(TCHAR_TO_UTF8(*userId))).c_str());

		if (!jStringUserId)
		{
			UE_LOG(LogTemp, Fatal, TEXT("Could Not generate jstring for userId"));
		}

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::SetHiUserIdMethod, jStringUserId);

		Env->DeleteLocalRef(jStringUserId);
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

void FAndroidGateway::SetHiSessionDuration(int32 milliseconds)
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::SetHiSessionDurationMethod, (jvalue *)(jlong)milliseconds);
		return;
	}
	return;
}

bool FAndroidGateway::IsHuaweiMobileServicesAvailable()
{
	bool bResult = false;
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::IsHuaweiMobileServicesAvailableMethod);
	}
	return bResult;
}


void FAndroidGateway::SetHiAnalyticsEnabled(bool enabled)
{
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::SetHiAnalyticsEnabledMethod, (jboolean)enabled);
		return;
	}
	return;
}
