#ifndef PRIMARYGENERATORMESSENGER_HH
#define PRIMARYGENERATORMESSENGER_HH 1

#include "PrimaryGeneratorAction.hh"
#include "BeamInfo.hh"
#include "G4UImessenger.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"

class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithAnInteger;
class G4UIcmdWithADouble;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWith3Vector;

class PrimaryGeneratorMessenger: public G4UImessenger
{
public:
    PrimaryGeneratorMessenger(PrimaryGeneratorAction* ipga);
    ~PrimaryGeneratorMessenger();
    
public:
    void SetNewValue(G4UIcommand* icmd, G4String istr);

public:
    const BeamInfo& GetBeamInfo() const;
    
private:
    PrimaryGeneratorAction*    ga;
    BeamInfo                   Binfo;
    G4UIdirectory*             beam;

//    G4UIcmdWithAString*        beam_gauss_xe;
//    G4UIcmdWithAString*        beam_gauss_ye;
//    
    G4UIcmdWith3Vector*        beam_gauss_Xabe;
    G4UIcmdWith3Vector*        beam_gauss_Yabe;
    G4UIcmdWithAString*        beam_energy_esratio;

//    G4UIcmdWithAString*        beam_energy_msratio;
    G4UIcmdWithAnInteger*      beam_rseed;
    
};


#endif // PRIMARYGENERATORMESSENGER_HH
