#ifndef AnalysisMessenger_hh_
#define AnalysisMessenger_hh_ 1

struct MonStatus;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;

#include "AnalysisManager.hh"

#include "globals.hh"
#include "G4UImessenger.hh"

class AnalysisMessenger: public G4UImessenger
{
public:
    AnalysisMessenger(AnalysisManager* iam);
    ~AnalysisMessenger();
    
public:
    void SetNewValue(G4UIcommand* icmd, G4String istr);
    
private:
    AnalysisManager*     am;
    G4UIdirectory*       ana;
    G4UIcmdWithAString*  result;
};

#endif // ANALYSISMESSENGER_HH_