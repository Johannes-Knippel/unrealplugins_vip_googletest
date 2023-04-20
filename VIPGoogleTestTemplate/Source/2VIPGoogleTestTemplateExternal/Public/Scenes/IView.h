#pragma once

class SCompoundWidget;

namespace ShowError
{
	struct FViewModel
	{
		FString Message;
	};
}

struct IView
{
	virtual ~IView() = default;
	virtual TSharedPtr<SCompoundWidget> FetchWidget() = 0;
	virtual void DisplayError(const ShowError::FViewModel &ViewModel) = 0;
};
