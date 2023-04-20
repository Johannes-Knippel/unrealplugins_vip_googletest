using System.IO;
using UnrealBuildTool;
 
public class VIPGoogleTestTemplateExternalEditor : ModuleRules
{
    public VIPGoogleTestTemplateExternalEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/"));
        bUseRTTI = true;

        PublicDependencyModuleNames.AddRange
        (
            new []
            {
                "Core",
                "EditorWidgets"
            }
        );

        PrivateDependencyModuleNames.AddRange
        (
            new []
            {
                "CoreUObject",
                "Engine",
                "InputCore",
                "Projects",
                "Slate",
                "SlateCore",
                "ToolMenus",
                "WorkspaceMenuStructure",
                
                // Our modules
                "VIPGoogleTestTemplateExternal",
                "VIPGoogleTestTemplateDomain",
            }
        );
    }
}
