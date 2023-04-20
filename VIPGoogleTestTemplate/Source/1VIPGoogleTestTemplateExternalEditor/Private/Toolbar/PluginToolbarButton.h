#pragma once

#include "CoreMinimal.h"

#include "VIPGoogleTestTemplateStyle.h"

#define LOCTEXT_NAMESPACE "FPluginToolbarButton"

class FPluginToolbarButton
{
public:
	void Init(FExecuteAction ExecuteAction);
	void Destroy();
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:

	void RegisterMenus();

	TSharedPtr<class FUICommandList> PluginCommands;
};

class FToolbarButtonCommands : public TCommands<FToolbarButtonCommands>
{
public:

	FToolbarButtonCommands()
		: TCommands<FToolbarButtonCommands>(TEXT("VIPGoogleTestTemplateToolbarButton"), NSLOCTEXT("Contexts", "VIPGoogleTestTemplateToolbarButton", "VIPGoogleTestTemplateToolbarButton Plugin"), NAME_None, FVIPGoogleTestTemplateStyle::GetStyleSetName())
	{
	}

	virtual void RegisterCommands() override
	{
		UI_COMMAND(VIPGoogleTestTemplatePluginAction, "VIPGoogleTestTemplate", "Execute VIPGoogleTestTemplate action", EUserInterfaceActionType::Button, FInputGesture());
	}
	TSharedPtr< FUICommandInfo > VIPGoogleTestTemplatePluginAction;
};

#undef LOCTEXT_NAMESPACE
