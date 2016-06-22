#include "PrimaryGeneratorAction.hh"
#include "PrimaryGeneratorMessenger.hh"

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
//#include "G4PartilceSource.hh"
#include "Randomize.hh"


PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    pgm = new PrimaryGeneratorMessenger(this);
    gun = new G4ParticleGun(1);
};

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete pgm;
    delete gun;
};
    

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* evt)
{
    G4cout<<" PGM : "<< RandSeed <<G4endl;
    
    G4double wld_zz = 15.0 * cm;
    G4double energy = energy = 60 * MeV;
    // pencil beam configuration
    G4ParticleTable* t = G4ParticleTable::GetParticleTable();
    gun->SetParticleDefinition(t->FindParticle("proton"));
    gun->SetParticlePosition(G4ThreeVector(0., 0., -0.5*wld_zz));
    gun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
    gun->SetParticleEnergy(energy);
    gun->GeneratePrimaryVertex(evt);
};

void PrimaryGeneratorAction::SetRandSeed(std::string iRandSeed)
{
    RandSeed=iRandSeed;
}