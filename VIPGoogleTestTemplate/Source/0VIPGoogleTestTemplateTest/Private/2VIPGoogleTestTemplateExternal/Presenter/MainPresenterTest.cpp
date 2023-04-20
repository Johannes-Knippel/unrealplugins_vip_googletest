#include "VIPGoogleTestTemplateDomainModule.h"
#include "CoreTypes.h"
#include "2VIPGoogleTestTemplateExternal/Mock/MockIMainPresenter.h"
#include "2VIPGoogleTestTemplateExternal/Mock/MockIMainView.h"
#include "3VIPGoogleTestTemplateDomain/Mock/MockIMainSceneDatastore.h"
#include "Misc/AutomationTest.h"

namespace MainPresenterTest{
#pragma region Utilities

#if WITH_DEV_AUTOMATION_TESTS
#define DEFAULT_TEST_FLAGS EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter

	using ::testing::AtLeast;
	using ::testing::Exactly;
	using ::testing::Return;
	using ::testing::ReturnNull;
	using ::testing::AtMost;

	TSharedPtr<IMainPresenter> Presenter;

	TSharedPtr<MockIMainView> MockView;
	TSharedPtr<MockIMainSceneDatastore> MockSceneDatastore;

	void Setup()
	{
		MockView = MakeShared<MockIMainView>();
		MockSceneDatastore = MakeShared<MockIMainSceneDatastore>();
		
		Presenter = FDomainModule::Get().GetContainer().GetInstance<IMainPresenter>();
		Presenter->Setup(MockView, MockSceneDatastore);
	}

	void Teardown()
	{
		MockView.Reset();
		MockSceneDatastore.Reset();
	}


#pragma endregion
#pragma region PresentError

	IMPLEMENT_SIMPLE_AUTOMATION_TEST(PresentError_CallsDisplayError,
	                                 "VIPGoogleTestTemplate.2Editor.MainPresenter.PresentError.CallsDisplayError", DEFAULT_TEST_FLAGS)

	bool PresentError_CallsDisplayError::RunTest(const FString& Parameters)
	{
		Setup();

		const FString ErrorMessage("Dummy Error Message");

		EXPECT_CALL(*MockView, DisplayError
		            (
			            testing::Field(&ShowError::FViewModel::Message, ErrorMessage)
		            ))
		.Times(Exactly(1));

		Presenter->PresentError(ShowError::FResponse{ErrorMessage});

		Teardown();
		return true;
	}

#pragma endregion
#endif
}
