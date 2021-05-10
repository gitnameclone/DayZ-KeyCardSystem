modded class ActionCloseDoors
{
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) 
			return false;

        SDM_Security_Door_Base door;

        if ( Class.CastTo(door, target.GetObject()) )
            return false;

        return super.ActionCondition( player, target, item);
	}
}
