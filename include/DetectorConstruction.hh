#ifndef DetectorConstruction_hh_
#define DetectorConstruction_hh_


#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class DetectorMessenger;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction();
    ~DetectorConstruction();
    
    G4VPhysicalVolume* Construct();
    
public:
    void SetDegraderMaterial(std::string imaterialname);
    void SetDegraderLength(double iDegLength);
    void SetDegraderPressure(double iDegPress);
    
private:
    DetectorMessenger* detMsn;
    G4String degraderMaterial;
    G4double degLength;
    G4double degPressure;
};

#endif /* DetectorConstruction_hh_ */


/*

 My old DetectorConstrution.hh
 
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

*/