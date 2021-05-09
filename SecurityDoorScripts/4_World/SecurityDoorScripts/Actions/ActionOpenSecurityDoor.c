class ActionOpenSecurityDoor : ActionInteractBase {
    void ActionOpenSecurityDoor() {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_HUDCursorIcon = CursorIcons.None;
	}
    
	override string GetText() {
		return "Open Security Door";
	}


	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        
        Print("ActionOpenSecurityDoor");

        Object targetObject = target.GetObject();

        Print( "" + targetObject );

        if (targetObject.IsInherited( SDM_Security_Door_Base )) {

            return true;
        }
        

		return false;
	}
}