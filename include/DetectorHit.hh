#ifndef DetectorHit_h
#define DetectorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4ThreeVector.hh"

class DetectorHit : public G4VHit
{
public:
    DetectorHit();
    ~DetectorHit();
    
    DetectorHit(const DetectorHit& right);
    const DetectorHit& operator=(const DetectorHit& right);

public:
    void SetEdeposit(G4double iedep);
    void SetPosition(G4ThreeVector ipos);
    
    G4double GetEdeposit() const;
    G4ThreeVector GetPosition() const;

private:
    G4double       eDepo;
    G4ThreeVector  position;
};

typedef G4THitsCollection<DetectorHit> DetectorHitsCollection;







//============================================================================
// HIT
//============================================================================
//#include "G4VHit.hh"
//#include "G4THitsCollection.hh"
//
//class MyHit : public G4VHit
//{
//public:
//  MyHit(){};
//  ~MyHit(){};
//  MyHit(const MyHit& right)
//    : G4VHit()
//  {
//    eDepo      = right.eDepo;
//    position   = right.position;
//  };
//
//  const MyHit& operator=(const MyHit& right)
//  {
//    eDepo      = right.eDepo;
//    position   = right.position;
//    return *this;
//  }
//
//public:
//  void SetEdeposit(G4double iedep){ eDepo = iedep; };
//  void SetPosition(G4ThreeVector ipos){ position = ipos; };
//
//  G4double GetEdeposit(){ return eDepo; };
//  G4ThreeVector GetPosition(){ return position; };
//
//private:
//  G4double       eDepo;
//  G4ThreeVector  position;
//};
//typedef G4THitsCollection<MyHit> MyHitsCollection;
