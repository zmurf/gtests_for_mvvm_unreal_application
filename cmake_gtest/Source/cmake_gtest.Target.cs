using UnrealBuildTool;
using System.Collections.Generic;

public class cmake_gtestTarget : TargetRules
{
    public cmake_gtestTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V2;

        GlobalDefinitions.Add("NO_LOGGING=0");
        GlobalDefinitions.Add("USE_LOGGING_IN_SHIPPING=1");
        GlobalDefinitions.Add("ALLOW_CONSOLE_IN_SHIPPING=1");

        bOverrideBuildEnvironment = true;
        bUseLoggingInShipping = true;


        //Added additional modules here otherwise not shown in editor also needed to be added under modules in .uproject file
        ExtraModuleNames.AddRange(new string[] { "ModuleA", "ModuleB", "Engine" });

        //Needed for protobuf
        bPublicSymbolsByDefault = true;
    }
}
