//============================================================================
// EVENT ACTION
//============================================================================

#include "EventAction.hh"
#include "AnalysisManager.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4SDManager.hh"
#include "G4HCtable.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"


//=============================================================================
EventAction::EventAction(){}

//=============================================================================
EventAction::~EventAction(){}

//=============================================================================
void EventAction::BeginOfEventAction(const G4Event* e)
{
    // Print out the event number at each 10 partilces were generated.
    // It could be changed by the situation.
    
    if ( (e->GetEventID()) % 10 == 0)
    {
        G4cout << "event: " << e->GetEventID() << G4endl;
    }
    else
    {
    
    }
}

//=============================================================================
void EventAction::EndOfEventAction(const G4Event* e)
{
    // data accumulation
    AnalysisManager* ana = AnalysisManager::GetInstance();
    
    G4HCofThisEvent* hcte = e->GetHCofThisEvent();
    
    const G4HCtable* hctable = G4SDManager::GetSDMpointer()->GetHCtable();
    
    G4String hchead;
    
    for (int i = 0; i < hctable->entries(); ++i)
    {
        G4String hcname = hctable->GetHCname(i);

        hchead.assign(hcname,0,4);

        if (hchead == "Trac")
        {
            //ana->FillTrackTuple(hcname, (TrackHitsCollection*) hcte->GetHC(i));
            //ana->FillTrackHisto2D(hcname, (TrackHitsCollection*) hcte->GetHC(i));
            
        }
        else if (hchead == "Calo")
        {
            //ana->FillCaloHisto3D(hcname, (CaloHitsCollection*) hcte->GetHC(i));
            ana->FillCaloHisto1D(hcname, (CaloHitsCollection*) hcte->GetHC(i));
        }
    }
}




//#include "G4Event.hh"
//#include "G4UserEventAction.hh"
//#include "G4SDManager.hh"
//
//#include "EventAction.hh"
//#include "DetectorHit.hh"
//#include "SensitiveDetector.hh"
//
//EventAction::EventAction()
//{
//
//}
//EventAction::~EventAction()
//{
//    
//}
//
//void EventAction::BeginOfEventAction(const G4Event* e)
//{
//    G4cout << "event n:" << e->GetEventID() << G4endl;
//};
//
//void EventAction::EndOfEventAction(const G4Event* e)
//{
//    G4HCofThisEvent* hcte = e->GetHCofThisEvent();
//    
//    G4int n_max_hc = G4SDManager::GetSDMpointer()->GetCollectionCapacity();
//    
//    DetectorHitsCollection* hc = 0;
//    
//    for (int i = 0; i < n_max_hc; ++i)
//    {
//        hc = (DetectorHitsCollection*) hcte->GetHC(i);
//        // analysis
//        for (int i = 0; i < hc->entries(); ++i)
//        {
//            G4ThreeVector x = (*hc)[i]->GetPosition();
//            
//            G4double tot_e_depo = (*hc)[i]->GetEdeposit()/joule;
//            
//            G4cout << " hit " << i<< " : (" << x.x() << ", " << x.y() << ", " << x.z() << ") mm : "
//                << tot_e_depo << " mJ" << G4endl;
//        }
//    }
//};