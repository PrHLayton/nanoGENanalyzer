#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <THStack.h>
#include "TLegend.h"
#include <iostream>
using namespace std;

// This function produces a stacked histogram of the distribution of the variable "cosThetaZ*" 
// for two different simulations called "powheg" and "MG5", and saves the plot as a PDF file.
// The histograms are normalized using the sum of their weights.

void plotHistogramZ()
{
    
    TH1F* powheg = new TH1F("powheg", "cosThetaZ*", 30, -1.0, 1.0);	// Create histograms for powheg and MG5 simulations
    TH1F* MG5 = new TH1F("MG5", "cosThetaZ*", 30, -1.0, 1.0);

    
    TFile* inputP = new TFile("ZW_LHE_POWHEG.root", "read");	// Open input files for powheg and MG5 simulations
    TFile* inputM = new TFile("ZW_LHE_MG5.root", "read");

   
    TTree* treeP = (TTree*)inputP->Get("LHE");	 // Get the trees from the input files
    TTree* treeM = (TTree*)inputM->Get("LHE");

    float cosThetaZStarM, cosThetaZStarP;
    double weightM, weightP;

    
    treeP->SetBranchAddress("cosThetaZStar", &cosThetaZStarP);	// Set the branch addresses for relevant variables in the trees
    treeP->SetBranchAddress("LHEweight", &weightP);
    treeM->SetBranchAddress("cosThetaZStar", &cosThetaZStarM);
    treeM->SetBranchAddress("LHEweight", &weightM);

    
    Long64_t pow_entries = treeP->GetEntries();	//Get the number of entries in the "LHE" tree for powheg and declare a variable to store the sum of the weights
    double sumOfWeightsP = 0;

   
    for (Long64_t i = 0; i < pow_entries; i++)	 // Fill the powheg histogram and calculate the sum of weights
    {
        treeP->GetEntry(i);
        powheg->Fill(cosThetaZStarP, weightP);
        sumOfWeightsP += weightP;
    }
    
  
    powheg->SetLineColor(kRed);

    Long64_t MG5_entries = treeM->GetEntries();
    double sumOfWeightsM = 0;

    
    for (Long64_t i = 0; i < MG5_entries; i++)	// Fill the MG5 histogram and calculate the sum of weights
    {
        treeM->GetEntry(i);
        MG5->Fill(cosThetaZStarM, weightM);
        sumOfWeightsM += weightM;
    }
    
    MG5->SetLineColor(kBlue);

   
    powheg->Scale(1.0 / sumOfWeightsP);	 // Normalize the histograms using the sum of weights
    MG5->Scale(1.0 / sumOfWeightsM);

    
    TCanvas* canvasZ = new TCanvas("canvasZ", "Histogram Canvas Z", 1200, 800);	// Create a canvas to draw the histogram

    MG5->SetStats(0);
    MG5->Draw("E");	 // Draw histograms on the canvas
    powheg->Draw("same");

    
    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);	// Create a legend to display the histogram labels
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasZ->SaveAs("LHE_ZW_cosThetaZ*.pdf");

    delete powheg;
    delete MG5;
    inputP->Close();
    inputM->Close();
}

//Same as previous function but for X and Y

void plotHistogramX()
{
	TH1F* powheg = new TH1F("powheg", "cosThetaX*", 30, -1.0, 1.0);
	TH1F* MG5 = new TH1F("MG5", "cosThetaX*", 30, -1.0, 1.0);

	TFile* inputP = new TFile("ZW_LHE_POWHEG.root", "read");
	TFile* inputM = new TFile("ZW_LHE_MG5.root", "read");

	TTree* treeP = (TTree*)inputP->Get("LHE");
	TTree* treeM = (TTree*)inputM->Get("LHE");

	float cosThetaXStarM, cosThetaXStarP;
	double weightM, weightP;

	treeP->SetBranchAddress("cosThetaXStar", &cosThetaXStarP);
	treeP->SetBranchAddress("LHEweight", &weightP);
	treeM->SetBranchAddress("cosThetaXStar", &cosThetaXStarM);
	treeM->SetBranchAddress("LHEweight", &weightM);

	Long64_t pow_entries = treeP->GetEntries();
	double sumOfWeightsP = 0;

	for (Long64_t i = 0; i < pow_entries; i++)
	{
	    treeP->GetEntry(i);
	    powheg->Fill(cosThetaXStarP, weightP);
	    sumOfWeightsP += weightP;
	}

	powheg->SetLineColor(kRed);

	Long64_t MG5_entries = treeM->GetEntries();
	double sumOfWeightsM = 0;

	for (Long64_t i = 0; i < MG5_entries; i++)
	{
	    treeM->GetEntry(i);
	    MG5->Fill(cosThetaXStarM, weightM);
	    sumOfWeightsM += weightM;
	}

	MG5->SetLineColor(kBlue);

	powheg->Scale(1.0 / sumOfWeightsP);
	MG5->Scale(1.0 / sumOfWeightsM);

	TCanvas* canvasX = new TCanvas("canvasX", "Histogram Canvas X", 1200, 800);

	MG5->SetStats(0);
	MG5->Draw("E");
	powheg->Draw("same");

	TLegend* legend = new TLegend(0.8, 0.8, 0.9, 0.9);
	legend->AddEntry(powheg, "powheg");
	legend->AddEntry(MG5, "MG5");
	legend->Draw();

	canvasX->SaveAs("LHE_ZW_cosThetaX*.pdf");

	delete powheg;
	delete MG5;
	inputP->Close();
	inputM->Close();

}


void plotHistogramY()
{
	TH1F* powheg = new TH1F("powheg", "cosThetaY*", 30, -1.0, 1.0);
	TH1F* MG5 = new TH1F("MG5", "cosThetaY*", 30, -1.0, 1.0);

	TFile* inputP = new TFile("ZW_LHE_POWHEG.root", "read");
	TFile* inputM = new TFile("ZW_LHE_MG5.root", "read");

	TTree* treeP = (TTree*)inputP->Get("LHE");
	TTree* treeM = (TTree*)inputM->Get("LHE");

	float cosThetaYStarM, cosThetaYStarP;
	double weightM, weightP;

	treeP->SetBranchAddress("cosThetaYStar", &cosThetaYStarP);
	treeP->SetBranchAddress("LHEweight", &weightP);
	treeM->SetBranchAddress("cosThetaYStar", &cosThetaYStarM);
	treeM->SetBranchAddress("LHEweight", &weightM);

	Long64_t pow_entries = treeP->GetEntries();
	double sumOfWeightsP = 0;

	for (Long64_t i = 0; i < pow_entries; i++)
	{
	    treeP->GetEntry(i);
	    powheg->Fill(cosThetaYStarP, weightP);
	    sumOfWeightsP += weightP;
	}

	powheg->SetLineColor(kRed);

	Long64_t MG5_entries = treeM->GetEntries();
	double sumOfWeightsM = 0;

	for (Long64_t i = 0; i < MG5_entries; i++)
	{
	    treeM->GetEntry(i);
	    MG5->Fill(cosThetaYStarM, weightM);
	    sumOfWeightsM += weightM;
	}

	MG5->SetLineColor(kBlue);

	powheg->Scale(1.0 / sumOfWeightsP);
	MG5->Scale(1.0 / sumOfWeightsM);

	TCanvas* canvasY = new TCanvas("canvasY", "Histogram Canvas Y", 1200, 800);

	MG5->SetStats(0);
	MG5->Draw("E");
	powheg->Draw("same");

	TLegend* legend = new TLegend(0.8, 0.8, 0.9, 0.9);
	legend->AddEntry(powheg, "powheg");
	legend->AddEntry(MG5, "MG5");
	legend->Draw();

	canvasY->SaveAs("LHE_ZW_cosThetaY*.pdf");

	delete powheg;
	delete MG5;
	inputP->Close();
	inputM->Close();

}


int main()
{
    plotHistogramZ();
    plotHistogramX();
    plotHistogramY();
    return 0;
}
