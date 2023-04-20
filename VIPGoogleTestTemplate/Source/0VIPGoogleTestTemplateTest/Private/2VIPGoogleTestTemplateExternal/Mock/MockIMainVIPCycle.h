#pragma once
#include "Scenes/Main/IMainVIPCycle.h"
#include "gmock/gmock.h"

class MockIMainVIPCycle : public IMainVIPCycle
{
public:
	MOCK_METHOD(IMainView*, GetView, (), ( const override));
	MOCK_METHOD(IMainPresenter*, GetPresenter, (), (const override));
	MOCK_METHOD(IMainInteractor*, GetInteractor, (), ( const override));
};
