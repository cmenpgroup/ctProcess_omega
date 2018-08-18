#ifndef CHARGEDPIONID_H
#define CHARGEDPIONID_H
#include <vector>
#include <string>

using namespace std;

class ChargedPionID
{
    vector<string> ChargedPionIDLabel;
    vector<double> RangeChargedPionSCMassSq;
    vector<double> RangeChargedPionDiffBeta;
    vector<double> RangeChargedPionEnergy;
    vector<double> RangeChargedPionMomentum;
    bool cuts_nPion_energy;
    bool cuts_pPion_energy;
    bool cuts_nPion_momentum;
    bool cuts_pPion_momentum;
    bool cuts_nPion_dbeta;
    bool cuts_pPion_dbeta;
    bool cuts_nPion_SCMassSq;
    bool cuts_pPion_SCMassSq;
    bool cuts_chPion;
public:
    ChargedPionID();
    int Get_nChargedPionID() {return ChargedPionIDLabel.size();};
    string Get_ChargedPionIDLabel(int num) {return ChargedPionIDLabel[num];};
    double Get_ChargedPionSCMassSq_lo() {return RangeChargedPionSCMassSq[0];};
    double Get_ChargedPionSCMassSq_hi() {return RangeChargedPionSCMassSq[1];};
    double Get_ChargedPionDiffBeta_lo() {return RangeChargedPionDiffBeta[0];};
    double Get_ChargedPionDiffBeta_hi() {return RangeChargedPionDiffBeta[1];};
    double Get_ChargedPionEnergy_lo() {return RangeChargedPionEnergy[0];};
    double Get_ChargedPionEnergy_hi() {return RangeChargedPionEnergy[1];};
    double Get_ChargedPionMomentum_lo() {return RangeChargedPionMomentum[0];};
    double Get_ChargedPionMomentum_hi() {return RangeChargedPionMomentum[1];};
    
    void InitCuts();
    bool Check_ChargedPionMomentum(double pP);
    bool Check_ChargedPionEnergy(double pE);
    bool Check_ChargedPionSCMassSq(double MassSq);
    bool Check_ChargedPionDiffBeta(double dBeta);

    void SetCut_PosPionEnergy(double pE);
    void SetCut_NegPionEnergy(double pE);
    void SetCut_PosPionMomentum(double pP);
    void SetCut_NegPionMomentum(double pP);
    void SetCut_PosPionSCMassSq(double MassSq);
    void SetCut_NegPionSCMassSq(double MassSq);
    void SetCut_PosPionDiffBeta(double dBeta);
    void SetCut_NegPionDiffBeta(double dBeta);
    void SetCut_ChargedPionPair();

    bool GetCut_PosPionEnergy() {return cuts_pPion_energy;};
    bool GetCut_NegPionEnergy() {return cuts_nPion_energy;};
    bool GetCut_PosPionMomentum() {return cuts_pPion_momentum;};
    bool GetCut_NegPionMomentum() {return cuts_nPion_momentum;};
    bool GetCut_PosPionSCMassSq() {return cuts_pPion_SCMassSq;};
    bool GetCut_NegPionSCMassSq() {return cuts_nPion_SCMassSq;};
    bool GetCut_PosPionDiffBeta() {return cuts_pPion_dbeta;};
    bool GetCut_NegPionDiffBeta() {return cuts_nPion_dbeta;};
    bool GetCut_ChargedPionPair() {return cuts_chPion;};
    
    void Print_ChargedPionID();
};
#endif
