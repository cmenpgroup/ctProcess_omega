#include <vector>
#include <string>
#include "OmegaMixedEvent.h"
#include <iostream>
#include "TLorentzVector.h"
OmegaMixedEvent::OmegaMixedEvent()
{
    int i;

    Label.push_back("No Mixing");
    Label.push_back("Mixing Photon 1");
    Label.push_back("Mixing Photon 2");
    Label.push_back("Mixing pi+");
    Label.push_back("Mixing pi-");
    Label.push_back("Mixing pi0");
    Label.push_back("Random Mixing");

    Index.push_back(0);
    Index.push_back(1);
    Index.push_back(2);
    Index.push_back(3);
    Index.push_back(4);
    Index.push_back(5);
    Index.push_back(6);

    MixingMethod = 0; // default is no mixing
    nEvtToMix = 0; // default is no mixing

    evtLabel.push_back("In Time Event");
    evtLabel.push_back("Out of Time Event");
    evtLabel.push_back("Mixed Event");

    evtIndex.push_back(0);
    evtIndex.push_back(1);
    evtIndex.push_back(2);

    evtNum.push_back(0); // pi+ event number
    evtNum.push_back(0); // pi- event number
    evtNum.push_back(0); // photon 1 event number
    evtNum.push_back(0); // photon 2 event number

    for(i=0; i<evtIndex.size(); i++){
        Photon1[i].SetPxPyPzE(0.,0.,0.,0.);
        Photon2[i].SetPxPyPzE(0.,0.,0.,0.);
        Pi0[i].SetPxPyPzE(0.,0.,0.,0.);
        PiPlus[i].SetPxPyPzE(0.,0.,0.,0.);
        PiMinus[i].SetPxPyPzE(0.,0.,0.,0.);
        Omega[i].SetPxPyPzE(0.,0.,0.,0.);
    }
}

void OmegaMixedEvent::Put_MixingMethod(int i)
{
    if(this->Check_Index(i)){
      this->MixingMethod = i;
    }else{
      cout<<"OmegaMixedEvent::Put_MixingMethod(), Unknown method"<<i<<endl;
      exit(0);
    }
}

void OmegaMixedEvent::Clear_TLorentzVectors()
{
    int i;

    for(i=0; i < this->Get_nEvtIndex(); i++){
        this->Photon1[i].SetPxPyPzE(0.,0.,0.,0.);
        this->Photon2[i].SetPxPyPzE(0.,0.,0.,0.);
        this->Pi0[i].SetPxPyPzE(0.,0.,0.,0.);
        this->PiPlus[i].SetPxPyPzE(0.,0.,0.,0.);
        this->PiMinus[i].SetPxPyPzE(0.,0.,0.,0.);
        this->Omega[i].SetPxPyPzE(0.,0.,0.,0.);
    }
}

void OmegaMixedEvent::Put_NumberOfEventsToMix(int i){
    this->nEvtToMix = i;
}

int OmegaMixedEvent::Get_NumberOfEventsToMix()
{
  int ret = MixingMethod ? nEvtToMix : 0;
  return ret;
}

void OmegaMixedEvent::Put_OffsetOfEventsToMix(int i){
    this->EvtOffset = i;
}

// check that the event index is in the correct range
bool OmegaMixedEvent::Check_evtIndex(int iME)
{
    bool ret = (iME>=0 && iME<this->Get_nEvtIndex()) ? true : false;
    return ret;
}

// check that the method index is in the correct range
bool OmegaMixedEvent::Check_Index(int iMethod)
{
    bool ret = (iMethod>=0 && iMethod<this->Get_nIndex()) ? true : false;
    return ret;
}

int OmegaMixedEvent::Get_Index(string label)
{
    int ret = -1;
    bool ifound = false;

    for(int ii=0; ii<this->Get_nLabel(); ii++){
        if (this->Get_Label(ii).compare(label)==0) {
            ret = ii;
            ifound = true;
        }
    }
    if(!ifound) cout<<"OmegaMixedEvent::Get_Index(), Unknown label "<<label<<endl;
    return ret;
}

void OmegaMixedEvent::Put_LorentzVector(TLorentzVector V, string particle, int iME){
    if(this->Check_evtIndex(iME)){
      if(particle.compare("Pi+")==0){
        this->PiPlus[iME] = V;
      }else if(particle.compare("Pi-")==0){
        this->PiMinus[iME] = V;
      }else if(particle.compare("Photon1")==0){
        this->Photon1[iME] = V;
      }else if(particle.compare("Photon2")==0){
        this->Photon2[iME] = V;
      }else if(particle.compare("Pi0")==0){
        this->Pi0[iME] = V;
      }else if(particle.compare("Omega")==0){
        this->Omega[iME] = V;
      }else{
        cout<<"OmegaMixedEvent::Put_LorentzVector(), Unknown particle"<<particle<<endl;
        exit(0);
      }
    }
}

TLorentzVector OmegaMixedEvent::Get_LorentzVector(string particle, int iME){

    TLorentzVector ret(0.,0.,0.,0.); // init the return variable

    if(this->Check_evtIndex(iME)){
      if(particle.compare("Pi+")==0){
        ret = this->PiPlus[iME];
      }else if(particle.compare("Pi-")==0){
        ret = this->PiMinus[iME];
      }else if(particle.compare("Photon1")==0){
        ret = this->Photon1[iME];
      }else if(particle.compare("Photon2")==0){
        ret = this->Photon2[iME];
      }else if(particle.compare("Pi0")==0){
        ret = this->Pi0[iME];
      }else if(particle.compare("Omega")==0){
        ret = this->Omega[iME];
      }else{
        cout<<"OmegaMixedEvent::Get_LorentzVector(), Unknown particle"<<particle<<endl;
        exit(0);
      }
    }
    return ret;
}

int OmegaMixedEvent::Get_EvtNum(string particle){
    int ret;
    if(particle.compare("Pi+")==0){
      ret = this->evtNum[0];
    }else if(particle.compare("Pi-")==0){
      ret = this->evtNum[1];
    }else if(particle.compare("Photon1")==0){
      ret = this->evtNum[2];
    }else if(particle.compare("Photon2")==0){
      ret = this->evtNum[3];
    }else{
      cout<<"OmegaMixedEvent::Get_EvtNum(), Unknown particle"<<particle<<endl;
      exit(0);
    }
    return ret;
}

void OmegaMixedEvent::Put_EvtNum(int num, string particle){
    if(particle.compare("Pi+")==0){
      this->evtNum[0] = num;
    }else if(particle.compare("Pi-")==0){
      this->evtNum[1] = num;
    }else if(particle.compare("Photon1")==0){
      this->evtNum[2] = num;
    }else if(particle.compare("Photon2")==0){
      this->evtNum[3] = num;
    }else{
      cout<<"OmegaMixedEvent::Put_EvtNum(), Unknown particle"<<particle<<endl;
      exit(0);
    }
}

void OmegaMixedEvent::Reconstruct_Pi0(int iME){
    if(this->Check_evtIndex(iME)){
        TLorentzVector tempPhoton1 = this->Get_LorentzVector("Photon1",iME);
        TLorentzVector tempPhoton2 = this->Get_LorentzVector("Photon2",iME);

        this->Put_LorentzVector(tempPhoton1 + tempPhoton2, "Pi0", iME);
    }
}

void OmegaMixedEvent::Reconstruct_Omega(int iME){
    if(this->Check_evtIndex(iME)){
        TLorentzVector tempPhoton1 = this->Get_LorentzVector("Photon1",iME);
        TLorentzVector tempPhoton2 = this->Get_LorentzVector("Photon2",iME);
        TLorentzVector tempPiPlus = this->Get_LorentzVector("Pi+",iME);
        TLorentzVector tempPiMinus = this->Get_LorentzVector("Pi-",iME);

        this->Put_LorentzVector(tempPhoton1 + tempPhoton2 + tempPiPlus + tempPiMinus, "Omega", iME);
    }
}

void OmegaMixedEvent::Mix_Omega(){

    double theta, phi, tempPx, tempPy, tempPz, tempE;
    TLorentzVector tempPhoton1 = this->Get_LorentzVector("Photon1",0);
    TLorentzVector tempPhoton2 = this->Get_LorentzVector("Photon2",0);
    TLorentzVector tempPiPlus = this->Get_LorentzVector("Pi+",0);
    TLorentzVector tempPiMinus = this->Get_LorentzVector("Pi-",0);
    TLorentzVector tempPi0 = tempPhoton1 + tempPhoton2;
    TLorentzVector A, B, C;

    this->Put_EvtNum(this->InTimeEvt,"Pi+");
    this->Put_EvtNum(this->InTimeEvt,"Pi-");
    this->Put_EvtNum(this->InTimeEvt,"Photon1");
    this->Put_EvtNum(this->InTimeEvt,"Photon2");

    switch (this->MixingMethod){
        case 0:
//            cout <<"case 0"<<endl;
            // no Mixing
            break;
        case 1:
//            cout <<"case 1"<<endl;
            tempPhoton1 = this->Get_LorentzVector("Photon1",1);
            this->Put_EvtNum(this->OutOfTimeEvt.at(2),"Photon1");
            tempPi0 = tempPhoton1 + tempPhoton2;
            break;
        case 2:
//            cout <<"case 2"<<endl;
            this->Put_EvtNum(this->OutOfTimeEvt.at(3),"Photon2");
            tempPhoton2 = this->Get_LorentzVector("Photon2",1);
            tempPi0 = tempPhoton1 + tempPhoton2;
            break;
        case 3:
//            cout <<"case 3"<<endl;
            this->Put_EvtNum(this->OutOfTimeEvt.at(0),"Pi+");
            A = this->Get_LorentzVector("Pi+",1);
            A.SetTheta(tempPiPlus.Theta());
            A.SetPhi(tempPiPlus.Phi());
            tempPiPlus = A;
            break;
        case 4:
//            cout <<"case 4"<<endl;
            this->Put_EvtNum(this->OutOfTimeEvt.at(1),"Pi-");
            A = this->Get_LorentzVector("Pi-",1);
            A.SetTheta(tempPiMinus.Theta());
            A.SetPhi(tempPiMinus.Phi());
            tempPiMinus = A;
            break;
        case 5:
//            cout <<"case 5"<<endl;
            this->Put_EvtNum(this->OutOfTimeEvt.at(2),"Photon1");
            this->Put_EvtNum(this->OutOfTimeEvt.at(3),"Photon2");
            A = this->Get_LorentzVector("Photon1",1) + this->Get_LorentzVector("Photon2",1);
            A.SetTheta(tempPi0.Theta());
            A.SetPhi(tempPi0.Phi());
            tempPi0 = A;
            break;
        case 6:
//            cout <<"case 6"<<endl;
            this->Put_EvtNum(this->OutOfTimeEvt.at(0),"Pi+");
            this->Put_EvtNum(this->OutOfTimeEvt.at(1),"Pi-");
            this->Put_EvtNum(this->OutOfTimeEvt.at(2),"Photon1");
            this->Put_EvtNum(this->OutOfTimeEvt.at(3),"Photon2");
            tempPhoton1 = this->Get_LorentzVector("Photon1",1);
            tempPhoton2 = this->Get_LorentzVector("Photon2",1);
            A = tempPiPlus = this->Get_LorentzVector("Pi+",1);
            A.SetTheta(tempPiPlus.Theta());
            A.SetPhi(tempPiPlus.Phi());
            tempPiPlus = A;
            B = tempPiPlus = this->Get_LorentzVector("Pi-",1);
            B.SetTheta(tempPiMinus.Theta());
            B.SetPhi(tempPiMinus.Phi());
            tempPiMinus = B;
            C = tempPhoton1 + tempPhoton2;
            C.SetTheta(tempPi0.Theta());
            C.SetPhi(tempPi0.Phi());
            tempPi0 = C;
            break;
        default:
            cout << "OmegaMixedEvent::Mix_Omega - incorrect mixing method " << this->MixingMethod <<endl;
            exit(0);
            break;
    }
    this->Put_LorentzVector(tempPhoton1,"Photon1",2);
    this->Put_LorentzVector(tempPhoton2,"Photon2",2);
    this->Put_LorentzVector(tempPiPlus,"Pi+",2);
    this->Put_LorentzVector(tempPiMinus,"Pi-",2);
    this->Put_LorentzVector(tempPi0,"Pi0",2);
    this->Put_LorentzVector((tempPi0 + tempPiPlus + tempPiMinus),"Omega", 2);
}

void OmegaMixedEvent::Print_Info()
{
    int ii;
    cout<<"Mixed Event Info"<<endl;
    cout<<"========================="<<endl;

    for(ii=0;ii<this->Get_nLabel();ii++){
        cout << "Method " << ii << "\t" << this->Get_Label(ii) << endl;
    }
    for(ii=0;ii<this->Get_nEvtLabel();ii++){
        cout << "Event type " << ii+1 << "\t" << this->Get_evtLabel(ii) << endl;
    }
    cout << endl;
}
