#include "PrimaryGeneratorAction.hh"
#include "PrimaryGeneratorMessenger.hh"
#include "CGlobal.hh"
#include "AnalysisManager.hh"
#include "BeamLineComponentManager.hh"

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
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete pgm;
    delete gun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* evt)
{
    AnalysisManager* ana = AnalysisManager::GetInstance();
    
    // G4double energy = 13 * MeV; For the Be
    // pencil beam configuration
    
    // Particle Definition
    const G4double Z = 1.0; // 6.0;
    const G4double A = 1.0; // 12.0;
    G4ParticleDefinition* pdef = G4ParticleTable::GetParticleTable()->FindIon(Z, A, 0, 0);
    gun->SetParticleDefinition(pdef);
    
    // Beam Information
    const BeamInfo& beam = pgm->GetBeamInfo();
    G4double xi, xpi, yi, ypi, wi;

    const G4ThreeVector gunpos = BeamLineComponentManager::GetInitVector();
    const G4RotationMatrix gunrot = BeamLineComponentManager::GetInitRotationMatrix();
    
    xi  = G4RandGauss::shoot(0.0, beam.X());
    xpi = G4RandGauss::shoot(beam.Slopx() * xi, beam.XpInt());
    yi  = G4RandGauss::shoot(0.0, beam.Y());
    ypi = G4RandGauss::shoot(beam.Slopy() * yi, beam.YpInt());
    wi  = G4RandGauss::shoot(beam.MeanEnergy() * A,
                             beam.MeanEnergy() * beam.EsRatio() * A);

   //G4cout<<"xi: "<< xi <<"/ xpi : "<< xpi <<"/ yi : "<<yi<<"/ ypi : "<<ypi<<"/ wi : "<<wi<<G4endl;

    gun->SetParticlePosition(gunpos + G4ThreeVector(xi, yi, 0.));
    gun->SetParticleMomentumDirection(gunrot * G4ThreeVector(xpi, ypi, 1.));
    gun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
    gun->SetParticleEnergy(wi);
    gun->GeneratePrimaryVertex(evt);
    ana->FillBullet(xi, xpi, yi, ypi, wi/A);
    
};

void PrimaryGeneratorAction::SetRandSeed(G4int iRandSeed)
{
    RandSeed=iRandSeed;
}
