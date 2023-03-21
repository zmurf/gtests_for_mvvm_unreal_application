using UnrealBuildTool;
using System.Collections.Generic;

public class cmake_gtestEditorTarget : TargetRules
{
    public cmake_gtestEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V2;

        //Added additional modules here otherwise not shown in editor also needed to be added under modules in .uproject file
        ExtraModuleNames.AddRange(new string[] { "ModuleA", "ModuleB", "Engine" });

        //Needed for protobuf
        bPublicSymbolsByDefault = true;
    }
}
