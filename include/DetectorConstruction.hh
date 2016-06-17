#ifndef DetectorConstruction_hh_
#define DetectorConstruction_hh_

#include "G4VUserDetectorConstruction.hh"


class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
    DetectorConstruction();
    ~DetectorConstruction();
    
    G4VPhysicalVolume* Construct();
    
    private:

};

#endif