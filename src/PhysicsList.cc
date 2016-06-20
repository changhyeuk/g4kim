#include "G4VUserPhysicsList.hh"
#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4DecayPhysics.hh"
#include "G4ProductionCuts.hh"
#include "PhysicsList.hh"


PhysicsList::PhysicsList():G4VUserPhysicsList()
{
    emPhys    = new G4EmStandardPhysics_option3();
    decayPhys = new G4DecayPhysics();
}

PhysicsList::~PhysicsList()
{
    delete decayPhys;
    delete emPhys;
}
    
//    G4EmStandardPhysics_option3* emPhys;            //E.M.
//    G4DecayPhysics*              decayPhys;         //Decay

// Construct particle and physics
void PhysicsList::ConstructParticle()
{
    decayPhys->ConstructParticle();
}

void PhysicsList::ConstructProcess()
{
    AddTransportation();
    decayPhys->ConstructProcess();
    emPhys->ConstructProcess();
}

void PhysicsList::SetCuts()
{
    SetCutsWithDefault();
    DumpCutValuesTable();
}

