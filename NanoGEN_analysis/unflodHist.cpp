#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include "RooUnfold.h"
#include "RooUnfoldResponse.h"

void plotHistogramZ()
{
    TH1F* h1 = new TH1F("h1", "cosThetaZ*", 30, -1.0, 1.0);

    TFile* input = new TFile("test.root", "read");
    TTree* tree = (TTree*)input->Get("LHE");

    float cosThetaZStar;

    tree->SetBranchAddress("cosThetaZStar", &cosThetaZStar);

    Long64_t num_entries = tree->GetEntries();

      const int nbins = 30;
  const double xmin = -1.0;
  const double xmax = 1.0;

  RooUnfoldResponse response(nbins, xmin, xmax);

    for (Long64_t i = 0; i < num_entries; i++)
    {
        tree->GetEntry(i);
        h1->Fill(cosThetaZStar);
	response.Fill(cosThetaZStar);
    }

    h1->GetXaxis()->SetTitle("cosThetaZ*");
    h1->GetYaxis()->SetTitle("NbrOfEvent");

    TCanvas* canvasZ = new TCanvas("canvasZ", "Histogram Canvas Z", 1200, 800);
    h1->Draw("E");

    canvasZ->SaveAs("cosThetaZ*.pdf");

	 // Define the unfolding object
  RooUnfoldSvd unfold(&response, h1, 4);

  // Perform the unfolding
  TH1F* h_unfolded = (TH1F*)unfold.Hreco();

  // Print the unfolded distribution
  std::cout << "Unfolded distribution:" << std::endl;
  h_unfolded->Print("all");


    delete h1;
    input->Close();
}

void plotHistogramX()
{
    TH1F* h1 = new TH1F("h1", "cosThetaX*", 30, -1.0, 1.0);

    TFile* input = new TFile("test.root", "read");
    TTree* tree = (TTree*)input->Get("LHE");

    float cosThetaXStar;

    tree->SetBranchAddress("cosThetaXStar", &cosThetaXStar);

    Long64_t num_entries = tree->GetEntries();

    for (Long64_t i = 0; i < num_entries; i++)
    {
        tree->GetEntry(i);
        h1->Fill(cosThetaXStar);
    }

    h1->GetXaxis()->SetTitle("cosThetaX*");
    h1->GetYaxis()->SetTitle("NbrOfEvent");

    TCanvas* canvasX = new TCanvas("canvasX", "Histogram Canvas X", 1200, 800);
    h1->Draw("E");

    canvasX->SaveAs("cosThetaX*.pdf");

    delete h1;
    input->Close();
}

void plotHistogramY()
{
    TH1F* h1 = new TH1F("h1", "cosThetaY*", 30, -1.0, 1.0);

    TFile* input = new TFile("test.root", "read");
    TTree* tree = (TTree*)input->Get("LHE");

    float cosThetaYStar;

    tree->SetBranchAddress("cosThetaYStar", &cosThetaYStar);

    Long64_t num_entries = tree->GetEntries();

    for (Long64_t i = 0; i < num_entries; i++)
    {
        tree->GetEntry(i);
        h1->Fill(cosThetaYStar);
    }

    h1->GetXaxis()->SetTitle("cosThetaY*");
    h1->GetYaxis()->SetTitle("NbrOfEvent");

    TCanvas* canvasY = new TCanvas("canvasY", "Histogram Canvas Y", 1200, 800);
    h1->Draw("E");

    canvasY->SaveAs("cosThetaY*.pdf");

    delete h1;
    input->Close();
}

int main()
{
    plotHistogramZ();
    plotHistogramX();
    plotHistogramY();
    return 0;
}
