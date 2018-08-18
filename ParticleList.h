#ifndef PARTICLELIST_H
#define PARTICLELIST_H
#include <vector>
#include <string>

using namespace std;

class ParticleList
{
    vector<string> PartLabel;
public:
    ParticleList();
    int Get_nPartLabel();
	string Get_PartLabel(int num);
    int Get_PartIndex(string label);
	void Print_PartLabel();
};
#endif
