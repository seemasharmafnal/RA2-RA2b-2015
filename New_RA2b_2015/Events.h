#ifndef EVENT_H
#define EVENT_H
#include "TTree.h"
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "TLorentzVector.h"
#include <stdio.h>
#include "TColor.h"
#include "TF1.h"
#include "TLegend.h"
#include "TVector3.h"
#include "TFile.h"
#include "TChain.h"
#include "TH1.h"
#include "TVector2.h"
#include "TCanvas.h"
using namespace std;

  class Events{

       // Declaration of leaf types
   UInt_t          RunNum;
   UInt_t          LumiBlockNum;
   UInt_t          EvtNum;
   Int_t           NVtx;
   Int_t           isoTracks;
   Int_t           Leptons;
   Int_t           NJets;
   Int_t           BTags;
   Float_t         Weight;
   Float_t         HT;
   Float_t         MHT;
   Float_t         DeltaPhi1;
   Float_t         DeltaPhi2;
   Float_t         DeltaPhi3;
   Float_t         minDeltaPhiN;
   TTree *         fChain;
   int             currentEntry_;
   int             template_Entries; 


   vector<double>  *testVec;

   vector<double>  *GenMuPtVec;
   vector<double>  *GenMuEtaVec;
   vector<double>  *GenMuPhiVec;

   vector<double>  *GenElecPtVec;
   vector<double>  *GenElecEtaVec;
   vector<double>  *GenElecPhiVec;


   vector<double>  *GenTauPtVec;
   vector<double>  *GenTauEtaVec;
   vector<double>  *GenTauPhiVec;

   vector<double>  *JetsPtVec;
   vector<double>  *JetsEtaVec;
   vector<double>  *JetsPhiVec;

   Int_t    *     GenMu_GenMuFromTau;   //[GenMuNum]
   Int_t    *      GenElec_GenElecFromTau;   //[GenElecNum]
   Int_t    *      GenTau_GenTauHad;   //[GenTauNum]


public:
//constructor
Events(TTree * ttree_, const std::string sampleKeyString="ttbar", int verbose=0);

//Functions
  bool loadNext();
  int nJets() const;
  int nBtags() const;
  int nLeptons() const;
  int nIso() const;
  double weight() const ;
  double ht() const ;
  double mht() const ;
  double deltaPhi1() const ;
  double deltaPhi2() const ;
  double deltaPhi3() const ;
  int nGenMu() const ;

   vector<double>  GenMuPtVec_() const;
   vector<double>  GenMuEtaVec_() const;
   vector<double>  GenMuPhiVec_() const;

   vector<double>  GenElecPtVec_() const;
   vector<double>  GenElecEtaVec_() const;
   vector<double>  GenElecPhiVec_() const;


   vector<double>  GenTauPtVec_() const;
   vector<double>  GenTauEtaVec_() const;
   vector<double>  GenTauPhiVec_() const;

   vector<double>  JetsPtVec_() const;
   vector<double>  JetsEtaVec_() const;
   vector<double>  JetsPhiVec_() const;

   vector<int>     GenMuFromTauVec_() const;   
   vector<int>     GenElecFromTauVec_() const;   
   vector<int>     GenTauHadVec_() const;   

};//end of class Events
#endif