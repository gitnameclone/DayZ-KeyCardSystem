/* ====================================================================================================================
*  Double Doors
*/

modded class SDM_Security_Double_Door_Base 
{
    /*  ================================== 
    *   Global configs for every Double door
    */

    override string GetCrateClassName()
    {
        return "TortillaBag";
    }

    override void AddLoot( EntityAI crate )
    {
        super.AddLoot( crate );

        crate.GetInventory().CreateInInventory("M4A1");
    }

};

modded class SDM_Security_Double_Door_Yellow 
{
    //super.AddLoot( crate ); /* Ignore global config */
	 override string GetCrateClassName()
    {
        return "SDM_BigCrate_Yellow";   										/* Override global config of crate for LVL 4*/
    }

    override void AddLoot( EntityAI crate )
    {
        crate.GetInventory().CreateInInventory("M4A1");
    }
};
modded class SDM_Security_Double_Door_Blue 
{
    //super.AddLoot( crate );
	override string GetCrateClassName()
    {
        return "SDM_BigCrate_Blue";   										/* Override global config of crate for LVL 4*/
    }

    override void AddLoot( EntityAI crate )
    {
        crate.GetInventory().CreateInInventory("M4A1");
    }
};
modded class SDM_Security_Double_Door_Red 
{
    override string GetCrateClassName()
    {
        return "SDM_BigCrate_Red";   										/* Override global config of crate for LVL 4*/
    }

    override void AddLoot( EntityAI crate )
    {
        crate.GetInventory().CreateInInventory("M4A1");
    }
};

modded class SDM_Security_Double_Door_Black 
{
    override string GetCrateClassName()
    {
        return "SDM_BigCrate_Black";   										/* Override global config of crate for LVL 4*/
    }

    override void AddLoot( EntityAI crate )
    {
        //super.AddLoot( crate ); /* Inherit global config */
		
		int selectedLoadout = Math.RandomIntInclusive( 0, 1);									//!change randomization limit after adding new loadouts!
		
        EntityAI weapon;
		if ( selectedLoadout == 0 )
		{
			weapon = EntityAI.Cast(crate.GetInventory().CreateInInventory("CBM_M82A2_Black")); 		
			if (weapon)
			{
				weapon.GetInventory().CreateAttachment("CBM_M82A2_Suppressor_Black");
				weapon.GetInventory().CreateAttachment("CBM_Mag_M82A2_10Rnd");
				weapon.GetInventory().CreateAttachment("HuntingOptic");
			}
			crate.GetInventory().CreateInInventory("MVS_Rucksack_Black");
			crate.GetInventory().CreateInInventory("CBM_Ammo_50BMG");
		}
		if ( selectedLoadout == 1 )
		{
			weapon = EntityAI.Cast(crate.GetInventory().CreateInInventory("CBM_M82A2_Grey")); 		
			if (weapon)
			{
				weapon.GetInventory().CreateAttachment("CBM_M82A2_Suppressor_Grey");
				weapon.GetInventory().CreateAttachment("CBM_Mag_M82A2_10Rnd");
				weapon.GetInventory().CreateAttachment("HuntingOptic");
			}
			crate.GetInventory().CreateInInventory("MVS_Rucksack_Black");
			crate.GetInventory().CreateInInventory("CBM_Ammo_50BMG");
		}
    }
};
