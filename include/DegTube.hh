#ifndef DegTube_h
#define DegTube_h 1

//#include "globals.hh"
#include "BeamLineComponent.hh"

class DegTube : public BeamLineComponent
{
public:
    DegTube(const G4double thickness,
            const G4double total_length,
            const char*    body_mat,
            const G4double pressure);
    
    DegTube(const G4double    thickness,
            const G4double total_length,
            G4Material* body_mat,
            const G4double pressure);
    
    ~DegTube();
    
    DegTube* New();
    DegTube* New(const G4double thickness);
    
    G4RotationMatrix GetNextRotationMatrix(const G4RotationMatrix& R0);
    G4ThreeVector GetNextPosition(const G4ThreeVector&    V0,
                                  const G4RotationMatrix& R0);
    
    void Generate(const G4RotationMatrix& R0,
                  const G4ThreeVector&    V0,
                  G4LogicalVolume*  mother_lv);
    
private:
    G4double    thickness;
    G4double    total_length;
    G4Material* body_mat;
    G4Material* bg_mat;
    G4double    gaspressure;
};

#endif
