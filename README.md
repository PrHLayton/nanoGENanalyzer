This is a simple C++, python and bash framework to create, analyze and skim root files created with MG5.
It was designed to analyzed collision events simulations at LHE and GEN level.

The main analyzer is located in the folder NanoGEN_analysis.

It has 3 scriptsL

pyPlotter.py:

This script defines a function `pyPlotter()` that generates plots of one-dimensional histograms using data from ROOT trees. The function takes two arguments, `variablesToPlot` and `outputFolder`, which specify the variables to be plotted and the folder where the plots will be saved, respectively.

The `variablesToPlot` dictionary contains keys that correspond to the variables to be plotted, and each key contains a list with two elements: a list of histogram configurations and a list of samples to be combined in the histogram. The histogram configurations specify the histogram name, number of bins, bin range, and legend label. The sample list contains tuples with the sample label, ROOT file name, tree name, weight name, and line color.

The function loops over the `variablesToPlot` dictionary and for each variable, it creates a `TCanvas` and a `TLegend` object. Then, it loops over the samples for the variable and creates a `RDataFrame` object from the sample's ROOT tree. It then creates a 1D histogram using the `Histo1D()` method of the `RDataFrame` object with the specified histogram configurations and sample weight. The histogram is then styled with a line color and width and added to the legend. The maximum Y value of the histogram is recorded to scale the Y-axis later. If the `normalize` flag is set to `True`, the histogram is normalized and the Y-axis range is set to the maximum Y value. Otherwise, the Y-axis range is set to 30% above the maximum Y value. The histogram is then drawn on the canvas with the legend entry. Finally, the canvas is saved to a PNG file in the specified output folder.

The script also defines a list `rootSamples` that contains the ROOT file names, tree names, weight names, and line colors for the samples used in the `variablesToPlot` dictionary. The variables to plot include the deltaR between the lepton and b-quark and between the lepton and spectator quark, the PhiStar variable, and the cosThetaStar variable.

NanoGENanalyzer.cpp + NanoGENanalyzer.h:

This two files loop over the events generated with MG5 and Pythia8 to select single top t-channel events (final state composed of 1 lepton, 1 neutrino, 2 quraks with one being a b quark).
Then it applies several cuts on the different final state objects in order to mimic the detector response.

From the selected objects a reconstruction of the top quark is performed by using algorithms encoded into functions inside the header.
From the reconstructed top we perform a TLorentz boost into the top quark resting frame and save several CP sensitive angle values into histogram on an output root file.

How to run it:

Load the script into a root session:
$ .L NanoGENanalyzer.cpp 

Execute the analyzer with the right input and ouput files: (the output file is specified in the script; the input file is defined during execution command)
$ NanoGENanalyzer("pwd_to_input_file").Loop()

