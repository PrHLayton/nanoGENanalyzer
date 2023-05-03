import ROOT
from ROOT import *
from ROOT import RDataFrame
import numpy as np


def pyPlotter(variablesToPlot, outputFolder):

    df = dict()
    hists = dict()

    for variable in variablesToPlot:

        samplesToCombine = dict()
        sampleTreeName = []
        sampleWeightName = []
        sampleColor = []

        histoConfigs = variablesToPlot[variable][0]

        for sample in variablesToPlot[variable][1]:

            label = sample[0]
            if label not in samplesToCombine:
                samplesToCombine[label] = []
                samplesToCombine[label].append(sample[1])
                sampleTreeName.append(sample[2])
                sampleWeightName.append(sample[3])
                sampleColor.append(sample[4])
            else: 
                samplesToCombine[label].append(sample[1])

        i = 0

        c1 = TCanvas('c1', 'c1', 1200,1200)
        legend1 = TLegend(0.7, 0.7, 0.99, 0.99, histoConfigs[4])
        tmpMax = 0.0

        for key in samplesToCombine:

            c1.cd()

            df[key] = RDataFrame(sampleTreeName[i], samplesToCombine[key])
            hists[key] = df[key].Histo1D((histoConfigs[0] + '_' + str(i), '', histoConfigs[1], histoConfigs[2], histoConfigs[3]), variable, sampleWeightName[i])
            
            hists[key].SetStats(kFALSE)
            hists[key].SetLineColor(sampleColor[i])
            hists[key].SetLineWidth(2)

            maximumY = hists[key].GetMaximum()
            if maximumY > tmpMax:
                tmpMax = maximumY
            
            if normalize:
                hists[key].Scale(1/hists[key].Integral())
                hists[key].SetAxisRange(0, tmpMax,'Y')
            else:
                hists[key].SetAxisRange(0, tmpMax*1.3,'Y')

            if i == 0:
                hists[key].Draw()
                hists[key].SetXTitle(histoConfigs[0])
            else:
                hists[key].Draw('SAME')
            legend1.AddEntry(hists[key].GetName(), str(key), 'l')

            
            print(f'Drawing: {histoConfigs[0]} for sample: {str(key)} in {str(sampleColor[i])}')
            i += 1
            

        legend1.Draw()
        c1.Update()
        outfileName = outputFolder + variable + '.png'
        if normalize: outfileName = outputFolder + variable + '_normalized.png'
        c1.Print(outfileName)
        c1.Close()
        # break
        

normalize = True
outputFolder = 'plots/nocuts/'
inputPWD = '/gridgroup/cms/greenberg/pheno/CMSSW_10_6_27/src/NanoGEN/NanoGEN_analysis/output/noCutsOnDeltaR/GENlevel/'


rootSamples = [

    [
        
        'MG5 (dim6top)',
        inputPWD + 'output_MG5sample_ST_t_channel_top_and_antitop_SM_atLO_LHE_NanoGEN_dim6top_model.root',
        'GENoutput',
        'GENweight',
        kGreen,

    ],

    [
        
        'MG5 (sm-no_b_mass)',
        inputPWD + 'output_MG5sample_ST_t_channel_top_and_antitop_SM_atLO_LHE_NanoGEN_sm-no_b_mass_model.root',
        'GENoutput',
        'GENweight',
        kRed,
        
    ],

    [

        'Powheg',
        inputPWD + 'output_POWHEGsample_ST_t_channel_top_SM_atNLO_LHE_NanoGEN.root',
        'GENoutput',
        'GENweight',
        kBlue,
        
    ],

    [

        'Powheg',
        inputPWD + 'output_POWHEGsample_ST_t_channel_antitop_SM_atNLO_LHE_NanoGEN.root',
        'GENoutput',
        'GENweight',
        kBlue,

    ],
]

variablesToPlot = {

    'deltaR_lepton_bQuark_GENlevel' : [

        ['DeltaR (lepton/b_Quark)', 60, 0 ,6, 'GENlevel nocut'],

        rootSamples,
    ],

    'deltaR_lepton_specQ_GENlevel' : [

        ['DeltaR (lepton/spec_Quark)', 60, 0 , 6, 'GENlevel nocut'],

        rootSamples,

    ],

    'PhiStar' : [

        ['PhiStar', 60, 0, 2*np.pi, 'GENlevel nocut'],

        rootSamples,

    ],

    'cosThetaStar' : [

        ['cos(#theta*)', 60, -1, 1, 'GENlevel nocut'],

        rootSamples,

    ],

}

pyPlotter(variablesToPlot, outputFolder)
