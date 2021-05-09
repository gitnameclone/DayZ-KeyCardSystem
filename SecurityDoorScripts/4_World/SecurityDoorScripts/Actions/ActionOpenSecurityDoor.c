class ActionOpenSecurityDoorCB : ActionContinuousBaseCB {

    override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 2 );
	}
}

class ActionOpenSecurityDoor : ActionContinuousBase {

    void ActionOpenSecurityDoor() {
        m_CallbackClass = ActionOpenSecurityDoorCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;

	}

    override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTObject();
	}

    



	override string GetText() {
		return "Swipe Card";
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

    
	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient( action_data );

        Print("OnEndClient");
        GetGame().ChatPlayer("OnEndClient");
		
		
	}
}