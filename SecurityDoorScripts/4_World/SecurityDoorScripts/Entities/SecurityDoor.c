class SecurityDoorPersistanceData {
    
}

class SDM_Security_Door_Base : Building {
    ref SecurityDoorPersistanceData m_persistanceData = new SecurityDoorPersistanceData();
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
    
    void SDM_Security_Double_Door_Lvl_4() {
        Print("TEST");
    }
};


