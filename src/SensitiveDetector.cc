#include "SensitiveDetector.hh"
#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4SDManager.hh"

SensitiveDetector::SensitiveDetector(G4String name)
:G4VSensitiveDetector(name)
{
    collectionName.insert((name+"HC").c_str());
}

SensitiveDetector::~SensitiveDetector()
{
    
}
//    ~SensitiveDetector(){};

void SensitiveDetector::Initialize(G4HCofThisEvent* hce)
{
    hits = new DetectorHitsCollection(SensitiveDetectorName, collectionName[0]);
    hce->AddHitsCollection((G4int)G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]),hits);
};

G4bool SensitiveDetector::ProcessHits(G4Step* Astp, G4TouchableHistory* t)
{
    G4Track* trk = Astp->GetTrack();
    DetectorHit* hit = new DetectorHit;
    hit->SetEdeposit(Astp->GetTotalEnergyDeposit());
    hit->SetPosition(trk->GetPosition());
    hits->insert(hit);
    return true;
};

void SensitiveDetector::EndOfEvent(G4HCofThisEvent* h)
{

};

////============================================================================
//// SENSITIVE DETECTOR
////============================================================================
//#include "G4VSensitiveDetector.hh"
//#include "G4HCofThisEvent.hh"
//#include "G4Step.hh"
//#include "G4TouchableHistory.hh"
//
//class SensitiveDetector : public G4VSensitiveDetector
//{
//public:
//  SensitiveDetector(G4String name)
// :G4VSensitiveDetector(name)
//  { collectionName.insert((name+"HC").c_str()); };
//  ~SensitiveDetector(){};
//
//  void Initialize(G4HCofThisEvent* hce)
//  {
//    hits = new MyHitsCollection(SensitiveDetectorName, collectionName[0]);
//    hce->AddHitsCollection(
//      (G4int)G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]),
//      hits);
//  };
//  G4bool ProcessHits(G4Step* stp, G4TouchableHistory* t)
//  {
//    G4Track* trk = stp->GetTrack();
//    MyHit* hit = new MyHit;
//    hit->SetEdeposit(stp->GetTotalEnergyDeposit());
//    hit->SetPosition(trk->GetPosition());
//    hits->insert(hit);
//    return true;
//  };
//  void   EndOfEvent(G4HCofThisEvent* h) {};
//
//private:
//  MyHitsCollection*   hits;
//};
//