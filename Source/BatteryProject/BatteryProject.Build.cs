// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BatteryProject : ModuleRules
{
	public BatteryProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
