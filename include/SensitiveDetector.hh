//============================================================================
// SENSITIVE DETECTOR
//============================================================================

#ifndef SensitiveDetector_hh_
#define SensitiveDetector_hh_

#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "DetectorHit.hh"

class SensitiveDetector : public G4VSensitiveDetector
{
public:
    SensitiveDetector(G4String name);
    ~SensitiveDetector();
    
    void Initialize(G4HCofThisEvent*);
    G4bool ProcessHits(G4Step* Astp, G4TouchableHistory* t);
    void EndOfEvent(G4HCofThisEvent* h);
    
private:
    DetectorHitsCollection* hits;
};

#endif

//#include "TrackHit.hh"
////#include "G4ThreeVector.hh"
////#include "G4RotationMatrix.hh"
//#include "G4VSensitiveDetector.hh"
//
//class SensitiveDetector : public G4VSensitiveDetector
//{
//public:
//    SensitiveDetector(const G4String iname,
//                      const G4RotationMatrix& iR,
//                      const G4ThreeVector& iV);
//    ~SensitiveDetector(); [done]
//
//protected:
//    static G4int         id;
//    G4RotationMatrix     R;
//    G4ThreeVector        V;
//};
//
//#endif
//
