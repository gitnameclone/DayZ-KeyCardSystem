class ActionOpenSecurityDoorCB : ActionContinuousBaseCB {

    override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 2 );
	}
}

class ActionOpenSecurityDoor : ActionContinuousBase {

    void ActionOpenSecurityDoor() 
    {
        m_CallbackClass = ActionOpenSecurityDoorCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
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
        
        Object targetObject = target.GetObject();

        if (targetObject.IsInherited( SDM_Security_Door_Base )) {

            SDM_Security_Door_Base door;
            Class.CastTo( door, targetObject );

            Print( "" + door);

            if (door.IsClosed())
                return true;
            else
                return false;
        }
        

		return false;
	}

    override void OnEndClient( ActionData action_data )
	{
        super.OnEndClient( action_data );

        Print("OnEndClient");
        GetGame().ChatPlayer("OnEndClient");
	}

    override void OnEndServer( ActionData action_data )
	{
        super.OnEndServer( action_data );

        Print("OnEndServer");

	}
}