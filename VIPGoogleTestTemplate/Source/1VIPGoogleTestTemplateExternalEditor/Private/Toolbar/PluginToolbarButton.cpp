#include "PluginToolbarButton.h"
#include "ToolMenus.h"

#ifndef LOCTEXT_NAMESPACE
	#define LOCTEXT_NAMESPACE "VIPGoogleTestTemplate"
#endif

void FPluginToolbarButton::Init(FExecuteAction ExecuteAction)
{	
	FVIPGoogleTestTemplateStyle::Initialize();
	FVIPGoogleTestTemplateStyle::ReloadTextures();
	FToolbarButtonCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FToolbarButtonCommands::Get().VIPGoogleTestTemplatePluginAction,
		ExecuteAction,
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FPluginToolbarButton::RegisterMenus));
}

void FPluginToolbarButton::Destroy()
{
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
	FVIPGoogleTestTemplateStyle::Shutdown();
	FToolbarButtonCommands::Unregister();
}

void FPluginToolbarButton::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FToolbarButtonCommands::Get().VIPGoogleTestTemplatePluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("TEST");
			{
				FToolMenuEntry& Entry = Section.AddEntry(
				FToolMenuEntry::InitToolBarButton(
						FToolbarButtonCommands::Get().VIPGoogleTestTemplatePluginAction,
						LOCTEXT("VIPGoogleTestTemplate","Some Tool"),
						LOCTEXT("VIPGoogleTestTemplateTooltip","Open the Tool"),
						FSlateIcon(FVIPGoogleTestTemplateStyle::GetStyleSetName(), "ToolbarButton.VIPGoogleTestTemplatePluginAction")));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
