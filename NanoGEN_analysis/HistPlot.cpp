#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <THStack.h>
#include "TLegend.h"
#include <iostream>
using namespace std;


void plotHistogramZ()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("GEN_powheg.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* MG5 = new TH1F("MG5", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("GEN_MG5.root", "read");
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
    //powheg->GetXaxis()->SetTitle("cosThetaZ*");

    Long64_t MG5_entries = treeM->GetEntries();

    double sumOfWeightsM = 0;

    for (Long64_t i = 0; i < MG5_entries; i++)
    {
        treeM->GetEntry(i);
        MG5->Fill(cosThetaZStarM, weightM);
	sumOfWeightsM += weightM;
    }
    MG5->SetLineColor(kBlue);
    //MG5->GetXaxis()->SetTitle("cosThetaZ*");
    
    powheg->Scale(1.0 / sumOfWeightsP);
    MG5->Scale(1.0 / sumOfWeightsM);

	double integral = powheg->Integral(1, powheg->GetNbinsX());

	cout << integral << endl;

    THStack *histStack = new THStack("histStack", "cosThetaZ*");

    histStack->Add(powheg);
    histStack->Add(MG5);

    TCanvas* canvasZ = new TCanvas("canvasZ", "Histogram Canvas Z", 1200, 800);
    histStack->Draw("nostack");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasZ->SaveAs("GENcosThetaZ*.pdf");

    delete powheg;
    delete MG5;
    inputP->Close();
    inputM->Close();
}



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
