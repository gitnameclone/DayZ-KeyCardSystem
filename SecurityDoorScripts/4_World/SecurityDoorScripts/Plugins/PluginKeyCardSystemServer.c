class SecurityDoorLocationConfig 
{
    string className;
    vector location;
    vector dir;

    void SecurityDoorLocationConfig( string ClassName, vector Location, vector Direction) 
    {
        className = ClassName;
        location = Location;
        dir = Direction;
    }

    string GetClassName() 
    {
        return className;
    }

    vector GetPosition() 
    {
        return location;
    }

    vector GetDirection() {
        return dir;
    }
}

class KeyCardSystemConfig 
{
    int version;
    ref array< ref SecurityDoorLocationConfig > locations;

    void KeyCardSystemConfig( int Version ) 
    {
        version = Version;
        locations = new array< ref SecurityDoorLocationConfig >;
    }

    void InsertLocation( string className, vector pos, vector dir)
    {
        locations.Insert( new SecurityDoorLocationConfig( className, pos, dir ));
    }

    void SetVersion( int Version ) {
        version = Version;
    }

}

class PluginKeyCardSystemServer : PluginBase 
{
    const static int VERSION = 5;

    const static string PROFILE = "$profile:KeyCardSystem";
    const static string CONFIG = PROFILE + "/config.json";

    const static string DATA_DIR = PROFILE + "/data";
    const static string LOCATION_DATA = DATA_DIR + "/cache.dat";
    const static string PERSISTANCE_DATA = DATA_DIR + "/persistance.dat";

    ref KeyCardSystemConfig m_config;
    ref array<ref SecurityDoorPersistanceData> m_persistanceData;

    protected bool m_HasConfigChanged = false;

    void PluginKeyCardSystemServer() 
    {
        Init();
    }

    void Init() 
    {

        m_config = new KeyCardSystemConfig(VERSION);
        m_persistanceData = new array< ref SecurityDoorPersistanceData>;

        if (!FileExist( PROFILE ))
            MakeDirectory( PROFILE );

        if ( !FileExist( CONFIG )) 
        {
            m_config.InsertLocation( "SDM_Security_Double_Door_Lvl_4", "8336.31 6.364 2941.23", "0 0 0" );

            JsonFileLoader<ref KeyCardSystemConfig>.JsonSaveFile( CONFIG, m_config);
        }

        JsonFileLoader<ref KeyCardSystemConfig>.JsonLoadFile( CONFIG, m_config);

        if( m_config.version != VERSION) 
        {
            DeletePersistanceFiles();
            m_config.SetVersion( VERSION );
            JsonFileLoader<ref KeyCardSystemConfig>.JsonSaveFile( CONFIG, m_config);
        }


        m_HasConfigChanged = HasConfigChanged();
    }

    /* 
    *   Compares current config with previous persitance data.
    *   True - OK
    *   False - corrupted/changed
    */
    protected bool HasConfigChanged() 
    {
        if ( !FileExist( DATA_DIR ) )
            MakeDirectory( DATA_DIR );
        
        if ( !FileExist( LOCATION_DATA ) || !FileExist( PERSISTANCE_DATA ))   
            return true;     /* data doesn't exist, return */


        ref array< ref SecurityDoorLocationConfig > prev_locations = new array< ref SecurityDoorLocationConfig >;
        FileSerializer fileHandle = new FileSerializer();

        if ( fileHandle.Open( LOCATION_DATA, FileMode.READ) ) {
            fileHandle.Read(prev_locations);
            fileHandle.Close();
        } else
            return true; /* Corrupted files probably, reset persistance data */

        if ( m_config.locations.Count() != prev_locations.Count() )
            return true;

        for ( int i=0; i<m_config.locations.Count(); i++ ) 
        {
            ref SecurityDoorLocationConfig currentConfig = m_config.locations[i];
            ref SecurityDoorLocationConfig persistanceConfig = prev_locations[i];

            if( !persistanceConfig )
                return true;

            /* Check if classnames are equal */
            if ( currentConfig.GetClassName() != persistanceConfig.GetClassName() )
                return true;

            /* Check for changes in position */
            if ( currentConfig.GetPosition() != persistanceConfig.GetPosition() )
                return true;

            /* Check for changes in direction */
            if ( currentConfig.GetDirection() != persistanceConfig.GetDirection() )
                return true;
            

        }

        return false;
    }

    protected void DeletePersistanceFiles() 
    {
        DeleteFile( LOCATION_DATA );
        DeleteFile( PERSISTANCE_DATA );
    }


    void SpawnItems() 
    {
        /*
        *   Has to be called from OnMissionStart() 
        */

        int i = 0;

        if ( m_HasConfigChanged ) {

            Print("KEYCARDSYSTEM: CREATING NEW PERSISTANCE DATA");

            /* config has changed, delete old persistance files and create new. */
            DeletePersistanceFiles();

            foreach( ref SecurityDoorLocationConfig config : m_config.locations ) {
                auto obj = GetGame().CreateObjectEx( config.GetClassName(), config.GetPosition(), ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);

                SDM_Security_Door_Base door;
                Class.CastTo( door, obj );

                door.SetPosition( config.GetPosition() );
                door.SetOrientation( config.GetDirection() );
                door.SetOrientation( door.GetOrientation() );
                door.Update();

                SecurityDoorPersistanceData persistanceData = new SecurityDoorPersistanceData;
                persistanceData.SetType( door.GetType() );
                persistanceData.SetPosition( door.GetPosition() );
                persistanceData.SetOrientation( door.GetOrientation() );

                door.SetPersistanceData( persistanceData );


                m_persistanceData.Insert( persistanceData );
            }

            CreatePersistanceFiles();

        } else {

            Print("KEYCARDSYSTEM: LOADING OLD PERSISTANCE DATA");

            /* Load old persistance data */
            LoadOldPersistance();


        }

        /* TODO: Start timer for monitor */
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( SavePersistance, 3000,  true );

    }

    protected void LoadOldPersistance() 
    {
		 FileSerializer fileHandle = new FileSerializer();
		
        if ( fileHandle.Open( PERSISTANCE_DATA, FileMode.READ) )
            fileHandle.Read( m_persistanceData ); 

        foreach( ref SecurityDoorPersistanceData persistantitem : m_persistanceData ) {
			
			
            auto obj = GetGame().CreateObjectEx( persistantitem.GetType(), persistantitem.GetPosition(), ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
            
			SDM_Security_Door_Base door;
            Class.CastTo( door, obj );
			
			door.SetPosition( persistantitem.GetPosition() );
            door.SetOrientation( persistantitem.GetOrientation() );
            door.SetOrientation( door.GetOrientation() );
            door.Update();
			
			door.SetPersistanceData( persistantitem );
			
			
        }

    }

    protected void CreatePersistanceFiles() 
    {
        FileSerializer fileHandle = new FileSerializer();

        /* Create locations data for config change comparison */
        if ( fileHandle.Open( LOCATION_DATA, FileMode.WRITE) )
            fileHandle.Write( m_config.locations );

        /* Create persistance for objects */
        if ( fileHandle.Open( PERSISTANCE_DATA, FileMode.WRITE) )
            fileHandle.Write( m_persistanceData ); 

    }

    protected void SavePersistance()
    {
        Print("Saving Persistance...");

        foreach( ref SecurityDoorPersistanceData data : m_persistanceData){

            foreach( int index, bool state: data.m_DoorState) {

                Print( "index: " + index + " state: " + state);
            }

        }

        FileSerializer fileHandle = new FileSerializer();

        if ( fileHandle.Open( PERSISTANCE_DATA, FileMode.WRITE) )
            fileHandle.Write( m_persistanceData ); 
    }
}