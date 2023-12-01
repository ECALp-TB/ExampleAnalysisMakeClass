//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Dec  1 17:19:08 2023 by ROOT version 6.28/06
// from TTree HitTracks/TB22 Slim Hits & Tracks
// found on file: ../../data/calice-c75_pdhbp.root
//////////////////////////////////////////////////////////

#ifndef HitTracks_h
#define HitTracks_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class HitTracks {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Short_t         runid;
   Long64_t        eventid;
   Short_t         planeid;
   Short_t         pad_num;
   Short_t         x_pad[101];   //[pad_num]
   Short_t         y_pad[101];   //[pad_num]
   Short_t         adc[101];   //[pad_num]
   Short_t         track_num;
   Double_t        x_stl[10];   //[track_num]
   Double_t        y_stl[10];   //[track_num]
   Double_t        ux_stl[10];   //[track_num]
   Double_t        uy_stl[10];   //[track_num]
   Double_t        chi2ndof;

   // List of branches
   TBranch        *b_RunId;   //!
   TBranch        *b_TluId;   //!
   TBranch        *b_PlaneId;   //!
   TBranch        *b_pad_num;   //!
   TBranch        *b_x_pad;   //!
   TBranch        *b_y_pad;   //!
   TBranch        *b_adc;   //!
   TBranch        *b_track_num;   //!
   TBranch        *b_x_stl;   //!
   TBranch        *b_y_stl;   //!
   TBranch        *b_ux_stl;   //!
   TBranch        *b_uy_stl;   //!
   TBranch        *b_Chi2_over_DoF;   //!

   HitTracks(TString tree_s, TString treename);
   virtual ~HitTracks();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual void     SimpleExample(Long64_t nentries);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HitTracks_cxx
HitTracks::HitTracks(TString tree_s, TString treename="HitTracks") : fChain(0) 
{

   cout<<tree_s<<endl;
   TFile *f = new TFile(tree_s);
   TTree *tree = (TTree*)f->Get(treename);
   //  tree->Print();                                                                                                                                                                                       
   Init(tree);
}

HitTracks::~HitTracks()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HitTracks::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HitTracks::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HitTracks::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runid", &runid, &b_RunId);
   fChain->SetBranchAddress("eventid", &eventid, &b_TluId);
   fChain->SetBranchAddress("planeid", &planeid, &b_PlaneId);
   fChain->SetBranchAddress("pad_num", &pad_num, &b_pad_num);
   fChain->SetBranchAddress("x_pad", x_pad, &b_x_pad);
   fChain->SetBranchAddress("y_pad", y_pad, &b_y_pad);
   fChain->SetBranchAddress("adc", adc, &b_adc);
   fChain->SetBranchAddress("track_num", &track_num, &b_track_num);
   fChain->SetBranchAddress("x_stl", x_stl, &b_x_stl);
   fChain->SetBranchAddress("y_stl", y_stl, &b_y_stl);
   fChain->SetBranchAddress("ux_stl", ux_stl, &b_ux_stl);
   fChain->SetBranchAddress("uy_stl", uy_stl, &b_uy_stl);
   fChain->SetBranchAddress("chi2ndof", &chi2ndof, &b_Chi2_over_DoF);
   Notify();
}

Bool_t HitTracks::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HitTracks::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HitTracks::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HitTracks_cxx
