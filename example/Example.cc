#include "TROOT.h"
#include "TFile.h"
#include "../src/HitTracks.C"

int Example(TString filename_in, Long64_t nentries=10){

  cout<<" Display of file: "<<filename_in<<endl;
  HitTracks ht(filename_in,"HitTracks");

  cout<<"Start NSlabsNAalysis"<<endl;
  ht.SimpleExample(nentries);
  return 1;

}
