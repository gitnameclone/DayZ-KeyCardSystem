class CfgPatches
{
    class SecurityDoorScriptClient
    {
        requiredAddons[]=
        {
            "Security_Doors_Mod"
        };
    };
};

class CfgMods
{
    class SecurityDoorScriptClient
    {
        name = "SecurityDoorScriptClient";
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
                files[] = {"SecurityDoorScriptClient\4_World"};
            };
        };
    };
};