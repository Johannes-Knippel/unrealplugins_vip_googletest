#pragma once
#include "Scenes/Main/IMainView.h"
#include "Scenes/Main/IMainInteractor.h"
#include "Scenes/Main/IMainView.h"
#include "Widgets/SMainWidget.h"

class FMainView : public IMainView
{
public:
	FMainView() = default;
	virtual ~FMainView() override = default;

	FORCEINLINE virtual void Setup(TSharedPtr<IMainInteractor> InInteractor) override
	{
		Interactor = InInteractor;
	}
	
	FORCEINLINE virtual TSharedPtr<SCompoundWidget> FetchWidget() override
	{
		return FetchMainWidget();
	}

	virtual void DisplayError(const ShowError::FViewModel& ViewModel) override;
	

private:
	TSharedRef<SMainWidget> FetchMainWidget();

	FReply OnAddTask() const;

	TSharedPtr<SMainWidget> Widget;
	TWeakPtr<IMainInteractor> Interactor;
};
