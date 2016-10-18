// Copyright 2015 Agog Labs, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
  public class SkookumScriptEditorGUI : ModuleRules
  {
    public SkookumScriptEditorGUI(TargetInfo Target)
    {
      // NOTE: SkookumScriptEditorGUI does not use the AgogCore or SkookumScript libraries
      
      PublicIncludePaths.AddRange(
        new string[] {					
          //"Programs/UnrealHeaderTool/Public",
          // ... add other public include paths required here ...
        }
        );

      PrivateIncludePaths.AddRange(
        new string[] {
          // ... add other private include paths required here ...
        }
        );

      PublicDependencyModuleNames.AddRange(
        new string[]
        {
          "Core",
          "CoreUObject",
          "Engine",
          "UnrealEd",
          // ... add other public dependencies that you statically link with here ...
        }
        );

      PrivateDependencyModuleNames.AddRange(
        new string[]
        {
          "InputCore",
          "AssetTools",
          "SkookumScriptRuntime",
          "ClassViewer",
          "KismetCompiler",
          "Kismet",
          "BlueprintGraph",
          "LevelEditor",
          "SlateCore",
          "Slate",
          "EditorStyle",
          "Projects",
          // ... add private dependencies that you statically link with here ...
        }
        );

      DynamicallyLoadedModuleNames.AddRange(
        new string[]
        {
          // ... add any modules that your module loads dynamically here ...
        }
        );
    }
  }
}