#include "G4VUserPhysicsList.hh"
#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronInelasticQBBC.hh"
//#include "G4IonBinaryCascadePhysics.hh"
#include "G4IonQMDPhysics.hh"

#include "G4ProductionCuts.hh"
#include "PhysicsList.hh"
#include "G4SystemOfUnits.hh"

PhysicsList::PhysicsList():G4VUserPhysicsList()
{
    SetVerboseLevel(0);
    defaultCutValue = 0.001 * mm;
    
    emPhys    = new G4EmStandardPhysics_option3();
    decayPhys = new G4DecayPhysics();
    hadronElastPhys    = new G4HadronElasticPhysics();
    hadronInelastPhys  = new G4HadronInelasticQBBC();
    hadronFragPhysJQMD = new G4IonQMDPhysics();
    
}

PhysicsList::~PhysicsList()
{
    delete decayPhys;
    delete emPhys;
    delete hadronFragPhysJQMD;
    delete hadronInelastPhys;
    delete hadronElastPhys;
}

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
    hadronElastPhys->ConstructProcess();
    hadronInelastPhys->ConstructProcess();
    hadronFragPhysJQMD->ConstructProcess();

}

// In other code following two functions were used.
//
////===================================================================================
//void PhysicsList::SetStepLimiter()
//{
//    // Step limitation seen as a process
//    G4StepLimiter* stepLimiter = new G4StepLimiter();
//    theParticleIterator->reset();
//    while ((*theParticleIterator)())
//    {
//        G4ParticleDefinition* particle = theParticleIterator->value();
//        G4ProcessManager* pmanager = particle->GetProcessManager();
//        if (stepLimiter->IsApplicable(*particle) && pmanager)
//        {
//            pmanager->AddDiscreteProcess(stepLimiter);
//        }
//    }
//}

void PhysicsList::SetCuts()
{
    SetCutsWithDefault();
    //DumpCutValuesTable();
}

//void PhysicsList::SetGlobalRangeCut(G4double c)
//{
//    defaultCutValue = c;
//}


