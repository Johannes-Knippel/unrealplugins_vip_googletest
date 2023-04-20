#pragma once

#include "gmock/gmock.h"
#include "Scenes/ISceneRouter.h"

class MockISceneRouter : public ISceneRouter
{
public:
	MOCK_METHOD(IMainView*, GetMainView, (), (override));
};
