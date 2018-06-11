#include <cmath>
#include <vector>
#include <string>
#include "KineReader.h"
#include <iostream>
KineReader::KineReader(TTree *tree)
{
    b_kine = tree->GetBranch("Kinematics");
    l_evtnum = b_kine->GetLeaf("EvtNum");
    l_q2 = b_kine->GetLeaf("Q2");
    l_nu = b_kine->GetLeaf("Nu");
    l_xb = b_kine->GetLeaf("Xb");
    l_w = b_kine->GetLeaf("W");
    l_xcorr = b_kine->GetLeaf("Xcorr");
    l_ycorr = b_kine->GetLeaf("Ycorr");
    l_zcorr = b_kine->GetLeaf("Zcorr");
    l_nelec = b_kine->GetLeaf("nElec");
    l_npip = b_kine->GetLeaf("nPip");
    l_npim = b_kine->GetLeaf("nPim");
    l_ngam = b_kine->GetLeaf("nGam");
    l_nproton = b_kine->GetLeaf("nProton");
    l_nneutron = b_kine->GetLeaf("nNeutron");
    l_nkp = b_kine->GetLeaf("nKp");
    l_nkm = b_kine->GetLeaf("nKm");
    l_npositron = b_kine->GetLeaf("nPositron");
    l_partcomb = b_kine->GetLeaf("PartComb");
}

void KineReader::ReadEntry(int num)
{
    b_kine->GetEntry(num);
}

int KineReader::Get_nProton()
{
    int ret = 0; // initial to zero protons in the event

    if(l_nproton) ret = l_nproton->GetValue(); // if ROOT tree has a TLeaf, fill the value

    return ret;
}

int KineReader::Get_nNeutron()
{
    int ret = 0; // initial to zero neutrons in the event
    
    if(l_nneutron) ret = l_nneutron->GetValue(); // if ROOT tree has a TLeaf, fill the value
    
    return ret;
}

int KineReader::Get_nKp()
{
    int ret = 0; // initial to zero K+ in the event
    
    if(l_nkp) ret = l_nkp->GetValue(); // if ROOT tree has a TLeaf, fill the value
    
    return ret;
}

int KineReader::Get_nKm()
{
    int ret = 0; // initial to zero K- in the event
    
    if(l_nkm) ret = l_nkm->GetValue(); // if ROOT tree has a TLeaf, fill the value
    
    return ret;
}

int KineReader::Get_nPositron()
{
    int ret = 0; // initial to zero e+ in the event
    
    if(l_npositron) ret = l_npositron->GetValue(); // if ROOT tree has a TLeaf, fill the value
    
    return ret;
}

int KineReader::Get_PartComb()
{
    int ret = 0; // initial to zero particle combinations in the event
    
    if(l_partcomb) ret = l_partcomb->GetValue(); // if ROOT tree has a TLeaf, fill the value
    
    return ret;
}
