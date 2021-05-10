modded class ActionOpenDoors
{
    protected string m_actionTXT = "#open";
    
    override string GetText()
	{
		return m_actionTXT;
	}

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{

        if ( !target ) 
			return false;

        SDM_Security_Door_Base door;
        SDM_Keycard_Base keyCard;

		if (Class.CastTo(door, target.GetObject())) 
            if (Class.CastTo(keyCard, item))
                m_actionTXT = "Swipe Card";
            else
                return false;

        return ActionCondition( player, target, item );
	}
}