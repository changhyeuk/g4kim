//
// G4KIM from the g4single file
//

//#include "G4VUserDetectorConstruction.hh"
//#include "G4Material.hh"
//#include "G4Tubs.hh"
//#include "G4LogicalVolume.hh"
//#include "G4PVPlacement.hh"
//#include "G4SDManager.hh"
#include "G4GeometryManager.hh"
#include "G4ThreeVector.hh"
//#include "G4NistManager.hh"
#include "G4ios.hh"


//G4double energy = 60 * MeV;


//============================================================================
// HIT
//============================================================================
//#include "G4VHit.hh"
//#include "G4THitsCollection.hh"
//
//class MyHit : public G4VHit
//{
//public:
//  MyHit(){};
//  ~MyHit(){};
//  MyHit(const MyHit& right)
//    : G4VHit()
//  {
//    eDepo      = right.eDepo;
//    position   = right.position;
//  };
//
//  const MyHit& operator=(const MyHit& right)
//  {
//    eDepo      = right.eDepo;
//    position   = right.position;
//    return *this;
//  }
//  
//public:
//  void SetEdeposit(G4double iedep){ eDepo = iedep; };
//  void SetPosition(G4ThreeVector ipos){ position = ipos; };
//
//  G4double GetEdeposit(){ return eDepo; };
//  G4ThreeVector GetPosition(){ return position; };
//
//private:
//  G4double       eDepo;
//  G4ThreeVector  position;
//};
//typedef G4THitsCollection<MyHit> MyHitsCollection;


////============================================================================
//// SENSITIVE DETECTOR
////============================================================================
//#include "G4VSensitiveDetector.hh"
//#include "G4HCofThisEvent.hh"
//#include "G4Step.hh"
//#include "G4TouchableHistory.hh"
//
//class SensitiveDetector : public G4VSensitiveDetector
//{
//public:
//  SensitiveDetector(G4String name)
// :G4VSensitiveDetector(name)
//  { collectionName.insert((name+"HC").c_str()); };
//  ~SensitiveDetector(){};
//  
//  void Initialize(G4HCofThisEvent* hce)
//  {
//    hits = new MyHitsCollection(SensitiveDetectorName, collectionName[0]);
//    hce->AddHitsCollection(
//      (G4int)G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]),
//      hits);
//  };
//  G4bool ProcessHits(G4Step* stp, G4TouchableHistory* t)
//  {
//    G4Track* trk = stp->GetTrack();
//    MyHit* hit = new MyHit;
//    hit->SetEdeposit(stp->GetTotalEnergyDeposit());
//    hit->SetPosition(trk->GetPosition());
//    hits->insert(hit);
//    return true;
//  };
//  void   EndOfEvent(G4HCofThisEvent* h) {};
//
//private:
//  MyHitsCollection*   hits;
//};
//

////============================================================================
//// DETECTOR CONSTRUCTION
////============================================================================
//class DetectorConstruction : public G4VUserDetectorConstruction
//{
//public:
//  DetectorConstruction(){};
//  ~DetectorConstruction(){};
//  
//  G4VPhysicalVolume* Construct()
//  {
//    G4Material* wld_mat = 
//      G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR", false);
//    G4Tubs* s_world = 
//      new G4Tubs("s_world", 0.0, wld_r, 0.5*wld_z, 0.0, 360.0);
//    G4LogicalVolume* l_world = 
//      new G4LogicalVolume(s_world, wld_mat, "l_world",0, 0);
//    G4PVPlacement* p_world 
//      = new G4PVPlacement(0, // rot_mat
//                          G4ThreeVector(0.,0.,0.), // cnt_pos
//                          l_world,   // curr_lv
//                          "p_world", // name
//                          0,         // mother_lv
//                          false,     // boolean op. not support
//                          0);        // copy num
//
//    G4SDManager* SDman = G4SDManager::GetSDMpointer();
//    SensitiveDetector* sd = new SensitiveDetector("block");
//    SDman->AddNewDetector(sd);
//    
//    G4Material* block_mat = 
//      G4NistManager::Instance()->FindOrBuildMaterial("G4_Fe", false);
//    G4Tubs* s_block = 
//      new G4Tubs("s_block", 0.0, 0.5*wld_r, 0.25*wld_z, 0.0, 360.0);
//    G4LogicalVolume* l_block = 
//      new G4LogicalVolume(s_block, block_mat, "l_block",0, sd);
//    G4PVPlacement* p_block 
//      = new G4PVPlacement(0, // rot_mat
//                          G4ThreeVector(0.,0.,0.), // cnt_pos
//                          l_block,   // curr_lv
//                          "p_block", // name
//                          l_world,   // mother_lv
//                          false,     // boolean op. not support
//                          0);        // copy num
//    return p_world;
//  };
//};


//============================================================================
// PHYSICS LIST
//============================================================================
//#include "G4VUserPhysicsList.hh"
//#include "G4ProcessManager.hh"
//#include "G4ParticleTypes.hh"
//#include "G4EmStandardPhysics_option3.hh"
//#include "G4DecayPhysics.hh"
//#include "G4ProductionCuts.hh"
//class PhysicsList: public G4VUserPhysicsList
//{
//public:
//  PhysicsList()
//  {
//    emPhys    = new G4EmStandardPhysics_option3();
//    decayPhys = new G4DecayPhysics();
//  };
//  ~PhysicsList()
//  {
//    delete decayPhys;
//    delete emPhys;
//  };
//
//protected:
//  G4EmStandardPhysics_option3* emPhys;            //E.M.
//  G4DecayPhysics*              decayPhys;         //Decay
//
//  // Construct particle and physics
//  void ConstructParticle()
//  {
//    decayPhys->ConstructParticle();
//  };
//  void ConstructProcess()
//  {
//    AddTransportation();
//    decayPhys->ConstructProcess();
//    emPhys->ConstructProcess();
//  };
//  void SetCuts()
//  {
//    SetCutsWithDefault();
//    DumpCutValuesTable();
//  };
//};


//============================================================================
// PRIMARY GENERATOR ACTION
//============================================================================
//#include "G4VUserPrimaryGeneratorAction.hh"
//#include "G4ParticleGun.hh"
//#include "G4Event.hh"
//#include "G4ParticleTable.hh"
//#include "G4ParticleDefinition.hh"
//#include "Randomize.hh"
//class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
//{
//public:
//  PrimaryGeneratorAction()
//  {
//    gun = new G4ParticleGun(1);
//  };
//  ~PrimaryGeneratorAction()
//  {
//    delete gun;
//  };
//
//public:
//  void GeneratePrimaries(G4Event* evt)
//  {
//    // pencil beam configuration
//    G4ParticleTable* t = G4ParticleTable::GetParticleTable();
//    gun->SetParticleDefinition(t->FindParticle("proton"));
//    gun->SetParticlePosition(
//      G4ThreeVector(0., 0., -0.5*wld_z));
//    gun->SetParticleMomentumDirection(
//      G4ThreeVector(0., 0., 1.)); 
//    gun->SetParticleEnergy(energy);
//    gun->GeneratePrimaryVertex(evt);
//  };
//
//private:
//  G4ParticleGun* gun;  
//};


////============================================================================
//// EVENT ACTION
////============================================================================
//#include "G4UserEventAction.hh"
//class EventAction : public G4UserEventAction
//{
//public:
//  EventAction(){};
//  ~EventAction(){};
//
//public:
//  void BeginOfEventAction(const G4Event* e)
//  {    G4cout << "event n:" << e->GetEventID() << G4endl;   };
//  void EndOfEventAction(const G4Event* e)
//  {
//    G4HCofThisEvent* hcte = e->GetHCofThisEvent();
//    G4int n_max_hc = G4SDManager::GetSDMpointer()->GetCollectionCapacity();
//    DetectorHitsCollection* hc = 0;
//    for (int i = 0; i < n_max_hc; ++i)
//    {
//      hc = (MyHitsCollection*) hcte->GetHC(i);
//      // analysis
//      for (int i = 0; i < hc->entries(); ++i)
//      {
//        G4ThreeVector x = (*hc)[i]->GetPosition();
//        G4double tot_e_depo = (*hc)[i]->GetEdeposit()/joule;
//        G4cout << " hit " << i
//               << " : (" << x.x() << ", " << x.y() << ", " << x.z() << ") mm : "
//               << tot_e_depo << " mJ" << G4endl;
//      }
//    }
//  }
//};
//  

#include "G4RunManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
  
int main(int argc,char** argv)
{
  // Geometry and physics definition
  G4RunManager * rman = new G4RunManager;
  rman->SetUserInitialization(new DetectorConstruction);
  rman->SetUserInitialization(new PhysicsList);

  // Actions definition
  rman->SetUserAction(new PrimaryGeneratorAction);
  rman->SetUserAction(new EventAction);

  // Visualization
  G4VisManager* vman = new G4VisExecutive("Quiet");
  vman->Initialize();

  // Interface..
  G4UImanager* uiman = G4UImanager::GetUIpointer();
  uiman->ApplyCommand("/vis/open OGL 600x600-0+0");
  uiman->ApplyCommand("/vis/drawVolume");
  uiman->ApplyCommand("/vis/scene/add/trajectories smooth");
  uiman->ApplyCommand("/vis/scene/endOfEventAction accumulate");
  uiman->ApplyCommand("/vis/viewer/set/autoRefresh true");

  rman->Initialize();

  // Pull the trigger
  rman->BeamOn(2);

  delete uiman;
  delete vman;
  delete rman;
  return 0;
 }


