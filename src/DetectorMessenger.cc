#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"


//==============================================================================
DetectorMessenger::DetectorMessenger(DetectorConstruction* idc)
:dc(idc)
{
    // directory definition
    detDir = new G4UIdirectory("/det/");
    detDir->SetGuidance("change phantom information");
    
    degraderMaterial = new G4UIcmdWithAString("/det/DegraderMaterial", this);
    degraderMaterial->SetGuidance("degrader material");
    degraderMaterial->SetParameterName("degraderMaterial", false);
    degraderMaterial->AvailableForStates(G4State_PreInit);
    
    //---------------------------------------------------------------------------
    
    deg_Length = new G4UIcmdWithADouble("/det/DegraderLength", this);
    deg_Length->SetGuidance("Gas Degrader Length ");
    deg_Length->SetParameterName("DegLenght", false);
    deg_Length->AvailableForStates(G4State_PreInit);
    
    //---------------------------------------------------------------------------
    
    deg_pressure = new G4UIcmdWithADouble("/det/GasPressure", this);
    deg_pressure->SetGuidance("Gas Degrader Pressure ");
    deg_pressure->SetParameterName("DegPress", false);
    deg_pressure->AvailableForStates(G4State_PreInit);
    
}

//==============================================================================
DetectorMessenger::~DetectorMessenger()
{
    delete detDir;
    delete degraderMaterial;
    delete deg_Length;
    delete deg_pressure;
}


//==============================================================================
void DetectorMessenger::SetNewValue(G4UIcommand* icmd, G4String istr)
{
    if (icmd == degraderMaterial)
    {
        dc->SetDegraderMaterial(istr);
    }
    else if (icmd == deg_Length)
    {
        dc->SetDegraderLength(deg_Length->GetNewDoubleValue(istr));
    }
    else if (icmd == deg_pressure)
    {
        dc->SetDegraderPressure(deg_pressure->GetNewDoubleValue(istr));
    }
}
