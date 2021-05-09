class ActionOpenSecurityDoorCB : ActionContinuousBaseCB {

    override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( -1.0 );
	}
}

class ActionOpenSecurityDoor : ActionContinuousBase {

    void ActionOpenSecurityDoor() {
        m_CallbackClass = ActionOpenSecurityDoorCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
	}


	override string GetText() {
		return "Open Security Door";
	}

    


	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        
        Print("ActionOpenSecurityDoor");

        Object targetObject = target.GetObject();

        Print( "" + targetObject );

        return true;

        if (targetObject.IsInherited( SDM_Security_Door_Base )) {

            return true;
        }
        

		return false;
	}

    
	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient( action_data );

        Print("OnEndClient");
        GetGame().ChatPlayer("OnEndClient");
		
		
	}
}