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

        if (item)
            Class.CastTo( keyCard, item);

		if (keyCard && Class.CastTo(door, target.GetObject())) 
            m_actionTXT = "Swipe Card";


        return super.ActionCondition( player, target, item );
	}
}