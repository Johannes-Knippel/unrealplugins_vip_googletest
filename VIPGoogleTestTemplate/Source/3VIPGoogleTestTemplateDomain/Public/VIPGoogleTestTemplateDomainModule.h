#pragma once

#include "CoreMinimal.h"

#include "Misc/TypeContainer.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class VIPGOOGLETESTTEMPLATEDOMAIN_API FDomainModule : public IModuleInterface
{
public:
	static FDomainModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FDomainModule>("VIPGoogleTestTemplateDomain");
	}

	virtual const TTypeContainer<>& GetContainer()
	{
		return Container;	
	}

	virtual void RegisterVIPInterfaces();
	virtual void UnregisterVIPInterfaces();

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	friend class FExternalEditorModule;
	friend class FExternalModule;
	friend class FDomainModuleProxy;
	TTypeContainer<> Container;

private:
	template <class R, class T, class ... P>
	void RegisterChecked(ETypeContainerScope Scope);
};
