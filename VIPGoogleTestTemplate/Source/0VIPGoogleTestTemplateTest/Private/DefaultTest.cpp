#include "gmock/gmock.h"

namespace DefaultTest
{
#if WITH_DEV_AUTOMATION_TESTS
#define DEFAULT_TEST_FLAGS EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(DefaultTest_ReturnsTrue,
    "VIPGoogleTestTemplate.DefaultTest.ReturnsTrue", DEFAULT_TEST_FLAGS)

	bool DefaultTest_ReturnsTrue::RunTest(const FString& Parameters)
	{
		EXPECT_THAT(1, testing::Eq(1));
		return true;
	}

#endif
}
