class SecurityDoorPersistanceData {
    string className;
    vector location;
    vector dir;
    vector crateLocation;
    vector crateDir;

    float autoClose;

    ref map<int, bool> m_DoorState;
	ref map<int, float> m_DoorTimers;

    void SecurityDoorPersistanceData() {
        m_DoorState = new map<int, bool>;
		m_DoorTimers = new map<int, float>;
    }

    string GetType() {
        return className;
    }

    vector GetPosition() {
        return location;
    }

    vector GetOrientation() {
        return dir;
    }

    vector GetCratePosition() {
        return crateLocation;
    }

    vector GetCrateOrientation()
    {
        return crateDir;
    }

    float GetAutoCloseTime() 
    {
        return autoClose;
    }

    bool IsOpen( int index ) {
        return m_DoorState[ index ];
    }

    void SetType( string ClassName ) {
        className = ClassName;
    }

    void SetPosition( vector Location ) {
        location = Location;
    }

    void SetOrientation( vector Orientation) {
        dir = Orientation;
    }

    void SetIsOpen( int index, bool state ) {
        m_DoorState[ index ] = state;
    }

    void SetAutoCloseTime( float AutoCloseTime ) {
        autoClose = AutoCloseTime;
    }

    void SetCratePosition( vector Location) {
        crateLocation = Location;
    }

    void SetCrateOrientation( vector Direction ) {
        crateDir = Direction;
    }

}

class SDM_Security_Door_Base : Building {
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
        Print("KEYCARDSYSTEM: ADDING LOOT...");
    }

    protected void SpawnRewards()
    {
        Print("KEYCARDSYSTEM: SPAWNING REWARD CRATE..");

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

    void Open( int index ) 
    {
        this.OpenDoor( index );
        m_persistanceData.SetIsOpen( index, true);

        SetTimeTillAutoClose( index, m_persistanceData.GetAutoCloseTime() * 1000 );

        /* Spawn crate */
        SpawnRewards();
    }

    void Close( int index )
    {
        this.CloseDoor( index );
        m_persistanceData.SetIsOpen( index, false);

        DeleteRewards();
    }
};

class SDM_Security_Single_Door_Base : SDM_Security_Door_Base {};

class SDM_Security_Single_Door_Lvl_1 : SDM_Security_Single_Door_Base {};
class SDM_Security_Single_Door_Lvl_2 : SDM_Security_Single_Door_Base {};
class SDM_Security_Single_Door_Lvl_3 : SDM_Security_Single_Door_Base {};
class SDM_Security_Single_Door_Lvl_4 : SDM_Security_Single_Door_Base {};

class SDM_Security_Double_Door_Base : SDM_Security_Door_Base {};

class SDM_Security_Double_Door_Lvl_1 : SDM_Security_Double_Door_Base {};
class SDM_Security_Double_Door_Lvl_2 : SDM_Security_Double_Door_Base {};
class SDM_Security_Double_Door_Lvl_3 : SDM_Security_Double_Door_Base {};
class SDM_Security_Double_Door_Lvl_4 : SDM_Security_Double_Door_Base {
    override void AddLoot( EntityAI crate )
    {
        super.AddLoot( crate );

        crate.GetInventory().CreateInInventory("M4A1");
    }

    override string GetCrateClassName()
    {
        return "TortillaBag";
    }
};

#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\init.c"

