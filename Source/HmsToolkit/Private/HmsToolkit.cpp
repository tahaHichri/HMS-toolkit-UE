/**
* !Created By Taha HICHRI
* @project    HMS Toolkit for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/

#include "HmsToolkit.h"



IMPLEMENT_MODULE(FHmsToolkitModule, HmsToolkit)

FHmsToolkitModule* TaModule = NULL;



void FHmsToolkitModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// AndroidGateway relies heavily on Android-specific dependencies, hence, won't be loaded unless we are building for android.
	#if PLATFORM_ANDROID
		AndroidGatewayInterface = MakeShareable(new FAndroidGateway());
		TaModule = &FModuleManager::LoadModuleChecked<FHmsToolkitModule>("HmsToolkit");
	#endif
}

void FHmsToolkitModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	#if PLATFORM_ANDROID
	// if (TaModule != NULL)
	// 	TaModule->ClearAllDeviceScanSucceedCompleteDelegate_Handle();
	#endif

	// Clean up
	TaModule = NULL;
}

#undef LOCTEXT_NAMESPACE

