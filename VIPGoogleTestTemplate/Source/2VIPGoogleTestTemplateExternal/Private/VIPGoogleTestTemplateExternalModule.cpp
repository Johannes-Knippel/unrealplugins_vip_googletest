#define LOCTEXT_NAMESPACE "FExternalModule"
#include "VIPGoogleTestTemplateExternalModule.h"

#include "VIPGoogleTestTemplateDomainModule.h"
#include "Scenes/ISceneRouter.h"
#include "Scenes/SceneRouter.h"
#include "Scenes/Main/IMainPresenter.h"
#include "Scenes/Main/IMainView.h"
#include "Scenes/Main/IMainVIPCycle.h"
#include "Scenes/Main/MainPresenter.h"
#include "Scenes/Main/MainView.h"
#include "Scenes/Main/MainVIPCycle.h"

void FExternalModule::RegisterVIPInterfaces()
{
	RegisterChecked<IMainVIPCycle, FMainVIPCycle>(ETypeContainerScope::Instance);
	RegisterChecked<ISceneRouter, FSceneRouter>(ETypeContainerScope::Instance);
	RegisterChecked<IMainView, FMainView>(ETypeContainerScope::Instance);
	RegisterChecked<IMainPresenter, FMainPresenter>(ETypeContainerScope::Instance);
}

void FExternalModule::UnregisterVIPInterfaces()
{
	FDomainModule::Get().Container.Unregister<IMainVIPCycle>();
	FDomainModule::Get().Container.Unregister<ISceneRouter>();
	FDomainModule::Get().Container.Unregister<IMainView>();
	FDomainModule::Get().Container.Unregister<IMainPresenter>();
}

template<class R, class T, typename... P>
void FExternalModule::RegisterChecked(ETypeContainerScope Scope = ETypeContainerScope::Process)
{
	if (!FDomainModule::Get().Container.IsRegistered<R>())
		FDomainModule::Get().Container.RegisterClass<R, T, P...>(Scope);
}

void FExternalModule::StartupModule()
{
	RegisterVIPInterfaces();
	UE_LOG(LogTemp, Warning, TEXT("ExternalModule has started!"));
}

void FExternalModule::ShutdownModule()
{
	UnregisterVIPInterfaces();
	UE_LOG(LogTemp, Warning, TEXT("ExternalModule has shut down"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FExternalModule, VIPGoogleTestTemplateExternal)
