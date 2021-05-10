class SecurityDoorPersistanceData {
    string className;
    vector location;
    vector dir;

    int randomvar;
    
    string GetType() {
        return className;
    }

    vector GetPosition() {
        return location;
    }

    vector GetOrientation() {
        return dir;
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
}

class SDM_Security_Door_Base : Building {
    ref SecurityDoorPersistanceData m_persistanceData = new SecurityDoorPersistanceData();

    void SetPersistanceData( ref SecurityDoorPersistanceData data ) {
        m_persistanceData = data;
    }

    void UpdatePersistance() {
        m_persistanceData.className = this.GetType();
        m_persistanceData.location = this.GetPosition();
        m_persistanceData.dir = this.GetDirection();
    }

    ref SecurityDoorPersistanceData GetPersistanceData() {
        return m_persistanceData;
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


