#pragma once

namespace ShowError{
	struct FResponse
	{
		FString Message;
	};
}

struct IPresenter
{
	virtual ~IPresenter() = default;
	virtual void PresentError(const ShowError::FResponse& Response) = 0;
};
