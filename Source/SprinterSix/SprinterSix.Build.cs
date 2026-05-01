// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SprinterSix : ModuleRules
{
	public SprinterSix(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"SprinterSix",
			"SprinterSix/Variant_Platforming",
			"SprinterSix/Variant_Platforming/Animation",
			"SprinterSix/Variant_Combat",
			"SprinterSix/Variant_Combat/AI",
			"SprinterSix/Variant_Combat/Animation",
			"SprinterSix/Variant_Combat/Gameplay",
			"SprinterSix/Variant_Combat/Interfaces",
			"SprinterSix/Variant_Combat/UI",
			"SprinterSix/Variant_SideScrolling",
			"SprinterSix/Variant_SideScrolling/AI",
			"SprinterSix/Variant_SideScrolling/Gameplay",
			"SprinterSix/Variant_SideScrolling/Interfaces",
			"SprinterSix/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
