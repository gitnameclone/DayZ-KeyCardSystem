class SDM_Security_Door_Base : Building 
{
    void Open( int index );
    void InitiateClose( int index );
    void Close( int index );
};

class SDM_Security_Single_Door_Base : SDM_Security_Door_Base {};

class SDM_Security_Single_Door_Yellow : SDM_Security_Single_Door_Base {};
class SDM_Security_Single_Door_Blue : SDM_Security_Single_Door_Base {};
class SDM_Security_Single_Door_Red : SDM_Security_Single_Door_Base {};
class SDM_Security_Single_Door_Black : SDM_Security_Single_Door_Base {};

class SDM_Security_Double_Door_Base : SDM_Security_Door_Base {};

class SDM_Security_Double_Door_Yellow : SDM_Security_Double_Door_Base {};
class SDM_Security_Double_Door_Blue : SDM_Security_Double_Door_Base {};
class SDM_Security_Double_Door_Red : SDM_Security_Double_Door_Base {};
class SDM_Security_Double_Door_Black : SDM_Security_Double_Door_Base {};

