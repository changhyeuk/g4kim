//============================================================================
// EVENT ACTION
//============================================================================
#ifndef EVENTACTION_HH
#define EVENTACTION_HH 1

#include "G4UserEventAction.hh"
#include "CGlobal.hh"

class G4Event;

class EventAction : public G4UserEventAction
{
public:
    EventAction();
    ~EventAction();
    
public:
    void BeginOfEventAction(const G4Event*);
    void EndOfEventAction(const G4Event*);
    
};


#endif //EVENTACTION_HH

