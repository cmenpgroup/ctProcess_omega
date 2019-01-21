#include <cmath>
#include <vector>
#include <string>
#include "MassDifference.h"
#include <iostream>

MassDifference::MassDifference()
{
    Label.push_back("Omega - pi0 - pi+ - pi-");
    Label.push_back("Omega - Pair(pi+pi-) - pi0");
    Label.push_back("Omega - Pair(pi+pi-)");
    Label.push_back("Omega - Pair(pi+pi0)");
    Label.push_back("Omega - Pair(pi-pi0)");
    Label.push_back("Omega - pi+");
    Label.push_back("Omega - pi-");
    Label.push_back("Omega - pi0");

    partLabel.push_back("Omega");
    partLabel.push_back("Pi+");
    partLabel.push_back("Pi-");
    partLabel.push_back("Pi0");
    partLabel.push_back("Pi+Pi-");
    partLabel.push_back("Pi+Pi0");
    partLabel.push_back("Pi-Pi0");

    MASS_PION_CHARGED = 0.138;
    MASS_PION_NEUTRAL = 0.135;
    M2_PION_CHARGED = MASS_PION_CHARGED*MASS_PION_CHARGED;
    M2_PION_NEUTRAL = MASS_PION_NEUTRAL*MASS_PION_NEUTRAL;

    this->ClearMasses();
}

void MassDifference::ClearMasses()
{
    partMass.assign(this->Get_nPartLabel(),0);
    partMassSq.assign(this->Get_nPartLabel(),0);
}

void MassDifference::Put_Mass(double Mass, string particle)
{
  bool ifound = false;

  for(int ii=0; ii<this->Get_nPartLabel(); ii++){
      if (this->Get_PartLabel(ii).compare(particle)==0) {
          partMass[ii] = Mass;
          ifound = true;
      }
  }
  if(!ifound) cout<<"MassDifference::Put_Mass(), Unknown particle"<<particle<<endl;
}

double MassDifference::Get_Mass(string particle)
{
  bool ifound = false;
  double Mass = 0.0;

  for(int ii=0; ii<this->Get_nPartLabel(); ii++){
      if (this->Get_PartLabel(ii).compare(particle)==0) {
          Mass = partMass[ii];
          ifound = true;
      }
  }
  if(!ifound) cout<<"MassDifference::Get_Mass(), Unknown particle"<<particle<<endl;
  return Mass;
}

void MassDifference::Put_MassSq(double MassSq, string particle)
{
  bool ifound = false;

  for(int ii=0; ii<this->Get_nPartLabel(); ii++){
      if (this->Get_PartLabel(ii).compare(particle)==0) {
          partMassSq[ii] = MassSq;
          ifound = true;
      }
  }
  if(!ifound) cout<<"MassDifference::Put_MassSq(), Unknown particle"<<particle<<endl;
}

double MassDifference::Get_MassSq(string particle)
{
  bool ifound = false;
  double MassSq = 0.0;

  for(int ii=0; ii<this->Get_nPartLabel(); ii++){
      if (this->Get_PartLabel(ii).compare(particle)==0) {
          MassSq = partMassSq[ii];
          ifound = true;
      }
  }
  if(!ifound) cout<<"MassDifference::Get_MassSq(), Unknown particle"<<particle<<endl;
  return MassSq;
}

double MassDifference::Get_MassDiff(string label)
{
  double diff = 0.0; // mass difference
  if(label.compare("Omega - pi0 - pi+ - pi-")==0){
    diff = this->Get_Mass("Omega") - this->Get_Mass("Pi0") - this->Get_Mass("Pi+") - this->Get_Mass("Pi-") + MASS_PION_NEUTRAL + 2.0*MASS_PION_CHARGED;
  }else if(label.compare("Omega - Pair(pi+pi-) - pi0")==0){
    diff = this->Get_Mass("Omega") - this->Get_Mass("Pi0") - this->Get_Mass("Pi+Pi-") + MASS_PION_NEUTRAL + 2.0*MASS_PION_CHARGED;
  }else if(label.compare("Omega - Pair(pi+pi-)")==0){
      diff = this->Get_Mass("Omega") - this->Get_Mass("Pi+Pi-") + 2.0*MASS_PION_CHARGED;
  }else if(label.compare("Omega - Pair(pi+pi0)")==0){
      diff = this->Get_Mass("Omega") - this->Get_Mass("Pi+Pi0") + MASS_PION_NEUTRAL + MASS_PION_CHARGED;
  }else if(label.compare("Omega - Pair(pi-pi0)")==0){
      diff = this->Get_Mass("Omega") - this->Get_Mass("Pi-Pi0") + MASS_PION_NEUTRAL + MASS_PION_CHARGED;
  }else if(label.compare("Omega - pi+")==0){
      diff = this->Get_Mass("Omega") - this->Get_Mass("Pi+") + MASS_PION_CHARGED;
  }else if(label.compare("Omega - pi-")==0){
      diff = this->Get_Mass("Omega") - this->Get_Mass("Pi-") + MASS_PION_CHARGED;
  }else if(label.compare("Omega - pi0")==0){
      diff = this->Get_Mass("Omega") - this->Get_Mass("Pi0") + MASS_PION_NEUTRAL;
  }else{
    cout<<"MassDifference::Get_MassDiff(), Unknown label"<<label<<endl;
  }
  return diff;
}

double MassDifference::Get_MassSqDiff(string label)
{
  double diff = 0.0; // mass difference
  if(label.compare("Omega - pi0 - pi+ - pi-")==0){
    diff = this->Get_MassSq("Omega") - this->Get_MassSq("Pi0") - this->Get_MassSq("Pi+") - this->Get_MassSq("Pi-") + M2_PION_NEUTRAL + 2.0*M2_PION_CHARGED;
  }else if(label.compare("Omega - Pair(pi+pi-) - pi0")==0){
    diff = this->Get_MassSq("Omega") - this->Get_MassSq("Pi0") - this->Get_MassSq("Pi+Pi-") + M2_PION_NEUTRAL + 2.0*M2_PION_CHARGED;
  }else if(label.compare("Omega - Pair(pi+pi-)")==0){
      diff = this->Get_MassSq("Omega") - this->Get_MassSq("Pi+Pi-") + 2.0*M2_PION_CHARGED;
  }else if(label.compare("Omega - Pair(pi+pi0)")==0){
      diff = this->Get_MassSq("Omega") - this->Get_MassSq("Pi+Pi0") + M2_PION_NEUTRAL + M2_PION_CHARGED;
  }else if(label.compare("Omega - Pair(pi-pi0)")==0){
      diff = this->Get_MassSq("Omega") - this->Get_MassSq("Pi-Pi0") + M2_PION_NEUTRAL + M2_PION_CHARGED;
  }else if(label.compare("Omega - pi+")==0){
      diff = this->Get_MassSq("Omega") - this->Get_MassSq("Pi+") + M2_PION_CHARGED;
  }else if(label.compare("Omega - pi-")==0){
      diff = this->Get_MassSq("Omega") - this->Get_MassSq("Pi-") + M2_PION_CHARGED;
  }else if(label.compare("Omega - pi0")==0){
      diff = this->Get_MassSq("Omega") - this->Get_MassSq("Pi0") + M2_PION_NEUTRAL;
  }else{
    cout<<"MassDifference::Get_MassSqDiff(), Unknown label"<<label<<endl;
  }
  return diff;
}

void MassDifference::Print()
{
    int ii;
    cout<<"MassDifference Labels"<<endl;
    cout<<"====================="<<endl;
    for(ii=0;ii<this->Get_nLabel();ii++){
        cout << this->Get_Label(ii) << endl;
    }
}
