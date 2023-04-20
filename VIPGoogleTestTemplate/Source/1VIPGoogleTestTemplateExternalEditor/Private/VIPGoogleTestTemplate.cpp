#include "VIPGoogleTestTemplate.h"

#include "VIPGoogleTestTemplateDomainModule.h"
#include "VIPGoogleTestTemplateExternalModule.h"
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"
#include "Misc/MessageDialog.h"
#include "Scenes/Main/IMainView.h"
#include "Scenes/Main/IMainVIPCycle.h"
#include "Toolbar/PluginToolbarButton.h"
#include "Widgets/Docking/SDockTab.h"

#ifndef LOCTEXT_NAMESPACE
	#define LOCTEXT_NAMESPACE "VIPGoogleTestTemplate"
#endif

static const FName VIPGoogleTestTemplateTabName("VIPGoogleTestTemplate");

FVIPGoogleTestTemplate::FVIPGoogleTestTemplate()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(VIPGoogleTestTemplateTabName, FOnSpawnTab::CreateRaw(this, &FVIPGoogleTestTemplate::OnSpawnPluginTab))
								.SetDisplayName(LOCTEXT("VIPGoogleTestTemplateTabTitle", "VIPGoogleTestTemplate"))
								.SetMenuType(ETabSpawnerMenuType::Hidden)
								.SetGroup( WorkspaceMenu::GetMenuStructure().GetToolsCategory() );
	
	ToolbarButton = MakeShared<FPluginToolbarButton>();
	ToolbarButton->Init(FExecuteAction::CreateRaw(this, &FVIPGoogleTestTemplate::OnPluginButtonClicked));
}

FVIPGoogleTestTemplate::~FVIPGoogleTestTemplate()
{
	if (ToolbarButton.IsValid())
		ToolbarButton->Destroy();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(VIPGoogleTestTemplateTabName);
}

void FVIPGoogleTestTemplate::OnPluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(VIPGoogleTestTemplateTabName);
}

TSharedRef<SDockTab> FVIPGoogleTestTemplate::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	// We can re-register them here each time, as registering is only happening if they are not yet registered
	FExternalModule::Get().RegisterVIPInterfaces();
	FDomainModule::Get().RegisterVIPInterfaces();
	
	const TSharedRef<SDockTab> MainTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FVIPGoogleTestTemplate::OnTabClosed));

	if (IMainView* MainView = FetchMainVipCycle()->GetView())
	{
		const auto MainWidget = MainView->FetchWidget();
		if (MainWidget.IsValid())
		{
			MainTab->SetContent(MainWidget.ToSharedRef());
			return MainTab;
		}
	}

	MainTab->SetContent(
		SNew(STextBlock)
		.Text(LOCTEXT("VIPGoogleTestTemplateError", "VIPGoogleTestTemplate: Something went wrong")));

	return MainTab;
}

void FVIPGoogleTestTemplate::OnTabClosed(TSharedRef<SDockTab> TabBeingClosed)
{
	MainVipCycle.Reset();
}

TSharedRef<IMainVIPCycle> FVIPGoogleTestTemplate::FetchMainVipCycle()
{
	if (!MainVipCycle.IsValid())
	{
		MainVipCycle = FDomainModule::Get().GetContainer().GetInstance<IMainVIPCycle>();
	}
	return MainVipCycle.ToSharedRef();
}

#undef LOCTEXT_NAMESPACE
