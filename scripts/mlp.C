void mlp(Int_t ntrain=100){
	if(!gROOT->GetClass("TMultiLayerPerceptron")){
		gSystem->Load("libMLP");
	}

	// Prepare inputs
	// The 2 trees are merged into one, and a "type" branch,
	// equal to 1 for signal and 0 for the background is added

	const char *f_sig = "../data/MC_1.root";
	const char *f_bckg = "..//data/RxOff.root";

	TFile *in_sig = TFile::Open(f_sig);
	TFile *in_bckg = TFile::Open(f_bckg);

	TTree *signal = (TTree *) in_sig->Get("Tibd");
   	TTree *background = (TTree *) in_bckg->Get("Tibd");
   	TTree *simu = new TTree("MonteCarlo", "Filtered Monte Carlo Events");
   	
   	Float_t Encapt, ncapt_dt, dr, E;
   	Float_t xyz[3];
   	Float_t n_xyz[3];
   	Int_t type;
   	signal->SetBranchAddress("Encapt", &Encapt);
   	signal->SetBranchAddress("ncapt_dt",  &ncapt_dt);
   	signal->SetBranchAddress("dr",    &dr);
   	signal->SetBranchAddress("E", &E);
   	signal->SetBranchAddress("xyz", xyz);
   	signal->SetBranchAddress("n_xyz", n_xyz);
   	background->SetBranchAddress("Encapt", &Encapt);
   	background->SetBranchAddress("ncapt_dt",  &ncapt_dt);
   	background->SetBranchAddress("dr",    &dr);
   	background->SetBranchAddress("E", &E);
   	background->SetBranchAddress("xyz", xyz);
   	background->SetBranchAddress("n_xyz", n_xyz);

   	simu->Branch("Encapt", &Encapt, "Encapt/F");
   	simu->Branch("ncapt_dt",  &ncapt_dt,  "ncapt_dt/F");
   	simu->Branch("dr",    &dr,    "dr/F");
   	simu->Branch("E", &E, "E/F");
   	simu->Branch("xyz", xyz, "E/F");
   	simu->Branch("n_xyz", n_xyz, "E/F");
   	simu->Branch("type", &type, "type/I");
 
   	type = 1;
  	Int_t i;
   	for (i = 0; i < signal->GetEntries(); i++) {
      signal->GetEntry(i);
      simu->Fill();
   	}
   	type = 0;
   	for (i = 0; i < background->GetEntries(); i++) {
      background->GetEntry(i);
      simu->Fill();
   	}
   // Build and train the NN ptsumf is used as a weight since we are primarly
   // interested  by high pt events.
   // The datasets used here are the same as the default ones.
   TMultiLayerPerceptron *mlp =
      //new TMultiLayerPerceptron("@Encapt,@ncapt_dt,@dr:5:3:type",
      new TMultiLayerPerceptron("@Encapt,@ncapt_dt,@E:5:3:type",
                                 simu,"Entry$%2","(Entry$+1)%2");
   mlp->Train(ntrain, "text,graph,update=10");
   //mlp->Export("test","python");
   mlp->Export("test");

   // Use TMLPAnalyzer to see what it looks for
   TCanvas* mlpa_canvas = new TCanvas("mlpa_canvas","Network analysis");
   mlpa_canvas->Divide(2,2);
   TMLPAnalyzer ana(mlp);
   // Initialisation
   ana.GatherInformations();
   // output to the console
   ana.CheckNetwork();
   mlpa_canvas->cd(1);
   // shows how each variable influences the network
   ana.DrawDInputs();
   mlpa_canvas->cd(2);
   // shows the network structure
   mlp->Draw();
   mlpa_canvas->cd(3);
   // draws the resulting network
   ana.DrawNetwork(0,"type==1","type==0");
   mlpa_canvas->cd(4);
   // Use the NN to plot the results for each sample
   // This will give approx. the same result as DrawNetwork.
   // All entries are used, while DrawNetwork focuses on
   // the test sample. Also the xaxis range is manually set.
   TH1F *bg = new TH1F("bgh", "NN output", 50, -.5, 1.5);
   TH1F *sig = new TH1F("sigh", "NN output", 50, -.5, 1.5);
   bg->SetDirectory(0);
   sig->SetDirectory(0);
   Double_t params[3];
   for (i = 0; i < background->GetEntries(); i++) {
      background->GetEntry(i);
      params[0] = Encapt;
      params[1] = ncapt_dt;
      //params[2] = xyz[2];
      params[2] = E;
      bg->Fill(mlp->Evaluate(0, params));
   }
   for (i = 0; i < signal->GetEntries(); i++) {
      signal->GetEntry(i);
      params[0] = Encapt;
      params[1] = ncapt_dt;
      //params[2] = xyz[2];
      params[2] = E;
      sig->Fill(mlp->Evaluate(0,params));
   }
   bg->SetLineColor(kBlue);
   bg->SetFillStyle(3008);   bg->SetFillColor(kBlue);
   sig->SetLineColor(kRed);
   sig->SetFillStyle(3003); sig->SetFillColor(kRed);
   bg->SetStats(0);
   sig->SetStats(0);
   bg->Draw();
   sig->Draw("same");
   TLegend *legend = new TLegend(.75, .80, .95, .95);
   legend->AddEntry(bg, "Background");
   legend->AddEntry(sig, "Signal");
   legend->Draw();
   mlpa_canvas->cd(0);

   delete in_bckg;
   delete in_sig;
}