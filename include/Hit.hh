#ifndef Hit_h
#define Hit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"

class Hit : public G4VHit
{
public:
    Hit();
    ~Hit();
    
    Hit(const Hit& right)
    : G4VHit()
    {
        eDepo      = right.eDepo;
        position   = right.position;
    };
    
    const Hit& operator=(const Hit& right)
    {
        eDepo      = right.eDepo;
        position   = right.position;
        return *this;
    }
    
public:
    void SetEdeposit(G4double iedep){ eDepo = iedep; };
    void SetPosition(G4ThreeVector ipos){ position = ipos; };
    
    G4double GetEdeposit(){ return eDepo; };
    G4ThreeVector GetPosition(){ return position; };
    
private:
    G4double       eDepo;
    G4ThreeVector  position;
};
typedef G4THitsCollection<Hit> HitsCollection;
