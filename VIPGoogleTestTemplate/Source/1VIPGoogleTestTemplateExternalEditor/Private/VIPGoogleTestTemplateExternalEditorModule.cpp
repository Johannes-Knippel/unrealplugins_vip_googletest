#define LOCTEXT_NAMESPACE "FExternalEditorModule"

#include "VIPGoogleTestTemplateExternalEditorModule.h"
#include "VIPGoogleTestTemplate.h"
#include "VIPGoogleTestTemplateDomainModule.h"

void FExternalEditorModule::StartupModule()
{
	VIPGoogleTestTemplate = MakeShared<FVIPGoogleTestTemplate>();

	UE_LOG(LogTemp, Warning, TEXT("ExternalEditorModule has started!"));
}

void FExternalEditorModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("ExternalEditorModule has shut down"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FExternalEditorModule, VIPGoogleTestTemplateExternalEditor)
