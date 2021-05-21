class SDM_Keycard_Base : ItemBase {
    bool CanAuthorizeDoor( string type ) {
        return false;
    }
};

class SDM_Keycard_Yellow : SDM_Keycard_Base {
    override bool CanAuthorizeDoor( string type ) {
        return type == "SDM_Security_Single_Door_Yellow" || type == "SDM_Security_Double_Door_Yellow";
    }
};
class SDM_Keycard_Blue : SDM_Keycard_Base {
    override bool CanAuthorizeDoor( string type ) {
        return type == "SDM_Security_Single_Door_Blue" || type == "SDM_Security_Double_Door_Blue";
    }
};
class SDM_Keycard_Red : SDM_Keycard_Base {
    override bool CanAuthorizeDoor( string type ) {
        return type == "SDM_Security_Single_Door_Red" || type == "SDM_Security_Double_Door_Red";
    }
};
class SDM_Keycard_Black : SDM_Keycard_Base {
    override bool CanAuthorizeDoor( string type ) {
        return type == "SDM_Security_Single_Door_Black" || type == "SDM_Security_Double_Door_Black";
    }
};