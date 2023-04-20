#pragma once
#include "Scenes/IInteractor.h"
#include "Scenes/IPresenter.h"
#include "Scenes/IView.h"

struct IVIPCycle
{
	virtual ~IVIPCycle() = default;

	virtual IView* GetView() const = 0;
	virtual IPresenter* GetPresenter() const = 0;
	virtual IInteractor* GetInteractor() const = 0;	
};
