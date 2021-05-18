/* ====================================================================================================================
*  Single Doors
*/


modded class SDM_Security_Single_Door_Base 
{
    /*  ==================================== 
    *   Global configs for every Double door
    */
    override string GetCrateClassName()
    {
        return "TortillaBag";
    }

    override void AddLoot( EntityAI crate )
    {
        super.AddLoot( crate );

        crate.GetInventory().CreateInInventory("AK74");
    }
};

modded class SDM_Security_Single_Door_Lvl_1 
{
    //super.AddLoot( crate ); /* Ignore global config */

    crate.GetInventory().CreateInInventory("M4A1");
};
modded class SDM_Security_Single_Door_Lvl_2 
{
    //super.AddLoot( crate );

    crate.GetInventory().CreateInInventory("M4A1");
};
modded class SDM_Security_Single_Door_Lvl_3 
{
    //super.AddLoot( crate );

    crate.GetInventory().CreateInInventory("M4A1");
};

modded class SDM_Security_Single_Door_Lvl_4
{
    override void AddLoot( EntityAI crate )
    {
        super.AddLoot( crate ); /* Inherit global config */

        crate.GetInventory().CreateInInventory("AK74"); /* Add additional M4A1 */
    }
};
