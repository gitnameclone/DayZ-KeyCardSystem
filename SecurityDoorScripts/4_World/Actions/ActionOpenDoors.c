modded class ActionOpenDoors
{
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        Print("" + item);
        
        if ( !target ) 
			return false;

        SDM_Security_Door_Base door;
		if ( Class.CastTo(door, target.GetObject()) )
            return false;

        return ActionCondition( player, target, item );
	}
}