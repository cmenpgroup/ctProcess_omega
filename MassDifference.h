#ifndef MASSDIFFERENCE_H
#define MASSDIFFERENCE_H
#include <vector>
#include <string>

using namespace std;

class MassDifference
{
    vector<string> Label;
    vector<string> partLabel;
    vector<double> partMass;
    vector<double> partMassSq;
    double MASS_PION_CHARGED; // mass of charged pion in GeV/c^2
    double MASS_PION_NEUTRAL; // mass of neutral pion in GeV/c^2
    double M2_PION_CHARGED; // squared mass of charged pion
    double M2_PION_NEUTRAL; // squared mass of neutral pion     
public:
    MassDifference();
    void Print();
    void ClearMasses();
    int Get_nLabel() {return Label.size();};
    string Get_Label(int num) {return Label[num];};
    int Get_nPartLabel() {return partLabel.size();};
    string Get_PartLabel(int num) {return partLabel[num];};
    void Put_Mass(double Mass, string particle);
    void Put_MassSq(double MassSq, string particle);
    double Get_Mass(string particle);
    double Get_MassSq(string particle);
    double Get_MassDiff(string label);
    double Get_MassSqDiff(string label);
};
#endif
