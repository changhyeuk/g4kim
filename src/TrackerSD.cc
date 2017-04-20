#include "TrackerSD.hh"
#include "SensitiveDetector.hh"
#include "AnalysisManager.hh"

#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"

#include "G4SDManager.hh"
#include "G4ios.hh"

//=============================================================================
TrackerSD::TrackerSD(const G4String iname,
                     const G4RotationMatrix& iR,
                     const G4ThreeVector& iV)
 :SensitiveDetector(G4String("TrackerSD_") + iname, iR, iV)
{
    AnalysisManager* ana = AnalysisManager::GetInstance();
    // 1. 'fullPathName' was used instead of SensitiveDetectorName.
    // 2. Only one HC on one SD was used, so HCname and SDname are the same.
    
    ana->BookTrackTuple(SensitiveDetectorName);
    /*
    ana->BookTrackHisto2D(SensitiveDetectorName,
                          100,  // const G4int inx,
                          -50, // const G4double ixmin,
                          50,  // const G4double ixmax,
                          100,  // const G4int iny,
                          -50, // const G4double iymin,
                          50); // const G4double iymax);
     */
    collectionName.insert(SensitiveDetectorName);
    
    // below must be bottom line of this constructor
    G4SDManager::GetSDMpointer()->AddNewDetector(this);
}

//=============================================================================
TrackerSD::~TrackerSD()
{
    
}

//=============================================================================
void TrackerSD::Initialize(G4HCofThisEvent* hce)
{
    hits = new TrackHitsCollection(SensitiveDetectorName, collectionName[0]);
    hce->AddHitsCollection(
                           (G4int)G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]),
                           hits);
}

//=============================================================================
G4bool TrackerSD::ProcessHits(G4Step* istp, G4TouchableHistory*)
{
    G4Track* trk = istp->GetTrack();
    
    G4ParticleDefinition *pDef = trk -> GetDefinition();
    G4int Aa = pDef -> GetAtomicMass();
    G4int Zz = pDef -> GetAtomicNumber();
    
   
    // G4cout<<" =========== Virtual Monitor was called ============"<<G4endl;
    if ( Aa == 1 && Zz == 0 )
    {
        G4cout<<" Neutron : "<<Aa<<" and "<<Zz<<G4endl;
        TrackHit* hit = new TrackHit();
        G4int PDGencoding = trk->GetDefinition()->GetPDGEncoding();
        //hit->SetParticleId(PDGencoding);
        //hit->SetTrackId(trk->GetTrackID());
        //hit->SetPosition(R * (trk->GetPosition() - V));
        //hit->SetMomentum(R * trk->GetMomentum());
        hit->SetKineticEnergy(trk->GetKineticEnergy());
        G4double N_energy = trk->GetKineticEnergy();
        G4cout<<" Energy is "<<N_energy/CLHEP::MeV<<" MeV"<<G4endl;
        G4int L = 0, A = 0, Z = 0, I = 0, TMP = 0;
        if ((PDGencoding > 100000000) || (PDGencoding < -100000000))
        { // if nuclei
            TMP = PDGencoding - 1000000000;
            L = TMP / 10000000;          // N_STRANGE_QUARK
            TMP = TMP - L * 10000000;
            Z = TMP / 10000;             // Atomic Mass (=N_BARYON)
            TMP = TMP - Z * 10000;
            A = TMP / 10;                // Atomic Number (=N_PROTON)
            I = TMP - A * 10;            // Isomeric Excitation Energy (1-4 Lv)
            //hit->SetNStrangeQuark(L);
            //hit->SetAtomicNumber(Z);
            //hit->SetAtomicMass(A);
            //hit->SetIsomericExtEnergy(I);
        }
        hits->insert(hit);
    }
    return true;
}

//=============================================================================
void TrackerSD::EndOfEvent(G4HCofThisEvent*)
{
}

