#include "TSystem.h"
#include <string>

void mergeFiles(){

	const char* ftype = "MC";
	const char* dir = "/home/andrea/P2x-output/MC/";

	void* dirp = gSystem->OpenDirectory(dir);

	const char* entry;
	const char* filename[100];
	Int_t n = 0;
	TString str;

	while((entry = (char*)gSystem->GetDirEntry(dirp))) {
    	str = entry;
      	filename[n++] = gSystem->ConcatFileName(dir, entry);
  	}

	for (Int_t i = 0; i < n; i++){

		TFile *input;
		TString fname = gSystem->ConcatFileName(filename[i],"AD1_IBD_2020.root");
    	if (!gSystem->AccessPathName( fname )) {
       		std::cout << "filename: " << fname << std::endl;
       		input = TFile::Open( fname ); // check if file in local directory exists
       		TTree *oldtree;
   			input->GetObject("P2kIBDPlugin/Tibd", oldtree);
   			// Activate only four of them
   			for (auto activeBranchName : {"t_abs", "E", "Encapt", "xyz", "E_adjacent", "ncapt_dt", "n_xyz", "rxpwr"}) {
      			oldtree->SetBranchStatus(activeBranchName, 1);
   			}
   			// Create a new file + a clone of old tree header. Do not copy events
   			string outname = "../data/MC_" + std::to_string(i) + ".root";
   			TFile newfile(outname.c_str(), "recreate");
   			auto newtree = oldtree->CloneTree(0);

			newtree->CopyEntries(oldtree);

			Float_t xyz[5];
			Float_t n_xyz[5];
			Float_t dr;

			TBranch *bdr = newtree->Branch("dr", &dr, "dr/F");
			newtree->SetBranchAddress("xyz", xyz);
			newtree->SetBranchAddress("n_xyz", n_xyz);
			Long64_t nentries= newtree->GetEntries();

			for(Long64_t i=0; i<nentries; i++){
				newtree->GetEntry(i);
				Double_t xydist = pow(xyz[0]-n_xyz[0],2) + pow(xyz[1]-n_xyz[1],2);
				dr = xydist + + pow(xyz[2]-n_xyz[2],2);
				bdr->Fill();
			}

   			//newtree->Print();
   			newfile.Write();
   			
   			//std::cout << "outname: " << outname << std::endl;
    	}
		else{
			std::cout << "Wrong filename..." <<std::endl;
    	}

	}
}