modded class ActionOpenDoors
{
    protected string m_actionTXT = "#open";
    protected bool m_IsSecurityDoor;
    protected ItemBase m_ItemInHands;
    
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

    protected bool CanAuthorize(Object target, ItemBase item) 
    {
        if ( !target || !item ) return false;

        SDM_Keycard_Base card;
        if ( !Class.CastTo( card, item )) return false;

        string doorType = target.GetType();

        return card.CanAuthorizeDoor( doorType );

    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        if (!target)
            return false;

        m_IsSecurityDoor = IsSecurityDoor( target.GetObject());

        if( m_IsSecurityDoor )
            if( !CanAuthorize( target.GetObject(), item ) )
                return false;
        

        SDM_Keycard_Base keyCard;

        if (item)
            Class.CastTo( keyCard, item);

		if (keyCard && m_IsSecurityDoor) 
            m_actionTXT = "Swipe Card";


        return super.ActionCondition( player, target, item );
	}

    override void OnStartServer( ActionData action_data )
	{
        if ( m_IsSecurityDoor ) 
        {
            m_ItemInHands = action_data.m_Player.GetItemInHands();
            if ( !m_ItemInHands.IsInherited( SDM_Keycard_Base ) ) {
                m_ItemInHands.Delete();
                return;
            }




            SDM_Security_Door_Base door;

            if (Class.CastTo( door, action_data.m_Target.GetObject())) {

                int doorIndex = door.GetDoorIndex(action_data.m_Target.GetComponentIndex());
                if ( doorIndex != -1 )
                    door.Open( doorIndex );

                return;
            }
            
        }

        super.OnStartServer( action_data );

	}
	
}