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

        class defs
        {
            class missionScriptModule
            {
                value = "";
                files[] = {"SecurityDoorScripts\5_Mission"};
            };
        };
    };
};