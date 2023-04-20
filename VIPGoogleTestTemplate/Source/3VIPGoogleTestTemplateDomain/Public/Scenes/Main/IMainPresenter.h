#pragma once
#include "../IPresenter.h"

struct IMainView;
struct IMainSceneDatastore;

struct IMainPresenter : IPresenter
{	
	virtual void Setup(TSharedPtr<IMainView> View, TSharedPtr<IMainSceneDatastore> SceneDatastore) = 0;
};

Expose_TNameOf(IMainPresenter)
