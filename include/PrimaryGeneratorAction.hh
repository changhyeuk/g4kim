#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "Randomize.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();
    
public:
    void GeneratePrimaries(G4Event* );
    
private:
    G4ParticleGun* gun;  
};

#endif

//#include "G4VUserPrimaryGeneratorAction.hh"
//#include "G4ParticleGun.hh"
//#include "G4Event.hh"
//#include "G4ParticleTable.hh"
//#include "G4ParticleDefinition.hh"
//#include "Randomize.hh"
//class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
//{
//public:
//    PrimaryGeneratorAction()
//    {
//        gun = new G4ParticleGun(1);
//    };
//    ~PrimaryGeneratorAction()
//    {
//        delete gun;
//    };
//    
//public:
//    void GeneratePrimaries(G4Event* evt)
//    {
//        // pencil beam configuration
//        G4ParticleTable* t = G4ParticleTable::GetParticleTable();
//        gun->SetParticleDefinition(t->FindParticle("proton"));
//        gun->SetParticlePosition(
//                                 G4ThreeVector(0., 0., -0.5*wld_z));
//        gun->SetParticleMomentumDirection(
//                                          G4ThreeVector(0., 0., 1.));
//        gun->SetParticleEnergy(energy);
//        gun->GeneratePrimaryVertex(evt);
//    };
//    
//private:
//    G4ParticleGun* gun;  
//};