#pragma once

#include "VIPGoogleTestTemplateDefines.h"
#include "Scenes/Main/IMainInteractor.h"
#include "Scenes/Main/IMainPresenter.h"
#include "Scenes/Main/IMainView.h"
#include "Scenes/Main/IMainVIPCycle.h"
#include "Scenes/Main/IMainSceneDatastore.h"

class FMainVIPCycle : public IMainVIPCycle
{
public:
	FMainVIPCycle()
	{
		View = FDomainModule::Get().GetContainer().GetInstance<IMainView>();
		Interactor = FDomainModule::Get().GetContainer().GetInstance<IMainInteractor>();
		Presenter = FDomainModule::Get().GetContainer().GetInstance<IMainPresenter>();
		SceneDatastore = FDomainModule::Get().GetContainer().GetInstance<IMainSceneDatastore>();
		SceneRouter = FDomainModule::Get().GetContainer().GetInstance<ISceneRouter>();

		View->Setup(Interactor);
		Presenter->Setup(View, SceneDatastore);
		Interactor->Setup(Presenter, SceneDatastore);
		SceneRouter->Setup(View);

	}

	virtual IMainView* GetView() const override
	{
		return View.Get();
	}

	virtual IMainPresenter* GetPresenter() const override
	{
		return Presenter.Get();
	}

	virtual IMainInteractor* GetInteractor() const override
	{
		return Interactor.Get();
	}

	TSharedPtr<IMainInteractor> Interactor;
	TSharedPtr<IMainPresenter> Presenter;
	TSharedPtr<IMainView> View;
	TSharedPtr<IMainSceneDatastore> SceneDatastore;
	TSharedPtr<ISceneRouter> SceneRouter;
};
