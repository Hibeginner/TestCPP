using UnrealBuildTool;
using System.IO;
using System;

/**
 * ���c#�ļ���vs�����ﲻ������룬Ҳ���ᱨ��
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