class SDM_Keycard_Base : ItemBase {

    override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionOpenSecurityDoor);
	} 

};

class SDM_Keycard_Lvl_1 : SDM_Keycard_Base {};
class SDM_Keycard_Lvl_2 : SDM_Keycard_Base {};
class SDM_Keycard_Lvl_3 : SDM_Keycard_Base {};
class SDM_Keycard_Lvl_4 : SDM_Keycard_Base {};