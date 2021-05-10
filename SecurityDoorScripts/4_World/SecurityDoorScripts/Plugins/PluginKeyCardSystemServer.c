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

        if (!CompareOldPersitance()) /* Check for changes in config */
        {       
            DeletePersistanceFiles();
        }
    }

    /* 
    *   Compares current config with previous persitance data.
    *   True - OK
    *   False - corrupted/changed
    */
    protected bool CompareOldPersitance() 
    {
        if ( !FileExist( DATA_DIR ) )
            MakeDirectory( DATA_DIR );
        
        if ( !FileExist( LOCATION_DATA ) || !FileExist( PERSISTANCE_DATA ))   
            return false;     /* data doesn't exist, return */


        ref array< ref SecurityDoorLocationConfig > prev_locations = new array< ref SecurityDoorLocationConfig >;
        FileSerializer fileHandle = new FileSerializer();

        if ( fileHandle.Open( LOCATION_DATA, FileMode.READ) )
            fileHandle.Read(prev_locations);
        else
            return false; /* Corrupted files probably, reset persistance data */

        if ( m_config.locations.Count() != prev_locations.Count() )
            return false;

        for ( int i=0; i<m_config.locations.Count(); i++ ) 
        {
            ref SecurityDoorLocationConfig currentConfig = m_config.locations[i];
            ref SecurityDoorLocationConfig persistanceConfig = prev_locations[i];

            if( !persistanceConfig )
                return false;

            /* Check if classnames are equal */
            if ( currentConfig.GetClassName() != persistanceConfig.GetClassName() )
                return false;

            /* Check for changes in position */
            if ( currentConfig.GetPosition() != persistanceConfig.GetPosition() )
                return false;

            /* Check for changes in direction */
            if ( currentConfig.GetDirection() != persistanceConfig.GetDirection() )
                return false;
            

        }


        foreach( ref SecurityDoorLocationConfig p_config : prev_locations ) {
            
            Print( string.Format("%1 %2 %3", p_config.GetClassName(), p_config.GetPosition(), p_config.GetDirection() ) );
        }

        foreach( ref SecurityDoorLocationConfig config : m_config.locations ) {
            
            Print( string.Format("%1 %2 %3", config.GetClassName(), config.GetPosition(), config.GetDirection() ) );
        }

        return true;
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

        Print("Spawning doors...");

        foreach( ref SecurityDoorLocationConfig config : m_config.locations ) {

            auto obj = GetGame().CreateObjectEx( config.GetClassName(), config.GetPosition(), ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);

            if ( !obj )
                continue;

            obj.SetPosition( config.GetPosition() );
            obj.SetOrientation( config.GetDirection() );
            obj.SetOrientation( obj.GetOrientation() );
            obj.Update();
        }

    }
}