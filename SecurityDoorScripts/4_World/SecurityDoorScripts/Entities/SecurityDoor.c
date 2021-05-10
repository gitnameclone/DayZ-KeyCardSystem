class SecurityDoorPersistanceData {
    string className;
    vector location;
    vector dir;

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
    
}

class SDM_Security_Door_Base : Building {
    ref SecurityDoorPersistanceData m_persistanceData;


    void SDM_Security_Door_Base() 
    {

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

    void Open( int index ) 
    {
        this.OpenDoor( index );
        m_persistanceData.SetIsOpen( index, true);

        SetTimeTillAutoClose( index, PluginKeyCardSystemServer.Cast( GetPlugin( PluginKeyCardSystemServer ) ).GetAutoCloseTimeConstant() * 1000 );
    }

    void Close( int index )
    {
        this.CloseDoor( index );
        m_persistanceData.SetIsOpen( index, false);
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
class SDM_Security_Double_Door_Lvl_4 : SDM_Security_Double_Door_Base {};


