#include "VIPGoogleTestTemplateTestModule.h"

#include "CustomTestFailureReporter.h"
#include "VIPGoogleTestTemplateDefines.h"
#include "VIPGoogleTestTemplateDomainModule.h"
#include "VIPGoogleTestTemplateExternalModule.h"
#include "IAutomationControllerModule.h"

#define LOCTEXT_NAMESPACE "FTestModule"
DEFINE_LOG_CATEGORY(VIPGoogleTestTemplateLog);

void FTestModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("TestModule has started!"));
	::testing::TestEventListeners& Listeners = ::testing::UnitTest::GetInstance()->listeners();
	Listeners.Append(new CustomTestFailureReporter());
}

void FTestModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("TestModule has shut down"));
}


void FTestModule::RegisterAutomationControllerDelegates()
{
	// The AutomationController seems to have a late loading-phase-> load it if necessary
	if (!FModuleManager::Get().IsModuleLoaded(TEXT("AutomationController")))
	{
		EModuleLoadResult FailureReason;
		FModuleManager::Get().LoadModuleWithFailureReason("AutomationController", FailureReason);
	}

	if (!FModuleManager::Get().IsModuleLoaded(TEXT("AutomationController")))
	{
		UE_LOG(VIPGoogleTestTemplateLog, Log, TEXT("AutomationController Module not loaded: Failed to register to Delegates"));
		return;
	}

	// Delegates need to be re-initialized OnControllerReset
	IAutomationControllerModule::Get().GetAutomationController()->OnControllerReset().AddLambda([this]()
	{
		IAutomationControllerModule::Get().GetAutomationController()->OnTestsAvailable().AddLambda([this](EAutomationControllerModuleState::Type Type)
		{
			if (Type == EAutomationControllerModuleState::Running)
			{
				UE_LOG(VIPGoogleTestTemplateLog, Log, TEXT("Tests: running"));
				bPreviousTestStateIsRunning = true;
			}
			if (Type == EAutomationControllerModuleState::Ready)
			{
				UE_LOG(VIPGoogleTestTemplateLog, Log, TEXT("Tests: ready"));
				if (bPreviousTestStateIsRunning)
				{
					bPreviousTestStateIsRunning = false;
					// After completing tests, we want to re-initialize all Dependencies, as the Plugin won't work correctly otherwise
					UE_LOG(VIPGoogleTestTemplateLog, Log, TEXT("Tests completed: Re-Registering VIP-Interfaces"));
					FDomainModule::Get().UnregisterVIPInterfaces();
					FDomainModule::Get().RegisterVIPInterfaces();
					FExternalModule::Get().UnregisterVIPInterfaces();
					FExternalModule::Get().RegisterVIPInterfaces();
				}
			}
		});
	});
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTestModule, VIPGoogleTestTemplateTest)
