#pragma once
#include "Scenes/Main/IMainView.h"
#include "gmock/gmock.h"

class MockIMainView : public IMainView
{
public:
	MOCK_METHOD(void, Setup, (TSharedPtr<IMainInteractor> Interactor), ( override));
	MOCK_METHOD(void, DisplayError, (const ShowError::FViewModel& ViewModel), ( override));

	virtual TSharedPtr<SCompoundWidget> FetchWidget() override
	{
		// can't be mocked (return type = Unreal)
		return nullptr;
	}
};
