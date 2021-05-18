class CfgPatches
{
    class SecurityDoorScripts
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
            "World",
			"Mission"
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