//
//  BeTarget.cpp
//
//  Created by Kim Chang Hyeuk on 2017. 3. 14..
//
//

#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Box.hh"
#include "CalorimeterSD.hh"
#include "TrackerSD.hh"

#include "CGlobal.hh"
#include "BeTarget.hh"

//===================================================================================
BeTarget::BeTarget(const G4double pX,
                   const G4double pY,
                   const G4double pZ,
                   const char* bm)
:BeamLineComponent(BLBeTarget)
{
    
    HalfX = pX;
    HalfY = pY;
    HalfZ = pZ;
    
    try
    {
        body_mat = G4NistManager::Instance()->FindOrBuildMaterial(bm, false);
    }
    catch (int e)
    {
        body_mat = G4NistManager::Instance()->FindOrBuildMaterial("G4_Be", false);
    }
}

//===================================================================================
BeTarget::BeTarget(const G4double pX,
                           const G4double pY,
                           const G4double pZ,
                           G4Material* mat)
:BeamLineComponent(BLBeTarget), HalfX(pX), HalfY(pY), HalfZ(pZ), body_mat(mat)
{
}

BeTarget::~BeTarget()
{
}

//===================================================================================

BeTarget* BeTarget::New()
{
    return new BeTarget(HalfX, HalfY, HalfZ, body_mat);
}

BeTarget* BeTarget::New(const G4double pZ)
{
    return new BeTarget(HalfX, HalfY, pZ,body_mat);
}


//===================================================================================
G4RotationMatrix BeTarget::GetNextRotationMatrix(const G4RotationMatrix& R0)
{
    return R0;
}

//===================================================================================
G4ThreeVector BeTarget::GetNextPosition(const G4ThreeVector& V0,
                                            const G4RotationMatrix& R0)
{
    return V0 + R0 * ( HalfZ * zhat);
}

//===================================================================================
void BeTarget::Generate(const G4RotationMatrix& R0,
                            const G4ThreeVector&    V0,
                            G4LogicalVolume*  mother_lv )
{
    if ( HalfZ == 0.0 ) return;
    G4Box*s_blk = new G4Box("degBeTarget",HalfX/2, HalfY/2,HalfZ/2);
    const G4ThreeVector VC = V0 + R0 * ( 0.5 * HalfZ * zhat);
    //G4cout<<" VO: "<<V0<<G4endl;
    //G4cout<<" VC: "<<VC<<G4endl;
    //G4cout<<" HalfZ : "<<HalfZ/2<<G4endl;
    //G4LogicalVolume* l_blk = new G4LogicalVolume(s_blk, body_mat, "l_blk");
    /*
    G4LogicalVolume* l_blk = new G4LogicalVolume(s_blk,
                                                 body_mat,
                                                 "l_blk",
                                                 0,
                                                 new CalorimeterSD("BeTarget",
                                                                   R0,
                                                                   VC,
                                                                   150,-HalfX/2,HalfX/2,
                                                                   150,-HalfY/2,HalfY/2,
                                                                   400,-HalfZ/2,HalfZ/2));
     */
    G4LogicalVolume* l_blk = new G4LogicalVolume(s_blk,
                                                 body_mat,
                                                 "l_blk",
                                                 0,
                                                 new TrackerSD("VM", R0, VC));
    G4cout<<" Be Target Was inserted "<<G4endl;
    
    l_blk->SetVisAttributes(new G4VisAttributes(cGreen));
    G4RotationMatrix* rr = new G4RotationMatrix(R0);
    rr->invert();
    new G4PVPlacement(rr,VC,l_blk,"p_blk",mother_lv,false,0);
    
}
