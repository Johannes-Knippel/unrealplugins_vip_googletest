#include "VIPGoogleTestTemplateStyle.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"

#define DEFAULT_FONT(...) FCoreStyle::GetDefaultFontStyle(__VA_ARGS__)

TSharedPtr< FSlateStyleSet > FVIPGoogleTestTemplateStyle::StyleInstance = NULL;

void FVIPGoogleTestTemplateStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FVIPGoogleTestTemplateStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FVIPGoogleTestTemplateStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("VIPGoogleTestTemplateStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FVIPGoogleTestTemplateStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("VIPGoogleTestTemplateStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("VIPGoogleTestTemplate")->GetBaseDir() / TEXT("Resources"));

	Style->Set("ToolbarButton.VIPGoogleTestTemplatePluginAction", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));
	Style->Set("ToolbarButton.DocumentationPluginAction.Small", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon20x20));

	// Button Style
	FButtonStyle Button = FButtonStyle();
	Style->Set("Button.AddTaskButton", FButtonStyle(Button)
	                               .SetNormal(BOX_BRUSH("RoundedSelection_16x", 4.0f / 16.0f, FLinearColor(0.10616, 0.48777, 0.10616)))
	                               .SetHovered(BOX_BRUSH("RoundedSelection_16x", 4.0f / 16.0f, FLinearColor(0.15616, 0.60777, 0.15616)))
	                               .SetPressed(BOX_BRUSH("RoundedSelection_16x", 4.0f / 16.0f, FLinearColor(0.08616, 0.38777, 0.08616))));

	auto NormalText = FTextBlockStyle()
			.SetFont(DEFAULT_FONT("Regular", FCoreStyle::RegularTextSize))
			.SetColorAndOpacity(FSlateColor::UseForeground())
			.SetShadowOffset(FVector2D::ZeroVector)
			.SetShadowColorAndOpacity(FLinearColor::Black)
			.SetHighlightColor( FLinearColor( 0.02f, 0.3f, 0.0f ) )
			.SetHighlightShape( BOX_BRUSH( "Common/TextBlockHighlightShape", FMargin(3.f/8.f) ) );
	
	Style->Set( "Text.AddTaskButton", FTextBlockStyle( NormalText )
			.SetFont( DEFAULT_FONT( "Bold", 11 ) )
			.SetColorAndOpacity( FLinearColor( 1.0f, 1.0f, 1.0f ) )
			.SetHighlightColor( FLinearColor( 1.0f, 1.0f, 1.0f ) )
			.SetShadowOffset( FVector2D( 1, 1 ) )
			.SetShadowColorAndOpacity( FLinearColor( 0, 0, 0, 0.9f ) ) );


	

	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FVIPGoogleTestTemplateStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FVIPGoogleTestTemplateStyle::Get()
{
	return *StyleInstance;
}
