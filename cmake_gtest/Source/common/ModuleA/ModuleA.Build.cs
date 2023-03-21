using System;
using System.IO;
using UnrealBuildTool;

public class ModuleA : ModuleRules
{
    public ModuleA(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        //bUseRTTI = true;
        bEnableExceptions = true;

        PublicIncludePaths.Add(ModuleDirectory);
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public/AExample"));

        PublicDependencyModuleNames.AddRange(new string[] {
            "ModuleB",
            "Core",
            "CoreUObject"
        });
    }
}
