#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Tubs.hh"
#include "CalorimeterSD.hh"

#include "CGlobal.hh"
#include "DegTube.hh"

//===================================================================================
DegTube::DegTube(const G4double thick,
                 const G4double totlength,
                 const char* bm,
                 const G4double gas_pressure)
:BeamLineComponent(DummyDegTube)
{
    thickness = thick;
    total_length  = totlength;
    gaspressure = gas_pressure;
    if ( bm != "Gas" )
    {
        body_mat = G4NistManager::Instance()->ConstructNewGasMaterial("He_Gas",bm,293.0*kelvin,gaspressure *atmosphere);
    }
    else
    {
        try
        {
            body_mat =
            G4NistManager::Instance()->FindOrBuildMaterial(bm, false);
        }
        catch (int e)
        {
            body_mat =
            G4NistManager::Instance()->FindOrBuildMaterial("G4_AL", false);
        }
    }
}



//===================================================================================
DegTube::DegTube(const G4double thick,
                 const G4double totlength,
                 G4Material* bm,
                 const G4double gas_pressure)
:BeamLineComponent(DummyDegTube)
{
    thickness = thick;
    total_length  = totlength;
    body_mat  = bm;
    gaspressure = gas_pressure;
}


//===================================================================================
DegTube::~DegTube()
{
}



//===================================================================================
DegTube* DegTube::New()
{
    return new DegTube(thickness, total_length, body_mat, gaspressure);
}


//===================================================================================
DegTube*
DegTube::New(const G4double thick)
{
    return new DegTube(thick, total_length, body_mat,gaspressure);
}

//===================================================================================
G4RotationMatrix
DegTube::GetNextRotationMatrix(const G4RotationMatrix& R0)
{
    return R0;
}

//===================================================================================
G4ThreeVector
DegTube::GetNextPosition(const G4ThreeVector&    V0,
                          const G4RotationMatrix& R0)
{
    return V0 + R0 * (total_length * zhat);
}


//===================================================================================
void DegTube::Generate(const G4RotationMatrix& R0,
                        const G4ThreeVector&    V0,
                        G4LogicalVolume*  mother_lv )
{
    if (thickness == 0.0) return;
    bg_mat = G4NistManager::Instance()->FindOrBuildMaterial("G4_Al", false);
    // Geometrical Volume Define
    G4Tubs* s_blk = new G4Tubs("GasDegTubeGas",
                               0.,
                               15.0 * mm,
                               0.5 * thickness,
                               0.,
                               360.0 * deg);
    const G4ThreeVector VC = V0 + R0 * (0.5 * thickness * zhat);
    //G4LogicalVolume* l_blk = new G4LogicalVolume(s_blk, body_mat, "l_blk");
    G4LogicalVolume* l_blk = new G4LogicalVolume(s_blk,
						 body_mat,
						 "l_blk",
						 0,
						 new CalorimeterSD("HeGas",
								   R0,
								   VC,
								   150,-(0.03*m)/2,(0.03*m)/2,
                                                                   150,-(0.03*m)/2,(0.03*m)/2,
                                                                   400,-thickness/2,thickness/2));
    //l_blk->SetVisAttributes(G4VisAttributes::Invisible);
    l_blk->SetVisAttributes(G4VisAttributes(cSkyBlue));
    G4RotationMatrix* rr = new G4RotationMatrix(R0);
    rr->invert();
    new G4PVPlacement(rr,
                      VC,
                      l_blk,
                      "p_blk",
                      mother_lv,
                      false,
                      0);
    
    G4cout<<" Tube Length : "<<total_length<<G4endl;
    G4cout<<" Gas Body : "<<body_mat<<G4endl;
    G4cout<<" Tube Body : "<<bg_mat<<G4endl;
    
    
    G4LogicalVolume* lv = 0;
    lv = new G4LogicalVolume(new G4Tubs("GasDegTube",
                                        15.0 *mm,
                                        16.0 *mm,
                                        0.5 *thickness,
                                        0.,
                                        360.0*deg),
                             bg_mat,
                             "lv_t");
    const G4ThreeVector VL = R0 * ( ( 0.0 ) * zhat );
       
    lv->SetVisAttributes(new G4VisAttributes(cBlue));
    new G4PVPlacement(rr,
                      VL,
                      lv,
                      "pv_l",
                      l_blk,
                      false,
                      0);
    
}
