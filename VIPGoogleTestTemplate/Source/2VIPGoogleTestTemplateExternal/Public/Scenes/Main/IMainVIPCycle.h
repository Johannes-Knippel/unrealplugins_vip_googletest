#pragma once
#include "IVIPCycle.h"

// We need includes instead of forward-declarations here for inheritance-by-dominance to work
#include "Scenes/Main/IMainInteractor.h"
#include "Scenes/Main/IMainView.h"
#include "Scenes/Main/IMainPresenter.h"

struct IMainVIPCycle : IVIPCycle
{
	virtual IMainView* GetView() const override = 0;
	virtual IMainPresenter* GetPresenter() const override = 0;
	virtual IMainInteractor* GetInteractor() const override = 0;
};

Expose_TNameOf(IMainVIPCycle)
