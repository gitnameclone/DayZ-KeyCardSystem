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
    ref array< ref SecurityDoorLocationConfig > locations;

    void KeyCardSystemConfig() 
    {
        locations = new array< ref SecurityDoorLocationConfig >;
    }

    void InsertLocation( string className, vector pos, vector dir)
    {
        locations.Insert( new SecurityDoorLocationConfig( className, pos, dir ));
    }

}

class PluginKeyCardSystemServer : PluginBase 
{
    const static string PROFILE = "$profile:KeyCardSystem";
    const static string CONFIG = PROFILE + "/config.json";

    const static string DATA_DIR = PROFILE + "/data";
    const static string LOCATION_DATA = DATA_DIR + "/cache.dat";
    const static string PERSISTANCE_DATA = DATA_DIR + "/persistance.dat";

    ref KeyCardSystemConfig m_config;

    void PluginKeyCardSystemServer() 
    {
        Init();

        CompareOldPersitance();
    }

    void Init() 
    {

        m_config = new KeyCardSystemConfig;

        if (!FileExist( PROFILE ))
            MakeDirectory( PROFILE );

        if ( !FileExist( CONFIG )) 
        {
            m_config.InsertLocation( "SDM_Security_Double_Door_Lvl_4", "8336.31 6.364 2941.23", "0 0 0" );
            m_config.InsertLocation( "SDM_Security_Double_Door_Lvl_4", "8337.31 6.364 2941.23", "0 0 0" );

            JsonFileLoader<ref KeyCardSystemConfig>.JsonSaveFile( CONFIG, m_config);
        }

        JsonFileLoader<ref KeyCardSystemConfig>.JsonLoadFile( CONFIG, m_config);
    }

    /* 
    *   Compares current config with previous persitance data.
    *   Resets data if there's any changes.
    */
    void CompareOldPersitance() {

        if ( !FileExist( DATA_DIR ) )
            MakeDirectory( DATA_DIR );
        
        if ( !FileExist( LOCATION_DATA ) || !FileExist( PERSISTANCE_DATA ))   
            return;     /* data doesn't exist, return */


        ref array< ref SecurityDoorLocationConfig > prev_locations = new array< ref SecurityDoorLocationConfig >;
        FileSerializer fileHandle = new FileSerializer();

        if ( fileHandle.Open( LOCATION_DATA, FileMode.READ) )
            fileHandle.Read(prev_locations);
        else {
            DeletePersistanceFiles(); /* Corrupted files probably, reset persistance data */
            return;
        }

        foreach( ref SecurityDoorLocationConfig p_config : prev_locations ) {
            
            Print( string.Format("%1 %2 %3", p_config.GetClassName(), p_config.GetPosition(), p_config.GetDirection() ) );
        }

        foreach( ref SecurityDoorLocationConfig config : m_config.locations ) {
            
            Print( string.Format("%1 %2 %3", config.GetClassName(), config.GetPosition(), config.GetDirection() ) );
        }
    }

    protected void DeletePersistanceFiles() {
        DeleteFile( LOCATION_DATA );
        DeleteFile( PERSISTANCE_DATA );
    }
}