#define NanoGENanalyzer_cxx
#include "NanoGENanalyzer.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <TTree.h>
#include <TObject.h>

#include <iostream>

using namespace std;

void NanoGENanalyzer::Loop()
{
//   In a ROOT session, you can do:
//      root> .L NanoGENanalyzer.C
//      root> NanoGENanalyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: reLHE_leptonace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   double sumOf_genWeights_beforeAnalysis = 0.0;
   double sumOf_LHEweights_beforeAnalysis = 0.0;


   // TFile* fOutput = new TFile("output/cutOnDeltaR0p4/GENlevel/output_MG5sample_ST_t_channel_top_and_antitop_SM_atLO_LHE_NanoGEN_sm-no_b_mass_model.root","RECREATE");
   // const float xSec = 35.8253;
   // sumOf_genWeights_beforeAnalysis = 1.94133e+08 ;

   TFile* fOutput = new TFile("test.root","RECREATE");
   const float xSec = 35.4209;
   // sumOf_genWeights_beforeAnalysis = 1.75335e+08;

   // TFile* fOutput = new TFile("output/cutOnDeltaR0p4/GENlevel/output_POWHEGsample_ST_t_channel_top_SM_atNLO_LHE_NanoGEN.root","RECREATE");
   // const float xSec = 136.02;
   // sumOf_genWeights_beforeAnalysis = 1.3808e+10;

   // TFile* fOutput = new TFile("output/cutOnDeltaR0p4/GENlevel/output_POWHEGsample_ST_t_channel_antitop_SM_atNLO_LHE_NanoGEN.root","RECREATE");
   // const float xSec = 80.95;
   // sumOf_genWeights_beforeAnalysis = 4.46287e+09;


   // TFile* fOutput = new TFile("test.root","RECREATE");


   TTree* LHEoutput = new TTree("LHE","LHE",0);
   TTree* GENoutput = new TTree("GENoutput","GENoutput",0);
   TTree* GENoutput_Real = new TTree("GENoutput_Real","GENoutput_Real",0);
   TTree* GENoutput_ComLHE_leptonex = new TTree("GENoutput_ComLHE_leptonex","GENoutput_ComLHE_leptonex",0);
   TTree* SumOfWeights = new TTree("SumOfWeights","SumOfWeights",0);
   TTree* Weights = new TTree("Weights","Weights",0);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   /*------------------- LHE Variables-------------------*/

   float deltaR_lepton_bQuark_LHElevel;
   float deltaR_lepton_specQ_LHElevel;
   float deltaR_lepton_bQuark_boosted_LHElevel;
   float deltaR_lepton_specQ_boosted_LHElevel;
   float nature_lepton_LHE;

   LHEoutput->Branch("deltaR_lepton_bQuark_LHElevel", &deltaR_lepton_bQuark_LHElevel, "deltaR_lepton_bQuark_LHElevel/F");
   LHEoutput->Branch("deltaR_lepton_specQ_LHElevel", &deltaR_lepton_specQ_LHElevel, "deltaR_lepton_specQ_LHElevel/F");
   LHEoutput->Branch("deltaR_lepton_bQuark_boosted_LHElevel", &deltaR_lepton_bQuark_LHElevel, "deltaR_lepton_bQuark_LHElevel/F");
   LHEoutput->Branch("deltaR_lepton_specQ_boosted_LHElevel", &deltaR_lepton_specQ_LHElevel, "deltaR_lepton_specQ_LHElevel/F");
   LHEoutput->Branch("nature_lepton_LHE",&nature_lepton_LHE,"nature_lepton_LHE/F");

   /*------------------- Generator Variables-------------------*/

   int SolutionNature;

   float sinTheta, cosThetaX;
   float sinThetaStar, cosThetaXStar, cosThetaYStar, cosThetaZStar;
   float sinPhiStar, cosPhiStar, PhiStar;
   float lepton_E_Wframe;
   float top_pt, W_pt, lepton_pt, neutrino_pt, specJet_pt, bJet_pt;
   float top_mass, W_mass, W_transverse_mass;
   float top_eta, neutrino_eta, lepton_eta, W_eta, specJet_eta, bJet_eta;
   float top_phi, neutrino_phi, lepton_phi, W_phi, specJet_phi, bJet_phi;
   float nature_lepton;

   /*________Variables to separate C and R solutions of W boson reconstruction________*/

   float sinTheta_Real, cosThetaX_Real;
   float sinThetaStar_Real, cosThetaXStar_Real, cosThetaYStar_Real, cosThetaZStar_Real;
   float sinPhiStar_Real, cosPhiStar_Real, PhiStar_Real;
   float lepton_E_Wframe_Real;
   float top_pt_Real, W_pt_Real, lepton_pt_Real, neutrino_pt_Real; 
   float top_eta_Real, neutrino_eta_Real;
   float top_phi_Real, neutrino_phi_Real;
   float top_mass_Real, W_mass_Real, W_transverse_mass_Real;

   float sinTheta_ComLHE_leptonex, cosTheta_ComLHE_leptonex;
   float sinThetaStar_ComLHE_leptonex, cosThetaStar_ComLHE_leptonex;
   float sinPhiStar_ComLHE_leptonex, cosPhiStar_ComLHE_leptonex, PhiStar_ComLHE_leptonex;
   float lepton_E_Wframe_ComLHE_leptonex;
   float top_pt_ComLHE_leptonex, W_pt_ComLHE_leptonex, lepton_pt_ComLHE_leptonex, neutrino_pt_ComLHE_leptonex;
   float top_eta_ComLHE_leptonex, neutrino_eta_ComLHE_leptonex;
   float top_phi_ComLHE_leptonex, neutrino_phi_ComLHE_leptonex;
   float top_mass_ComLHE_leptonex, W_mass_ComLHE_leptonex, W_transverse_mass_ComLHE_leptonex;



   int nbOfRealSolutions = 0;
   int nbOfComLHE_leptonexSolutions = 0;

   int nbOfRealSolutions_Streco = 0;
   int nbOfComLHE_leptonexSolutions_Streco = 0;


   double met_pt;
   double met_phi;

   float deltaR_lepton_bQuark_GENlevel;
   float deltaR_lepton_specQ_GENlevel;

   GENoutput->Branch("deltaR_lepton_bQuark_GENlevel",&deltaR_lepton_bQuark_GENlevel,"deltaR_lepton_bQuark_GENlevel/F");
   GENoutput->Branch("deltaR_lepton_specQ_GENlevel",&deltaR_lepton_specQ_GENlevel,"deltaR_lepton_specQ_GENlevel/F");

   GENoutput->Branch("SolutionNature",&SolutionNature,"SolutionNature/I");

   // Real + ComLHE_leptonex Solutions
   GENoutput->Branch("nature_lepton",&nature_lepton,"nature_lepton/F");
   GENoutput->Branch("cosTheta",&cosTheta,"cosTheta/F");
   GENoutput->Branch("sinTheta",&sinTheta,"sinTheta/F");
   GENoutput->Branch("cosThetaStar",&cosThetaStar,"cosThetaStar/F");
   GENoutput->Branch("sinThetaStar",&sinThetaStar,"sinThetaStar/F");
   GENoutput->Branch("cosPhiStar",&cosPhiStar,"cosPhiStar/F");
   GENoutput->Branch("sinPhiStar",&sinPhiStar,"sinPhiStar/F");
   GENoutput->Branch("PhiStar",&PhiStar,"PhiStar/F");

   GENoutput->Branch("lepton_E_Wframe",&lepton_E_Wframe,"lepton_E_Wframe/F");
   GENoutput->Branch("lepton_pt",&lepton_pt,"lepton_pt/F");
   GENoutput->Branch("lepton_eta",&lepton_eta,"lepton_eta/F");
   GENoutput->Branch("lepton_phi",&lepton_phi,"lepton_phi/F");



   GENoutput->Branch("top_pt",&top_pt,"top_pt/F");
   GENoutput->Branch("top_eta",&top_eta,"top_eta/F");
   GENoutput->Branch("top_phi",&top_phi,"top_phi/F");
   GENoutput->Branch("top_mass", &top_mass, "top_mass/F");

   GENoutput->Branch("specJet_pt",&specJet_pt,"specJet_pt/F");
   GENoutput->Branch("specJet_eta",&specJet_eta,"specJet_eta/F");
   GENoutput->Branch("specJet_phi",&specJet_phi,"specJet_phi/F");

   GENoutput->Branch("bJet_pt",&bJet_pt,"bJet_pt/F");
   GENoutput->Branch("bJet_eta",&bJet_eta,"bJet_eta/F");
   GENoutput->Branch("bJet_phi",&bJet_phi,"bJet_phi/F");


  
   GENoutput->Branch("neutrino_pt",&neutrino_pt,"neutrino_pt/F");
   GENoutput->Branch("neutrino_eta",&neutrino_eta,"neutrino_eta/F");
   GENoutput->Branch("neutrino_phi",&neutrino_phi,"neutrino_phi/F");

   GENoutput->Branch("W_pt",&W_pt,"W_pt/F");
   GENoutput->Branch("W_eta",&W_eta,"W_eta/F");
   GENoutput->Branch("W_phi",&W_phi,"W_phi/F");
   GENoutput->Branch("W_mass", &W_mass, "W_mass/F");
   GENoutput->Branch("W_transverse_mass", &W_transverse_mass, "W_transverse_mass/F");



   GENoutput_Real->Branch("cosTheta_Real",&cosTheta_Real,"cosTheta_Real/F");
   GENoutput_Real->Branch("sinTheta_Real",&sinTheta_Real,"sinTheta_Real/F");
   GENoutput_Real->Branch("cosThetaStar_Real",&cosThetaStar_Real,"cosThetaStar_Real/F");
   GENoutput_Real->Branch("sinThetaStar_Real",&sinThetaStar_Real,"sinThetaStar_Real/F");
   GENoutput_Real->Branch("cosPhiStar_Real",&cosPhiStar_Real,"cosPhiStar_Real/F");
   GENoutput_Real->Branch("sinPhiStar_Real",&sinPhiStar_Real,"sinPhiStar_Real/F");
   GENoutput_Real->Branch("PhiStar_Real",&PhiStar_Real,"PhiStar_Real/F");
   GENoutput_Real->Branch("lepton_E_Wframe_Real",&lepton_E_Wframe_Real,"lepton_E_Wframe_Real/F");
   GENoutput_Real->Branch("top_pt_Real",&top_pt_Real,"top_pt_Real/F");
   GENoutput_Real->Branch("top_eta_Real",&top_eta_Real,"top_eta_Real/F");
   GENoutput_Real->Branch("top_phi_Real",&top_phi_Real,"top_phi_Real/F");
   GENoutput_Real->Branch("top_mass_Real", &top_mass_Real, "top_mass_Real/F");
   GENoutput_Real->Branch("W_pt_Real",&W_pt_Real,"W_pt_Real/F");
   GENoutput_Real->Branch("lepton_pt_Real",&lepton_pt_Real,"lepton_pt_Real/F");
   GENoutput_Real->Branch("neutrino_pt_Real",&neutrino_pt_Real,"neutrino_pt_Real/F");
   GENoutput_Real->Branch("neutrino_eta_Real",&neutrino_eta_Real,"neutrino_eta_Real/F");
   GENoutput_Real->Branch("neutrino_phi_Real",&neutrino_phi_Real,"neutrino_phi_Real/F");
   GENoutput_Real->Branch("W_mass_Real", &W_mass_Real, "W_mass_Real/F");
   GENoutput_Real->Branch("W_transverse_mass_Real", &W_transverse_mass_Real, "W_transverse_mass_Real/F");

   GENoutput_ComLHE_leptonex->Branch("cosTheta_ComLHE_leptonex",&cosTheta_ComLHE_leptonex,"cosTheta_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("sinTheta_ComLHE_leptonex",&sinTheta_ComLHE_leptonex,"sinTheta_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("cosThetaStar_ComLHE_leptonex",&cosThetaStar_ComLHE_leptonex,"cosThetaStar_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("sinThetaStar_ComLHE_leptonex",&sinThetaStar_ComLHE_leptonex,"sinThetaStar_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("cosPhiStar_ComLHE_leptonex",&cosPhiStar_ComLHE_leptonex,"cosPhiStar_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("sinPhiStar_ComLHE_leptonex",&sinPhiStar_ComLHE_leptonex,"sinPTreehiStar_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("PhiStar_ComLHE_leptonex",&PhiStar_ComLHE_leptonex,"PhiStar_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("lepton_E_Wframe_ComLHE_leptonex",&lepton_E_Wframe_ComLHE_leptonex,"lepton_E_Wframe_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("top_pt_ComLHE_leptonex",&top_pt_ComLHE_leptonex,"top_pt_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("top_eta_ComLHE_leptonex",&top_eta_ComLHE_leptonex,"top_eta_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("top_phi_ComLHE_leptonex",&top_phi_ComLHE_leptonex,"top_phi_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("top_mass_ComLHE_leptonex", &top_mass_ComLHE_leptonex, "top_mass_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("W_pt_ComLHE_leptonex",&W_pt_ComLHE_leptonex,"W_pt_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("lepton_pt_ComLHE_leptonex",&lepton_pt_ComLHE_leptonex,"lepton_pt_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("neutrino_pt_ComLHE_leptonex",&neutrino_pt_ComLHE_leptonex,"neutrino_pt_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("neutrino_eta_ComLHE_leptonex",&neutrino_eta_ComLHE_leptonex,"neutrino_eta_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("neutrino_phi_ComLHE_leptonex",&neutrino_phi_ComLHE_leptonex,"neutrino_phi_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("W_mass_ComLHE_leptonex", &W_mass_ComLHE_leptonex, "W_mass_ComLHE_leptonex/F");
   GENoutput_ComLHE_leptonex->Branch("W_transverse_mass_ComLHE_leptonex", &W_transverse_mass_ComLHE_leptonex, "W_transverse_mass_ComLHE_leptonex/F");

   /*-------------------- Sum Of Weights computation-------------------- */

   // double sumOf_LHEweights = 0.0;
   double sumOf_genWeights = 0.0;
   double sumOf_LHEweights = 0.0;

   double GENweight;
   double LHEweight;
   int numberOfEvents = 0;

   GENoutput->Branch("sumOf_genWeights",&sumOf_genWeights,"sumOf_genWeights/D");
   GENoutput->Branch("sumOf_LHEweights",&sumOf_LHEweights,"sumOf_LHEweights/D");
   LHEoutput->Branch("GENweight", &GENweight, "GENweight/D");
   LHEoutput->Branch("LHEweight", &LHEweight, "LHEweight/D");
   GENoutput->Branch("GENweight", &GENweight, "GENweight/D");
   GENoutput->Branch("LHEweight", &LHEweight, "LHEweight/D");

   if(sumOf_genWeights_beforeAnalysis == 0.0)
   {

      for (Long64_t jentry=0; jentry<nentries;jentry++)
      {
         Long64_t ientry = LoadTree(jentry);
         if (ientry < 0) break;
         nb = fChain->GetEntry(jentry);   nbytes += nb;
         // std::cout << "nb = " << nb << std::endl;
         // if (Cut(ientry) < 0) continue;

         if(jentry%1000000==0) std::cout<<"weights loop "<<jentry<<std::endl;
         // if(jentry==1000000) break;

         sumOf_genWeights_beforeAnalysis += genWeight;
         sumOf_LHEweights_beforeAnalysis += LHEWeight_originalXWGTUP;
   
      }

   }

   std::cout << "sumOf_genWeights_beforeAnalysis = " << sumOf_genWeights_beforeAnalysis << std::endl;

   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // std::cout << "nb = " << nb << std::endl;
      // if (Cut(ientry) < 0) continue;

      if(jentry%1000000==0) std::cout<<"Analysis loop "<<jentry<<std::endl;
      // if(jentry==1000000) break;

      sumOf_genWeights += genWeight;
      sumOf_LHEweights += LHEWeight_originalXWGTUP;

      met_pt = MET_fiducialGenPt;
      met_phi = MET_fiducialGenPhi;

      // std::cout<<"met_pt = "<<met_pt<<std::endl;
      // std::cout<<"met_phi = "<<met_phi<<std::endl;

      /*----- GEN-LEVEL SELECTION -----*/

      unsigned int nSelectedGenDressedLepton = 0;
      TLorentzVector SelectedGenDressedLepton_sublead(0,0,0,0);
      unsigned int nSelectedGenJet = 0;
      std::vector<TLorentzVector> SelectedJet;
      std::vector<int> SelectedJet_hadronFlavour;
      int nbOfBjets = 0;
      int nbOfNonBjets = 0;
      double maxEtaNonBjet = 0.0;
      bool atLeastOneBjet = false;
      
      TLorentzVector SelectedGenDressedLepton_lead(0,0,0,0);
      TLorentzVector qSpec(0,0,0,0);
      TLorentzVector bJet(0,0,0,0);
      // Reco objects
      TLorentzVector Wboson(0,0,0,0);
      TLorentzVector neutrino(0,0,0,0);
      TLorentzVector top(0,0,0,0);


      TLorentzVector Wboson_Streco(0,0,0,0);
      TLorentzVector neutrino_Streco(0,0,0,0), neutrino_pz_LHE_leptonus_Streco(0,0,0,0), neutrino_pz_minus_Streco(0,0,0,0);
      TLorentzVector top_Streco(0,0,0,0);


      Bool_t isRealSolution;
      Bool_t isRealSolution_Streco;
      Bool_t isNotAValidReco;

      TLorentzVector p4nu_LHE_leptonus(0,0,0,0), p4nu_minus(0,0,0,0);


      for (unsigned int i=0; i<nGenDressedLepton; i++)
      {  
         // if(i==0) std::cout<<"Before selection on leptons"<<std::endl;
         // std::cout<<"lepton pt = "<<GenDressedLepton_pt[i]<<std::endl;
         
         if((GenDressedLepton_pt[i]<32 || fabs(GenDressedLepton_eta[i])>2.1)  && fabs(GenDressedLepton_pdgId[i])==11) continue;
         if((GenDressedLepton_pt[i]<30 || fabs(GenDressedLepton_eta[i])>2.4) && fabs(GenDressedLepton_pdgId[i])==13) continue;

         if (GenDressedLepton_pt[i] > SelectedGenDressedLepton_lead.Pt()) 
         SelectedGenDressedLepton_lead.SetPtEtaPhiM(GenDressedLepton_pt[i], GenDressedLepton_eta[i], GenDressedLepton_phi[i], GenDressedLepton_mass[i]); 
         else if (GenDressedLepton_pt[i] > SelectedGenDressedLepton_sublead.Pt())
         SelectedGenDressedLepton_sublead.SetPtEtaPhiM(GenDressedLepton_pt[i], GenDressedLepton_eta[i], GenDressedLepton_phi[i], GenDressedLepton_mass[i]);

         nSelectedGenDressedLepton++;
	
      }

      // std::cout << "nSelectedGenDressedLepton="<<nSelectedGenDressedLepton<<endl;
      // std::cout << "SelectedGenDressedLepton_lead pt="<<SelectedGenDressedLepton_lead.Pt()<<" eta="<<SelectedGenDressedLepton_lead.Eta()<<endl;
      // std::cout << "SelectedGenDressedLepton_sublead pt="<<SelectedGenDressedLepton_sublead.Pt()<<" eta="<<SelectedGenDressedLepton_sublead.Eta()<<endl;


      for (unsigned int i=0; i<nGenJet; i++)
      {
	      // std::cout << "Jet "<<i<<" pt="<<GenJet_pt[i]<<" eta="<<GenJet_eta[i]<<" hadronFlavour="<< (int)GenJet_hadronFlavour[i] <<endl;
	      if(GenJet_pt[i]<40 || fabs(GenJet_eta[i])>4.7) continue;
         if(fabs(GenJet_eta[i])>=2.4 && GenJet_pt[i]<60) continue;

	      TLorentzVector jet;
	      jet.SetPtEtaPhiM(GenJet_pt[i], GenJet_eta[i], GenJet_phi[i], GenJet_mass[i]);

	      bool keepJet = true;
	      for (unsigned int j=0; j<nGenDressedLepton; j++)
         {
            if((GenDressedLepton_pt[j]<32 || fabs(GenDressedLepton_eta[j])>2.1) && fabs(GenDressedLepton_pdgId[j])==11) continue;
            if((GenDressedLepton_pt[j]<30 || fabs(GenDressedLepton_eta[j])>2.4) && fabs(GenDressedLepton_pdgId[j])==13) continue;
	         TLorentzVector lepton;
	         lepton.SetPtEtaPhiM(GenDressedLepton_pt[j], GenDressedLepton_eta[j], GenDressedLepton_phi[j], GenDressedLepton_mass[j]);
	         if(jet.DeltaR(lepton)<0.4) keepJet = false;
	      }
         if(keepJet) 
         {
            SelectedJet.push_back(jet);
            SelectedJet_hadronFlavour.push_back(GenJet_hadronFlavour[i]);
            nSelectedGenJet++;
         }
      }

      // std::cout << "nGenJet="<< nGenJet<<" nSelectedGenJet="<<nSelectedGenJet<<endl;
      for (unsigned int i=0; i<nSelectedGenJet; i++) 
      {
         // std::cout << "SelectedJet pt="<<SelectedJet[i].Pt()<<" eta="<<SelectedJet[i].Eta()<<" hadronFlavour="<<SelectedJet_hadronFlavour[i]<<endl; 
	      if(SelectedJet_hadronFlavour[i]==5)
         { 
            atLeastOneBjet = true;
            nbOfBjets += 1;
            bJet.SetPtEtaPhiM(SelectedJet[i].Pt(),SelectedJet[i].Eta(),SelectedJet[i].Phi(),SelectedJet[i].M());
         }
         else
         {
            nbOfNonBjets += 1;
            if(fabs(SelectedJet[i].Eta())>fabs(maxEtaNonBjet))
            {
               maxEtaNonBjet = SelectedJet[i].Eta();
               qSpec.SetPtEtaPhiM(SelectedJet[i].Pt(),SelectedJet[i].Eta(),SelectedJet[i].Phi(),SelectedJet[i].M());
            } 
         }
      }

      // std::cout<<"atLeastOneBjet="<<atLeastOneBjet<<endl;


      // std::cout<<"Passed 1st Selection"<<endl;
      // std::cout<<"Non b Jet to keep pt="<<qSpec.Pt()<<" eta="<<qSpec.Eta()<<endl;
      // std::cout<<"b Jet to keep pt="<<bJet.Pt()<<" eta="<<bJet.Eta()<<endl;
      // std::cout<<"Number of b jets = "<<nbOfBjets<<endl;
      // std::cout<<"Lepton to keep pT= "<<SelectedGenDressedLepton_lead.Pt()<<" eta = "<<SelectedGenDressedLepton_lead.Eta()<<endl;

      reconstructW(&Wboson, &neutrino, SelectedGenDressedLepton_lead, met_pt, met_phi, &isRealSolution, &isNotAValidReco);
         
      top = bJet + Wboson;

      if(isNotAValidReco == true) continue;
      if( nSelectedGenDressedLepton>2 || nSelectedGenDressedLepton==0 || nSelectedGenJet<2 || !atLeastOneBjet || nbOfBjets>1) continue;


      // ReconstructW_Streco(&Wboson_Streco, &neutrino_Streco, SelectedGenDressedLepton_lead, met_pt, met_phi, &isRealSolution_Streco, &p4nu_LHE_leptonus, &p4nu_minus);

      // top_Streco = bJet + Wboson_Streco;

      // if(isRealSolution_Streco) nbOfRealSolutions_Streco += 1;
      // else nbOfComLHE_leptonexSolutions_Streco +=1;


      // cout<<"W boson pt= "<<Wboson.Pt()<<" W boson Eta= "<<Wboson.Eta()<<" W boson Phi= "<<Wboson.Phi()<<" W boson mass= "<<Wboson.M()<<endl;
      // cout<<"neutrino pt= "<<neutrino.Pt()<<" neutrino Eta= "<<neutrino.Eta()<<" neutrino Phi= "<<neutrino.Phi()<<endl;
      // cout<<"top pt= "<<top.Pt()<<" top Eta= "<<top.Eta()<<" top Phi= "<<top.Phi()<<" top mass= "<<top.M()<<endl;

      // cout<<"W boson Streco pt= "<<Wboson_Streco.Pt()<<" W boson Streco Eta= "<<Wboson_Streco.Eta()<<" W boson Streco Phi= "<<Wboson_Streco.Phi()<<" W boson Streco mass= "<<Wboson_Streco.M()<<endl;
      // cout<<"neutrino Streco pt= "<<neutrino_Streco.Pt()<<" neutrino Streco Eta= "<<neutrino_Streco.Eta()<<" neutrino Streco Phi= "<<neutrino_Streco.Phi()<<endl;
      // cout<<"top Streco pt= "<<top_Streco.Pt()<<" top Streco Eta= "<<top_Streco.Eta()<<" top Streco Phi= "<<top_Streco.Phi()<<" top Streco mass= "<<top_Streco.M()<<endl;


      /*______________ANGLE RECONSTRUCTION______________*/

      
      
      sinTheta = calculate_sinTheta(Wboson, top, qSpec);
      cosThetaZ = calculate_cosThetaZ(Wboson, top, qSpec);

      cosThetaZStar = calculate_cosThetaZStar(SelectedGenDressedLepton_lead, Wboson);
      cosThetaXStar = calculate_cosThetaXStar(SelectedGenDressedLepton_lead, Wboson);
      cosThetaYStar = calculate_cosThetaYStar(SelectedGenDressedLepton_lead, Wboson);
      sinThetaStar = calculate_sinThetaStar(SelectedGenDressedLepton_lead, Wboson);

      PhiStar = calculate_PhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);

      sinPhiStar = calculate_sinPhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);
      cosPhiStar = calculate_cosPhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);

      if(isRealSolution)
      {
         nbOfRealSolutions += 1;
         SolutionNature = 1;
         // std::cout<<"real solution"<<std::endl;
         sinTheta_Real = calculate_sinTheta(Wboson, top, qSpec);
         cosThetaX_Real = calculate_cosThetaX(Wboson, top, qSpec);

         cosThetaXStar_Real = calculate_cosThetaXStar(SelectedGenDressedLepton_lead, Wboson);
	 cosThetaYStar_Real = calculate_cosThetaYStar(SelectedGenDressedLepton_lead, Wboson);
	 cosThetaZStar_Real = calculate_cosThetaZStar(SelectedGenDressedLepton_lead, Wboson);
         sinThetaStar_Real = calculate_sinThetaStar(SelectedGenDressedLepton_lead, Wboson);

         PhiStar_Real = calculate_PhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);

         sinPhiStar_Real = calculate_sinPhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);
         cosPhiStar_Real = calculate_cosPhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);

         top_pt_Real = top.Pt();
         top_eta_Real = top.Eta();
         top_phi_Real = top.Phi();
         top_mass_Real = top.M();

         neutrino_pt_Real = neutrino.Pt();
         neutrino_eta_Real = neutrino.Eta();
         neutrino_phi_Real = neutrino.Phi();

         GENoutput_Real->Fill();
      }

      if(!isRealSolution)
      {
         nbOfComLHE_leptonexSolutions +=1;
         SolutionNature = -1;
         // std::cout<<"comLHE_leptonex solution"<<std::endl;
         sinTheta_ComLHE_leptonex = calculate_sinTheta(Wboson, top, qSpec);
         cosThetaX_ComLHE_leptonex = calculate_cosThetaX(Wboson, top, qSpec);

         cosThetaXStar_ComLHE_leptonex = calculate_cosThetaXStar(SelectedGenDressedLepton_lead, Wboson);
	 cosThetaYStar_ComLHE_leptonex = calculate_cosThetaYStar(SelectedGenDressedLepton_lead, Wboson);
	 cosThetaZStar_ComLHE_leptonex = calculate_cosThetaZStar(SelectedGenDressedLepton_lead, Wboson);
         sinThetaStar_ComLHE_leptonex = calculate_sinThetaStar(SelectedGenDressedLepton_lead, Wboson);

         PhiStar_ComLHE_leptonex = calculate_PhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);

         sinPhiStar_ComLHE_leptonex = calculate_sinPhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);
         cosPhiStar_ComLHE_leptonex = calculate_cosPhiStar(SelectedGenDressedLepton_lead, Wboson, qSpec);

         top_pt_ComLHE_leptonex = top.Pt();
         top_eta_ComLHE_leptonex = top.Eta();
         top_phi_ComLHE_leptonex = top.Phi();
         top_mass_ComLHE_leptonex = top.M();

         neutrino_pt_ComLHE_leptonex = neutrino.Pt();
         neutrino_eta_ComLHE_leptonex = neutrino.Eta();
         neutrino_phi_ComLHE_leptonex = neutrino.Phi();

         GENoutput_ComLHE_leptonex->Fill();
      }
      
      top_pt = top.Pt();
      top_eta = top.Eta();
      top_phi = top.Phi();
      top_mass = top.M();

      neutrino_pt = neutrino.Pt();
      neutrino_eta = neutrino.Eta();
      neutrino_phi = neutrino.Phi();

      lepton_pt = SelectedGenDressedLepton_lead.Pt();
      lepton_eta = SelectedGenDressedLepton_lead.Eta();
      lepton_phi = SelectedGenDressedLepton_lead.Phi();

      W_pt = Wboson.Pt();
      W_eta = Wboson.Eta();
      W_phi = Wboson.Phi();
      W_mass = Wboson.M();
      W_transverse_mass = Wboson.Mt();

      specJet_pt = qSpec.Pt();
      specJet_eta = qSpec.Eta();
      specJet_phi = qSpec.Phi();

      bJet_pt = bJet.Pt();
      bJet_eta = bJet.Eta();
      bJet_phi = bJet.Phi();


      lepton_pt = SelectedGenDressedLepton_lead.Pt();

      GENweight = xSec*genWeight/sumOf_genWeights_beforeAnalysis;
      LHEweight = xSec*LHEWeight_originalXWGTUP/sumOf_LHEweights_beforeAnalysis;

      deltaR_lepton_bQuark_GENlevel = SelectedGenDressedLepton_lead.DeltaR(bJet);
      deltaR_lepton_specQ_GENlevel = SelectedGenDressedLepton_lead.DeltaR(qSpec);




      GENoutput->Fill();















      /*---------------------- LHE level analysis -------------------------*/

      // TLorentzVector LHE_Wboson(0,0,0,0);
      // TLorentzVector LHE_lepton(0,0,0,0);
      // TLorentzVector LHE_specQ(0,0,0,0);
      // TLorentzVector LHE_bQuark(0,0,0,0);
      // TLorentzVector LHE_topQ(0,0,0,0);
      // TLorentzVector LHE_neutrino(0,0,0,0);

      // // std::cout << "LHE_NLHE_leptonO = " << LHE_NLHE_leptonO << std::endl;



      // for(int i=0; i<nLHEPart; i++)
      // {

      // //   std::cout << "LHEPart_pdgId = " << LHEPart_pdgId[i] << std::endl;
      // //   std::cout << "LHEPart_status = " << LHEPart_status[i] << std::endl;


		//   if (TMath::Abs(LHEPart_pdgId[i])==24)
		// 	   LHE_Wboson.SetPtEtaPhiM(LHEPart_pt[i], LHEPart_eta[i], LHEPart_phi[i], LHEPart_mass[i]);

		//   if (TMath::Abs(LHEPart_pdgId[i])==5 && LHEPart_status[i]==1)
		// 	  LHE_bQuark.SetPtEtaPhiM(LHEPart_pt[i], LHEPart_eta[i], LHEPart_phi[i], LHEPart_mass[i]);

		//   if (TMath::Abs(LHEPart_pdgId[i])<5 && LHEPart_status[i]==1)
		// 	  LHE_specQ.SetPtEtaPhiM(LHEPart_pt[i], LHEPart_eta[i], LHEPart_phi[i], LHEPart_mass[i]);

		//   if ((TMath::Abs(LHEPart_pdgId[i])==11 || TMath::Abs(LHEPart_pdgId[i])==13))
      //    {
      //       LHE_lepton.SetPtEtaPhiM(LHEPart_pt[i], LHEPart_eta[i], LHEPart_phi[i], LHEPart_mass[i]);

      //       if (abs(LHEPart_pdgId[i]) == 11)
      //       {
      //          nature_lepton_LHE = 1.0; //Electron
      //       }
      //       if (abs(LHEPart_pdgId[i]) == 13)
      //       {
      //          nature_lepton_LHE = 2.0; //Muon
      //       }
      //    }


      //    if ((TMath::Abs(LHEPart_pdgId[i])==12 || TMath::Abs(LHEPart_pdgId[i])==14))
  		//       LHE_neutrino.SetPtEtaPhiM(LHEPart_pt[i], LHEPart_eta[i], LHEPart_phi[i], LHEPart_mass[i]);

      // }

      // LHE_topQ = LHE_bQuark + LHE_lepton + LHE_neutrino;

      // TVector3 InvariantTopBoost;
      // InvariantTopBoost.SetXYZ(-LHE_topQ.Px()/LHE_topQ.E(),-LHE_topQ.Py()/LHE_topQ.E(),-LHE_topQ.Pz()/LHE_topQ.E());


  	   // if ((LHE_lepton.Pt()<32 || TMath::Abs(LHE_lepton.Eta())>2.1) && nature_lepton_LHE==1.0) continue; //Electron Streco Selection
      // if ((LHE_lepton.Pt()<30 || TMath::Abs(LHE_lepton.Eta())>2.4) && nature_lepton_LHE==2.0) continue; //Muon Streco Selection
      // if (LHE_specQ.Pt()<40 || TMath::Abs(LHE_specQ.Eta())>4.7) continue; //Jet 1st selection
      // if (TMath::Abs(LHE_specQ.Eta()) >= 2.4 && LHE_specQ.Pt() < 60) continue; //Jet Streco 2nd selection for |eta|>=2.4
      // if (LHE_bQuark.Pt()<40 || TMath::Abs(LHE_bQuark.Eta())>2.5) continue; //b jetStreco Selection 
      // if (TMath::Abs(LHE_bQuark.Eta()) >= 2.4 && LHE_bQuark.Pt() < 60) continue; //Jet Streco 2nd selection for |eta|>=2.4


      // deltaR_lepton_bQuark_LHElevel = LHE_lepton.DeltaR(LHE_bQuark);
      // deltaR_lepton_specQ_LHElevel = LHE_lepton.DeltaR(LHE_specQ);

      // LHE_lepton.Boost(InvariantTopBoost);
      // LHE_specQ.Boost(InvariantTopBoost);
      // LHE_bQuark.Boost(InvariantTopBoost);

      // deltaR_lepton_bQuark_boosted_LHElevel = LHE_lepton.DeltaR(LHE_bQuark);
      // deltaR_lepton_specQ_boosted_LHElevel = LHE_lepton.DeltaR(LHE_specQ);


      // // LHEoutput->SetWeight(genWeight/sumOf_genWeights);

      // GENweight = genWeight;
      // LHEweight = LHEWeight_originalXWGTUP;

      // // Weights->Fill();
      // LHEoutput->Fill();
   }

   SumOfWeights->Fill();


   GENoutput->Write(0,TObject::kWriteDelete);
   GENoutput_Real->Write(0,TObject::kWriteDelete);
   GENoutput_ComLHE_leptonex->Write(0,TObject::kWriteDelete);
   SumOfWeights->Write(0,TObject::kWriteDelete);
   LHEoutput->Write(0,TObject::kWriteDelete);
   Weights->Write(0,TObject::kWriteDelete);

   fOutput->Close();
}
