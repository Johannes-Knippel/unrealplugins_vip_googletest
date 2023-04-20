#pragma once
#include "VIPGoogleTestTemplateDomainModule.h"
#include "Misc/TypeContainer.h"

class FDomainModuleProxy
{
public:
	virtual ~FDomainModuleProxy() = default;
	
	static TTypeContainer<>& GetWritableContainer()
	{
		return FDomainModule::Get().Container;
	}
};
