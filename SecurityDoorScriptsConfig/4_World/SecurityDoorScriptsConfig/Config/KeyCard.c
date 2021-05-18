class SDM_Keycard_Lvl_1 : SDM_Keycard_Base {
    override bool CanAuthorizeDoor( string type ) {
        return type == "SDM_Security_Single_Door_Lvl_1" || type == "SDM_Security_Double_Door_Lvl_1";
    }
};
class SDM_Keycard_Lvl_2 : SDM_Keycard_Base {
    override bool CanAuthorizeDoor( string type ) {
        return type == "SDM_Security_Single_Door_Lvl_2" || type == "SDM_Security_Double_Door_Lvl_2";
    }
};
class SDM_Keycard_Lvl_3 : SDM_Keycard_Base {
    override bool CanAuthorizeDoor( string type ) {
        return type == "SDM_Security_Single_Door_Lvl_3" || type == "SDM_Security_Double_Door_Lvl_3";
    }
};
class SDM_Keycard_Lvl_4 : SDM_Keycard_Base {
    override bool CanAuthorizeDoor( string type ) {
        return type == "SDM_Security_Single_Door_Lvl_4" || type == "SDM_Security_Double_Door_Lvl_4";
    }
};