#pragma once
#include "Scenes/IInteractor.h"

struct IMainSceneDatastore;
struct IMainPresenter;

namespace AddTask {
	struct FRequest
	{
	};
}

struct IMainInteractor : IInteractor
{
	virtual void Setup(TSharedPtr<IMainPresenter> Presenter, TSharedPtr<IMainSceneDatastore> SceneDatastore) = 0;
	virtual void AddTask(const AddTask::FRequest& Request) = 0;
};

Expose_TNameOf(IMainInteractor)
