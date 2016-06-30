#include "PrimaryGeneratorMessenger.hh"
#include "DetectorConstruction.hh"
#include "CGlobal.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWith3Vector.hh"

#include "Randomize.hh"

//============================================================================
PrimaryGeneratorMessenger::PrimaryGeneratorMessenger(
                                                     PrimaryGeneratorAction* iga)
:ga(iga)
{
    beam = new G4UIdirectory("/beam/");
    beam->SetGuidance("set paramters of beam");

//    beam_gauss_xe = new G4UIcmdWithAString("/beam/gauss/xe",this);
//    beam_gauss_xe->SetGuidance("x[mm] xp[mrad]");
//    beam_gauss_xe->AvailableForStates(G4State_PreInit);
//
//    beam_gauss_ye = new G4UIcmdWithAString("/beam/gauss/ye",this);
//    beam_gauss_ye->SetGuidance("y[mm] yp[mrad]");
//    beam_gauss_ye->AvailableForStates(G4State_PreInit);
//    
    beam_gauss_Xabe = new G4UIcmdWith3Vector("/beam/gauss/Xabe",this);
    beam_gauss_Xabe->SetGuidance("AlphaX[-] BetaX[m] EmittanceX [pi.mm.mrad]");
    beam_gauss_Xabe->AvailableForStates(G4State_PreInit);

    beam_gauss_Yabe = new G4UIcmdWith3Vector("/beam/gauss/Yabe",this);
    beam_gauss_Yabe->SetGuidance("alpy[-] bety[m] emity[pi.mm.mrad]");
    beam_gauss_Yabe->AvailableForStates(G4State_PreInit);
    
    beam_energy_esratio = new G4UIcmdWithAString("/beam/energy_esratio", this);
    beam_energy_esratio->SetGuidance("e_mean[MeV/u] es_ratio[-]");
    beam_energy_esratio->AvailableForStates(G4State_PreInit);
//
//    beam_energy_msratio = new G4UIcmdWithAString("/beam/energy_msratio", this);
//    beam_energy_msratio->SetGuidance("e_mean[MeV/u] ms_ratio[-]");
//    beam_energy_msratio->AvailableForStates(G4State_PreInit);
    
    beam_rseed = new G4UIcmdWithAnInteger("/beam/rseed", this);
    beam_rseed->SetGuidance("random_seed");
    beam_rseed->AvailableForStates(G4State_PreInit);
}

//============================================================================
PrimaryGeneratorMessenger::~PrimaryGeneratorMessenger()
{
    delete beam;
    delete beam_gauss_Xabe;
    delete beam_gauss_Yabe;
    delete beam_energy_esratio;
    delete beam_rseed;
}

//============================================================================
void PrimaryGeneratorMessenger::SetNewValue(G4UIcommand* icmd, G4String istr)
{
    
    if (icmd == beam_gauss_Xabe)
    {
    
        //ga->SetBeamEmittX(beam_gauss_Xabe->GetNew3VectorValue(istr));
        std::vector<double> xabe = ckim::ssplit_to_doubles(istr);
        Binfo.SetXabe(xabe[0],
                      xabe[1] * m, //(* mm / mrad)
                      xabe[2] * mm * mrad);
        //G4cout<<" Messenger file : "<<beam_gauss_Xabe->GetNew3VectorValue(istr)<<G4endl;
    
    }

    else if (icmd == beam_gauss_Yabe)
    {
        std::vector<double> yabe = ckim::ssplit_to_doubles(istr);
        Binfo.SetYabe(yabe[0],
                      yabe[1] * m, //(* mm / mrad)
                      yabe[2] * mm * mrad);
    }
    
    else if (icmd == beam_energy_esratio)
    {
        std::vector<double> e_es = ckim::ssplit_to_doubles(istr);
        Binfo.SetEnergyAndEnergyRatio(e_es[0] * MeV, e_es[1]);
    }
//
//    else if (icmd == beam_energy_msratio)
//    {
//        std::vector<double> e_ms = garam::ssplit_to_doubles(istr);
//        binfo.SetEnergyAndMomentumRatio(e_ms[0] * MeV, e_ms[1]);
//    }
    
    else if (icmd == beam_rseed)
    {
        //G4cout<<" The Seed number from messenger file : "<<beam_rseed->GetNewIntValue(istr)<<G4endl;
        //ga -> SetRandSeed(beam_rseed->GetNewIntValue(istr));
        CLHEP::HepRandom::setTheSeed(beam_rseed->GetNewIntValue(istr));
    }
}

const BeamInfo& PrimaryGeneratorMessenger::GetBeamInfo() const
{
    return Binfo;
}
