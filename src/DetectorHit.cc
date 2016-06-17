#include "DetectorHit.hh"

DetectorHit::DetectorHit()
{
    
}

DetectorHit::~DetectorHit()
{
    
}

DetectorHit::DetectorHit(const DetectorHit& right)
: G4VHit()
{
    eDepo      = right.eDepo;
    position   = right.position;
}


const DetectorHit& DetectorHit::operator=(const DetectorHit& right)
{
    eDepo      = right.eDepo;
    position   = right.position;
    return *this;
}

void DetectorHit::SetEdeposit(G4double iedep)
{
    eDepo = iedep;
};

void DetectorHit::SetPosition(G4ThreeVector ipos)
{
    position = ipos;
};

G4double DetectorHit::GetEdeposit() const {return eDepo;}
G4ThreeVector DetectorHit::GetPosition() const {return position;}


//typedef G4THitsCollection<MyHit> MyHitsCollection;
