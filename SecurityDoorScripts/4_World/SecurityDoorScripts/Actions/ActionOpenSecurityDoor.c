class ActionOpenSecurityDoorCB : ActionContinuousBaseCB {

    override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 2 );
	}
}

class ActionOpenSecurityDoor : ActionInteractBase {

    void ActionOpenSecurityDoor() 
    {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_HUDCursorIcon = CursorIcons.None;
	}

    override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText() {
		return "Swipe Card";
	}


    override bool HasProgress() 
    {
        return true;
    }

	override bool HasTarget()
	{
		return true;
	}

	override bool HasProneException()
	{
		return true;
	}
    


	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        if ( GetGame().IsServer())
            return true;
        
        Print("ActionOpenSecurityDoor");

        Object targetObject = target.GetObject();

        Print( "" + targetObject );

        if (targetObject.IsInherited( SDM_Security_Door_Base )) {
            return true;
        }
        

		return false;
	}

    override  void OnExecuteClient( ActionData action_data )
	{
        super.OnExecuteClient( action_data );

        Print("OnExecuteClient");
        GetGame().ChatPlayer("OnExecuteClient");
	}

    override void OnExecuteServer( ActionData action_data )
	{	
		super.OnExecuteServer( action_data );

        Print("OnExecuteServer");
	}
}