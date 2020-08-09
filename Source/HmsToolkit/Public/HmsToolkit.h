/**
* !Created By Taha HICHRI
* @project    HMS Toolkit for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/


#pragma once

#include "Modules/ModuleManager.h"
#include "TaDispatcher.h"

#define LOCTEXT_NAMESPACE "HmsToolkit"

class FHmsToolkitModule : public TaDispatcher
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
