#include "MainInteractor.h"

#include "Scenes/Main/IMainPresenter.h"

void FMainInteractor::Setup(TSharedPtr<IMainPresenter> InPresenter, TSharedPtr<IMainSceneDatastore> InSceneDatastore)
{
	Presenter = InPresenter;
	SceneDatastore = InSceneDatastore;
}

void FMainInteractor::AddTask(const AddTask::FRequest& Request)
{
	Presenter.Pin()->PresentError(
		ShowError::FResponse{ TEXT("CreateTask failed") });
}
