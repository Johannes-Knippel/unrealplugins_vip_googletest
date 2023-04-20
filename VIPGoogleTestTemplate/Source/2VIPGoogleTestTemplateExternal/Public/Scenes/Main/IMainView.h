#pragma once
#include "Scenes/IView.h"

struct IMainInteractor;

struct IMainView: IView
{
	virtual void Setup(TSharedPtr<IMainInteractor> Interactor) = 0;
};

Expose_TNameOf(IMainView)
