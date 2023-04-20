#pragma once

#include "CoreMinimal.h"

#include "Misc/TypeContainer.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class VIPGOOGLETESTTEMPLATEEXTERNAL_API FExternalModule : public IModuleInterface
{
public:
	static FExternalModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FExternalModule>("VIPGoogleTestTemplateExternal");
	}

	virtual void RegisterVIPInterfaces();
	virtual void UnregisterVIPInterfaces();

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	template <class R, class T, class ... P>
	void RegisterChecked(ETypeContainerScope Scope);
};
