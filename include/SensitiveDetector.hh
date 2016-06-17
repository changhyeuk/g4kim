#ifndef SensitiveDetector_hh_
#define SensitiveDetector_hh_


#include "TrackHit.hh"
//#include "G4ThreeVector.hh"
//#include "G4RotationMatrix.hh"
#include "G4VSensitiveDetector.hh"

class SensitiveDetector : public G4VSensitiveDetector
{
public:
    SensitiveDetector(const G4String iname,
                      const G4RotationMatrix& iR,
                      const G4ThreeVector& iV);
    ~SensitiveDetector();
    
protected:
    static G4int         id;
    G4RotationMatrix     R;
    G4ThreeVector        V;
};

#endif


//============================================================================
// SENSITIVE DETECTOR
//============================================================================
#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"

class SensitiveDetector : public G4VSensitiveDetector
{
public:
    SensitiveDetector(G4String name)
    :G4VSensitiveDetector(name)
    { collectionName.insert((name+"HC").c_str()); };
    ~SensitiveDetector(){};
    
    void Initialize(G4HCofThisEvent* hce)
    {
        hits = new MyHitsCollection(SensitiveDetectorName, collectionName[0]);
        hce->AddHitsCollection(
                               (G4int)G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]),
                               hits);
    };
    G4bool ProcessHits(G4Step* stp, G4TouchableHistory* t)
    {
        G4Track* trk = stp->GetTrack();
        MyHit* hit = new MyHit;
        hit->SetEdeposit(stp->GetTotalEnergyDeposit());
        hit->SetPosition(trk->GetPosition());
        hits->insert(hit);
        return true;
    };
    void   EndOfEvent(G4HCofThisEvent* h) {};
    
private:
    MyHitsCollection*   hits;
};

