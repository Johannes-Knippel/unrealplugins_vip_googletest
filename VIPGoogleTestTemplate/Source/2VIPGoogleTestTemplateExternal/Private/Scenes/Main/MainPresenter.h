#pragma once
#include "Scenes/Main/IMainPresenter.h"

class FMainPresenter : public IMainPresenter
{
public:
	virtual void Setup(TSharedPtr<IMainView> InView, TSharedPtr<IMainSceneDatastore> InSceneDatastore) override
	{
		View = InView;
		SceneDatastore = InSceneDatastore;
	}

	virtual void PresentError(const ShowError::FResponse& Response) override
	{
		UE_LOG(LogTemp, Warning, TEXT("Message: >%s<."), *Response.Message);
		View.Pin()->DisplayError(ShowError::FViewModel{Response.Message});
	}

private:
	TWeakPtr<IMainView> View;
	TWeakPtr<IMainSceneDatastore> SceneDatastore;
};
