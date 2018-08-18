#include <cmath>
#include <vector>
#include <string>
#include "ChargedPionID.h"
#include <iostream>
ChargedPionID::ChargedPionID()
{
    ChargedPionIDLabel.push_back("No Cuts");
    ChargedPionIDLabel.push_back("SCMassSq");
    ChargedPionIDLabel.push_back("DiffBeta");
    ChargedPionIDLabel.push_back("Energy");
    ChargedPionIDLabel.push_back("Momentum");
    
    RangeChargedPionDiffBeta.push_back(-0.035); // Lower limit on beta_TOF - beta_ideal
    RangeChargedPionDiffBeta.push_back(0.025); // Upper limit on beta_TOF - beta_ideal

    double Centroid, Width, Nsigmas, Lo, Hi;
    Centroid = 0.017956;
    Width = 0.005;
    Nsigmas = 3.0;
    Lo = Centroid - Nsigmas*Width;
    Hi = Centroid + Nsigmas*Width;
    RangeChargedPionSCMassSq.push_back(Lo);
    RangeChargedPionSCMassSq.push_back(Hi);
    
    RangeChargedPionEnergy.push_back(0.3); // Lower limit on pion energy
    RangeChargedPionEnergy.push_back(1000000.0); // Upper limit on pion energy

    RangeChargedPionMomentum.push_back(0.3); // Lower limit on pion energy
    RangeChargedPionMomentum.push_back(1000000.0); // Upper limit on pion energy
    
    this->InitCuts();
}

void ChargedPionID::InitCuts()
{
    cuts_nPion_SCMassSq = false;
    cuts_pPion_SCMassSq = false;
    cuts_nPion_dbeta = false;
    cuts_pPion_dbeta = false;
    cuts_nPion_energy = false;
    cuts_pPion_energy = false;
    cuts_nPion_momentum = false;
    cuts_pPion_momentum = false;
    cuts_chPion = false;
}

// check the cut on the energy
bool ChargedPionID::Check_ChargedPionEnergy(double pE)
{
    bool ret = (pE >= this->Get_ChargedPionEnergy_lo() && pE < this->Get_ChargedPionEnergy_hi()) ? true : false;
    return ret;
}

// check the cut on the momentum
bool ChargedPionID::Check_ChargedPionMomentum(double pP)
{
    bool ret = (pP >= this->Get_ChargedPionMomentum_lo() && pP < this->Get_ChargedPionMomentum_hi()) ? true : false;
    
    return ret;
}

// check the cut on TOF mass squared
bool ChargedPionID::Check_ChargedPionSCMassSq(double MassSq)
{
    bool ret = (MassSq >= this->Get_ChargedPionSCMassSq_lo() && MassSq < this->Get_ChargedPionSCMassSq_hi()) ? true : false;
    
    return ret;
}

// check the cut on beta difference
bool ChargedPionID::Check_ChargedPionDiffBeta(double dBeta)
{
    bool ret = (dBeta >= this->Get_ChargedPionDiffBeta_lo() && dBeta < this->Get_ChargedPionDiffBeta_hi()) ? true : false;
    
    return ret;
}

// set the value of the momentum cut for pi+
void ChargedPionID::SetCut_PosPionMomentum(double pP)
{
    cuts_pPion_momentum = this->Check_ChargedPionMomentum(pP);
}

// set the value of the momentum cut for pi-
void ChargedPionID::SetCut_NegPionMomentum(double pP)
{
    cuts_nPion_momentum = this->Check_ChargedPionMomentum(pP);
}

// set the value of the energy cut for pi+
void ChargedPionID::SetCut_PosPionEnergy(double pE)
{
    cuts_pPion_energy = this->Check_ChargedPionEnergy(pE);
}

// set the value of the energy cut for pi-
void ChargedPionID::SetCut_NegPionEnergy(double pE)
{
    cuts_nPion_energy = this->Check_ChargedPionEnergy(pE);
}

// set the value of the TOF mass squared cut for pi+
void ChargedPionID::SetCut_PosPionSCMassSq(double MassSq)
{
    cuts_pPion_SCMassSq = this->Check_ChargedPionSCMassSq(MassSq);
}

// set the value of the TOF mass squared cut for pi-
void ChargedPionID::SetCut_NegPionSCMassSq(double MassSq)
{
    cuts_nPion_SCMassSq = this->Check_ChargedPionSCMassSq(MassSq);
}

// set the value of the beta difference cut for pi+
void ChargedPionID::SetCut_PosPionDiffBeta(double dBeta)
{
    cuts_pPion_dbeta = this->Check_ChargedPionDiffBeta(dBeta);
}

// set the value of the beta diffrence cut for pi-
void ChargedPionID::SetCut_NegPionDiffBeta(double dBeta)
{
    cuts_nPion_dbeta = this->Check_ChargedPionDiffBeta(dBeta);
}

// set the final charged pion cut
void ChargedPionID::SetCut_ChargedPionPair()
{
    cuts_chPion = (this->GetCut_NegPionDiffBeta() && this->GetCut_PosPionDiffBeta());
}

// print the cut information
void ChargedPionID::Print_ChargedPionID()
{
    int ii;
    cout<<"ChargedPion ID Info"<<endl;
    cout<<"========================="<<endl;
    
    for(ii=0;ii<this->Get_nChargedPionID();ii++){
        cout << this->Get_ChargedPionIDLabel(ii) << "\t";
        if (this->Get_ChargedPionIDLabel(ii).compare("SCMassSq")==0) {
            cout << "[" << this->Get_ChargedPionSCMassSq_lo() << "," << this->Get_ChargedPionSCMassSq_hi() << "] (GeV)" << endl;
        }else if (this->Get_ChargedPionIDLabel(ii).compare("DiffBeta")==0) {
            cout << "[" << this->Get_ChargedPionDiffBeta_lo() << "," << this->Get_ChargedPionDiffBeta_hi() << "]" << endl;
        }else{
            cout << endl;
        }
    }
    cout << endl;
}
