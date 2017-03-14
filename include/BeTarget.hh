//
//  Header.hh
//  projg4kim
//
//  Created by Kim Chang Hyeuk on 2017. 3. 14..
//

#ifndef BeTarget_h
#define BeTarget_h 1

#include "CGlobal.hh"
#include "BeamLineComponent.hh"

class BeTarget : public BeamLineComponent
{
public:
    
    BeTarget(const G4double HalfX,
             const G4double HalfY,
             const G4double HalfZ,
             const char*    body_mat);
    
    BeTarget(const G4double HalfX,
             const G4double HalfY,
             const G4double HalfZ,
             G4Material* mat);
    
    ~BeTarget();
    
    BeTarget* New();
    BeTarget* New(const G4double HalfZ);
    
    G4RotationMatrix GetNextRotationMatrix(const G4RotationMatrix& R0);
    G4ThreeVector GetNextPosition(const G4ThreeVector&    V0,
                                  const G4RotationMatrix& R0);
    
    void Generate(const G4RotationMatrix& R0,
                  const G4ThreeVector&    V0,
                  G4LogicalVolume*  mother_lv);
    
private:
    
    G4double HalfX;
    G4double HalfY;
    G4double HalfZ;
    G4Material* body_mat;
};

#endif
