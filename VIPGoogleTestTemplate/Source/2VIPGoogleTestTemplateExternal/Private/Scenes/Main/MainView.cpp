#pragma once

#include "MainView.h"
#include "Scenes/Main/IMainInteractor.h"
#include "Scenes/Main/IMainView.h"
#include "Widgets/SMainWidget.h"

void FMainView::DisplayError(const ShowError::FViewModel& ViewModel)
{
	// TODO: Not implemented
}

TSharedRef<SMainWidget> FMainView::FetchMainWidget()
{
	if (!Widget.IsValid())
		Widget = SNew(SMainWidget)
		.OnAddTask_Raw(this, &FMainView::OnAddTask);
	return Widget.ToSharedRef();
}

FReply FMainView::OnAddTask() const
{
	Interactor.Pin()->AddTask(AddTask::FRequest());
	return FReply::Handled();
}