#include "VIPGoogleTestTemplateDomainModule.h"

#include "Scenes/Main/IMainInteractor.h"
#include "Scenes/Main/IMainSceneDatastore.h"
#include "Scenes/Main/MainInteractor.h"
#include "Scenes/Main/MainSceneDatastore.h"

#ifndef LOCTEXT_NAMESPACE
	#define LOCTEXT_NAMESPACE "VIPGoogleTestTemplate"
#endif

void FDomainModule::RegisterVIPInterfaces()
{
	RegisterChecked<IMainSceneDatastore, FMainSceneDatastore>(ETypeContainerScope::Instance);
	RegisterChecked<IMainInteractor, FMainInteractor>(ETypeContainerScope::Instance);
}

void FDomainModule::UnregisterVIPInterfaces()
{
	Container.Unregister<IMainSceneDatastore>();
	Container.Unregister<IMainInteractor>();
}

template<class R, class T, typename... P>
void FDomainModule::RegisterChecked(ETypeContainerScope Scope)
{
	if (!Container.IsRegistered<R>())
		Container.RegisterClass<R, T, P...>(Scope);
}

void FDomainModule::StartupModule()
{
	RegisterVIPInterfaces();
	UE_LOG(LogTemp, Warning, TEXT("DomainModule has started!"));
}

void FDomainModule::ShutdownModule()
{
	UnregisterVIPInterfaces();
	UE_LOG(LogTemp, Warning, TEXT("DomainModule has shut down"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDomainModule, VIPGoogleTestTemplateDomain)
