//
// This tutorials demonstrate how to store and restore simple vectors
// in a TTree
//

#include <vector>

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TH1F.h"
#include "TBenchmark.h"
#include "TRandom.h"
#include "TSystem.h"

using namespace std;

void read()
{
    
    TFile *f = TFile::Open("PipPimPi0_clas_42011_v3.pass2.root","READ");
    
    if (!f) { return; }
    
    TTree *myTree = (TTree*)f->Get("Data");
    int entries = myTree->GetEntries();
    
    // Create a new canvas.
    TCanvas *c1 = new TCanvas("c1","Dynamic Filling Example",200,10,700,500);
    c1->SetFillColor(42);
    c1->GetFrame()->SetFillColor(21);
    c1->GetFrame()->SetBorderSize(6);
    c1->GetFrame()->SetBorderMode(-1);
    
    const Int_t kUPDATE = 50;

    vector<int> *pr_pevtnum;
    vector<Double_t> *pr_charge;
    vector<Double_t> *pr_pid;

    TBranch *b_pevtnum;
    TBranch *b_charge;
    TBranch *b_pid;

    myTree->SetBranchAddress("pEvtNum",&pr_pevtnum,&b_pevtnum);
    myTree->SetBranchAddress("Charge",&pr_charge,&b_charge);
    myTree->SetBranchAddress("Pid",&pr_pid,&b_pid);
    
    TBranch *b_kine = myTree->GetBranch("Kinematics");
    TLeaf *l_evtnum = b_kine->GetLeaf("EvtNum");
    
    // Create one histograms
    TH1F *h = new TH1F("h","This is the particle charge",100,-4,4);
    h->SetFillColor(48);
    
    for (Int_t i = 0; i < entries; i++) {
        
        b_kine->GetEntry(i);
        cout<<"Kine evt: "<<l_evtnum->GetValue()<<endl;
        
        Long64_t tentry = myTree->LoadTree(i);
        b_pevtnum->GetEntry(tentry);
        b_charge->GetEntry(tentry);
        b_pid->GetEntry(tentry);
        
        cout << "Event Number: "<<pr_pevtnum->at(0)<<"\t"<<pr_pevtnum->size()<<endl;
        
        for (UInt_t j = 0; j < pr_charge->size(); ++j) {
         
            cout<<i<<"\t"<<j<<"\t"<<tentry<<"\t"<<pr_charge->at(j)<<"\t"<<pr_pid->at(j)<<endl;
            h->Fill(pr_charge->at(j));
            
        }
        if (i && (i%kUPDATE) == 0) {
            if (i == kUPDATE) h->Draw();
            c1->Modified();
            c1->Update();
            if (gSystem->ProcessEvents())
                break;
        }
    }
    
    // Since we passed the address of a local variable we need
    // to remove it.
    myTree->ResetBranchAddresses();
}


void TreeVector()
{
    gBenchmark->Start("TreeVector");
    
    read();
    
    gBenchmark->Show("TreeVector");
}

