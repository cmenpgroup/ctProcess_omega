#ifndef OMEGAMIXEDEVENT_H
#define OMEGAMIXEDEVENT_H
#include <vector>
#include <string>
#include "TLorentzVector.h"
#include "PartReader.h"

using namespace std;

class OmegaMixedEvent
{
    int nEvtToMix;
    int EvtOffset;
    int MixingMethod;
    int InTimeEvt;
    vector<int> OutOfTimeEvt;
    vector<string> Label;
    vector<int> Index;
    vector<string> evtLabel;
    vector<int> evtIndex;
    vector<int> evtNum;
    TLorentzVector Photon1[3];
    TLorentzVector Photon2[3];
    TLorentzVector PiPlus[3];
    TLorentzVector PiMinus[3];
    TLorentzVector Pi0[3];
    TLorentzVector Omega[3];
public:
    OmegaMixedEvent();
    int Get_NumberOfEventsToMix();
    void Put_NumberOfEventsToMix(int i);
    int Get_OffsetOfEventsToMix(){return EvtOffset;};
    void Put_OffsetOfEventsToMix(int i);
    bool Check_evtIndex(int iME);
    bool Check_Index(int iMethod);
    int Get_nLabel() {return Label.size();};
    int Get_nIndex() {return Index.size();};
    int Get_Index(string label);    
    string Get_Label(int num) {return Label[num];};
    int Get_nEvtLabel() {return evtLabel.size();};
    int Get_nEvtIndex() {return evtIndex.size();};
    int Get_EvtNum(string particle);
    void Put_EvtNum(int num, string particle);
    void Put_InTimeEvt(int num) {InTimeEvt = num;};
    void Put_OutOfTimeEvt(vector<int> vnum) {OutOfTimeEvt = vnum;};
    string Get_evtLabel(int num) {return evtLabel[num];};
    void Put_MixingMethod(int i);
    TLorentzVector Get_LorentzVector(string particle, int iME);
    void Reconstruct_Pi0(int iME);
    void Reconstruct_Omega(int iME);
    void Mix_Omega();
    void Put_LorentzVector(TLorentzVector V, string particle, int iME);
    void Clear_TLorentzVectors();
    void Print_Info();
};
#endif
