#pragma once

#include "CoreMinimal.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SButton.h"
#include "VIPGoogleTestTemplateStyle.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "TemplateToolMainWidget"

class SMainWidget : public SCompoundWidget
{
public:
SLATE_BEGIN_ARGS(SMainWidget)
		{
		}

	SLATE_EVENT(FOnClicked, OnAddTask);

	SLATE_END_ARGS()

	BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION


	void Construct(const FArguments& InArgs)
	{
		const FText AddTaskButtonText = LOCTEXT("Add Task button text", "+ Add Task");
		
		ChildSlot
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SButton)
						.ButtonStyle(FVIPGoogleTestTemplateStyle::Get(), "Button.AddTaskButton")
						.TextStyle(FVIPGoogleTestTemplateStyle::Get(), "Text.AddTaskButton")
						.ForegroundColor(FLinearColor::White)
						.ContentPadding(FMargin(6, 2))
						.Text(AddTaskButtonText)
						.OnClicked(InArgs._OnAddTask)
					]
				]
			];
	}

	END_SLATE_FUNCTION_BUILD_OPTIMIZATION
};

#undef LOCTEXT_NAMESPACE