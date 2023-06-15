#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <THStack.h>
#include "TLegend.h"

//These functions produce histograms from data analysed at GEN level

void plotHistogramZ()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("new_LHE_POWHEG.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* MG5 = new TH1F("MG5", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("new_LHE_MG5.root", "read");
    TTree* treeM = (TTree*)inputM->Get("GENoutput");

    float cosThetaZStarM, cosThetaZStarP;
    double weightM, weightP;

    treeP->SetBranchAddress("cosThetaZStar", &cosThetaZStarP);
    treeP->SetBranchAddress("sumOf_genWeights", &weightP);
    treeM->SetBranchAddress("cosThetaZStar", &cosThetaZStarM);
    treeM->SetBranchAddress("sumOf_genWeights", &weightM);

    Long64_t pow_entries = treeP->GetEntries();

    double sumOfWeightsP = 0;

    for (Long64_t i = 0; i < pow_entries; i++)
    {
        treeP->GetEntry(i);
        powheg->Fill(cosThetaZStarP, weightP);
	sumOfWeightsP += weightP;
    }
    powheg->SetLineColor(kRed);
   

    Long64_t MG5_entries = treeM->GetEntries();

    double sumOfWeightsM = 0;

    for (Long64_t i = 0; i < MG5_entries; i++)
    {
        treeM->GetEntry(i);
        MG5->Fill(cosThetaZStarM, weightM);
	sumOfWeightsM += weightM;
    }
    MG5->SetLineColor(kBlue);
    
    powheg->Scale(1.0 / sumOfWeightsP);
    MG5->Scale(1.0 / sumOfWeightsM);

    TCanvas* canvasZ = new TCanvas("canvasZ", "Histogram Canvas Z", 1200, 800);
    MG5->Draw("E");
    powheg->Draw("same");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasZ->SaveAs("LHE_new_cosThetaZ*.pdf");

    delete powheg;
    delete MG5;
    inputP->Close();
    inputM->Close();
}



void plotHistogramX()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaX*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("new_LHE_POWHEG.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* MG5 = new TH1F("MG5", "cosThetaX*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("new_LHE_MG5.root", "read");
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

    TCanvas* canvasX = new TCanvas("canvasX", "Histogram Canvas X", 1200, 800);
    MG5->Draw("E");
    powheg->Draw("same");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasX->SaveAs("LHE_new_cosThetaX*.pdf");

    delete powheg;
    delete MG5;
    inputP->Close();
    inputM->Close();
}


void plotHistogramY()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaY*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("new_LHE_POWHEG.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* MG5 = new TH1F("MG5", "cosThetaY*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("new_LHE_MG5.root", "read");
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

    TCanvas* canvasY = new TCanvas("canvasY", "Histogram Canvas Y", 1200, 800);
    MG5->Draw("E");
    powheg->Draw("same");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasY->SaveAs("LHE_new_cosThetaY*.pdf");

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
