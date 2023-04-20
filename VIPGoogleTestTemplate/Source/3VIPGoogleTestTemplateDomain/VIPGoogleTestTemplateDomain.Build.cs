using System.IO;
using UnrealBuildTool;
 
public class VIPGoogleTestTemplateDomain : ModuleRules
{
    public VIPGoogleTestTemplateDomain(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/"));
        bUseRTTI = true;

        PublicDependencyModuleNames.AddRange
        (
            new []
            {
                "Core"
            }
        );
    }
}
