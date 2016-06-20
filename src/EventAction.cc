//============================================================================
// EVENT ACTION
//============================================================================

#include "G4Event.hh"
#include "G4UserEventAction.hh"
#include "G4SDManager.hh"

#include "EventAction.hh"
#include "DetectorHit.hh"
#include "SensitiveDetector.hh"

EventAction::EventAction()
{

}
EventAction::~EventAction()
{
    
}

void EventAction::BeginOfEventAction(const G4Event* e)
{
    G4cout << "event n:" << e->GetEventID() << G4endl;
};

void EventAction::EndOfEventAction(const G4Event* e)
{
    G4HCofThisEvent* hcte = e->GetHCofThisEvent();
    G4int n_max_hc = G4SDManager::GetSDMpointer()->GetCollectionCapacity();
    DetectorHitsCollection* hc = 0;
    for (int i = 0; i < n_max_hc; ++i)
    {
        hc = (DetectorHitsCollection*) hcte->GetHC(i);
        // analysis
        for (int i = 0; i < hc->entries(); ++i)
        {
            G4ThreeVector x = (*hc)[i]->GetPosition();
            G4double tot_e_depo = (*hc)[i]->GetEdeposit()/joule;
            G4cout << " hit " << i<< " : (" << x.x() << ", " << x.y() << ", " << x.z() << ") mm : "
                << tot_e_depo << " mJ" << G4endl;
        }
    }
};


