#pragma once
#include "Toolbar/PluginToolbarButton.h"

struct IMainVIPCycle;
struct ISceneRouter;

class FVIPGoogleTestTemplate
{
public:
	FVIPGoogleTestTemplate();
	~FVIPGoogleTestTemplate();	
private:
	void OnPluginButtonClicked();
	TSharedRef<SDockTab> OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs);
	void OnTabClosed(TSharedRef<SDockTab> TabBeingClosed);
	
	TSharedRef<IMainVIPCycle> FetchMainVipCycle();

	TSharedPtr<FPluginToolbarButton> ToolbarButton;
	TSharedPtr<IMainVIPCycle> MainVipCycle;
};
