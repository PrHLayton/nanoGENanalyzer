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
// The histograms are normalized by the sum of their weights.

void plotHistogramZ()
{
    // Create histograms for powheg and MG5 simulations
    TH1F* powheg = new TH1F("powheg", "cosThetaZ*", 30, -1.0, 1.0);
    TH1F* MG5 = new TH1F("MG5", "cosThetaZ*", 30, -1.0, 1.0);

    // Open input files for powheg and MG5 simulations
    TFile* inputP = new TFile("powheg.root", "read");
    TFile* inputM = new TFile("MG5.root", "read");

    // Get the trees from the input files
    TTree* treeP = (TTree*)inputP->Get("LHE");
    TTree* treeM = (TTree*)inputM->Get("LHE");

// Declare variables to store the values of the "cosThetaZStar" and "LHEweight" branches
    float cosThetaZStarM, cosThetaZStarP;
    double weightM, weightP;

    // Set the branch addresses for relevant variables in the trees
    treeP->SetBranchAddress("cosThetaZStar", &cosThetaZStarP);
    treeP->SetBranchAddress("LHEweight", &weightP);
    treeM->SetBranchAddress("cosThetaZStar", &cosThetaZStarM);
    treeM->SetBranchAddress("LHEweight", &weightM);

    //Get the number of entries in the "LHE" tree for powheg and declare a variable to store the sum of the weights
    Long64_t pow_entries = treeP->GetEntries();
    double sumOfWeightsP = 0;

    // Fill the powheg histogram and calculate the sum of weights
    for (Long64_t i = 0; i < pow_entries; i++)
    {
        treeP->GetEntry(i);
        powheg->Fill(cosThetaZStarP), weightP);
        sumOfWeightsP += weightP;
    }
    
    // Set the line color of the powheg histogram
    powheg->SetLineColor(kRed);

    Long64_t MG5_entries = treeM->GetEntries();
    double sumOfWeightsM = 0;

    // Fill the MG5 histogram and calculate the sum of weights
    for (Long64_t i = 0; i < MG5_entries; i++)
    {
        treeM->GetEntry(i);
        MG5->Fill(cosThetaZStarM), weightM);
        sumOfWeightsM += weightM;
    }
    
    // Set the line color of the MG5 histogram
    MG5->SetLineColor(kBlue);

    // Normalize the histograms by the sum of weights
    powheg->Scale(1.0 / sumOfWeightsP);
    MG5->Scale(1.0 / sumOfWeightsM);

    // Create a THStack to stack the histograms
    THStack *histStack = new THStack("histStack", "cosThetaZ*");

    // Add the histograms to the stack
    histStack->Add(powheg);
    histStack->Add(MG5);

    // Create a canvas to draw the histogram
    TCanvas* canvasZ = new TCanvas("canvasZ", "Histogram Canvas Z", 1200, 800);

    // Draw the stacked histogram on the canvas
    histStack->Draw("nostack");

    // Create a legend to display the histogram labels
    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    // Save the canvas as a PDF file
    canvasZ->SaveAs("cosThetaZ*.pdf");

    delete powheg;
    delete MG5;
    inputP->Close();
    inputM->Close();
}

//Same as previous function but for X and Y

void plotHistogramX()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaX*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("GEN_powheg.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* MG5 = new TH1F("MG5", "cosThetaX*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("GEN_MG5.root", "read");
    TTree* treeM = (TTree*)inputM->Get("GENoutput");

    float cosThetaXStarM, cosThetaXStarP;
    double weightM, weightP;

    treeP->SetBranchAddress("cosThetaXStar", &cosThetaXStarP);
    treeP->SetBranchAddress("sumOf_genWeights", &weightP);
    treeM->SetBranchAddress("cosThetaXStar", &cosThetaXStarM);
    treeM->SetBranchAddress("sumOf_genWeights", &weightM);

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

    THStack *histStack = new THStack("histStack", "cosThetaX*");

    histStack->Add(powheg);
    histStack->Add(MG5);

    TCanvas* canvasX = new TCanvas("canvasX", "Histogram Canvas X", 1200, 800);
    histStack->Draw("nostack");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasX->SaveAs("GENcosThetaX*.pdf");

    delete powheg;
    delete MG5;
    inputP->Close();
    inputM->Close();
}


void plotHistogramY()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaY*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("GEN_powheg.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* MG5 = new TH1F("MG5", "cosThetaY*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("GEN_MG5.root", "read");
    TTree* treeM = (TTree*)inputM->Get("GENoutput");

    float cosThetaYStarM, cosThetaYStarP;
    double weightM, weightP;

    treeP->SetBranchAddress("cosThetaYStar", &cosThetaYStarP);
    treeP->SetBranchAddress("sumOf_genWeights", &weightP);
    treeM->SetBranchAddress("cosThetaYStar", &cosThetaYStarM);
    treeM->SetBranchAddress("sumOf_genWeights", &weightM);

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

    THStack *histStack = new THStack("histStack", "cosThetaY*");

    histStack->Add(powheg);
    histStack->Add(MG5);

    TCanvas* canvasY = new TCanvas("canvasY", "Histogram Canvas Y", 1200, 800);
    histStack->Draw("nostack");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasY->SaveAs("GENcosThetaY*.pdf");

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
