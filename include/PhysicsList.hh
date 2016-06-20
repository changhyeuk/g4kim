#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
//#include "G4ProcessManager.hh"
//#include "G4ParticleTypes.hh"
//#include "G4EmStandardPhysics_option3.hh"
//#include "G4DecayPhysics.hh"
//#include "G4ProductionCuts.hh"

class G4EmStandardPhysics_option3;
class G4DecayPhysics;

class PhysicsList: public G4VUserPhysicsList
{
public:
    PhysicsList();
    ~PhysicsList();
    
protected:
    
    G4EmStandardPhysics_option3* emPhys;            //E.M.
    G4DecayPhysics*              decayPhys;         //Decay
    
    // Construct particle and physics
    void ConstructParticle();
    void ConstructProcess();
    void SetCuts();
    
};

#endif

//#include "G4VUserPhysicsList.hh"
//#include "G4ProcessManager.hh"
//#include "G4ParticleTypes.hh"
//#include "G4EmStandardPhysics_option3.hh"
//#include "G4DecayPhysics.hh"
//#include "G4ProductionCuts.hh"
//class PhysicsList: public G4VUserPhysicsList
//{
//public:
//    PhysicsList()
//    {
//        emPhys    = new G4EmStandardPhysics_option3();
//        decayPhys = new G4DecayPhysics();
//    };
//    ~PhysicsList()
//    {
//        delete decayPhys;
//        delete emPhys;
//    };
//    
//protected:
//    G4EmStandardPhysics_option3* emPhys;            //E.M.
//    G4DecayPhysics*              decayPhys;         //Decay
//    
//    // Construct particle and physics
//    void ConstructParticle()
//    {
//        decayPhys->ConstructParticle();
//    };
//    void ConstructProcess()
//    {
//        AddTransportation();
//        decayPhys->ConstructProcess();
//        emPhys->ConstructProcess();
//    };
//    void SetCuts()
//    {
//        SetCutsWithDefault();
//        DumpCutValuesTable();
//    };
//};
