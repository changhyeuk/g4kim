#include "Hit.hh"

Hit::Hit()
{
    
}

Hit::~Hit()
{
    
}
~MyHit(){};
MyHit(const MyHit& right)
: G4VHit()
{
    eDepo      = right.eDepo;
    position   = right.position;
};

const MyHit& operator=(const MyHit& right)
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
typedef G4THitsCollection<MyHit> MyHitsCollection;
