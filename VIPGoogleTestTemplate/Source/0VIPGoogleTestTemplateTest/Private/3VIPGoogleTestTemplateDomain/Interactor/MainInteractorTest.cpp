#include "VIPGoogleTestTemplateDomainModule.h"
#include "CoreTypes.h"
#include "2VIPGoogleTestTemplateExternal/Mock/MockIMainPresenter.h"
#include "3VIPGoogleTestTemplateDomain/Mock/MockIMainSceneDatastore.h"
#include "Misc/AutomationTest.h"
#include "Scenes/Main/IMainInteractor.h"

namespace MainInteractorTest
{
#pragma region Utilities

#if WITH_DEV_AUTOMATION_TESTS
#define DEFAULT_TEST_FLAGS EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter

using ::testing::AtLeast;
using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnNull;
using ::testing::AtMost;

TSharedPtr<IMainInteractor> Interactor;

TSharedPtr<MockIMainPresenter> MockPresenter;
TSharedPtr<MockIMainSceneDatastore> MockSceneDatastore;

void Setup()
{
	MockPresenter = MakeShared<MockIMainPresenter>();
	MockSceneDatastore = MakeShared<MockIMainSceneDatastore>();

	// This is an example of how we can register a mock instance in the DI Container
	// FDomainModuleProxy::GetWritableContainer().RegisterInstance<IExternalService>(MockExternalService.ToSharedRef());
	
	Interactor = FDomainModule::Get().GetContainer().GetInstance<IMainInteractor>();
	Interactor->Setup(MockPresenter, MockSceneDatastore);
}

void Teardown()
{
	MockPresenter.Reset();
	MockSceneDatastore.Reset();
}


#pragma endregion
#pragma region DummyMethod

IMPLEMENT_SIMPLE_AUTOMATION_TEST(DummyMethod_CallsSpecifiedMockedMethod,
	"VIPGoogleTestTemplate.3Domain.MainInteractor.DummyMethod.CallsSpecifiedMockedMethod", DEFAULT_TEST_FLAGS)

bool DummyMethod_CallsSpecifiedMockedMethod::RunTest(const FString& Parameters)
{
	Setup();

	// TODO: This is just a placeholder. Real test could look like the following:
	
	// const TArray<TSharedPtr<FCapturableProperty>> CapturableProperties = CreateDefaultCapturableProperties();
	//
	// EXPECT_CALL(*DefaultCameraVariant, RemoveBindings())
	// .Times(Exactly(1));
	//
	// EXPECT_CALL(*MockVariantManagerFacade, GetCapturedProperties(_))
	// .Times(Exactly(0));
	//
	// EXPECT_CALL(*MockVariantManagerFacade, CaptureProperties(_, _, _, _))
	// .Times(Exactly(2))
	// .WillRepeatedly(SetArgReferee<1>(CapturableProperties));
	//
	// EXPECT_CALL(*MockVariantManagerFacade, CreateObjectBindingsOfObjects(_, _))
	// .Times(Exactly(2))
	// .WillRepeatedly(Return(FakeNewObjectBindings));	
	//
	// EXPECT_CALL(*MockVariantManagerFacade, CreatePropertyCaptures(
	// TestUtils::ArrayHasExpectedSize<TSharedPtr<FCapturableProperty>>(IBMWCameraVariant::GetRootSceneComponentPropertyNames().Num()), FakeNewObjectBindings, true))
	// .Times(Exactly(1));
	//
	// TestEqual(TEXT("Should be equal"),
	// 	VariantManagerService->UpdateCameraVariantProperties(DefaultCameraVariant), EVariantManagerServiceResult::Success);

	Teardown();
	return true;
}

#pragma endregion 
#endif
}
