modded class ActionOpenDoors
{
    protected bool m_IsSecurityDoor;
    protected ItemBase m_ItemInHands;
    
    override string GetText()
	{
        if ( m_IsSecurityDoor )
		    return "Swipe Card";
        else
            return "#open";
            
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

    protected bool CanAuthorize(Object target, SDM_Keycard_Base card) 
    {
        if ( !target ) return false;

        string doorType = target.GetType();

        return card.CanAuthorizeDoor( doorType );

    }

    protected ItemBase GetItemInHands( PlayerBase player) {
        return player.GetItemInHands();
    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        if (!target)
            return false;

        m_IsSecurityDoor = IsSecurityDoor( target.GetObject());

        if( m_IsSecurityDoor ) 
        {
            ItemBase inHandItem = GetItemInHands( player );

            if( !inHandItem)
                return false;

            SDM_Keycard_Base keyCard;

            if (inHandItem)
                Class.CastTo( keyCard, inHandItem);

            if( CanAuthorize( target.GetObject(), keyCard ) ) 
                return super.ActionCondition( player, target, inHandItem );
            else
                return false;

        }


        return super.ActionCondition( player, target, item );
	}

    override void OnStartServer( ActionData action_data )
	{
        if ( m_IsSecurityDoor ) 
        {
            m_ItemInHands = action_data.m_Player.GetItemInHands();
            if ( !m_ItemInHands.IsInherited( SDM_Keycard_Base ) )
                return;
            
            m_ItemInHands.Delete();

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