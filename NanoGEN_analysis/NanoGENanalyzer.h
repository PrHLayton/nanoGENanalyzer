//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan 27 14:00:46 2022 by ROOT version 6.14/09
// from TTree Events/Events
// found on file: PROC_SM_ttbar_emu_13TeV_LHE_0to200_NanoGEN.root
//////////////////////////////////////////////////////////

#ifndef NanoGENanalyzer_h
#define NanoGENanalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <stdio.h>
#include <math.h>

#include "Math/Functor.h"
#include "Math/Factory.h"
#include "Math/Minimizer.h"
#include "TMatrixD.h"
#include "TVector2.h"
#include "Math/GSLMinimizer1D.h"

// Header file for the classes stored in the TTree if any.

class NanoGENanalyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
/*
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   Float_t         HTXS_Higgs_pt;
   Float_t         HTXS_Higgs_y;
   Int_t           HTXS_stage1_1_cat_pTjet25GeV;
   Int_t           HTXS_stage1_1_cat_pTjet30GeV;
   Int_t           HTXS_stage1_1_fine_cat_pTjet25GeV;
   Int_t           HTXS_stage1_1_fine_cat_pTjet30GeV;
   Int_t           HTXS_stage1_2_cat_pTjet25GeV;
   Int_t           HTXS_stage1_2_cat_pTjet30GeV;
   Int_t           HTXS_stage1_2_fine_cat_pTjet25GeV;
   Int_t           HTXS_stage1_2_fine_cat_pTjet30GeV;
   Int_t           HTXS_stage_0;
   Int_t           HTXS_stage_1_pTjet25;
   Int_t           HTXS_stage_1_pTjet30;
   UChar_t         HTXS_njets25;
   UChar_t         HTXS_njets30;
   UInt_t          nGenJetAK8;
   Float_t         GenJetAK8_eta[8];   //[nGenJetAK8]
   Float_t         GenJetAK8_mass[8];   //[nGenJetAK8]
   Float_t         GenJetAK8_phi[8];   //[nGenJetAK8]
   Float_t         GenJetAK8_pt[8];   //[nGenJetAK8]
*/
   UInt_t          nGenJet;
   Float_t         GenJet_eta[25];   //[nGenJet]
   Float_t         GenJet_mass[25];   //[nGenJet]
   Float_t         GenJet_phi[25];   //[nGenJet]
   Float_t         GenJet_pt[25];   //[nGenJet]

   Float_t         Generator_weight;
   Float_t         genWeight;
   Float_t         LHEWeight_originalXWGTUP;
/*
   UInt_t          nGenPart;
   Float_t         GenPart_eta[4400];   //[nGenPart]
   Float_t         GenPart_mass[4400];   //[nGenPart]
   Float_t         GenPart_phi[4400];   //[nGenPart]
   Float_t         GenPart_pt[4400];   //[nGenPart]
   Int_t           GenPart_genPartIdxMother[4400];   //[nGenPart]
   Int_t           GenPart_pdgId[4400];   //[nGenPart]
   Int_t           GenPart_status[4400];   //[nGenPart]
   Int_t           GenPart_statusFlags[4400];   //[nGenPart]
   Float_t         Generator_binvar;
   Float_t         Generator_scalePDF;
   Float_t         Generator_x1;
   Float_t         Generator_x2;
   Float_t         Generator_xpdf1;
   Float_t         Generator_xpdf2;
   Int_t           Generator_id1;
   Int_t           Generator_id2;
   Float_t         GenVtx_x;
   Float_t         GenVtx_y;
   Float_t         GenVtx_z;
   UInt_t          nGenVisTau;
   Float_t         GenVisTau_eta[3];   //[nGenVisTau]
   Float_t         GenVisTau_mass[3];   //[nGenVisTau]
   Float_t         GenVisTau_phi[3];   //[nGenVisTau]
   Float_t         GenVisTau_pt[3];   //[nGenVisTau]
   Int_t           GenVisTau_charge[3];   //[nGenVisTau]
   Int_t           GenVisTau_genPartIdxMother[3];   //[nGenVisTau]
   Int_t           GenVisTau_status[3];   //[nGenVisTau]
   
   */
   UInt_t          nLHEPdfWeight;
   Float_t         LHEPdfWeight[103];   //[nLHEPdfWeight]
   UInt_t          nLHEReweightingWeight;
   Float_t         LHEReweightingWeight[1];   //[nLHEReweightingWeight]
   UInt_t          nLHEScaleWeight;
   Float_t         LHEScaleWeight[8];   //[nLHEScaleWeight]
   UInt_t          nPSWeight;
   Float_t         PSWeight[44];   //[nPSWeight]

   
   Float_t         LHE_HT;
   Float_t         LHE_HTIncoming;
   Float_t         LHE_Vpt;
   Float_t         LHE_AlphaS;
   UChar_t         LHE_Njets;
   UChar_t         LHE_Nb;
   UChar_t         LHE_Nc;
   UChar_t         LHE_Nuds;
   UChar_t         LHE_Nglu;
   UChar_t         LHE_NpNLO;
   UChar_t         LHE_NpLO;

   UInt_t          nLHEPart;
   Float_t         LHEPart_pt[10];   //[nLHEPart]
   Float_t         LHEPart_eta[10];   //[nLHEPart]
   Float_t         LHEPart_phi[10];   //[nLHEPart]
   Float_t         LHEPart_mass[10];   //[nLHEPart]
   Float_t         LHEPart_incomingpz[10];   //[nLHEPart]
   Int_t           LHEPart_pdgId[10];   //[nLHEPart]
   Int_t           LHEPart_status[10];   //[nLHEPart]
   Int_t           LHEPart_spin[10];   //[nLHEPart]
/*
   Float_t         GenMET_phi;
   Float_t         GenMET_pt;
*/
   UInt_t          nGenDressedLepton;
   Float_t         GenDressedLepton_eta[8];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_mass[8];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_phi[8];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_pt[8];   //[nGenDressedLepton]
   Int_t           GenDressedLepton_pdgId[8];   //[nGenDressedLepton]
   Bool_t          GenDressedLepton_hasTauAnc[8];   //[nGenDressedLepton]
   
   Float_t         MET_fiducialGenPhi;
   Float_t         MET_fiducialGenPt;

/*
   UInt_t          nGenIsolatedPhoton;
   Float_t         GenIsolatedPhoton_eta[4];   //[nGenIsolatedPhoton]
   Float_t         GenIsolatedPhoton_mass[4];   //[nGenIsolatedPhoton]
   Float_t         GenIsolatedPhoton_phi[4];   //[nGenIsolatedPhoton]
   Float_t         GenIsolatedPhoton_pt[4];   //[nGenIsolatedPhoton]
   Int_t           GenJetAK8_partonFlavour[8];   //[nGenJetAK8]
   UChar_t         GenJetAK8_hadronFlavour[8];   //[nGenJetAK8]
*/
   Int_t           GenJet_partonFlavour[25];   //[nGenJet]
   UChar_t         GenJet_hadronFlavour[25];   //[nGenJet]
//   Float_t         GenVtx_t0;

   // List of branches
/*
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_HTXS_Higgs_pt;   //!
   TBranch        *b_HTXS_Higgs_y;   //!
   TBranch        *b_HTXS_stage1_1_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_1_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage1_1_fine_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_1_fine_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage1_2_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_2_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage1_2_fine_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_2_fine_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage_0;   //!
   TBranch        *b_HTXS_stage_1_pTjet25;   //!
   TBranch        *b_HTXS_stage_1_pTjet30;   //!
   TBranch        *b_HTXS_njets25;   //!
   TBranch        *b_HTXS_njets30;   //!
   TBranch        *b_nGenJetAK8;   //!
   TBranch        *b_GenJetAK8_eta;   //!
   TBranch        *b_GenJetAK8_mass;   //!
   TBranch        *b_GenJetAK8_phi;   //!
   TBranch        *b_GenJetAK8_pt;   //!
*/
   TBranch        *b_nGenJet;   //!
   TBranch        *b_GenJet_eta;   //!
   TBranch        *b_GenJet_mass;   //!
   TBranch        *b_GenJet_phi;   //!
   TBranch        *b_GenJet_pt;   //!

   // TBranch        *b_nGenPart;   //!
   // TBranch        *b_GenPart_eta;   //!
   // TBranch        *b_GenPart_mass;   //!
   // TBranch        *b_GenPart_phi;   //!
   // TBranch        *b_GenPart_pt;   //!
   // TBranch        *b_GenPart_genPartIdxMother;   //!
   // TBranch        *b_GenPart_pdgId;   //!
   // TBranch        *b_GenPart_status;   //!
   // TBranch        *b_GenPart_statusFlags;   //!
   // TBranch        *b_Generator_binvar;   //!
   // TBranch        *b_Generator_scalePDF;   //!
   // TBranch        *b_Generator_weight;   //!
   // TBranch        *b_Generator_x1;   //!
   // TBranch        *b_Generator_x2;   //!
   // TBranch        *b_Generator_xpdf1;   //!
   // TBranch        *b_Generator_xpdf2;   //!
   // TBranch        *b_Generator_id1;   //!
   // TBranch        *b_Generator_id2;   //!
   // TBranch        *b_GenVtx_x;   //!
   // TBranch        *b_GenVtx_y;   //!
   // TBranch        *b_GenVtx_z;   //!
   // TBranch        *b_nGenVisTau;   //!
   // TBranch        *b_GenVisTau_eta;   //!
   // TBranch        *b_GenVisTau_mass;   //!
   // TBranch        *b_GenVisTau_phi;   //!
   // TBranch        *b_GenVisTau_pt;   //!
   // TBranch        *b_GenVisTau_charge;   //!
   // TBranch        *b_GenVisTau_genPartIdxMother;   //!
   // TBranch        *b_GenVisTau_status;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_LHEWeight_originalXWGTUP;   //!
   // TBranch        *b_nLHEPdfWeight;   //!
   // TBranch        *b_LHEPdfWeight;   //!
   // TBranch        *b_nLHEReweightingWeight;   //!
   // TBranch        *b_LHEReweightingWeight;   //!
   // TBranch        *b_nLHEScaleWeight;   //!
   // TBranch        *b_LHEScaleWeight;   //!
   // TBranch        *b_nPSWeight;   //!
   // TBranch        *b_PSWeight;   //!
   // TBranch        *b_LHE_HT;   //!
   // TBranch        *b_LHE_HTIncoming;   //!
   // TBranch        *b_LHE_Vpt;   //!
   // TBranch        *b_LHE_AlphaS;   //!
   // TBranch        *b_LHE_Njets;   //!
   // TBranch        *b_LHE_Nb;   //!
   // TBranch        *b_LHE_Nc;   //!
   // TBranch        *b_LHE_Nuds;   //!
   // TBranch        *b_LHE_Nglu;   //!
   // TBranch        *b_LHE_NpNLO;   //!
   // TBranch        *b_LHE_NpLO;   //!

   TBranch        *b_nLHEPart;   //!
   TBranch        *b_LHEPart_pt;   //!
   TBranch        *b_LHEPart_eta;   //!
   TBranch        *b_LHEPart_phi;   //!
   TBranch        *b_LHEPart_mass;   //!
   TBranch        *b_LHEPart_incomingpz;   //!
   TBranch        *b_LHEPart_pdgId;   //!
   TBranch        *b_LHEPart_status;   //!
   TBranch        *b_LHEPart_spin;   //!
/*
   TBranch        *b_GenMET_phi;   //!
   TBranch        *b_GenMET_pt;   //!
*/
   TBranch        *b_nGenDressedLepton;   //!
   TBranch        *b_GenDressedLepton_eta;   //!
   TBranch        *b_GenDressedLepton_mass;   //!
   TBranch        *b_GenDressedLepton_phi;   //!
   TBranch        *b_GenDressedLepton_pt;   //!
   TBranch        *b_GenDressedLepton_pdgId;   //!
   TBranch        *b_GenDressedLepton_hasTauAnc;   //!
/*
   TBranch        *b_MET_fiducialGenPhi;   //!
   TBranch        *b_MET_fiducialGenPt;   //!
   TBranch        *b_nGenIsolatedPhoton;   //!
   TBranch        *b_GenIsolatedPhoton_eta;   //!
   TBranch        *b_GenIsolatedPhoton_mass;   //!
   TBranch        *b_GenIsolatedPhoton_phi;   //!
   TBranch        *b_GenIsolatedPhoton_pt;   //!
   TBranch        *b_GenJetAK8_partonFlavour;   //!
   TBranch        *b_GenJetAK8_hadronFlavour;   //!
*/
   TBranch        *b_GenJet_partonFlavour;   //!
   TBranch        *b_GenJet_hadronFlavour;   //!
//   TBranch        *b_GenVtx_t0;   //!

   // TLorentzVector, TMatrixD, double parameters declaration
   bool* passGenLevelSelection;
   double* SelectedGenDressedLepton_dileptonMass;

   NanoGENanalyzer(TString rootFile, TTree *tree=0);
   virtual ~NanoGENanalyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef NanoGENanalyzer_cxx
NanoGENanalyzer::NanoGENanalyzer(TString rootFile, TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(rootFile);
      if (!f || !f->IsOpen()) {
         f = new TFile(rootFile);
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

NanoGENanalyzer::~NanoGENanalyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t NanoGENanalyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NanoGENanalyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void NanoGENanalyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   // fChain->SetBranchAddress("run", &run, &b_run);
   // fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   // fChain->SetBranchAddress("event", &event, &b_event);
   // fChain->SetBranchAddress("HTXS_Higgs_pt", &HTXS_Higgs_pt, &b_HTXS_Higgs_pt);
   // fChain->SetBranchAddress("HTXS_Higgs_y", &HTXS_Higgs_y, &b_HTXS_Higgs_y);
   // fChain->SetBranchAddress("HTXS_stage1_1_cat_pTjet25GeV", &HTXS_stage1_1_cat_pTjet25GeV, &b_HTXS_stage1_1_cat_pTjet25GeV);
   // fChain->SetBranchAddress("HTXS_stage1_1_cat_pTjet30GeV", &HTXS_stage1_1_cat_pTjet30GeV, &b_HTXS_stage1_1_cat_pTjet30GeV);
   // fChain->SetBranchAddress("HTXS_stage1_1_fine_cat_pTjet25GeV", &HTXS_stage1_1_fine_cat_pTjet25GeV, &b_HTXS_stage1_1_fine_cat_pTjet25GeV);
   // fChain->SetBranchAddress("HTXS_stage1_1_fine_cat_pTjet30GeV", &HTXS_stage1_1_fine_cat_pTjet30GeV, &b_HTXS_stage1_1_fine_cat_pTjet30GeV);
   // fChain->SetBranchAddress("HTXS_stage1_2_cat_pTjet25GeV", &HTXS_stage1_2_cat_pTjet25GeV, &b_HTXS_stage1_2_cat_pTjet25GeV);
   // fChain->SetBranchAddress("HTXS_stage1_2_cat_pTjet30GeV", &HTXS_stage1_2_cat_pTjet30GeV, &b_HTXS_stage1_2_cat_pTjet30GeV);
   // fChain->SetBranchAddress("HTXS_stage1_2_fine_cat_pTjet25GeV", &HTXS_stage1_2_fine_cat_pTjet25GeV, &b_HTXS_stage1_2_fine_cat_pTjet25GeV);
   // fChain->SetBranchAddress("HTXS_stage1_2_fine_cat_pTjet30GeV", &HTXS_stage1_2_fine_cat_pTjet30GeV, &b_HTXS_stage1_2_fine_cat_pTjet30GeV);
   // fChain->SetBranchAddress("HTXS_stage_0", &HTXS_stage_0, &b_HTXS_stage_0);
   // fChain->SetBranchAddress("HTXS_stage_1_pTjet25", &HTXS_stage_1_pTjet25, &b_HTXS_stage_1_pTjet25);
   // fChain->SetBranchAddress("HTXS_stage_1_pTjet30", &HTXS_stage_1_pTjet30, &b_HTXS_stage_1_pTjet30);
   // fChain->SetBranchAddress("HTXS_njets25", &HTXS_njets25, &b_HTXS_njets25);
   // fChain->SetBranchAddress("HTXS_njets30", &HTXS_njets30, &b_HTXS_njets30);
   // fChain->SetBranchAddress("nGenJetAK8", &nGenJetAK8, &b_nGenJetAK8);
   // fChain->SetBranchAddress("GenJetAK8_eta", GenJetAK8_eta, &b_GenJetAK8_eta);
   // fChain->SetBranchAddress("GenJetAK8_mass", GenJetAK8_mass, &b_GenJetAK8_mass);
   // fChain->SetBranchAddress("GenJetAK8_phi", GenJetAK8_phi, &b_GenJetAK8_phi);
   // fChain->SetBranchAddress("GenJetAK8_pt", GenJetAK8_pt, &b_GenJetAK8_pt);

   fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   fChain->SetBranchAddress("GenJet_eta", GenJet_eta, &b_GenJet_eta);
   fChain->SetBranchAddress("GenJet_mass", GenJet_mass, &b_GenJet_mass);
   fChain->SetBranchAddress("GenJet_phi", GenJet_phi, &b_GenJet_phi);
   fChain->SetBranchAddress("GenJet_pt", GenJet_pt, &b_GenJet_pt);

   // fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   // fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   // fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   // fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   // fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   // fChain->SetBranchAddress("GenPart_genPartIdxMother", GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
   // fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   // fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   // fChain->SetBranchAddress("GenPart_statusFlags", GenPart_statusFlags, &b_GenPart_statusFlags);
   // fChain->SetBranchAddress("Generator_binvar", &Generator_binvar, &b_Generator_binvar);
   // fChain->SetBranchAddress("Generator_scalePDF", &Generator_scalePDF, &b_Generator_scalePDF);
   // fChain->SetBranchAddress("Generator_weight", &Generator_weight, &b_Generator_weight);
   // fChain->SetBranchAddress("Generator_x1", &Generator_x1, &b_Generator_x1);
   // fChain->SetBranchAddress("Generator_x2", &Generator_x2, &b_Generator_x2);
   // fChain->SetBranchAddress("Generator_xpdf1", &Generator_xpdf1, &b_Generator_xpdf1);
   // fChain->SetBranchAddress("Generator_xpdf2", &Generator_xpdf2, &b_Generator_xpdf2);
   // fChain->SetBranchAddress("Generator_id1", &Generator_id1, &b_Generator_id1);
   // fChain->SetBranchAddress("Generator_id2", &Generator_id2, &b_Generator_id2);
   // fChain->SetBranchAddress("GenVtx_x", &GenVtx_x, &b_GenVtx_x);
   // fChain->SetBranchAddress("GenVtx_y", &GenVtx_y, &b_GenVtx_y);
   // fChain->SetBranchAddress("GenVtx_z", &GenVtx_z, &b_GenVtx_z);
   // fChain->SetBranchAddress("nGenVisTau", &nGenVisTau, &b_nGenVisTau);
   // fChain->SetBranchAddress("GenVisTau_eta", GenVisTau_eta, &b_GenVisTau_eta);
   // fChain->SetBranchAddress("GenVisTau_mass", GenVisTau_mass, &b_GenVisTau_mass);
   // fChain->SetBranchAddress("GenVisTau_phi", GenVisTau_phi, &b_GenVisTau_phi);
   // fChain->SetBranchAddress("GenVisTau_pt", GenVisTau_pt, &b_GenVisTau_pt);
   // fChain->SetBranchAddress("GenVisTau_charge", GenVisTau_charge, &b_GenVisTau_charge);
   // fChain->SetBranchAddress("GenVisTau_genPartIdxMother", GenVisTau_genPartIdxMother, &b_GenVisTau_genPartIdxMother);
   // fChain->SetBranchAddress("GenVisTau_status", GenVisTau_status, &b_GenVisTau_status);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("LHEWeight_originalXWGTUP", &LHEWeight_originalXWGTUP, &b_LHEWeight_originalXWGTUP);
   // fChain->SetBranchAddress("nLHEPdfWeight", &nLHEPdfWeight, &b_nLHEPdfWeight);
   // fChain->SetBranchAddress("LHEPdfWeight", LHEPdfWeight, &b_LHEPdfWeight);
   // fChain->SetBranchAddress("nLHEReweightingWeight", &nLHEReweightingWeight, &b_nLHEReweightingWeight);
   // fChain->SetBranchAddress("LHEReweightingWeight", &LHEReweightingWeight, &b_LHEReweightingWeight);
   // fChain->SetBranchAddress("nLHEScaleWeight", &nLHEScaleWeight, &b_nLHEScaleWeight);
   // fChain->SetBranchAddress("LHEScaleWeight", LHEScaleWeight, &b_LHEScaleWeight);
   // fChain->SetBranchAddress("nPSWeight", &nPSWeight, &b_nPSWeight);
   // fChain->SetBranchAddress("PSWeight", PSWeight, &b_PSWeight);
   // fChain->SetBranchAddress("LHE_HT", &LHE_HT, &b_LHE_HT);
   // fChain->SetBranchAddress("LHE_HTIncoming", &LHE_HTIncoming, &b_LHE_HTIncoming);
   // fChain->SetBranchAddress("LHE_Vpt", &LHE_Vpt, &b_LHE_Vpt);
   // fChain->SetBranchAddress("LHE_AlphaS", &LHE_AlphaS, &b_LHE_AlphaS);
   // fChain->SetBranchAddress("LHE_Njets", &LHE_Njets, &b_LHE_Njets);
   // fChain->SetBranchAddress("LHE_Nb", &LHE_Nb, &b_LHE_Nb);
   // fChain->SetBranchAddress("LHE_Nc", &LHE_Nc, &b_LHE_Nc);
   // fChain->SetBranchAddress("LHE_Nuds", &LHE_Nuds, &b_LHE_Nuds);
   // fChain->SetBranchAddress("LHE_Nglu", &LHE_Nglu, &b_LHE_Nglu);
   // fChain->SetBranchAddress("LHE_NpNLO", &LHE_NpNLO, &b_LHE_NpNLO);
   // fChain->SetBranchAddress("LHE_NpLO", &LHE_NpLO, &b_LHE_NpLO);

   fChain->SetBranchAddress("nLHEPart", &nLHEPart, &b_nLHEPart);
   fChain->SetBranchAddress("LHEPart_pt", LHEPart_pt, &b_LHEPart_pt);
   fChain->SetBranchAddress("LHEPart_eta", LHEPart_eta, &b_LHEPart_eta);
   fChain->SetBranchAddress("LHEPart_phi", LHEPart_phi, &b_LHEPart_phi);
   fChain->SetBranchAddress("LHEPart_mass", LHEPart_mass, &b_LHEPart_mass);
   fChain->SetBranchAddress("LHEPart_incomingpz", LHEPart_incomingpz, &b_LHEPart_incomingpz);
   fChain->SetBranchAddress("LHEPart_pdgId", LHEPart_pdgId, &b_LHEPart_pdgId);
   fChain->SetBranchAddress("LHEPart_status", LHEPart_status, &b_LHEPart_status);
   fChain->SetBranchAddress("LHEPart_spin", LHEPart_spin, &b_LHEPart_spin);

   // fChain->SetBranchAddress("GenMET_phi", &GenMET_phi, &b_GenMET_phi);
   // fChain->SetBranchAddress("GenMET_pt", &GenMET_pt, &b_GenMET_pt);

   fChain->SetBranchAddress("nGenDressedLepton", &nGenDressedLepton, &b_nGenDressedLepton);
   fChain->SetBranchAddress("GenDressedLepton_eta", GenDressedLepton_eta, &b_GenDressedLepton_eta);
   fChain->SetBranchAddress("GenDressedLepton_mass", GenDressedLepton_mass, &b_GenDressedLepton_mass);
   fChain->SetBranchAddress("GenDressedLepton_phi", GenDressedLepton_phi, &b_GenDressedLepton_phi);
   fChain->SetBranchAddress("GenDressedLepton_pt", GenDressedLepton_pt, &b_GenDressedLepton_pt);
   fChain->SetBranchAddress("GenDressedLepton_pdgId", GenDressedLepton_pdgId, &b_GenDressedLepton_pdgId);
   fChain->SetBranchAddress("GenDressedLepton_hasTauAnc", GenDressedLepton_hasTauAnc, &b_GenDressedLepton_hasTauAnc);

   fChain->SetBranchAddress("MET_fiducialGenPhi", &MET_fiducialGenPhi);
   fChain->SetBranchAddress("MET_fiducialGenPt", &MET_fiducialGenPt);

   // fChain->SetBranchAddress("nGenIsolatedPhoton", &nGenIsolatedPhoton, &b_nGenIsolatedPhoton);
   // fChain->SetBranchAddress("GenIsolatedPhoton_eta", GenIsolatedPhoton_eta, &b_GenIsolatedPhoton_eta);
   // fChain->SetBranchAddress("GenIsolatedPhoton_mass", GenIsolatedPhoton_mass, &b_GenIsolatedPhoton_mass);
   // fChain->SetBranchAddress("GenIsolatedPhoton_phi", GenIsolatedPhoton_phi, &b_GenIsolatedPhoton_phi);
   // fChain->SetBranchAddress("GenIsolatedPhoton_pt", GenIsolatedPhoton_pt, &b_GenIsolatedPhoton_pt);
   // fChain->SetBranchAddress("GenJetAK8_partonFlavour", GenJetAK8_partonFlavour, &b_GenJetAK8_partonFlavour);
   // fChain->SetBranchAddress("GenJetAK8_hadronFlavour", GenJetAK8_hadronFlavour, &b_GenJetAK8_hadronFlavour);

   fChain->SetBranchAddress("GenJet_partonFlavour", GenJet_partonFlavour, &b_GenJet_partonFlavour);
   fChain->SetBranchAddress("GenJet_hadronFlavour", GenJet_hadronFlavour, &b_GenJet_hadronFlavour);
   
//   fChain->SetBranchAddress("GenVtx_t0", &GenVtx_t0, &b_GenVtx_t0);
   Notify();
}

Bool_t NanoGENanalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void NanoGENanalyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t NanoGENanalyzer::Cut(Long64_t entry)
{
entry = entry;
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef NanoGENanalyzer_cxx








/*___________________W reco___________________*/


double calculateLambda(TLorentzVector lepton, double met_pt, double met_phi)
{
   double met_px = met_pt*TMath::Cos(met_phi);
   double met_py = met_pt*TMath::Sin(met_phi);
   double mW = 80.385;

   return mW*mW/2 + met_px*lepton.Px()+met_py*lepton.Py();
}

double calculateDelta(TLorentzVector lepton, double met_pt, double met_phi)
{
   double lambda = calculateLambda(lepton, met_pt, met_phi);

   double delta = 4*lambda*lambda*lepton.Pz()*lepton.Pz() - 4*lepton.Pt()*lepton.Pt()*(lepton.E()*lepton.E()*met_pt*met_pt - lambda*lambda);

   return delta;
}

double calculate_p_nu_z_plus(TLorentzVector lepton, double met_pt, double met_phi)
{
   double lambda = calculateLambda(lepton, met_pt, met_phi);

   double a = lambda*lambda*lepton.Pz()*lepton.Pz()/pow(lepton.Pt(),4);
   double b = (lepton.E()*lepton.E()*met_pt*met_pt - lambda*lambda)/pow(lepton.Pt(),2);

   double p_nu_z_plus = (lambda*lepton.Pz())/pow(lepton.Pt(),2) + sqrt(a-b);
   return p_nu_z_plus;
}

double calculate_p_nu_z_minus(TLorentzVector lepton, double met_pt, double met_phi)
{
   double lambda = calculateLambda(lepton, met_pt, met_phi);

   double a = lambda*lambda*lepton.Pz()*lepton.Pz()/pow(lepton.Pt(),4);
   double b = (lepton.E()*lepton.E()*met_pt*met_pt - lambda*lambda)/pow(lepton.Pt(),2);

   double p_nu_z_minus = (lambda*lepton.Pz())/pow(lepton.Pt(),2) - sqrt(a-b);
   return p_nu_z_minus;
}


bool reconstructWrealSolution(TLorentzVector* Wboson, TLorentzVector* neutrino, TLorentzVector lepton, double met_pt, double met_phi)
{
   double met_px = met_pt*TMath::Cos(met_phi); 
   double met_py = met_pt*TMath::Sin(met_phi);

   double p_nu_z_plus = calculate_p_nu_z_plus(lepton, met_pt, met_phi);
   double p_nu_z_minus = calculate_p_nu_z_minus(lepton, met_pt, met_phi);

   double met_pz = std::abs(p_nu_z_plus) < std::abs(p_nu_z_minus) ? p_nu_z_plus : p_nu_z_minus;

   double neutrinoEnergy = TMath::Sqrt(met_px*met_px+met_py*met_py+met_pz*met_pz);

   neutrino->SetPxPyPzE(met_px, met_py, met_pz, neutrinoEnergy);

   *Wboson = *neutrino + lepton;

   return true;
}

bool reconstructWcomplexSolution(TLorentzVector* Wboson, TLorentzVector* neutrino, TLorentzVector lepton, double met_pt, double met_phi, bool* isNotANumber)
{
   *isNotANumber = false;
   double met_px; 
   double met_py;
   double mW = 80.385;

   double reco_nu_pt_up = sqrt(2)*abs(mW + lepton.Pt()/sqrt(2));
   double reco_nu_pt_down = sqrt(2)*abs(mW - lepton.Pt()/sqrt(2));

   double reco_nu_pt;
   double reco_nu_phi;

   if (reco_nu_pt_down < 0)
   {
      reco_nu_pt = reco_nu_pt_up;
   }
   else if (abs(met_pt - reco_nu_pt_down) < abs(met_pt - reco_nu_pt_up))
   {
      reco_nu_pt = reco_nu_pt_down;
   }
   else if (abs(met_pt - reco_nu_pt_down) > abs(met_pt - reco_nu_pt_up))
   {
      reco_nu_pt = reco_nu_pt_up;
   }

   double cosThetaLepNu = (mW*mW - reco_nu_pt*reco_nu_pt - lepton.Pt()*lepton.Pt())/(2*lepton.Pt()*reco_nu_pt);


   if (abs(cosThetaLepNu)>1 && abs(met_pt - reco_nu_pt_down) < abs(met_pt - reco_nu_pt_up) && reco_nu_pt_up > 0 )
   {
      reco_nu_pt = reco_nu_pt_up;
   }
   if (abs(cosThetaLepNu)>1 && abs(met_pt - reco_nu_pt_down) > abs(met_pt - reco_nu_pt_up) && reco_nu_pt_down > 0)
   {
      reco_nu_pt = reco_nu_pt_down;
   }

   cosThetaLepNu = (mW*mW - reco_nu_pt*reco_nu_pt - lepton.Pt()*lepton.Pt())/(2*lepton.Pt()*reco_nu_pt);

   if(cosThetaLepNu>=0) reco_nu_phi = lepton.Phi() + acos(cosThetaLepNu);
   if(cosThetaLepNu<0) reco_nu_phi = lepton.Phi() + (2*M_PI - acos(cosThetaLepNu));
   if (isnan(reco_nu_phi)) *isNotANumber = true;

   met_px = reco_nu_pt*TMath::Cos(reco_nu_phi); 
   met_py = reco_nu_pt*TMath::Sin(reco_nu_phi);

   double lambda = mW*mW/2 + reco_nu_pt*lepton.Pt()*cosThetaLepNu;

   double met_pz = lambda*lepton.Pz()/pow(lepton.Pt(),2);
   double neutrinoEnergy = TMath::Sqrt(reco_nu_pt*reco_nu_pt + met_pz*met_pz);


   neutrino->SetPxPyPzE(met_px, met_py, met_pz, neutrinoEnergy);

   *Wboson = *neutrino + lepton;

   return true;
}




bool reconstructW(TLorentzVector* Wboson, TLorentzVector* neutrino, TLorentzVector lepton, double met_pt, double met_phi, bool* isRealSolution, bool* isNaN)
{
   double delta = calculateDelta(lepton,met_pt,met_phi);

   if(delta>0)
   {
      reconstructWrealSolution(Wboson, neutrino, lepton, met_pt, met_phi);
      *isRealSolution = true;
   }

   if(delta<=0)
   {
      reconstructWcomplexSolution(Wboson, neutrino, lepton, met_pt, met_phi, isNaN);
      *isRealSolution = false;
   }
   return true;
}





/*_______________________STreco_____________________*/



double calc_p_nu_y_plus(double p_nu_x, double mw, TLorentzVector lepton){

    double a = mw*mw*lepton.Py() + 2*lepton.Px()*lepton.Py()*p_nu_x;
    double b = 2*lepton.Px()*lepton.Px();
    double c = mw*lepton.Pt();
    double d = mw*mw + 4*lepton.Px()*p_nu_x;
    return (a + c * TMath::Sqrt(d)) / b;
    }

double calc_p_nu_y_minus(double p_nu_x, double mw, TLorentzVector lepton){

    double a = mw*mw*lepton.Py() + 2*lepton.Px()*lepton.Py()*p_nu_x;
    double b = 2*lepton.Px()*lepton.Px();
    double c = mw*lepton.Pt();
    double d = mw*mw + 4*lepton.Px()*p_nu_x;
    return (a - c * TMath::Sqrt(d)) / b;
    }

double calc_rad(double p_nu_x, double p_nu_y, double mw, TLorentzVector lepton){
    double p_nu_T = TMath::Sqrt(p_nu_x*p_nu_x + p_nu_y*p_nu_y);
    TVector2 lep(lepton.Px(), lepton.Py());
    TVector2 neu(p_nu_x, p_nu_y);
    double cos_delta_phi = TMath::Cos(lep.DeltaPhi(neu));
    double mu = mw*mw/2 + lepton.Pt()*p_nu_T*cos_delta_phi; 

    double c = mu*mu*lepton.E()*lepton.E();
    double d = lepton.E()*lepton.E()*lepton.Pt()*lepton.Pt()*p_nu_T*p_nu_T;

    return c - d;
}


double calc_p_nu_z_plus(double p_nu_x, double p_nu_y, double mw, TLorentzVector lepton){

    double p_nu_T = TMath::Sqrt(p_nu_x*p_nu_x + p_nu_y*p_nu_y);
    TVector2 lep(lepton.Px(), lepton.Py());
    TVector2 neu(p_nu_x, p_nu_y);
    double cos_delta_phi = TMath::Cos(lep.DeltaPhi(neu));
    double mu = mw*mw/2 + lepton.Pt()*p_nu_T*cos_delta_phi; 

    double a = 1 / lepton.Pt() / lepton.Pt();
    double b = mu*lepton.Pz();

    double rad = calc_rad(p_nu_x, p_nu_y, mw, lepton);

    return a*(b + TMath::Sqrt(rad));
}

double calc_p_nu_z_minus(double p_nu_x, double p_nu_y, double mw, TLorentzVector lepton){

    double p_nu_T = TMath::Sqrt(p_nu_x*p_nu_x + p_nu_y*p_nu_y);
    TVector2 lep(lepton.Px(), lepton.Py());
    TVector2 neu(p_nu_x, p_nu_y);
    double cos_delta_phi = TMath::Cos(lep.DeltaPhi(neu));

    double mu = mw*mw/2 + lepton.Pt()*p_nu_T*cos_delta_phi; 

    double a = 1 / lepton.Pt() / lepton.Pt();
    double b = mu*lepton.Pz();

    double rad = calc_rad(p_nu_x, p_nu_y, mw, lepton);

    return a*(b - TMath::Sqrt(rad));
}

double calc_p_nu_z_compl(double p_nu_x, double p_nu_y, double mw, TLorentzVector lepton){

    double p_nu_T = TMath::Sqrt(p_nu_x*p_nu_x + p_nu_y*p_nu_y);
    TVector2 lep(lepton.Px(), lepton.Py());
    TVector2 neu(p_nu_x, p_nu_y);
    double cos_delta_phi = TMath::Cos(lep.DeltaPhi(neu));

    double mu = mw*mw/2 + lepton.Pt()*p_nu_T*cos_delta_phi; 

    double a = 1 / lepton.Pt() / lepton.Pt();
    double b = mu*lepton.Pz();

    return a*b;
}

double calc_delta_plus(double p_nu_x, double mw, TLorentzVector lepton, double met_px, double met_py){
    double p_nu_y = calc_p_nu_y_plus(p_nu_x, mw, lepton);
    double d_x = met_px - p_nu_x;
    double d_y = met_py - p_nu_y;
    return TMath::Sqrt(d_x*d_x + d_y*d_y);
}


double calc_delta_minus(double p_nu_x, double mw, TLorentzVector lepton, double met_px, double met_py){
    double p_nu_y = calc_p_nu_y_minus(p_nu_x, mw, lepton);
    double d_x = met_px - p_nu_x;
    double d_y = met_py - p_nu_y;
    return TMath::Sqrt(d_x*d_x + d_y*d_y);
}

bool ReconstructWRealSolution(TLorentzVector* p4W, TLorentzVector* p4nu, TLorentzVector lepton, double met_pt, double met_phi, TLorentzVector* p4nu_plus, TLorentzVector* p4nu_minus) {

        double met_px = met_pt*TMath::Cos(met_phi);
        double met_py = met_pt*TMath::Sin(met_phi);
        double mw = 80.385;

        double p_nu_z_plus = calc_p_nu_z_plus(met_px, met_py, mw, lepton);
        double p_nu_z_minus = calc_p_nu_z_minus(met_px, met_py, mw, lepton);

        double pz_min = std::abs(p_nu_z_plus) < std::abs(p_nu_z_minus) ? p_nu_z_plus : p_nu_z_minus;
        
        double pz = pz_min;

        p4nu->SetPxPyPzE(met_px, met_py, pz, TMath::Sqrt(met_px*met_px+met_py*met_py+pz*pz));
        *p4W = *p4nu + lepton;

        p4nu_plus->SetPxPyPzE(met_px, met_py, p_nu_z_plus, TMath::Sqrt(met_px*met_px+met_py*met_py+p_nu_z_plus*p_nu_z_plus));
        p4nu_minus->SetPxPyPzE(met_px, met_py, p_nu_z_minus, TMath::Sqrt(met_px*met_px+met_py*met_py+p_nu_z_minus*p_nu_z_minus));
        
        return true;
}


bool ReconstructWComplexSolution(TLorentzVector* p4W, TLorentzVector* p4nu, TLorentzVector lepton, double met_pt, double met_phi) {

        double met_px = met_pt*TMath::Cos(met_phi);
        double met_py = met_pt*TMath::Sin(met_phi);
        double mw = 80.385;

        std::string minName = "Minuit2";
        std::string algoName = "Scan";

        ROOT::Math::Minimizer* min_plus = 
            ROOT::Math::Factory::CreateMinimizer(minName, algoName);

        ROOT::Math::Minimizer* min_minus = 
             ROOT::Math::Factory::CreateMinimizer(minName, algoName);

        min_plus->SetMaxFunctionCalls(10000000);
        min_plus->SetTolerance(0.01);
        min_plus->SetPrintLevel(-2);

        min_minus->SetMaxFunctionCalls(10000000);
        min_minus->SetTolerance(0.01);
        min_minus->SetPrintLevel(-2);

        auto f_plus = [lepton, mw, met_px, met_py](const double *x){ 
                return calc_delta_plus(x[0], mw, lepton, met_px, met_py);
        };

        auto f_minus = [lepton, mw, met_px, met_py](const double *x){ 
                return calc_delta_minus(x[0], mw, lepton, met_px, met_py);
        };

        double step[1] = {0.01};
        if(lepton.Px() > 0){
            double lower = -mw*mw /4 / lepton.Px() + 0.1;
            // lower = std::max((double) (met_px - 50.), lower);
            double upper = 2*std::abs(met_px);
            // double upper = std::max((double) 3000., 2*std::abs(met_px));
            min_plus->SetLimitedVariable(0, "px", met_px, step[0], lower, upper);
            min_minus->SetLimitedVariable(0, "px", met_px, step[0], lower, upper);
        }
        else if (lepton.Px() < 0){
            double upper = -mw*mw /4 / lepton.Px() - 0.1;
            // upper = std::min((double) (met_px + 50.), upper);
            double lower = -2*std::abs(met_px);
            // double lower = std::min((double) -3000., -2*std::abs(met_px));
            min_plus->SetLimitedVariable(0, "px", met_px, step[0], lower, upper);
            min_minus->SetLimitedVariable(0, "px", met_px, step[0], lower, upper);
        }
        else{
            double lower = met_px - 50.;
            double upper = met_px + 50.;
            min_plus->SetLimitedVariable(0, "px", met_px, step[0], lower, upper);
            min_minus->SetLimitedVariable(0, "px", met_px, step[0], lower, upper);
        }


        ROOT::Math::Functor functor_plus(f_plus, 1);
        ROOT::Math::Functor functor_min(f_minus, 1);

        min_plus->SetFunction(functor_min);
        min_minus->SetFunction(functor_plus);


        bool status_plus = min_plus->Minimize(); 
        bool status_minus = min_minus->Minimize(); 

        double px_plus = min_plus->X()[0];
        double px_minus = min_minus->X()[0];

        double min_delta_plus = calc_delta_plus(px_plus, mw, lepton, met_px, met_py);
        double min_delta_minus = calc_delta_minus(px_minus, mw, lepton, met_px, met_py);

        double px = 0;
        double py = 0;
        double py_plus = calc_p_nu_y_plus(px_plus, mw, lepton);
        double py_minus = calc_p_nu_y_minus(px_minus, mw, lepton);
        
        if(min_delta_plus < min_delta_minus){
            px = px_plus;
            py = py_plus;
        }
        else{
            px = px_minus;
            py = py_minus;
        }

        double pz = calc_p_nu_z_compl(px, py, mw, lepton);

        if(!status_plus || !status_minus)
            std::cout << "Minimization did not converge: " << px << " " << py << " " << met_px << " " << met_py << std::endl;

        p4nu->SetPxPyPzE(px, py, pz, TMath::Sqrt(px*px+py*py+pz*pz));
        *p4W = *p4nu + lepton;

        // p4W->SetPtEtaPhiM(p4W->Pt(), p4W->Eta(), p4W->Phi(), 80.385);

        if(std::abs(p4W->M() - 80.385) > 5){
            std::cout << std::endl << "WARNING! W boson mass doesn't match with closest solution. "  << p4W->M() << " " << px_plus << " " << py_plus << " " << px_minus << " " << py_minus << " " << pz << std::endl;
            std::cout << p4W->Pt() << " " << p4W->Eta() << " " << p4W->Phi() << " " << p4W->E() << std::endl;
            std::cout << p4nu->Pt() << " " << p4nu->Eta() << " " << p4nu->Phi() << " " << p4nu->E() << std::endl;
            std::cout << lepton.Pt() << " " << lepton.Eta() << " " << lepton.Phi() << " " << lepton.E() << std::endl;
            if((std::abs(px_plus - px_minus) < 1 && (px_plus > 10000) && (met_px > 30000 || met_py > 30000))||(p4W->Pt() > 600000.) ){ 

                float npt = std::min(1000., p4W->Pt()/1000.);
            
                p4W->SetPtEtaPhiM(npt, p4W->Eta(), p4W->Phi(), 80.385);
                *p4nu = *p4W - lepton;
            }
        }

        return true;
}


bool ReconstructW_Streco(TLorentzVector* p4W, TLorentzVector* p4nu, TLorentzVector lepton, double met_pt, double met_phi, bool* is_real_solution, TLorentzVector* p4nu_plus, TLorentzVector* p4nu_minus){
    double met_px = met_pt*TMath::Cos(met_phi);
    double met_py = met_pt*TMath::Sin(met_phi);
    double mw = 80.385;

    double rad = calc_rad(met_px, met_py, mw, lepton);

    if(rad >= 0){
        ReconstructWRealSolution(p4W, p4nu, lepton, met_pt, met_phi, p4nu_plus, p4nu_minus);
        *is_real_solution = true;
    }
    else{
        ReconstructWComplexSolution(p4W, p4nu, lepton, met_pt, met_phi);
        *p4nu_plus = *p4nu;
        *p4nu_minus = *p4nu;
        *is_real_solution = false;
    }
   //  if(std::abs(p4W->M() - 80.385) > 5){
   //      std::cout << p4W->M() << std::endl;
   //      p4W->Print();
   //      std::cout << *is_real_solution << std::endl;
   //      std::cout << p4W->Mt() << std::endl;
   //      throw std::runtime_error("w mass wrong!");
   //      }
    return true;
}





/*_____________________Angles reco______________________*/

double calculate_sinTheta(TLorentzVector Wboson, TLorentzVector top, TLorentzVector qSpec)
{

    double sinTheta;

   TVector3 InvariantTopBoost;
   InvariantTopBoost.SetXYZ(-top.Px()/top.E(),-top.Py()/top.E(),-top.Pz()/top.E());
   
   TVector3 InvariantWBoost;
   InvariantWBoost.SetXYZ(-Wboson.Px()/Wboson.E(),-Wboson.Py()/Wboson.E(),-Wboson.Pz()/Wboson.E());

   Wboson.Boost(InvariantTopBoost);
   qSpec.Boost(InvariantTopBoost);

   TVector3 Zdir = Wboson.Vect().Unit();
   TVector3 qSpecUnit = qSpec.Vect().Unit();
   TVector3 Ydir = qSpecUnit.Cross(Zdir).Unit();
   TVector3 Xdir = Ydir.Cross(Zdir);

   sinTheta = qSpecUnit.Cross(Zdir).Mag();
   if(sinTheta<0) sinTheta=-sinTheta;

   return sinTheta;
}


double calculate_cosTheta(TLorentzVector Wboson, TLorentzVector top, TLorentzVector qSpec)
{

    double cosTheta;

   TVector3 InvariantTopBoost;
   InvariantTopBoost.SetXYZ(-top.Px()/top.E(),-top.Py()/top.E(),-top.Pz()/top.E());
   
   TVector3 InvariantWBoost;
   InvariantWBoost.SetXYZ(-Wboson.Px()/Wboson.E(),-Wboson.Py()/Wboson.E(),-Wboson.Pz()/Wboson.E());

   Wboson.Boost(InvariantTopBoost);
   qSpec.Boost(InvariantTopBoost);

   TVector3 Zdir = Wboson.Vect().Unit();
   TVector3 qSpecUnit = qSpec.Vect().Unit();

   cosTheta = qSpecUnit.Dot(Zdir);
   
   return cosTheta;
}

double calculate_sinThetaStar(TLorentzVector lepton, TLorentzVector Wboson)
{
   double sinThetaStar;

   TVector3 Zdir = Wboson.Vect().Unit();
   TVector3 leptonUnitary = lepton.Vect().Unit();

   sinThetaStar = leptonUnitary.Cross(Zdir).Mag();
   if(sinThetaStar<0) sinThetaStar=-sinThetaStar;

   return sinThetaStar;
}

double calculate_cosThetaStar(TLorentzVector lepton, TLorentzVector Wboson)
{
   double cosThetaStar;

   TVector3 Zdir = Wboson.Vect().Unit();
   TVector3 leptonUnitary = lepton.Vect().Unit();

   cosThetaStar = leptonUnitary.Dot(Zdir);

   return cosThetaStar;
}

double calculate_sinPhiStar(TLorentzVector lepton, TLorentzVector Wboson, TLorentzVector qSpec)
{
   double sinPhiStar;

   TVector3 Zdir = Wboson.Vect().Unit();
   TVector3 qSpecUnit = qSpec.Vect().Unit();
   TVector3 Ydir = qSpecUnit.Cross(Zdir).Unit();
   TVector3 leptonUnitary = lepton.Vect().Unit();
   TVector3 leptonUnitary_PlaneXY = (leptonUnitary - (leptonUnitary.Dot(Zdir))*Zdir).Unit();    

   
   sinPhiStar = leptonUnitary_PlaneXY.Dot(Ydir);
   
   return sinPhiStar;
}

double calculate_cosPhiStar(TLorentzVector lepton, TLorentzVector Wboson, TLorentzVector qSpec)
{
   double cosPhiStar;

   TVector3 Zdir = Wboson.Vect().Unit();
   TVector3 qSpecUnit = qSpec.Vect().Unit();
   TVector3 Ydir = qSpecUnit.Cross(Zdir).Unit();
   TVector3 Xdir = Ydir.Cross(Zdir);
   TVector3 leptonUnitary = lepton.Vect().Unit();
   TVector3 leptonUnitary_PlaneXY = (leptonUnitary - (leptonUnitary.Dot(Zdir))*Zdir).Unit();    

   
   cosPhiStar = leptonUnitary_PlaneXY.Dot(Xdir);
   
   return cosPhiStar;
}

double calculate_PhiStar(TLorentzVector lepton, TLorentzVector Wboson, TLorentzVector qSpec)
{
   double cosPhiStar;
   double sinPhiStar;
   double PhiStar;

   cosPhiStar = calculate_cosPhiStar(lepton, Wboson, qSpec);
   sinPhiStar =  calculate_sinPhiStar(lepton, Wboson, qSpec);

   if (sinPhiStar>0) PhiStar = TMath::ACos(cosPhiStar);
   if (sinPhiStar<0) PhiStar = 2*TMath::Pi()-TMath::ACos(cosPhiStar);

   return PhiStar;
}