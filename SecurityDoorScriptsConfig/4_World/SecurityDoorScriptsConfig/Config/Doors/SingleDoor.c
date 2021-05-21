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

modded class SDM_Security_Single_Door_Yellow 
{
    //super.AddLoot( crate ); /* Ignore global config */

    override void AddLoot( EntityAI crate )
    {
        crate.GetInventory().CreateInInventory("M4A1");
    }
};
modded class SDM_Security_Single_Door_Blue 
{
    //super.AddLoot( crate );

    override void AddLoot( EntityAI crate )
    {
        crate.GetInventory().CreateInInventory("M4A1");
    }
};
modded class SDM_Security_Single_Door_Red 
{
    //super.AddLoot( crate );

    override void AddLoot( EntityAI crate )
    {
        crate.GetInventory().CreateInInventory("M4A1");
    }
};

modded class SDM_Security_Single_Door_Black
{
    override void AddLoot( EntityAI crate )
    {
        super.AddLoot( crate ); /* Inherit global config */

        crate.GetInventory().CreateInInventory("AK74"); /* Add additional M4A1 */
    }
};
