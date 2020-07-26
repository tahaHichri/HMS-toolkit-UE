/**
* !Created By Taha HICHRI
* @project    HMS Toolkit for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/tahaHichri
* Copyright (c) 2020 hishri.com
*/


using UnrealBuildTool;

public class HmsToolkit : ModuleRules
{
    public HmsToolkit(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                 "HmsToolkit/Private",
            }
            );


        PrivateIncludePaths.AddRange(
            new string[]
            {
                "Core",
                "Engine",
                "CoreUObject"
            }
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Engine",
                "Slate",
                "SlateCore"
			}
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
			}
            );


        // ignore platforms, except for Android.
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            //PrivateIncludePaths.Add("BluetoothSupport/Private/Android");

            PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });

            string PluginRelativePath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginRelativePath, "HmsModuleAPL.xml")));
        }
    }
}
