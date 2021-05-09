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
        
        Print("ActionOpenSecurityDoor");

        Object targetObject = target.GetObject();

        Print( "" + targetObject );

        if (targetObject.IsInherited( SDM_Security_Door_Base )) {
            return true;
        }
        

		return false;
	}

    override  void OnFinishProgressClient( ActionData action_data )
	{
        super.OnFinishProgressClient( action_data );

        Print("OnFinishProgressClient");
        GetGame().ChatPlayer("OnFinishProgressClient");
	}

    override void OnFinishProgressServer( ActionData action_data )
	{	
		super.OnFinishProgressServer( action_data );

        Print("OnFinishProgressServer");
	}
}