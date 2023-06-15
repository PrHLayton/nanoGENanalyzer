#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <THStack.h>
#include "TLegend.h"



void plotHistogramZ()
{
    TH1F* SM = new TH1F("SM", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* input_SM = new TFile("bump_new.root", "read");
    TTree* tree_SM = (TTree*)input_SM->Get("GENoutput");

    TH1F* cbwi_p2 = new TH1F("cbwi_p2", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("ZW_output_cbwi_p2.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* cbwi_m2 = new TH1F("cbwi_m2", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* input_cbwi_m2 = new TFile("ZW_output_cbwi_m2.root", "read");
    TTree* tree_cbwi_m2 = (TTree*)input_cbwi_m2->Get("GENoutput");

    TH1F* ctwi_p2 = new TH1F("ctwi_p2", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("ZW_output_ctwi_p2.root", "read");
    TTree* treeM = (TTree*)inputM->Get("GENoutput");

    TH1F* ctwi_m2 = new TH1F("ctwi_m2", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* input_ctwi_m2 = new TFile("ZW_output_ctwi_m2.root", "read");
    TTree* tree_ctwi_m2 = (TTree*)input_ctwi_m2->Get("GENoutput");
	    
    TH1F* cptbi_m5 = new TH1F("cptbi_m5", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* input_cptbi_m5 = new TFile("output_cptbi_m5.root", "read");
    TTree* tree_cptbi_m5 = (TTree*)input_cptbi_m5->Get("GENoutput");

    TH1F* cptbi_p5 = new TH1F("cptbi_p5", "cosThetaZ*", 30, -1.0, 1.0);
    TFile* input_cptbi_p5 = new TFile("output_cptbi_p5.root", "read");
    TTree* tree_cptbi_p5 = (TTree*)input_cptbi_p5->Get("GENoutput");

    float cosThetaZStar;
    double weight;

    tree_SM->SetBranchAddress("cosThetaZStar", &cosThetaZStar);
    tree_SM->SetBranchAddress("sumOf_genWeights", &weight);
    treeP->SetBranchAddress("cosThetaZStar", &cosThetaZStar);
    treeP->SetBranchAddress("sumOf_genWeights", &weight);
    treeM->SetBranchAddress("cosThetaZStar", &cosThetaZStar);
    treeM->SetBranchAddress("sumOf_genWeights", &weight);
    tree_ctwi_m2->SetBranchAddress("cosThetaZStar", &cosThetaZStar);
    tree_ctwi_m2->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cbwi_m2->SetBranchAddress("cosThetaZStar", &cosThetaZStar);
    tree_cbwi_m2->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cptbi_m5->SetBranchAddress("cosThetaZStar", &cosThetaZStar);
    tree_cptbi_m5->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cptbi_p5->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cptbi_p5->SetBranchAddress("cosThetaZStar", &cosThetaZStar);


    Long64_t SM_entries = tree_SM->GetEntries();
    double sumOfWeights_SM = 0;

    for (Long64_t i = 0; i < SM_entries; i++)
    {
        tree_SM->GetEntry(i);
        SM->Fill(cosThetaZStar, weight);
	sumOfWeights_SM += weight;
    }
	SM->SetLineColor(kBlack);

    Long64_t cbwi_p2_entries = treeP->GetEntries();

    double sumOfWeights_cbwi_p2 = 0;

    for (Long64_t i = 0; i < cbwi_p2_entries; i++)
    {
        treeP->GetEntry(i);
        cbwi_p2->Fill(cosThetaZStar, weight);
	sumOfWeights_cbwi_p2 += weight;
    }
    cbwi_p2->SetLineColor(kRed);
   

    Long64_t ctwi_p2_entries = treeM->GetEntries();

    double sumOfWeights_ctwi_p2 = 0;

    for (Long64_t i = 0; i < ctwi_p2_entries; i++)
    {
        treeM->GetEntry(i);
        ctwi_p2->Fill(cosThetaZStar, weight);
	sumOfWeights_ctwi_p2 += weight;
    }
    ctwi_p2->SetLineColor(kBlue);

    Long64_t ctwi_m2_entries = tree_ctwi_m2->GetEntries();

    double sumOfWeights_ctwi_m2 = 0;

    for (Long64_t i = 0; i < ctwi_m2_entries; i++)
    {
        tree_ctwi_m2->GetEntry(i);
        ctwi_m2->Fill(cosThetaZStar, weight);
	sumOfWeights_ctwi_m2 += weight;
    }
    ctwi_m2->SetLineColor(kRed);

    Long64_t cbwi_m2_entries = tree_cbwi_m2->GetEntries();

    double sumOfWeights_cbwi_m2 = 0;

    for (Long64_t i = 0; i < cbwi_m2_entries; i++)
    {
        tree_cbwi_m2->GetEntry(i);
        cbwi_m2->Fill(cosThetaZStar, weight);
	sumOfWeights_cbwi_m2 += weight;
    }
    cbwi_m2->SetLineColor(kGreen);

    Long64_t cptbi_m5_entries = tree_cptbi_m5->GetEntries();

    double sumOfWeights_cptbi_m5 = 0;

    for (Long64_t i = 0; i < cptbi_m5_entries; i++)
    {
        tree_cptbi_m5->GetEntry(i);
        cptbi_m5->Fill(cosThetaZStar, weight);
	sumOfWeights_cptbi_m5 += weight;
    }
    cptbi_m5->SetLineColor(kGreen);

    Long64_t cptbi_p5_entries = tree_cptbi_p5->GetEntries();

    double sumOfWeights_cptbi_p5 = 0;

    for (Long64_t i = 0; i < cptbi_p5_entries; i++)
    {
        tree_cptbi_p5->GetEntry(i);
        cptbi_p5->Fill(cosThetaZStar, weight);
	sumOfWeights_cptbi_p5 += weight;
    }
    cptbi_p5->SetLineColor(kRed);
    
    SM->Scale(1.0 / sumOfWeights_SM);
    cbwi_p2->Scale(1.0 / sumOfWeights_cbwi_p2);
    ctwi_p2->Scale(1.0 / sumOfWeights_ctwi_p2);
    ctwi_m2->Scale(1.0 / sumOfWeights_ctwi_m2);
    cbwi_m2->Scale(1.0 / sumOfWeights_cbwi_m2);
    cptbi_m5->Scale(1.0 / sumOfWeights_cptbi_m5);
    cptbi_p5->Scale(1.0 / sumOfWeights_cptbi_p5);

    TCanvas* canvasZ = new TCanvas("canvasZ", "Histogram Canvas Z", 1200, 800);

    SM->SetStats(kFALSE);
	
    SM->Draw("E");
    //cbwi_p2->Draw("same");
    //ctwi_p2->Draw("same");
    //ctwi_m2->Draw("same");
    //cbwi_m2->Draw("same");
    cptbi_m5->Draw("same");
    cptbi_p5->Draw("same");


    TLegend *legend = new TLegend(0.3, 0.8, 0.5, 0.9);
    legend->AddEntry(SM, "SM");
    //legend->AddEntry(cbwi_p2, "cbwi_p2");
    //legend->AddEntry(ctwi_p2, "ctwi_p2");
    //legend->AddEntry(ctwi_m2, "ctwi_m2");
    //legend->AddEntry(cbwi_m2, "cbwi_m2");
    legend->AddEntry(cptbi_m5, "cptbi_m5");
    legend->AddEntry(cptbi_p5, "cptbi_p5");
    legend->Draw();

    canvasZ->SaveAs("GEN_new_cptbi_pm5_cosThetaZ*.pdf");

    delete SM;
    delete cbwi_p2;
    delete ctwi_p2;
    delete ctwi_m2;
    delete cbwi_m2;
    delete cptbi_m5;
    delete cptbi_p5;
    input_SM->Close();
    inputP->Close();
    inputM->Close();
    input_ctwi_m2->Close();
    input_cbwi_m2->Close();
    input_cptbi_m5->Close();
    input_cptbi_p5->Close();
}


void plotHistogramX()
{
    TH1F* SM = new TH1F("SM", "cosThetaX*", 30, -1.0, 1.0);
    TFile* input_SM = new TFile("bump_new.root", "read");
    TTree* tree_SM = (TTree*)input_SM->Get("GENoutput");

    TH1F* cbwi_p2 = new TH1F("cbwi_p2", "cosThetaX*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("ZW_output_cbwi_p2.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* cbwi_m2 = new TH1F("cbwi_m2", "cosThetaX*", 30, -1.0, 1.0);
    TFile* input_cbwi_m2 = new TFile("ZW_output_cbwi_m2.root", "read");
    TTree* tree_cbwi_m2 = (TTree*)input_cbwi_m2->Get("GENoutput");

    TH1F* ctwi_p2 = new TH1F("ctwi_p2", "cosThetaX*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("ZW_output_ctwi_p2.root", "read");
    TTree* treeM = (TTree*)inputM->Get("GENoutput");

    TH1F* ctwi_m2 = new TH1F("ctwi_m2", "cosThetaX*", 30, -1.0, 1.0);
    TFile* input_ctwi_m2 = new TFile("ZW_output_ctwi_m2.root", "read");
    TTree* tree_ctwi_m2 = (TTree*)input_ctwi_m2->Get("GENoutput");

    TH1F* cptbi_m5 = new TH1F("cptbi_m5", "cosThetaX*", 30, -1.0, 1.0);
    TFile* input_cptbi_m5 = new TFile("output_cptbi_m5.root", "read");
    TTree* tree_cptbi_m5 = (TTree*)input_cptbi_m5->Get("GENoutput");

    TH1F* cptbi_p5 = new TH1F("cptbi_p5", "cosThetaX*", 30, -1.0, 1.0);
    TFile* input_cptbi_p5 = new TFile("output_cptbi_p5.root", "read");
    TTree* tree_cptbi_p5 = (TTree*)input_cptbi_p5->Get("GENoutput");

    float cosThetaXStar;
    double weight;

    tree_SM->SetBranchAddress("cosThetaXStar", &cosThetaXStar);
    tree_SM->SetBranchAddress("sumOf_genWeights", &weight);
    treeP->SetBranchAddress("cosThetaXStar", &cosThetaXStar);
    treeP->SetBranchAddress("sumOf_genWeights", &weight);
    treeM->SetBranchAddress("cosThetaXStar", &cosThetaXStar);
    treeM->SetBranchAddress("sumOf_genWeights", &weight);
    tree_ctwi_m2->SetBranchAddress("cosThetaXStar", &cosThetaXStar);
    tree_ctwi_m2->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cbwi_m2->SetBranchAddress("cosThetaXStar", &cosThetaXStar);
    tree_cbwi_m2->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cptbi_m5->SetBranchAddress("cosThetaXStar", &cosThetaXStar);
    tree_cptbi_m5->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cptbi_p5->SetBranchAddress("cosThetaXStar", &cosThetaXStar);
    tree_cptbi_p5->SetBranchAddress("sumOf_genWeights", &weight);


    Long64_t SM_entries = tree_SM->GetEntries();
    double sumOfWeights_SM = 0;

    for (Long64_t i = 0; i < SM_entries; i++)
    {
        tree_SM->GetEntry(i);
        SM->Fill(cosThetaXStar, weight);
	sumOfWeights_SM += weight;
    }
	SM->SetLineColor(kBlack);

    Long64_t cbwi_p2_entries = treeP->GetEntries();

    double sumOfWeights_cbwi_p2 = 0;

    for (Long64_t i = 0; i < cbwi_p2_entries; i++)
    {
        treeP->GetEntry(i);
        cbwi_p2->Fill(cosThetaXStar, weight);
	sumOfWeights_cbwi_p2 += weight;
    }
    cbwi_p2->SetLineColor(kRed);
   

    Long64_t ctwi_p2_entries = treeM->GetEntries();

    double sumOfWeights_ctwi_p2 = 0;

    for (Long64_t i = 0; i < ctwi_p2_entries; i++)
    {
        treeM->GetEntry(i);
        ctwi_p2->Fill(cosThetaXStar, weight);
	sumOfWeights_ctwi_p2 += weight;
    }
    ctwi_p2->SetLineColor(kBlue);

    Long64_t ctwi_m2_entries = tree_ctwi_m2->GetEntries();

    double sumOfWeights_ctwi_m2 = 0;

    for (Long64_t i = 0; i < ctwi_m2_entries; i++)
    {
        tree_ctwi_m2->GetEntry(i);
        ctwi_m2->Fill(cosThetaXStar, weight);
	sumOfWeights_ctwi_m2 += weight;
    }
    ctwi_m2->SetLineColor(kRed);

    Long64_t cbwi_m2_entries = tree_cbwi_m2->GetEntries();

    double sumOfWeights_cbwi_m2 = 0;

    for (Long64_t i = 0; i < cbwi_m2_entries; i++)
    {
        tree_cbwi_m2->GetEntry(i);
        cbwi_m2->Fill(cosThetaXStar, weight);
	sumOfWeights_cbwi_m2 += weight;
    }
    cbwi_m2->SetLineColor(kGreen);

    Long64_t cptbi_m5_entries = tree_cptbi_m5->GetEntries();

    double sumOfWeights_cptbi_m5 = 0;

    for (Long64_t i = 0; i < cptbi_m5_entries; i++)
    {
        tree_cptbi_m5->GetEntry(i);
        cptbi_m5->Fill(cosThetaXStar, weight);
	sumOfWeights_cptbi_m5 += weight;
    }
    cptbi_m5->SetLineColor(kGreen);

    Long64_t cptbi_p5_entries = tree_cptbi_p5->GetEntries();

    double sumOfWeights_cptbi_p5 = 0;

    for (Long64_t i = 0; i < cptbi_p5_entries; i++)
    {
        tree_cptbi_p5->GetEntry(i);
        cptbi_p5->Fill(cosThetaXStar, weight);
	sumOfWeights_cptbi_p5 += weight;
    }
    cptbi_p5->SetLineColor(kRed);
    
    SM->Scale(1.0 / sumOfWeights_SM);
    cbwi_p2->Scale(1.0 / sumOfWeights_cbwi_p2);
    ctwi_p2->Scale(1.0 / sumOfWeights_ctwi_p2);
    ctwi_m2->Scale(1.0 / sumOfWeights_ctwi_m2);
    cbwi_m2->Scale(1.0 / sumOfWeights_cbwi_m2);
    cptbi_m5->Scale(1.0 / sumOfWeights_cptbi_m5);
    cptbi_p5->Scale(1.0 / sumOfWeights_cptbi_p5);

    TCanvas* canvasX = new TCanvas("canvasX", "Histogram Canvas X", 1200, 800);

    SM->SetStats(kFALSE);
	
    SM->Draw("E");
    //cbwi_p2->Draw("same");
    //ctwi_p2->Draw("same");
    //ctwi_m2->Draw("same");
    //cbwi_m2->Draw("same");
    cptbi_m5->Draw("same");
    cptbi_p5->Draw("same");


    TLegend *legend = new TLegend(0.5, 0.8, 0.7, 0.9);
    legend->AddEntry(SM, "SM");
    //legend->AddEntry(cbwi_p2, "cbwi_p2");
    //legend->AddEntry(ctwi_p2, "ctwi_p2");
    //legend->AddEntry(ctwi_m2, "ctwi_m2");
    //legend->AddEntry(cbwi_m2, "cbwi_m2");
    legend->AddEntry(cptbi_m5, "cptbi_m5");
    legend->AddEntry(cptbi_p5, "cptbi_p5");
    legend->Draw();

    canvasX->SaveAs("GEN_new_cptbi_pm5_cosThetaX*.pdf");

    delete SM;
    delete cbwi_p2;
    delete ctwi_p2;
    delete ctwi_m2;
    delete cbwi_m2;
    delete cptbi_m5;
    delete cptbi_p5;
    input_SM->Close();
    inputP->Close();
    inputM->Close();
    input_ctwi_m2->Close();
    input_cbwi_m2->Close();
    input_cptbi_m5->Close();
    input_cptbi_p5->Close();
}

 
void plotHistogramY()
{
    TH1F* SM = new TH1F("SM", "cosThetaY*", 30, -1.0, 1.0);
    TFile* input_SM = new TFile("bump_new.root", "read");
    TTree* tree_SM = (TTree*)input_SM->Get("GENoutput");

    TH1F* cbwi_p2 = new TH1F("cbwi_p2", "cosThetaY*", 30, -1.0, 1.0);
    TFile* inputP = new TFile("ZW_output_cbwi_p2.root", "read");
    TTree* treeP = (TTree*)inputP->Get("GENoutput");

    TH1F* cbwi_m2 = new TH1F("cbwi_m2", "cosThetaY*", 30, -1.0, 1.0);
    TFile* input_cbwi_m2 = new TFile("ZW_output_cbwi_m2.root", "read");
    TTree* tree_cbwi_m2 = (TTree*)input_cbwi_m2->Get("GENoutput");

    TH1F* ctwi_p2 = new TH1F("ctwi_p2", "cosThetaY*", 30, -1.0, 1.0);
    TFile* inputM = new TFile("ZW_output_ctwi_p2.root", "read");
    TTree* treeM = (TTree*)inputM->Get("GENoutput");

    TH1F* ctwi_m2 = new TH1F("ctwi_m2", "cosThetaY*", 30, -1.0, 1.0);
    TFile* input_ctwi_m2 = new TFile("ZW_output_ctwi_m2.root", "read");
    TTree* tree_ctwi_m2 = (TTree*)input_ctwi_m2->Get("GENoutput");

    TH1F* cptbi_m5 = new TH1F("cptbi_m5", "cosThetaY*", 30, -1.0, 1.0);
    TFile* input_cptbi_m5 = new TFile("output_cptbi_m5.root", "read");
    TTree* tree_cptbi_m5 = (TTree*)input_cptbi_m5->Get("GENoutput");

    TH1F* cptbi_p5 = new TH1F("cptbi_p5", "cosThetaY*", 30, -1.0, 1.0);
    TFile* input_cptbi_p5 = new TFile("output_cptbi_p5.root", "read");
    TTree* tree_cptbi_p5 = (TTree*)input_cptbi_p5->Get("GENoutput");

    float cosThetaYStar;
    double weight;

    tree_SM->SetBranchAddress("cosThetaYStar", &cosThetaYStar);
    tree_SM->SetBranchAddress("sumOf_genWeights", &weight);
    treeP->SetBranchAddress("cosThetaYStar", &cosThetaYStar);
    treeP->SetBranchAddress("sumOf_genWeights", &weight);
    treeM->SetBranchAddress("cosThetaYStar", &cosThetaYStar);
    treeM->SetBranchAddress("sumOf_genWeights", &weight);
    tree_ctwi_m2->SetBranchAddress("cosThetaYStar", &cosThetaYStar);
    tree_ctwi_m2->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cbwi_m2->SetBranchAddress("cosThetaYStar", &cosThetaYStar);
    tree_cbwi_m2->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cptbi_m5->SetBranchAddress("cosThetaYStar", &cosThetaYStar);
    tree_cptbi_m5->SetBranchAddress("sumOf_genWeights", &weight);
    tree_cptbi_p5->SetBranchAddress("cosThetaYStar", &cosThetaYStar);
    tree_cptbi_p5->SetBranchAddress("sumOf_genWeights", &weight);


    Long64_t SM_entries = tree_SM->GetEntries();
    double sumOfWeights_SM = 0;

    for (Long64_t i = 0; i < SM_entries; i++)
    {
        tree_SM->GetEntry(i);
        SM->Fill(cosThetaYStar, weight);
	sumOfWeights_SM += weight;
    }
	SM->SetLineColor(kBlack);

    Long64_t cbwi_p2_entries = treeP->GetEntries();

    double sumOfWeights_cbwi_p2 = 0;

    for (Long64_t i = 0; i < cbwi_p2_entries; i++)
    {
        treeP->GetEntry(i);
        cbwi_p2->Fill(cosThetaYStar, weight);
	sumOfWeights_cbwi_p2 += weight;
    }
    cbwi_p2->SetLineColor(kRed);
   

    Long64_t ctwi_p2_entries = treeM->GetEntries();

    double sumOfWeights_ctwi_p2 = 0;

    for (Long64_t i = 0; i < ctwi_p2_entries; i++)
    {
        treeM->GetEntry(i);
        ctwi_p2->Fill(cosThetaYStar, weight);
	sumOfWeights_ctwi_p2 += weight;
    }
    ctwi_p2->SetLineColor(kBlue);

    Long64_t ctwi_m2_entries = tree_ctwi_m2->GetEntries();

    double sumOfWeights_ctwi_m2 = 0;

    for (Long64_t i = 0; i < ctwi_m2_entries; i++)
    {
        tree_ctwi_m2->GetEntry(i);
        ctwi_m2->Fill(cosThetaYStar, weight);
	sumOfWeights_ctwi_m2 += weight;
    }
    ctwi_m2->SetLineColor(kRed);

    Long64_t cbwi_m2_entries = tree_cbwi_m2->GetEntries();

    double sumOfWeights_cbwi_m2 = 0;

    for (Long64_t i = 0; i < cbwi_m2_entries; i++)
    {
        tree_cbwi_m2->GetEntry(i);
        cbwi_m2->Fill(cosThetaYStar, weight);
	sumOfWeights_cbwi_m2 += weight;
    }
    cbwi_m2->SetLineColor(kGreen);

    Long64_t cptbi_m5_entries = tree_cptbi_m5->GetEntries();

    double sumOfWeights_cptbi_m5 = 0;

    for (Long64_t i = 0; i < cptbi_m5_entries; i++)
    {
        tree_cptbi_m5->GetEntry(i);
        cptbi_m5->Fill(cosThetaYStar, weight);
	sumOfWeights_cptbi_m5 += weight;
    }
    cptbi_m5->SetLineColor(kGreen);

    Long64_t cptbi_p5_entries = tree_cptbi_p5->GetEntries();

    double sumOfWeights_cptbi_p5 = 0;

    for (Long64_t i = 0; i < cptbi_p5_entries; i++)
    {
        tree_cptbi_p5->GetEntry(i);
        cptbi_p5->Fill(cosThetaYStar, weight);
	sumOfWeights_cptbi_p5 += weight;
    }
    cptbi_p5->SetLineColor(kRed);
    
    SM->Scale(1.0 / sumOfWeights_SM);
    cbwi_p2->Scale(1.0 / sumOfWeights_cbwi_p2);
    ctwi_p2->Scale(1.0 / sumOfWeights_ctwi_p2);
    ctwi_m2->Scale(1.0 / sumOfWeights_ctwi_m2);
    cbwi_m2->Scale(1.0 / sumOfWeights_cbwi_m2);
    cptbi_m5->Scale(1.0 / sumOfWeights_cptbi_m5);
    cptbi_p5->Scale(1.0 / sumOfWeights_cptbi_p5);

    TCanvas* canvasY = new TCanvas("canvasY", "Histogram Canvas Y", 1200, 800);

    SM->SetStats(kFALSE);
	
    SM->Draw("E");
    //cbwi_p2->Draw("same");
    //ctwi_p2->Draw("same");
    //ctwi_m2->Draw("same");
    //cbwi_m2->Draw("same");
    cptbi_m5->Draw("same");
    cptbi_p5->Draw("same");


    TLegend *legend = new TLegend(0.3, 0.8, 0.5, 0.9);
    legend->AddEntry(SM, "SM");
    //legend->AddEntry(cbwi_p2, "cbwi_p2");
    //legend->AddEntry(ctwi_p2, "ctwi_p2");
    //legend->AddEntry(ctwi_m2, "ctwi_m2");
    //legend->AddEntry(cbwi_m2, "cbwi_m2");
    legend->AddEntry(cptbi_m5, "cptbi_m5");
    legend->AddEntry(cptbi_p5, "cptbi_p5");
    legend->Draw();

    canvasY->SaveAs("GEN_new_cptbi_pm5_cosThetaY*.pdf");

    delete SM;
    delete cbwi_p2;
    delete ctwi_p2;
    delete ctwi_m2;
    delete cbwi_m2;
    delete cptbi_m5;
    delete cptbi_p5;
    input_SM->Close();
    inputP->Close();
    inputM->Close();
    input_ctwi_m2->Close();
    input_cbwi_m2->Close();
    input_cptbi_m5->Close();
    input_cptbi_p5->Close();
}
int main()
{
    plotHistogramZ();
    plotHistogramX();
    plotHistogramY();
    return 0;
}
