#pragma once
#include "Scenes/Main/IMainPresenter.h"
#include "gmock/gmock.h"

class MockIMainPresenter : public IMainPresenter
{
public:
	MOCK_METHOD(void, Setup, (TSharedPtr<IMainView> View, TSharedPtr<IMainSceneDatastore> SceneDatastore), ( override));
	MOCK_METHOD(void, PresentError, (const ShowError::FResponse& Response), ( override));
};
