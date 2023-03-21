using System;
using System.IO;
using UnrealBuildTool;

public class ModuleB : ModuleRules
{
    public ModuleB(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        //bUseRTTI = true;
        bEnableExceptions = true;

        PublicIncludePaths.Add(ModuleDirectory);
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "FolderA/Public"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "FolderB/Public"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "FolderC/Public"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "FolderC/Public/Defines"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "FolderD/Public"));

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject"
        });
    }
}
