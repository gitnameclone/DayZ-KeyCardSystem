class CfgPatches
{
    class SecurityDoorScriptsClient
    {
        requiredAddons[]=
        {
            "Security_Doors_Mod"
        };
    };
};

class CfgMods
{
    class SecurityDoorScriptsClient
    {
        name = "SecurityDoorScriptsClient";
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
                files[] = {"SecurityDoorScriptsClient\4_World"};
            };
        };
    };
};