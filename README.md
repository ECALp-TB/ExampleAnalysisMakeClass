# ExampleAnalysisMakeClass
This is a simple example of an analysis using the root MakeClass method and the root-files with sensor-telescope alignment performed by Shan before Dec 2023

## Based on the MakeClass method...

Check 14.21 in https://root.cern.ch/root/htmldoc/guides/users-guide/Trees.html

* is this too old school?... check the RDataFrame tutorials to get used to newer methods!!
  * https://root.cern/doc/master/classROOT_1_1RDataFrame.html
 
## Creating the code

### 1 Creating the skeleton code

* You should have access to a root file with a calo-sensor and the telescope data as in the format provided by Shan in November 2023 (manual alignment)
  * In my case, this file is ../../../TB2022/data/calice-c75.root
* Open this file and create the class skeletons

> root -l ../../../TB2022/data/calice-c75.root
> HitTracks->MakeClass("HitTracks")
> .q

* copy HitClass.C in the src/folder
* and HitClass.h in the include/folder

Finally, you should modify the files:

in **HitClass.C**
>change #include "HitTracks.h" by #include "../include/HitTracks.h"

in **HitClass.h**
> edit the HitTracks::HitTracks function such that it is:

> HitTracks::HitTracks(TString tree_s, TString treename="HitTracks") : fChain(0) 
> {

>   cout<<tree_s<<endl;
>   TFile *f = new TFile(tree_s);
>   TTree *tree = (TTree*)f->Get(treename);
>   //  tree->Print();                                                                                                                                                                                       
>   Init(tree);
> }

Also change the definition of such function (line 54) to
>  HitTracks(TString tree_s, TString treename);

### 2 Creating an example function

Define in HitTracks.h and HitTracks.C a function as in the example
https://github.com/ECALp-TB/ExampleAnalysisMakeClass/blob/4ed7df7175e65edc2a17c6a25a59bbf30dfdf640/src/HitTracks.C#L46C1-L46C1
https://github.com/ECALp-TB/ExampleAnalysisMakeClass/blob/4ed7df7175e65edc2a17c6a25a59bbf30dfdf640/include/HitTracks.h#L61

### 3 Create the macros to run the examples

Check the the folder examples/
https://github.com/ECALp-TB/ExampleAnalysisMakeClass/blob/1d922ed6f4f43abab4ef8eff8ee9cad79f99814c/example/Example.cc#L1

This function simply loades the class HitTracks and uses their methods. In this way it is very straightforward to use scripts to run the analysis.
This is will become very handy whenever you are required to perform several analysis (or several runs or define many different functions).

### 4 Run the examples

You can run directly the "Example.cc" with root
> root -l Example.cc
It will complain and say that arguments are missing, for that you pass the the arguments as input
> root -l Example.cc\("fullpath_to_filename.root",10\)
can be 10 or whatever integer...

Examples of how to run this are in example.sh

> source example.sh

### 5 Run using condor_ht (parallel jobs)

You can run the Example.cc scripts in a farm managed by condor, using the example_condor.sh

> source example_condor.sh "../../../TB2022/data/calice-c75.root" 10

Of course, this particular example does nothing since we are only writing the result in terminal but this job is not running in our interface but in a remote core.
To check that the script has run successfully, you can check the recently created folder log/
For example, the file: ls log/outfile_test_condor.txt 

More info on condor_ht https://htcondor.readthedocs.io/en/latest/users-manual/quick-start-guide.html


