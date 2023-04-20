#pragma once

struct IMainView;

struct ISceneRouter
{
	virtual ~ISceneRouter() = default;
	virtual void Setup(TSharedPtr<IMainView> InMainView) = 0;
};

Expose_TNameOf(ISceneRouter)
