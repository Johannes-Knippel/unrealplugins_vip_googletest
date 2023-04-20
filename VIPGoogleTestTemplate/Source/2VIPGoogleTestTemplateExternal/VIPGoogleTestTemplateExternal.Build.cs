using System.IO;
using UnrealBuildTool;
 
public class VIPGoogleTestTemplateExternal : ModuleRules
{
    public VIPGoogleTestTemplateExternal(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/"));
        bUseRTTI = true;

        PublicDependencyModuleNames.AddRange
        (
            new []
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange
        (
            new []
            {
                "Engine",
                "Slate",
                "SlateCore",
                "Projects",
                                
                // Our modules
                "VIPGoogleTestTemplateDomain",
            }
        );
    }
}
