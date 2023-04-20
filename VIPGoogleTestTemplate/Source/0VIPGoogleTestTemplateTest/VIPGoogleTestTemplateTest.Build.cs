// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VIPGoogleTestTemplateTest : ModuleRules
{
	public VIPGoogleTestTemplateTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bUseRTTI = true;

		PublicDependencyModuleNames.AddRange
		(
			new []
			{
				"Core"
			}
		);

		PrivateDependencyModuleNames.AddRange
		(
			new []
			{
				"Engine",
				"GoogleTest",
				"CoreUObject",

				// Our modules
				"VIPGoogleTestTemplateDomain",
                "VIPGoogleTestTemplateExternal",
                "VIPGoogleTestTemplateExternalEditor"
			}
		);
	}
}
