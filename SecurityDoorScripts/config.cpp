class CfgPatches
{
    class SecurityDoorScripts
    {
        requiredAddons[]=
        {
            "Security_Doors_Mod"
        };
    };
};

class CfgMods
{
    class SecurityDoorScripts
    {
        name = "SecurityDoorScripts";
        type = "mod";
        dependencies[]=
		{
			"Mission"
		};
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"SecurityDoorScripts\4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"SecurityDoorScripts\5_Mission"};
            };
        };
    };
};