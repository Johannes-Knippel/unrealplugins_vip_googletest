#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class FVIPGoogleTestTemplate;

class VIPGOOGLETESTTEMPLATEEXTERNALEDITOR_API FExternalEditorModule : public IModuleInterface
{
public:
	static FExternalEditorModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FExternalEditorModule>("VIPGoogleTestTemplateExternalEditor");
	}

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<FVIPGoogleTestTemplate> VIPGoogleTestTemplate;
};
