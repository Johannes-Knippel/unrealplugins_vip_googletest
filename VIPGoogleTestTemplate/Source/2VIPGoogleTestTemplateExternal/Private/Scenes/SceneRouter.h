#pragma once
#include "IVIPCycle.h"
#include "Scenes/ISceneRouter.h"
#include "Scenes/Main/IMainVIPCycle.h"

class FSceneRouter : public ISceneRouter, public TSharedFromThis<FSceneRouter>
{
public:
	virtual void Setup(TSharedPtr<IMainView> InMainView)
	{
		MainView = InMainView;
	}

private:
	TWeakPtr<IMainView> MainView;
	TSharedPtr<IVIPCycle> ActiveInnerVIPCycle;
};
