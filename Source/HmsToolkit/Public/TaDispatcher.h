/**
* !Created By Taha HICHRI
* @project    HMS Toolkit for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/


#pragma once

#include "Modules/ModuleManager.h"
#include "EngineMinimal.h"
#include "Core.h"
#include "Interfaces/HmsKitsOperationsInterface.h"


typedef TSharedPtr<IHmsKitsOperationsInterface, ESPMode::ThreadSafe> FAndroidGatewayPtr;

class TaDispatcher : public IModuleInterface
{
public:
	static inline TaDispatcher& Get()
	{
		return FModuleManager::LoadModuleChecked< TaDispatcher >("HmsToolkit");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("HmsToolkit");
	}

	inline FAndroidGatewayPtr GetAndroidGatewayInterface() const
	{
		return AndroidGatewayInterface;
	}

protected:
	FAndroidGatewayPtr AndroidGatewayInterface;
};
