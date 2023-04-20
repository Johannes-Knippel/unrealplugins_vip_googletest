#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class VIPGOOGLETESTTEMPLATETEST_API FTestModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	bool bPreviousTestStateIsRunning = false;

	// This method has two purposes:
	// - disable to logger during test execution, to have green tests instead of yellow once (warnings are yellow)
	// - re-register all VIP-Interfaces after execution, as otherwise the plugin will probably crash on opening
	void RegisterAutomationControllerDelegates();
};
