Here's an improved version of the README file:

## Introduction

This is a framework designed to analyze collision event simulations at LHE and GEN level, created with MG5. It provides a set of C++, Python, and Bash scripts that can be used to analyze, skim, and plot data from ROOT files.

## Structure

The main analyzer is located in the `NanoGEN_analysis` folder. It contains two files, `NanoGENanalyzer.cpp` and `NanoGENanalyzer.h`, which loop over the events generated with MG5 and Pythia8 to select single top t-channel events with a final state composed of 1 lepton, 1 neutrino, and 2 quarks, one of which is a b quark. Then, it applies several cuts on the different final state objects to mimic the detector response. From the selected objects, a reconstruction of the top quark is performed using algorithms encoded into functions inside the header file. From the reconstructed top quark, several CP-sensitive angle values are saved into histograms on an output ROOT file.

In addition to the analyzer, the framework includes a Python script, `pyPlotter.py`, that generates one-dimensional histograms using data from ROOT trees. The script defines a function, `pyPlotter()`, that takes two arguments: `variablesToPlot` and `outputFolder`, which specify the variables to be plotted and the folder where the plots will be saved, respectively.

The `variablesToPlot` dictionary contains keys that correspond to the variables to be plotted, and each key contains a list with two elements: a list of histogram configurations and a list of samples to be combined in the histogram. The histogram configurations specify the histogram name, number of bins, bin range, and legend label. The sample list contains tuples with the sample label, ROOT file name, tree name, weight name, and line color.

The `pyPlotter()` function loops over the `variablesToPlot` dictionary, creates a `TCanvas` and a `TLegend` object for each variable, and loops over the samples for the variable. It then creates a `RDataFrame` object from the sample's ROOT tree and creates a 1D histogram using the `Histo1D()` method of the `RDataFrame` object with the specified histogram configurations and sample weight. The histogram is then styled with a line color and width and added to the legend. The maximum Y value of the histogram is recorded to scale the Y-axis later. If the normalize flag is set to True, the histogram is normalized and the Y-axis range is set to the maximum Y value. Otherwise, the Y-axis range is set to 30% above the maximum Y value. The histogram is then drawn on the canvas with the legend entry. Finally, the canvas is saved to a PNG file in the specified output folder.

## Usage

To use the framework, first load the analyzer script into a ROOT session:

```
$ .L NanoGENanalyzer.cpp
```

Then, execute the analyzer with the right input and output files. The output file is specified in the script, while the input file is defined during execution command:

```
$ NanoGENanalyzer("path/to/input_file").Loop()
```

To use the `pyPlotter.py` script, simply import the `pyPlotter()` function into your Python script and call it with the appropriate arguments:

```
python pyPlotter.py
```