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
    }
}