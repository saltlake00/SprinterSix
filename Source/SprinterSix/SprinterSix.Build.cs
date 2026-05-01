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
			ModuleDirectory,
			"SprinterSix",
			"SprinterSix/_Example",
			"SprinterSix/_Example/Variant_Platforming",
			"SprinterSix/_Example/Variant_Platforming/Animation",
			"SprinterSix/_Example/Variant_Combat",
			"SprinterSix/_Example/Variant_Combat/AI",
			"SprinterSix/_Example/Variant_Combat/Animation",
			"SprinterSix/_Example/Variant_Combat/Gameplay",
			"SprinterSix/_Example/Variant_Combat/Interfaces",
			"SprinterSix/_Example/Variant_Combat/UI",
			"SprinterSix/_Example/Variant_SideScrolling",
			"SprinterSix/_Example/Variant_SideScrolling/AI",
			"SprinterSix/_Example/Variant_SideScrolling/Gameplay",
			"SprinterSix/_Example/Variant_SideScrolling/Interfaces",
			"SprinterSix/_Example/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
