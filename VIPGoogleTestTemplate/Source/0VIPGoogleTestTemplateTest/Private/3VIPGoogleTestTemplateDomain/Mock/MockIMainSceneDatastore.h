#pragma once
#include "MockISceneDatastore.h"
#include "Scenes/Main/IMainSceneDatastore.h"
#include "gmock/gmock.h"

class MockIMainSceneDatastore : public IMainSceneDatastore, public MockISceneDatastore
{
public:
	
};
