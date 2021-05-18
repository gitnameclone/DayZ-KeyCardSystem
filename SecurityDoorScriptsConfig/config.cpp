class CfgPatches
{
    class SecurityDoorScriptsConfig
    {
        requiredAddons[]=
        {
            "SecurityDoorScripts"
        };
    };
};

class CfgMods
{
    class SecurityDoorScriptsConfig
    {
        name = "SecurityDoorScriptsConfig";
        type = "mod";
        dependencies[]=
		{
            "World"
		};
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"SecurityDoorScriptsConfig\4_World"};
            };
        };
    };
};