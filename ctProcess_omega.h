#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "TLorentzVector.h"
#include "TLorentzRotation.h"
#include "TVector3.h"
#include "TFile.h"
#include "TChain.h"
#include "TBranch.h"
#include "TLeaf.h"
#include "DetectedParticles.h"
#include "IntermediateParticles.h"
#include "ReconstructedParticles.h"
#include "ParticleList.h"
#include "EG2Target.h"
#include "EG2Cuts.h"
#include "ElectronID.h"
#include "PhotonID.h"
#include "ChargedPionID.h"
#include "EC_geometry.h"
#include "Vertex_Corrections.h"
#include "OmegaMixedEvent.h"
#include "HistManager.h"
#include "KineReader.h"
#include "PartReader.h"
#include "RunCounter.h"
#include "MassDifference.h"

#define DEBUG 0
#define ECSC_TimeOffset 0.7

using namespace std;

HistManager myHistManager; // declare the histogram manager
RunCounter myCounter; // declare the counters

bool Analyze_PipPim(PartReader pimReader, PartReader pipReader, bool bPlot);
bool Analyze_Photons(PartReader photon1Reader, PartReader photon2Reader, int iSim, bool bPlot);
bool Analyze_Electron(PartReader elecReader, double Qsq, double targMass, int iSim, bool bPlot);
int GetSectorByPhi(double phi_rad);
double Calc_PhiPQ(TLorentzVector p, TLorentzVector q);
int process (string inFile, int MaxEvents, int dEvents, int targMass, int iSim, bool printCuts, int bMixEvt);
void PrintUsage(char *processName);
void PrintAnalysisTime(float tStart, float tStop);
int CheckCut(double var, double LowerLimit, double UpperLimit);
void Fill_EC_Histograms(PartReader Rdr, int ip);
void PrintTVector3(TVector3 V);
void PrintTLorentzVector(TLorentzVector TLV);
void Plot_Pi0_Decay(TLorentzVector TwoPhoton);
