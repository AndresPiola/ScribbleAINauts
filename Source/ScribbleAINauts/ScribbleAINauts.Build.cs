// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ScribbleAINauts : ModuleRules
{
	public ScribbleAINauts(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		PrivateDependencyModuleNames.AddRange(new[] {"Json", "JsonUtilities"});
		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"HTTP", "Json", "JsonUtilities"
			});
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}