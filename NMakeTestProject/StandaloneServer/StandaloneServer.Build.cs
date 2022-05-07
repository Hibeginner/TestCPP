using UnrealBuildTool;
using System.IO;
using System;

/**
 * 这个c#文件在vs工程里不参与编译，也不会报错
 */
public class StandaloneServer : ModuleRules
{
    public StandaloneServer(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}