modded class SDM_Security_Door_Base {
    ref SecurityDoorPersistanceData m_persistanceData;
    ref PluginKeyCardSystemServer m_Plugin;


    void SDM_Security_Door_Base() 
    {
        m_Plugin = PluginKeyCardSystemServer.Cast( GetPlugin( PluginKeyCardSystemServer ) );
    }

    void SetPersistanceData( ref SecurityDoorPersistanceData data ) 
    {
        m_persistanceData = data;

        /* Update door state */
        foreach( int index, bool state : m_persistanceData.m_DoorState ) 
            if (state == true)
                this.OpenDoor( index );

    }

    void UpdatePersistance() 
    {
        m_persistanceData.className = this.GetType();
        m_persistanceData.location = this.GetPosition();
        m_persistanceData.dir = this.GetDirection();

        foreach( int index, bool state : m_persistanceData.m_DoorState )
            m_persistanceData.m_DoorState[index] = IsDoorOpen( index );
    }

    ref SecurityDoorPersistanceData GetPersistanceData() 
    {
        return m_persistanceData;
    }


    void SetTimeTillAutoClose( int index, float time ) 
    {
        m_persistanceData.m_DoorTimers[index] = time;
    }

    float TimeTillAutoClose(int index ) 
    {
        return m_persistanceData.m_DoorTimers[index];
    }

    protected string GetCrateClassName()
    {
        return "";
    }

    protected void AddLoot( EntityAI crate ) 
    {
        /* To be modded */
    }

    protected void SpawnRewards()
    {

        /* Spawn crate */
        if( GetCrateClassName() == "")
            return;

        Object crateObject = m_Plugin.SpawnRewardCrate( GetCrateClassName(), m_persistanceData.GetCratePosition(), m_persistanceData.GetCrateOrientation() );
        EntityAI crate;

        if ( Class.CastTo( crate, crateObject) )
            AddLoot(crate);

    }

    protected void DeleteRewards()
    {
        vector cratePos = m_persistanceData.GetCratePosition();

        bool success = m_Plugin.DeleteRewardCrate( GetCrateClassName(), m_persistanceData.GetCratePosition());
    }

    override void Open( int index ) 
    {
        this.OpenDoor( index );
        m_persistanceData.SetIsOpen( index, true);

        SetTimeTillAutoClose( index, m_persistanceData.GetAutoCloseTime() * 1000 );

        /* Spawn crate */
        SpawnRewards();
    }

    override void InitiateClose( int index )
    {
        float delay = m_persistanceData.GetCloseDelay();

        Print("Closing...");
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Close, delay, false, new Param1<index> );
    }

    override void Close( int index )
    {
        Print("Close...");

        this.CloseDoor( index );
        m_persistanceData.SetIsOpen( index, false);

        DeleteRewards();
    }
};