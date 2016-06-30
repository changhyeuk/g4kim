#include "DetectorConstruction.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SDManager.hh"
//#include "SensitiveDetector.hh"
#include "CalorimeterSD.hh"

DetectorConstruction::DetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4double wld_x = 10.0 * cm;
    G4double wld_y = 10.0 * cm;
    G4double wld_z = 20.0 * cm;
    
    G4Material* wld_mat =
    G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR", false);
    G4Box* s_world = new G4Box("s_world", wld_x/2,wld_y/2,wld_z/2);
    G4LogicalVolume* l_world = new G4LogicalVolume(s_world, wld_mat, "l_world",0, 0);
    G4PVPlacement* p_world = new G4PVPlacement(0, // rot_mat
                    G4ThreeVector(0.,0.,0.), // cnt_pos
                    l_world,   // curr_lv
                    "p_world", // name
                    0,         // mother_lv
                    false,     // boolean op. not support
                    0);        // copy num

//    G4SDManager* SDman = G4SDManager::GetSDMpointer();
//    SensitiveDetector* sd = new SensitiveDetector("block");
//    SDman->AddNewDetector(sd);

    G4Material* block_mat =
    G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER", false);
    G4Tubs* s_block = new G4Tubs("s_block", 0.0, 0.3*wld_x, 0.25*wld_z, 0.0, 360.0);
    G4LogicalVolume* l_block = new G4LogicalVolume(s_block, block_mat, "l_block",0,
                                                   new CalorimeterSD("WaterPhantom",
                                                                     //R0,
                                                                     //VC,
                                                                     100,-wld_x/3,wld_x/3,
                                                                     100,-wld_y/3,wld_y/3,
                                                                     200,-wld_z/3,wld_z/3));
    G4PVPlacement* p_block = new G4PVPlacement(0, // rot_mat
                    G4ThreeVector(0.,0.,0.), // cnt_pos
                    l_block,   // curr_lv
                    "p_block", // name
                    l_world,   // mother_lv
                    false,     // boolean op. not support
                    0);        // copy num
return p_world;
}
