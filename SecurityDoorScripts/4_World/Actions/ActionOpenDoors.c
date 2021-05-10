modded class ActionOpenDoors
{
    protected string m_actionTXT = "#open";
    protected bool m_IsSecurityDoor;
    
    override string GetText()
	{
		return m_actionTXT;
	}

    protected bool IsSecurityDoor(Object target) 
    {
        if ( !target ) 
			return false;

        SDM_Security_Door_Base door;
        if ( Class.CastTo(door, target))
            return true;

        return false;
    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        if (!target)
            return false;

        m_IsSecurityDoor = IsSecurityDoor( target.GetObject());

        SDM_Keycard_Base keyCard;

        if (item)
            Class.CastTo( keyCard, item);

		if (keyCard && m_IsSecurityDoor) 
            m_actionTXT = "Swipe Card";


        return super.ActionCondition( player, target, item );
	}
}