#pragma once
#include "Scenes/Main/IMainInteractor.h"

class FMainInteractor : public IMainInteractor
{
public:
	virtual void Setup(TSharedPtr<IMainPresenter> InPresenter, TSharedPtr<IMainSceneDatastore> InSceneDatastore) override;
	virtual void AddTask(const AddTask::FRequest& Request) override;

private:
	TWeakPtr<IMainPresenter> Presenter;
	TWeakPtr<IMainSceneDatastore> SceneDatastore;
};
