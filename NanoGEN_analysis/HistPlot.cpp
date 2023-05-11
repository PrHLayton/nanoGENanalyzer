#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <THStack.h>
#include "TLegend.h"


void plotHistogramZ()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("powheg.root", "read");
    TTree* treeP = (TTree*)inputP->Get("LHE");

    TH1F* MG5 = new TH1F("MG5", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("MG5.root", "read");
    TTree* treeM = (TTree*)inputM->Get("LHE");

    float cosThetaZStar;

    treeP->SetBranchAddress("cosThetaZStar", &cosThetaZStar);
    treeM->SetBranchAddress("cosThetaZStar", &cosThetaZStar);

    Long64_t pow_entries = treeP->GetEntries();

    for (Long64_t i = 0; i < pow_entries; i++)
    {
        treeP->GetEntry(i);
        powheg->Fill(cosThetaZStar);
    }
    powheg->SetLineColor(kRed);
    powheg->Scale(1.0/powheg->Integral());
    


    Long64_t MG5_entries = treeM->GetEntries();

    for (Long64_t i = 0; i < MG5_entries; i++)
    {
        treeM->GetEntry(i);
        MG5->Fill(cosThetaZStar);
    }
    MG5->SetLineColor(kBlue);
    MG5->Scale(1.0/MG5->Integral());
  
     
    THStack *histStack = new THStack("histStack", "cosThetaZ*");

    histStack->Add(powheg);
    histStack->Add(MG5);
    

    TCanvas* canvasZ = new TCanvas("canvasZ", "Histogram Canvas Z", 1200, 800);
    histStack->Draw("E");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasZ->SaveAs("cosThetaZ*.pdf");

    delete powheg;
    delete MG5;
    inputP->Close();
    inputM->Close();
}

void plotHistogramX()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaX*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("powheg.root", "read");
    TTree* treeP = (TTree*)inputP->Get("LHE");

    TH1F* MG5 = new TH1F("MG5", "cosThetaX*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("MG5.root", "read");
    TTree* treeM = (TTree*)inputM->Get("LHE");

    float cosThetaXStar;

    treeP->SetBranchAddress("cosThetaXStar", &cosThetaXStar);
    treeM->SetBranchAddress("cosThetaXStar", &cosThetaXStar);

    Long64_t pow_entries = treeP->GetEntries();

    for (Long64_t i = 0; i < pow_entries; i++)
    {
        treeP->GetEntry(i);
        powheg->Fill(cosThetaXStar);
    }
    powheg->SetLineColor(kRed);
    powheg->Scale(1.0/powheg->Integral());


    Long64_t MG5_entries = treeM->GetEntries();

    for (Long64_t i = 0; i < MG5_entries; i++)
    {
        treeM->GetEntry(i);
        MG5->Fill(cosThetaXStar);
    }
    MG5->SetLineColor(kBlue);
    MG5->Scale(1.0/MG5->Integral());
  
     
    THStack *histStack = new THStack("histStack", "cosThetaX*");

   
    histStack->Add(powheg);
    histStack->Add(MG5);
    

    TCanvas* canvasX = new TCanvas("canvasX", "Histogram Canvas X", 1200, 800);
    histStack->Draw("E");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasX->SaveAs("cosThetaX*.pdf");

    delete powheg;
    delete MG5;
    inputP->Close();
    inputM->Close();
}

void plotHistogramY()
{
    TH1F* powheg = new TH1F("powheg", "cosThetaY*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("powheg.root", "read");
    TTree* treeP = (TTree*)inputP->Get("LHE");

    TH1F* MG5 = new TH1F("MG5", "cosThetaY*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("MG5.root", "read");
    TTree* treeM = (TTree*)inputM->Get("LHE");

    float cosThetaYStar;

    treeP->SetBranchAddress("cosThetaYStar", &cosThetaYStar);
    treeM->SetBranchAddress("cosThetaYStar", &cosThetaYStar);

    Long64_t pow_entries = treeP->GetEntries();

    for (Long64_t i = 0; i < pow_entries; i++)
    {
        treeP->GetEntry(i);
        powheg->Fill(cosThetaYStar);
    }
    powheg->SetLineColor(kRed);
    powheg->Scale(1.0/powheg->Integral());


    Long64_t MG5_entries = treeM->GetEntries();

    for (Long64_t i = 0; i < MG5_entries; i++)
    {
        treeM->GetEntry(i);
        MG5->Fill(cosThetaYStar);
    }
    MG5->SetLineColor(kBlue);
    MG5->Scale(1.0/MG5->Integral());
  
     
    THStack *histStack = new THStack("histStack", "cosThetaY*");

   
    histStack->Add(powheg);
    histStack->Add(MG5);
    

    TCanvas* canvasY = new TCanvas("canvasY", "Histogram Canvas Y", 1200, 800);
    histStack->Draw("E");

    TLegend *legend = new TLegend(0.8, 0.8, 0.9, 0.9);
    legend->AddEntry(powheg, "powheg");
    legend->AddEntry(MG5, "MG5");
    legend->Draw();

    canvasY->SaveAs("cosThetaY*.pdf");

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
