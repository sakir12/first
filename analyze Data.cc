
#include <TStyle.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include "Event.h"
#include <TMVA/Reader.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TH2D.h>
#include <string>
#include <THStack.h>
#include <TLeaf.h>



int main() {

  gStyle->SetOptStat(111111);

// Set up an output file and book some histograms

  TFile* histFile = new TFile("analysis.root", "RECREATE");
    TH1D* hBDTSig = new TH1D("hBDTSig", "BDT, signal", 100, -10., 10.);
     TH1D* hBDTBkg = new TH1D("BDTBkg", "BDT, background", 100, -10., 10.);
  // create 2D histograms to fill BDT vs signal and background variables
  
 
 TH2D* BDT_fill  = new TH2D("BDT_fill", " BDTvs Fill",50,-3,3,50,0,100000);
  TH2D* BDT_COM_Pt  = new TH2D(" BDT_COM_Pt", " BDTvs COM_Pt",50,-3,3,50,0,100000);
  TH2D* BDT_jet_ETA  = new TH2D(" BDT_jet_ETA", " BDTvs jet_ETA",50,-3,3,50,-5,5);			    
  TH2D* BDT_jet_PHI  = new TH2D(" BDT_jet_PHI", " BDTvs jet_PHI",50,-3,3,50,0,5);
  TH2D* BDT_njet_20  = new TH2D("BDT_njet_20", " BDTvs njet_20",50,-3,3,50,0,10);
  TH2D* BDT_njet_40  = new TH2D("BDT_njet_40", " BDTvs njet_20",50,-3,3,50,0,10);
  TH2D* BDT_jet1ET  = new TH2D("  BDT_jet1ET", " BDTvs jet1ET ",50,-3,3,50,0,1000000);
  TH2D* BDT_jet2ET  = new TH2D("  BDT_jet2ET", " BDTvs jet2ET ",50,-3,3,50,0,100000);
  TH2D* BDT_jet1PT  = new TH2D("  BDT_jet1PT", " BDTvs jet1PT ", 50,-3,3,50,0,100000);
  //  TH2D* BDT_jetETPT  = new TH2D("  BDT_jetETPT", " BDTvs jetETPT ", 50,-3,3,50,0,10);
  TH2D* BDT_n_lep20  = new TH2D("BDT_n_lep20,"," BDTvs n_lep20",50,-3,3,50,0,5);
  TH2D* BDT_delPHI12  = new TH2D("BDT_delPHI12", " BDTvs delPHI12",50,-3,3,50,-5,5);
  TH2D* BDT_met  = new TH2D("  BDT_met", " BDTvs met ", 50,-3,3,50,0,400000);
  TH2D* BDT_delr12  = new TH2D("BDT_delr12", " BDTvs delr12",50,-3,3,50,-5,5);
  TH2D* BDT_jet1M  = new TH2D("  BDT_jet1M", " BDTvs jet1M ",50,-3,3,50,0,100000);

  TH2D* BDT_filltt  = new TH2D("BDT_filltt","BDTvs filltt",50,-3,3,50,0,100000);
  TH2D* BDT_COM_Pt_tt  = new TH2D(" BDT_COM_Pt_tt", " BDTvs COM_Pt_tt",50,-3,3,50,0,100000);
  TH2D* BDT_jet_ETAtt  = new TH2D(" BDT_jet_ETAtt", " BDTvs jet_ETAtt",50,-3,3,50,-5,5);
  TH2D* BDT_jet_PHItt  = new TH2D(" BDT_jet_PHItt", " BDTvs jet_PHItt",50,-3,3,50,0,5);
  TH2D* BDT_njet_20tt  = new TH2D("BDT_njet_20tt,", " BDTvs njet_20tt",50,-3,3,50,0,10);
  TH2D* BDT_njet_40tt  = new TH2D("BDT_njet_40tt,", " BDTvs njet_20tt",50,-3,3,50,0,10);
  TH2D* BDT_jet1ETtt  = new TH2D("  BDT_jet1ETtt", " BDTvs jet1ETtt",50,-3,3,50,0,100000);
  TH2D* BDT_jet2ETtt  = new TH2D("  BDT_jet2ETtt", " BDTvs jet2ETtt ",50,-3,3,50,0,100000);
  TH2D* BDT_jet1PTtt  = new TH2D("  BDT_jet1PTtt", " BDTvs jet1PTtt", 50,-3,3,50,0,100000);
  TH2D* BDT_n_lep20tt  = new TH2D("BDT_n_lep20tt", " BDTvs n_lep20tt",50,-3,3,50,0,5);
  TH2D* BDT_delPHI12tt  = new TH2D("BDT_delPHI12tt", " BDTvs delPHI12tt",50,-3,3,50,-5,5);
  TH2D* BDT_met_tt  = new TH2D("  BDT_met_tt"," BDTvs met_tt ", 50,-3,3,50,0,400000);
  TH2D* BDT_delr12tt  = new TH2D("BDT_delr12tt", " BDTvs delr12tt",50,-3,3,50,-5,5);
  TH2D* BDT_jet1Mtt = new TH2D("  BDT_jet1M_tt"," BDTvs jet1M_tt ",50,-3,3,50,0,100000);
  
  //create histograms in a vector in orrder of variables 1 to 16 1=fill

  //use Tstring to create TString integer
  
  //  std::vector<TH2D> BDT;
  // create vector to stor values of nbins argument of histogram
    std::vector<int> nbins;
  for(unsigned int n0 = 0 ; n0<15; n0++){
    nbins.push_back(100);
}


  std::vector<int> xmax;

  

    
  
      xmax.push_back(1000000); xmax.push_back(100000);
    
   xmax.push_back(5);   xmax.push_back(5);
    
    xmax.push_back(10); xmax.push_back(10);
    
  xmax.push_back(1000000); xmax.push_back(100000);  xmax.push_back(100000);
  //  xmax.push_back(10);
    xmax.push_back(5); 
 xmax.push_back(5);
    
     xmax.push_back(400000);
    
     xmax.push_back(5);
    

     xmax.push_back(100000);   xmax.push_back(100000);





  std::vector<int> xmin;

    xmin.push_back(0);  xmin.push_back(0);
     xmin.push_back(-5);
     xmin.push_back(0); xmin.push_back(0); xmin.push_back(0); xmin.push_back(0); xmin.push_back(0);
      xmin.push_back(0);
 xmin.push_back(0);

 xmin.push_back(-5);  xmin.push_back(0);   xmin.push_back(-5);  xmin.push_back(0);  xmin.push_back(0);
    
  






  std::vector<std::string> histname;
  std::vector<std::string> BDT_name;
   for(unsigned int h0 =0; h0<70; h0++){
     BDT_name.push_back("BDT_");

   }
   
  
   std::vector<std::string> name;/*  std::vector<string> COM_Ptname;  std::vector<string> jet_ETAname; std::vector<string> jet_PHIname; 
   std::vector<string> njet_20name; std::vector<string> njet_40name; std::vector<string> jet1ETname; std::vector<string> jet2ETname; 
   std::vector<string> jet1PTAname; std::vector<string> jet1Mname; std::vector<string> n_lep20name; std::vector<string> delPHI12name;
   std::vector<string> delr12name; std::vector<string> metname;   
				 */

   



	
	

		   name.push_back("fillm");	
		   name.push_back("COM_Pt");		  
		   name.push_back("jet_ETA");

		   name.push_back("jet_PHI");
		   name.push_back("njet_20");
		   name.push_back("njet_40");
		   name.push_back("jet1ET");
		   name.push_back("jet2ET");
		   name.push_back("jet1PT");
		   //		   name.push_back("jetETPT");
		   name.push_back("n_lep20");
	   name.push_back("delPHI12");
           name.push_back("met");
	   name.push_back("delr12");
	   name.push_back("jet1M");
	   name.push_back("COM_Pt_lep");


	   std::vector<std::string> units;


	   units.push_back("GeV");  units.push_back("GeV");  units.push_back("eta");   units.push_back("phi");  units.push_back(" ");  units.push_back("");   units.push_back("GeV"); units.push_back("GeV"); units.push_back("GeV");  units.push_back("");  units.push_back("phi");   units.push_back("GeV");  units.push_back("");   units.push_back("GeV");  units.push_back("GeV");   

   
   
                           std::vector<std::string> namef;
	      
/*		      for(unsigned int nj= 0; nj<14; nj++){
     for(unsigned int ni= 0; ni<14; ni++){
     


       if(nj==0){
	 namef.push_back("");
       }  
      
       else if(nj==1){
	 namef.push_back("COM_Pt");
       }
       else if(nj==2){
	 namef.push_back("jet_ETA");
       }
       else if(nj==3){
	 namef.push_back("jet_PHI");
       }
       else if(nj==4){
	 namef.push_back("njet_20");
       }
       else if(nj==5){
	 namef.push_back("njet_40");
       }
       else if(nj==6){
	 namef.push_back("jet1ET");
       }
       else if(nj==7){
	 namef.push_back("jet2ET");
       }
       else if(nj==8){
	 namef.push_back("jet1PT");
       }
       else if(nj==9){
	 namef.push_back("jet1M");
       }
       else if(nj==10){
	 namef.push_back(" n_lep20");
       }

       else if(nj==11){
	 namef.push_back("delPHI12");
       }
       else if(nj==12){
	 namef.push_back("delr12");
       }
       else if(nj==13){
	 namef.push_back("met");
       }
    

 }}
*/     
			

/*    for(unsigned int print = 0; print<14 ;print++){
      std::cout<<print<<std::endl;
   std::cout<<name[print]<< std::endl;
            std::cout<<nbins[print]<< std::endl;
	     std::cout<<xmin[print]<< std::endl;
	      std::cout<<xmax[print]<< std::endl;
   
}
*/
/*for(unsigned int p_ii =0; p_ii<14; p_ii++){
  for(unsigned int p_jj = p_ii +1; p_jj<14; p_jj++){
    std::cout<<name[p_ii]<<std::endl;   std::cout<<name[p_jj]<<std::endl;
    std::cout<<nbins[p_ii]<<std::endl;  std::cout<<nbins[p_jj]<<std::endl;
    std::cout<<xmin[p_ii]<<std::endl;  std::cout<<xmin[p_jj]<<std::endl;
    std::cout<<xmax[p_ii]<<std::endl;  std::cout<<xmax[p_jj]<<std::endl;

  }}
*/
			      std::vector<TH2D*> variables_comparison;


    for(unsigned int hi= 0; hi<15; hi++){
      for(unsigned int hj= hi +1; hj<15; hj++){
	TH2D * histadd = new TH2D((name[hi]+name[hj]).c_str(),(name[hi]+name[hj]).c_str(),nbins[hi],xmin[hi],xmax[hi],nbins[hj],xmin[hj],xmax[hj]);                                                  
	variables_comparison.push_back(histadd);         

      }}
			   
    std::vector<std::string> save_name;

    for(unsigned int hii= 0; hii<15; hii++){
      for(unsigned int hjj= hii +1; hjj<15; hjj++){
     
			
	save_name.push_back((name[hii]+name[hjj]).c_str());
       

	  }}

      for(unsigned int comparison= 0; comparison<90; comparison++){

	//	std::cout<<save_name[comparison]<< comparison<<std::endl;
      }


     
    std::vector<std::string> namei;
    namei.push_back("400");
    namei.push_back("tt");
 namei.push_back("3000");  
  namei.push_back("top"); 
namei.push_back("w");
    std::vector<TH1D*> files_stacked;


    
    unsigned int name_index;    
    
    for(unsigned int in =0; in<15; in++){
      //  std::cout<<in<<std::endl;

          TH1D * hist_stack = new TH1D((name[in]+namei[0]).c_str(),(name[in]+namei[0]).c_str(),nbins[in],xmin[in],xmax[in]);
      TH1D * hist_stack1 = new TH1D((name[in]+namei[1]).c_str(),(name[in]+namei[1]).c_str(),nbins[in],xmin[in],xmax[in]);
      TH1D * hist_stack2 = new TH1D((name[in]+namei[2]).c_str(),(name[in]+namei[2]).c_str(),nbins[in],xmin[in],xmax[in]);
      TH1D * hist_stack3 = new TH1D((name[in]+namei[3]).c_str(),(name[in]+namei[3]).c_str(),nbins[in],xmin[in],xmax[in]);
      TH1D * hist_stack4 = new TH1D((name[in]+namei[4]).c_str(),(name[in]+namei[4]).c_str(),nbins[in],xmin[in],xmax[in]);
      files_stacked.push_back(hist_stack);
      files_stacked.push_back(hist_stack1);
      files_stacked.push_back(hist_stack2);
      files_stacked.push_back(hist_stack3);   
      files_stacked.push_back(hist_stack4);
}
    




 // Set up the TMVA Reader object.
// Set up the TMVA Reader object.
// The names in AddVariable must be same as in the input (weight) file.

  TMVA::Reader* reader = new TMVA::Reader();
  float COM_Pt;
  float njet_20=0;
   float njet_40=0;
  int njet_30=0;
  float jet1M;    float jet1ET; float jet2ET; float jet1PT;  float delPHI12=- 100; float jet_ETA = 0;  float jet_PHI = 0;  float lep_ETPT;   float n_lep20 = 0;
  float met;  float DRmin =10; float delr12; float jet_ETPT; float fillm; float jetETPT;  float COM_Pt_lep;
 


  /*  dataloader->AddVariable("fill", 'F');
  dataloader->AddVariable("COM_Pt", 'F');
  dataloader->AddVariable("jet_ETA", 'F');
  dataloader->AddVariable("jet_PHI", 'F');
  dataloader->AddVariable("njet_20", 'F');
  dataloader->AddVariable("njet_40", 'F');
  dataloader->AddVariable("jet1ET", 'F');
  dataloader->AddVariable("jet2ET", 'F');
  dataloader->AddVariable("jet1PT", 'F');
  dataloader->AddVariable("n_lep20", 'F');
  dataloader->AddVariable("delPHI12", 'F');
  dataloader->AddVariable("met", 'F');
  dataloader->AddVariable("delr12", 'F');
  dataloader->AddVariable("jet1M", 'F');
  //  dataloader->AddVariable("DRmin", 'F');    
  */
   
    
                         // TMVA needs float, not double
    reader->AddVariable("fillm", &fillm);  
  reader->AddVariable("COM_Pt", &COM_Pt);
  reader->AddVariable("jet_ETA", &jet_ETA);
  reader->AddVariable("jet_PHI", &jet_PHI);
  reader->AddVariable("njet_20", &njet_20);
  reader->AddVariable("njet_40", &njet_40);
  reader->AddVariable("jet1ET", &jet1ET);
  reader->AddVariable("jet2ET", &jet2ET);
  reader->AddVariable("jet1PT", &jet1PT);
  // reader->AddVariable("jetETPT", &jetETPT);
 reader->AddVariable("n_lep20", &n_lep20);
  reader->AddVariable("delPHI12", &delPHI12);
  reader->AddVariable("met", &met);
  reader->AddVariable("delr12", &delr12);
  reader->AddVariable("jet1M", &jet1M);
  reader->AddVariable("COM_Pt_lep", &COM_Pt_lep);


  std::string dir    = "../train/weights/";
  std::string prefix = "tmvaTest";
  reader->BookMVA("BDT", dir + prefix + "_BDT.weights.xml");

// Open input file, get the TTrees, put into a vector

  TFile* inputFile1 = new TFile("/home/ap15061/variables_mc_110899.ZPrime400.root");
  inputFile1->ls();
  TFile* inputFile2 = new TFile("/home/ap15061/variables_mc_117049.ttbar_had.root");
  inputFile2->ls();
  TFile* inputFile3 = new TFile("/home/ap15061/variables_mc_110903.ZPrime1000.root");
  inputFile3->ls();
  TFile* inputFile4 = new TFile("/home/ap15061/variables_mc_110090.stop_tchan_top.root");
  inputFile4->ls();
  TFile* inputFile5 = new TFile("/home/ap15061/variables_mc_167740.WenuWithB.root");
  inputFile5->ls();


  TTree* sig = dynamic_cast<TTree*>(inputFile1->Get("myvariables"));
  TTree* sig1 = dynamic_cast<TTree*>(inputFile3->Get("myvariables"));
  TTree* bkg1 = dynamic_cast<TTree*>(inputFile4->Get("myvariables"));
  TTree* bkg = dynamic_cast<TTree*>(inputFile2->Get("myvariables"));
  TTree* bkg2 = dynamic_cast<TTree*>(inputFile5->Get("myvariables"));

  std::vector<TTree*> treeVec;
  treeVec.push_back(sig);
  treeVec.push_back(bkg);
  treeVec.push_back(sig1);
  treeVec.push_back(bkg1);
  treeVec.push_back(bkg2);

  std::vector<float> entries_scalefactor;
  entries_scalefactor.push_back(28.2/23.48);
  entries_scalefactor.push_back(28.2/85);
  entries_scalefactor.push_back(28.2/230415);
  entries_scalefactor.push_back(28.2/24.21);
  entries_scalefactor.push_back(28.2/12.33);




  int nSigAccBDt = 0;
  int nBkgAccBDT = 0;
  int nSig, nBkg, nSig1, nBkg1 , nBkg2;
  const double tCutFisher = 0.0;
  const double tCutMLP = 0.5;
  for (int i=0; i<treeVec.size(); i++){

    treeVec[i]->Print();

    /*  
    treeVec[i]->SetBranchAddress("fillm", &fillm);
    treeVec[i]->SetBranchAddress("COM_Pt", &COM_Pt);
    treeVec[i]->SetBranchAddress("jet_ETA", &jet_ETA);
    treeVec[i]->SetBranchAddress("jet_PHI", &jet_PHI);
    treeVec[i]->SetBranchAddress("njet_20", &njet_20);
    treeVec[i]->SetBranchAddress("njet_40", &njet_40);
    treeVec[i]->SetBranchAddress("jet1ET", &jet1ET);
    treeVec[i]->SetBranchAddress("jet2ET", &jet2ET);
    treeVec[i]->SetBranchAddress("jet1PT", &jet1PT);
    treeVec[i]->SetBranchAddress("n_lep20", & n_lep20);
    treeVec[i]->SetBranchAddress("delPHI12", & delPHI12);
    treeVec[i]->SetBranchAddress("met", &met);
    treeVec[i]->SetBranchAddress("delr12", &delr12);
    treeVec[i]->SetBranchAddress("jet1M", &jet1M);
    */
      
  int numEntries = treeVec[i]->GetEntries();

  //  std::cout<<treeVec[i]->GetEntries()<< (namei[i]).c_str()<<std::endl;
  std::cout<<i<<std::endl;
  float numEntries_scaled = numEntries*entries_scalefactor[i];

    if ( i == 0 ) { nSig = numEntries; }
    if ( i == 1 ) { nBkg = numEntries; }
        if ( i == 2 ) { nSig1 = numEntries; }
    if ( i == 3 ) { nBkg1 = numEntries; }
    if ( i == 4 ) { nBkg2 = numEntries; }
   
    //  std::cout << "number of entries = " << numEntries << std::endl;

// Loop over events.  The test statistic is identified by the first 
// argument used above in BookMVA (below, e.g., "Fisher").

     for (int j=0; j< numEntries; j++){
       //                std::cout << " Tree " << i << " Entry " << j << std::endl;
      treeVec[i]->GetEntry(j);                // sets evt
      // std::cout << " Got Entry! " << std::endl;

      unsigned int hist_index = 0;  unsigned int histstack_index = 0;
      for(unsigned int hi= 0; hi<15; hi++){

	TLeaf * leaf_stack = treeVec[i]->GetLeaf(name[hi].c_str());
	leaf_stack->GetBranch()->GetEntry(j);
	float fill_stack =  leaf_stack->GetValue();


	files_stacked[5*hi + i]->Fill(fill_stack);




	//	std::cout <<j<<std::endl;
	//	std::cout <<5*hi + i<<std::endl;
	for(unsigned int hj= hi +1; hj<15; hj++){

	  //	     std::cout << hi << " " << hj << std::endl;
	    //	   std::cout << name[hi] << " " << name[hj] << std::endl;

	  TLeaf *leafhi = treeVec[i]->GetLeaf(name[hi].c_str());
	  leafhi->GetBranch()->GetEntry(j);
	  float valhi = leafhi->GetValue();

	  TLeaf *leafhj = treeVec[i]->GetLeaf(name[hj].c_str());
	  leafhj->GetBranch()->GetEntry(j);
	  float valhj = leafhj->GetValue();

	  // std::cout << " Value of (" << name[hi] << ", " << name[hj] << ") for entry " << j << " in tree " << i << " is (" << valhi << ", " << valhj << ")" << std::endl;

	  //  std::cout << variables_comparison[hist_index]->GetName() << std::endl;
	   variables_comparison[hist_index]->Fill(valhi,valhj);	   
hist_index++;


// std::cout <<j<<std::endl;	 
//std::cout <<hist_index<<std::endl;


	}
      }
      
      double tBDT = reader->EvaluateMVA("BDT");
      if ( i == 0 || i == 2 ){                       // signal
        hBDTSig->Fill(tBDT);

	BDT_fill->Fill(tBDT,fillm);
	BDT_COM_Pt->Fill(tBDT,COM_Pt);
        BDT_jet_ETA->Fill(tBDT,jet_ETA);
	BDT_jet_PHI->Fill(tBDT,jet_PHI);
	  BDT_njet_20->Fill(tBDT,njet_20);
	  BDT_njet_40->Fill(tBDT,njet_40);
	  BDT_jet1ET->Fill(tBDT,jet1ET);
	  BDT_jet2ET->Fill(tBDT,jet2ET);
	  BDT_jet1PT->Fill(tBDT,jet1PT);
	  BDT_n_lep20->Fill(tBDT,n_lep20);
          BDT_delPHI12->Fill(tBDT,delPHI12);
          BDT_met->Fill(tBDT,met);
          BDT_delr12->Fill(tBDT,delr12);
          BDT_jet1M->Fill(tBDT,jet1M);


	   	 
      }
        else if ( i == 1  || i== 3 || i== 4){                  // background
        hBDTBkg->Fill(tBDT);
	BDT_filltt->Fill(tBDT,fillm); 
	BDT_COM_Pt_tt->Fill(tBDT,COM_Pt);
        BDT_jet_ETAtt->Fill(tBDT,jet_ETA);
        BDT_jet_PHItt->Fill(tBDT,jet_PHI);
	BDT_njet_20tt->Fill(tBDT,njet_20);
	BDT_njet_40tt->Fill(tBDT,njet_40);
	BDT_jet1ETtt->Fill(tBDT,jet1ET);
	BDT_jet2ETtt->Fill(tBDT,jet2ET);
	BDT_jet1PTtt->Fill(tBDT,jet1PT);
	BDT_n_lep20tt->Fill(tBDT,n_lep20);
	BDT_delPHI12tt->Fill(tBDT,delPHI12);
	BDT_met_tt->Fill(tBDT,met);
	BDT_delr12tt->Fill(tBDT,delr12);
	BDT_jet1Mtt->Fill(tBDT,jet1M);


	

     }
      




      if (j == 0) {
	std::cout << "Here are some variables for the first event and the";
	if ( i == 0 ) {
	  std::cout << " signal:" << std::endl;
	} else if ( i == 1 ) {
	  std::cout << " background:" << std::endl;
	}
	std::cout << "  tBDT=" << tBDT << std::endl;
	std::cout << "  njet_20=" << njet_20 << std::endl;
	std::cout << "  njet_40=" << njet_40 << std::endl;
	std::cout << "  jet1ET=" << jet1ET << std::endl;
	std::cout << "  jet2ET=" << jet2ET << std::endl;
	std::cout << "  n_lep20=" << n_lep20 << std::endl;
	std::cout << "  delPHI12=" << delPHI12 << std::endl;
	std::cout << "  met=" << met << std::endl;
	std::cout << "  delr12=" << delr12 << std::endl;
	std::cout << "  jet1M=" << jet1M << std::endl;
      } 

    }
  }
  
    
  TCanvas * v_canvas = new TCanvas("v_canvas", "v_canvas",600,600);
  v_canvas->cd();

  
  for(unsigned int stack = 0; stack<15 ; stack++){
    THStack * v_stack = new THStack("v_stack", "v_stack");   

 files_stacked[stack*5 ]->SetFillColor(1);
    files_stacked[stack*5 +1]->SetFillColor(2);
    files_stacked[stack *5 +2]->SetFillColor(3);
    files_stacked[stack *5 +3]->SetFillColor(4);
    files_stacked[stack *5 +4]->SetFillColor(6);

     files_stacked[stack*5 ]->Scale(entries_scalefactor[0]);
    files_stacked[stack*5+1 ]->Scale(entries_scalefactor[1]);
    files_stacked[stack*5+2 ]->Scale(entries_scalefactor[2]);
       files_stacked[stack*5+3 ]->Scale(entries_scalefactor[3]);
    files_stacked[stack*5+4 ]->Scale(entries_scalefactor[4]);


    
 
 files_stacked[stack*5 ]->GetXaxis()->SetTitle((units[stack]).c_str());
 files_stacked[stack*5 +1]->GetXaxis()->SetTitle((units[stack]).c_str());
 files_stacked[stack *5 +2]->GetXaxis()->SetTitle((units[stack]).c_str());
 files_stacked[stack *5 +3]->GetXaxis()->SetTitle((units[stack]).c_str());
 files_stacked[stack *5 +4]->GetXaxis()->SetTitle((units[stack]).c_str());


 files_stacked[stack*5 ]->GetYaxis()->SetTitle((std::string(("frequency"))).c_str());
 files_stacked[stack*5 +1]->GetYaxis()->SetTitle((std::string(("frequency"))).c_str());
 files_stacked[stack *5 +2]->GetYaxis()->SetTitle((std::string(("frequency"))).c_str());
 files_stacked[stack *5 +3]->GetYaxis()->SetTitle((std::string(("frequency"))).c_str());
 files_stacked[stack *5 +4]->GetYaxis()->SetTitle((std::string(("frequency"))).c_str());

 v_stack->Add( files_stacked[stack*5]);
       //  files_stacked[stack*5]->Draw("hist  ");
    v_stack->Add( files_stacked[stack*5 +1]);
    // files_stacked[stack +2]->Draw("hist  same");
    v_stack->Add( files_stacked[stack*5  +2]);
    // files_stacked[stack +3]->Draw("hist  same");
    v_stack->Add( files_stacked[stack*5 +3]);
    //  files_stacked[stack +4]->Draw("hist  same");
    v_stack->Add( files_stacked[stack*5 +4]);
 
    TLegend * leg = new TLegend(0.1,0.6,0.4,0.5);
        v_stack->Draw("hist");
    v_stack->Print();
    v_stack->GetXaxis()->SetTitle((units[stack]).c_str());

    v_stack->GetYaxis()->SetTitle((std::string(("frequency"))).c_str());


    leg->SetHeader((name[stack] + std::string((".png"))).c_str(),"C");
     leg->AddEntry(files_stacked[stack*5], "");
    leg->AddEntry(files_stacked[stack*5 +1], "");
    leg->AddEntry(files_stacked[stack*5 +2], "");
    leg->AddEntry(files_stacked[stack*5 +3], "");
    leg->AddEntry(files_stacked[stack*5 +4], "");
    leg->Draw();
  
  v_canvas->SaveAs((name[stack] + std::string((".png"))).c_str());
  }  
  
  unsigned int binx;
  for(unsigned int cut = 1; cut<101; cut++){

     if(files_stacked[30]->GetBinLowEdge(20)){ 
       std::cout<<files_stacked[70]->GetBinLowEdge(cut)<<"Z prime 1000 "<<(name[1]).c_str()<<std::endl;
       std::cout<<files_stacked[70]->Integral(cut,100)*0.11<<std::endl;
       std::cout<<files_stacked[0]->GetBin(binx,0,0)<<std::endl;
     }
}
  
    unsigned int binx1;
  for(unsigned int CUT_1 = 1; CUT_1<101; CUT_1++){
    if(files_stacked[31]->GetBinLowEdge(20)){   
      std::cout<<files_stacked[71]->GetBinLowEdge(CUT_1)<<"ttbar"<<(name[4]).c_str()<<std::endl;
    std::cout<<files_stacked[71]->Integral(CUT_1,100)*entries_scalefactor[1]<<std::endl;
    std::cout<<files_stacked[31]->GetBin(binx1,0,0)<<std::endl;
    }
  }
 
  unsigned int binx2;
  for(unsigned int cut2 = 1; cut2<101; cut2++){
    if(files_stacked[32]->GetBinLowEdge(20)){
    std::cout<<files_stacked[72]->GetBinLowEdge(cut2)<<"Z prime 2000"<< (name[4]).c_str()<<std::endl;
    std::cout<<files_stacked[72]->Integral(cut2,100)*0.005<<std::endl;
    std::cout<<files_stacked[2]->GetBin(binx2,0,0)<<std::endl;
    }
  }
 
  
  unsigned int binx3;
  for(unsigned int cut3 = 1; cut3<101; cut3++){
    if(files_stacked[33]->GetBinLowEdge(20) ){   
      std::cout<<files_stacked[73]->GetBinLowEdge(cut3)<<"top"<<(name[4]).c_str()<<std::endl;
    std::cout<<files_stacked[73]->Integral(cut3,100)*entries_scalefactor[3]<<std::endl;
    std::cout<<files_stacked[33]->GetBin(binx3,0,0)<<std::endl;
    }
  }

  
  unsigned int binx4;
  for(unsigned int cut4 = 1; cut4<101; cut4++){
    if(files_stacked[34]->GetBinLowEdge(20) ){   
      std::cout<<files_stacked[74]->GetBinLowEdge(cut4)<<"W+jets"<<(name[4]).c_str()<<std::endl;
    std::cout<<files_stacked[74]->Integral(cut4,100)*entries_scalefactor[4]<<std::endl;
    std::cout<<files_stacked[34]->GetBin(binx4,0,0)<<std::endl;
    }
  }

  
 
    TCanvas * comparison_canvas = new TCanvas("comparison_canvas", "comparison_canvas",600,600);
  comparison_canvas->cd(); 


    for(unsigned int comparison= 0; comparison<99; comparison++){
   variables_comparison[comparison]->Draw();

   comparison_canvas->SaveAs((save_name[comparison]+ std::string((".png"))).c_str());


  



  }
  
    TCanvas * BDT1 = new  TCanvas("BDT1","BDT1",600,600);
    BDT1->cd();
    hBDTSig->SetLineColor(1);
    hBDTBkg->SetLineColor(2);

    hBDTSig->Draw("hist");
    hBDTBkg->Draw("same hist");

    BDT1->SaveAs("BDT.png");
   
std::cout<<"end here"<<std::endl;
histFile->Close();

return 0;

}


      // ADD YOUR CODE HERE TO INCLUDE OTHER CLASSIFIERS SUCH AS MLP
      // AND COUNT THE NUMBERS OF SELECTED EVENTS (COMPARE CLASSIFIER
      // VALUE TFISHER, ETC., TO TCUT).

      

/*

  TCanvas * c111 = new TCanvas("c111","c111",600,600);
  c111->cd();

  THStack * hd = new THStack("first_stack","");
  files_stacked[0]->Draw("hist");
  files_stacked[1]->Draw("hist same");  files_stacked[2]->Draw("hist same"); files_stacked[3]->Draw("hist same");  files_stacked[4]->Draw("hist same");  files_stacked[5]->Draw("hist same");

  files_stacked[0]->SetFillColor(1); files_stacked[1]->SetFillColor(2); files_stacked[2]->SetFillColor(3); files_stacked[3]->SetFillColor(4);  files_stacked[4]->SetFillColor(5);


  hd->Draw();
c111->SaveAs("first_stacked.gif");


  


TCanvas * c220 = new TCanvas("c220","c220",600,600);
  c220->cd();

   BDT_fill->Draw("hist");
 
  BDT_fill->SetLineColor(3);

  
 
 
 c220->SaveAs("BDT_fill.gif");

TCanvas * c221 = new TCanvas("c221","c221",600,600);
  c221->cd();

  BDT_filltt->Draw("hist ");

  BDT_filltt->SetLineColor(4);

   
  c221->SaveAs("BDT_filltt.gif");

TCanvas * c222 = new TCanvas("c222","c222",600,600);
  c222->cd();

 BDT_COM_Pt->Draw("hist");

  BDT_COM_Pt->SetLineColor(3);
 
  c222->SaveAs("BDT_COM_Pt.gif");

  return 0;
}


TCanvas * c223 = new TCanvas("c223","c223",600,600);
  c223->cd();

 BDT_COM_Pt_tt->Draw("hist ");



  BDT_COM_Pt_tt->SetLineColor(4);

c223->SaveAs("BDT_COM_Pt_tt.gif");

TCanvas * c224 = new TCanvas("c224","c224",600,600);
c224->cd();
 

 BDT_jet_PHI->Draw("hist");

 
  BDT_jet_PHI->SetLineColor(3);
 
c224->SaveAs("BDT_jetPHI.gif");

TCanvas * c25 = new TCanvas("c25","c25",600,600);
c25->cd();
  
BDT_jet_PHItt->Draw("hist ");

BDT_jet_PHItt->SetLineColor(4);

  c225->SaveAs("BDT_phitt.gif");

TCanvas * c226 = new TCanvas("c226","c226",600,600);
  c226->cd();

  BDT_njet_20->Draw("hist");

  BDT_njet_20->SetLineColor(3);
  
  c226->SaveAs("BDT_jetnumber20.gif");

TCanvas * c227 = new TCanvas("c227","c227",600,600);
  c227->cd();
  BDT_njet_20tt->Draw("hist ");
 
  BDT_njet_20tt->SetLineColor(4);
TCanvas * c228 = new TCanvas("c228","c228",600,600);
c228->cd();

  BDT_njet_40->Draw("hist");
  BDT_njet_40->SetLineColor(3);

  c228->SaveAs("BDT_jetnumber40.gif");

TCanvas * c229 = new TCanvas("c229","c229",600,600);
  c229->cd();

BDT_njet_40tt->Draw("hist");

BDT_njet_40tt->SetLineColor(4);
TCanvas * c230 = new TCanvas("c230","c230",600,600);
c230->cd();

  BDT_jet1ET->Draw("hist");
  BDT_jet1ET->SetLineColor(3);
  
  c230->SaveAs("BDT_jet1ET.gif");
TCanvas * c230 = new TCanvas("c27","c27",600,600);

  c230->cd();

BDT_jet1ETtt->Draw("hist");
BDT_jet1ETtt->SetLineColor(4);
c230->SaveAs("BDT_jet1ETtt.gif");

TCanvas * c231 = new TCanvas("c231","c231",600,600);
c231->cd();

  BDT_jet2ET->Draw("hist");
  BDT_jet2ET->SetLineColor(3);
  c231->SaveAs("BDT_jet2ET.gif");
TCanvas * c232 = new TCanvas("c232","c232",600,600);
  c232->cd();

  BDT_jet2ETtt->Draw("hist"); 
  BDT_jet2ETtt->SetLineColor(4);
c232->SaveAs("BDT_jet2ETtt.gif");

TCanvas * c29 = new TCanvas("c29","c29",600,600);
c29->cd();

  BDT_jet1PT->Draw("hist");
   BDT_jet1PT->SetLineColor(3);
  c28->SaveAs("BDT_jet1PT.gif");

TCanvas * c233 = new TCanvas("c233","c233",600,600);
 c233->cd();

BDT_jet1PTtt->Draw("hist");
BDT_jet1PTtt->SetLineColor(4);
c29->SaveAs("BDT_jet1PTtt.gif");


TCanvas * c234 = new TCanvas("c234","c234",600,600);
c234->cd();

BDT_n_lep20->Draw("hist ");
 BDT_n_lep20->SetLineColor(3);
 c234->SaveAs("BDT_nlep20.gif");

TCanvas * c235 = new TCanvas("c235","c235",600,600);
 c235->cd();

BDT_n_lep20tt->Draw("hist");
BDT_n_lep20tt->SetLineColor(4);
c234->SaveAs("BDT_nlep20.gif");
TCanvas * c236 = new TCanvas("c236","c236",600,600);
c236->cd();

 BDT_delPHI12->Draw("hist");
 BDT_delPHI12->SetLineColor(3);
 c236->SaveAs("BDT_delPHI.gif");

TCanvas * c237 = new TCanvas("c237","c237",600,600);
 c237->cd();

BDT_delPHI12tt->Draw("hist");
BDT_delPHI12tt->SetLineColor(4);
c237->SaveAs("BDT_selPHI12.gif");

TCanvas * c238 = new TCanvas("c238","c238",600,600);
c238->cd();

 BDT_met->Draw("hist");
 BDT_met->SetLineColor(3);
  c238->SaveAs("BDT_met.gif");

TCanvas * c239 = new TCanvas("c239","c239",600,600);
 c239->cd();

BDT_met_tt->Draw("hist ");
BDT_met_tt->SetLineColor(4);
c31->SaveAs("BDT_met.gif");
TCanvas * c240 = new TCanvas("c240","c240",600);
c240->cd();

 BDT_delr12->Draw("hist");
 BDT_delr12->SetLineColor(3);
  c240->SaveAs("BDT_delr12.gif");
 

TCanvas * c241 = new TCanvas("c241","c241",600,600);
 c241->cd();

BDT_delr12tt->Draw("hist same");
BDT_delr12tt->SetLineColor(4);
c241->SaveAs("BDT_delr12.gif");
TCanvas * c242 = new TCanvas("c242","c242",600,600);
c242->cd();
 BDT_jet1M->Draw("hist");
 BDT_jet1M->SetLineColor(3);
 c242->SaveAs("BDT_jet1M.gif");


TCanvas * c243 = new TCanvas("c243","c243",600,600);
c243->cd();
BDT_jet1Mtt->Draw("hist ");
BDT_jet1Mtt->SetLineColor(4);
c243->SaveAs("BDT_jet1Mtt.gif");

  TCanvas * c17 = new TCanvas("c17","c17",600,600);
  c17->cd();

  hBDTSig->Draw("hist");
  hBDTBkg->Draw("hist same");
  hBDTSig->SetLineColor(3);
  hBDTBkg->SetLineColor(4);

  c17->SaveAs("BDT.gif");



  TCanvas * c17 = new TCanvas("c17","c17",600,600);
  c17->cd();


  TFile *plotZ400 = new TFile("variables_mc_110899.ZPrime400.root");
  TFile *plot_tt = new TFile("variables_mc_117049.ttbar_had.root");

  TObject * histZ400 = plotZ400->Get("myvariables");
  TObject * hist_tt = plot_tt->Get("myvariables");

  TTree * att_h400 = (TTree*)histZ400;
  TTree * att_htt = (TTree*)hist_tt;


  // create histograms                                                                                                                                                                                       

  TH1F *jet_invariant = new TH1F("jet_invariant","jet of Z prime to calculate total invariant", 100,0,6000000);
  TH1F *jet_invariant_tt = new TH1F("jet_invariant_tt","jet of Z prime to calculate total invariant fot ttba jets", 100,0,6000000);
  TH1F *jet_Pt = new TH1F("jet_Pt_top","jet_Pt",50,0,600000);
  TH1F *jet_Pt_tt = new TH1F("jet_Pt_top","jet_Pt",50,0,600000);

  TH1F *Jet_eta  = new TH1F("Jet_eta", "values of eta after cut",50,-8,8);
  TH1F *Jet_eta_tt = new   TH1F(  "Jet_eta_tt","values of eta after cut",50,-8,8);
  TH1F *jet_phi = new TH1F("jet_phi","values of phi",50,0,9);
  TH1F *jet_phi_tt = new TH1F("jet_phi_tt","values of phi for the channels",50,0,9);
  TH1F *jet_N = new TH1F("jet_N","jet number with Et>20GeV",50, 0,60);
  TH1F *jet_N_tt = new TH1F("jet_N_tt","jet number for ttbar with Et>20GeV",50, 0,60);
  TH1F *jet_N40 = new TH1F("jet_N40","jet number with Et>40GeV",50, 0,40);
  TH1F *jet_N_tt40 = new TH1F("jet_N_top40","jet number for ttbar with Et>40GeV",50, 0,40);
  TH1F *jet1_Et =new TH1F("jet1_Et","jet 1 Et",50,0,1000000);
  TH1F *jet1_Et_tt =new TH1F("jet1_Et_tt","jet 1 Et",50,0,1000000);

  TH1F *lep_N = new TH1F("lep_N","lep_N",50, 0,40);
  TH1F *lep_N_tt = new TH1F("lep_N_tt","lep_N_tt",50, 0,40);
  TH1F * jet2_Et = new TH1F("jet2_Et","jet 2 Et",50,0,1000000);
  TH1F * jet2_Et_tt = new TH1F("jet2_Et_tt","jet 2 Et",50,0,1000000);

  TH1F * jet1_Pt = new TH1F("jet1_Pt","jet 1 Pt",50,0,1000000);
  TH1F * jet1_Pt_tt = new TH1F("jet1_Pt","jet 1 Pt ttbar",50,0,1000000);
  TH1F * jetdelphi12 = new TH1F("delphi12","difference of phi between jet 1 and jet 2",50 ,0,4);
  TH1F * jetdelphi12_tt = new TH1F("delphi12_tt","difference of phi between jet 1 and jet 2",50 ,0,4);
  TH1F *jet1mass = new TH1F("jet1mass","mass of jet1",50,0,200000);
  TH1F *jet1mass_tt = new TH1F("jet1mass_tt","mass of jet1",50,0,200000);
  TH1F *DRMIN = new TH1F("DRMIN", "minimum alue of Delta R",50,0,100);
  TH1F *DRMIN_tt = new TH1F("DRMIN_tt", "minimum alue of Delta R",50,0,100);
  TH1F *Met = new TH1F("Met","Met",50,0.,100000);
  TH1F *Met_tt = new TH1F("Mettt","Mettt",50,0.,100000);
  TH1F *delrjet12 = new TH1F("delrjet12", "delta R of jet 1 and 2", 50,0,5);
  TH1F *delrjet12_tt = new TH1F("delrjet12_tt", "delta R of jet 1 and 2", 50,0,5);


  att_h400->Project("jet_invariant","fill");
  att_h400->Project("jet_Pt","COM_Pt");
  att_h400->Project("Jet_eta ","jet_ETA");
  att_h400->Project("jet_phi","jet_PHI");
  att_h400->Project("jet_N","njet_20");
  att_h400->Project("jet_N40 ","njet_40");
  att_h400->Project("jet1_Et","jet1ET");
  att_h400->Project("jet2_Et","jet2ET");
  att_h400->Project("jet1_Pt","jet1PT");
  att_h400->Project("lep_N ","n_lep20");
  att_h400->Project("jetdelphi12","delPHI12");
  att_h400->Project("Met","met");
  att_h400->Project("delrjet12","delr12");
  att_h400->Project("jet1mass","jet1M");
  att_h400->Project("DRMIN","DRmin");

  att_htt->Project("jet_invariant_tt","fill");
  att_htt->Project("jet_Pt_tt","COM_Pt");
  att_htt->Project("Jet_eta_tt ","jet_ETA");
  att_htt->Project("jet_phi_tt","jet_PHI");
  att_htt->Project("jet_N_tt","njet_20");
  att_htt->Project("jet_N_tt40 ","njet_40");
  att_htt->Project("jet1_Et_tt","jet1ET");
  att_htt->Project("jet2_Et_tt","jet2ET");
  att_htt->Project("jet1_Pt_tt","jet1PT");
  att_htt->Project("lep_N_tt ","n_lep20");
  att_htt->Project("jetdelphi12_tt","delPHI12");
  att_htt->Project("Met_tt","met");
  att_htt->Project("delrjet12_tt","delr12");
  att_htt->Project("jet1mass_tt","jet1M");
  att_htt->Project("DRMIN_tt","DRmin");

  att_htt->Print();

  TCanvas *c1 = new TCanvas("c1","c1",600,600);
  c1->cd();
  jet_invariant->Scale(1./jet_invariant->Integral());
  jet_invariant_tt->Scale(1./jet_invariant_tt->Integral());

  jet_invariant->Draw("hist");
  jet_invariant_tt->Draw("hist same");

  jet_invariant->SetLineColor(1);

  jet_invariant_tt->SetLineColor(4);

  jet_invariant->GetXaxis()->SetTitle("invariant mass of Z prime squared Mev ");//set x axis as" ... "                                                                                                             
  jet_invariant->GetYaxis()->SetTitle("frequency");// set Y axis as "..."                                                                                                                                          


  c1->SaveAs("invariant_mass.gif");

  TCanvas *c2 =new TCanvas("c2","c2",600,600);
  c2->cd();

  // here I scale my plots to fit the screen                                                                                                                                                                       
  if (jet_Pt->Integral() > 0.1) {

    jet_Pt->Scale(1./jet_Pt->Integral());
    jet_Pt_tt->Scale(1./jet_Pt_tt->Integral());
    
    jet_Pt->GetXaxis()->SetTitle("Pt,MeV");
    jet_Pt->GetYaxis()->SetTitle("frequency");
    
    jet_Pt->SetLineColor(1);
    jet_Pt_tt->SetLineColor(4);
    
    jet_Pt->Draw("hist  ");
    jet_Pt_tt->Draw("hist  same ");
    
    jet_Pt->GetXaxis()->SetTitle("Pt,MeV");
    jet_Pt->GetYaxis()->SetTitle("frequency");

    c2->SaveAs("backgrounds_rejection.gif");
  } else {
    std::cout << "SKIPPING jet_pt integral=" << jet_Pt->Integral() << std::endl;
  }

  TCanvas *c3 =new TCanvas("c3","c3",600,600);
  c3->cd();

  Jet_eta->Scale(1./Jet_eta->Integral());
  Jet_eta_tt->Scale(1./Jet_eta_tt->Integral());
  Jet_eta->Draw("hist ");
  Jet_eta_tt->Draw(" hist same  " );
  Jet_eta->GetXaxis()->SetTitle("etavalues after cut");
  Jet_eta_tt->GetYaxis()->SetTitle("frequency");

  Jet_eta->SetLineColor(1);
  Jet_eta_tt->SetLineColor(4);

  c3->SaveAs("backgrounds_eta_rejetion.gif");

  TCanvas *c4 =new TCanvas("c4","c4",600,600);
  c4->cd();
  jet_phi->Scale(1./jet_phi->Integral());
  jet_phi_tt->Scale(1./jet_phi_tt->Integral());

  jet_phi->Draw("hist ");
  jet_phi_tt->Draw("hist same ");

  jet_phi->GetXaxis()->SetTitle("phi values ");
  jet_phi->GetYaxis()->SetTitle("frequency");

  jet_phi->SetLineColor(1);
  jet_phi_tt->SetLineColor(4);

  c4->SaveAs("backgrounds_phi_rejetion.gif");
 
  TCanvas *c6 = new TCanvas("c6","c6",600,600);
  c6->cd();

  jet_N->Scale(1./jet_N->Integral());
  jet_N_tt->Scale(1./jet_N_tt->Integral());

  jet_N->Draw("hist  ");
  jet_N_tt->Draw("hist same  ");

  jet_N->GetXaxis()->SetTitle("Jet number ");
  jet_N->GetYaxis()->SetTitle("frequency");

  jet_N->Draw("hist");
  jet_N_tt->Draw("hist same  ");
  jet_N->GetXaxis()->SetTitle("jet number");
  jet_N->GetYaxis()->SetTitle("frequency");

  jet_N->SetLineColor(1);
  jet_N_tt->SetLineColor(4);
 
  c6->SaveAs("jet_number_Et20.gif");

  TCanvas *c7 = new TCanvas("c7","c7",600,600);
  c7->cd();

  jet_N40->Scale(1./jet_N40->Integral());
  jet_N_tt40->Scale(1./jet_N_tt40->Integral());

  jet_N40->Draw("hist ");
  jet_N_tt40->Draw("hist same ");
  jet_N40->SetLineColor(1);
  jet_N_tt40->SetLineColor(4);

  c7->SaveAs("The_jet_number_with_Et40_GeV.gif");

  TCanvas *c8 = new TCanvas("c8","c8",600,600);
  c8->cd();

  jet1_Et->Scale(1./jet1_Et->Integral());
  jet1_Et_tt->Scale(1./jet1_Et_tt->Integral());
   jet1_Et->Draw("hist ");
  jet1_Et_tt->Draw("hist same ");
 
  jet1_Et->GetXaxis()->SetTitle("ET of Jet 1 ");
  jet1_Et->GetYaxis()->SetTitle("frequency");
  jet1_Et->SetLineColor(1);
  jet1_Et_tt->SetLineColor(4);

  c8->SaveAs("Et_of_jet_1.gif");
  TCanvas *c9 = new TCanvas("c9","c9",600,600);
  c9->cd();
  lep_N->Scale(1./lep_N->Integral());
  lep_N_tt->Scale(1./lep_N_tt->Integral());

  lep_N->Draw("hist");
  lep_N_tt->Draw("hist same");

  lep_N->SetLineColor(1);
  lep_N_tt->SetLineColor(4);

  lep_N->GetXaxis()->SetTitle("Lepton Number ");
  lep_N->GetYaxis()->SetTitle("frequency");

  c9->SaveAs("lepton_Number_per_event.gif");
  TCanvas *c10 = new TCanvas("c10","c10",600,600);
  c10->cd();

  std::cout << "jet2_Et integral=" << jet2_Et->Integral() << std::endl;
  std::cout << "jet2_Et_tt integral=" << jet2_Et_tt->Integral() << std::endl;


  jet2_Et->Scale(1./jet2_Et->Integral());
  jet2_Et_tt->Scale(1./jet2_Et_tt->Integral());


  jet2_Et->Draw("hist ");
  jet2_Et_tt->Draw("hist same ");

  jet2_Et->GetXaxis()->SetTitle("ET of Jet 2");
  jet2_Et->GetYaxis()->SetTitle("frequency");

  jet2_Et->SetLineColor(1);
  jet2_Et_tt->SetLineColor(4);


  c10->SaveAs("Et_of_jet_2 .gif");

  TCanvas *c11 = new TCanvas("c11","c11",600,600);
  c11->cd();

  jetdelphi12->Scale(1./jetdelphi12->Integral());
  jetdelphi12_tt->Scale(1./jetdelphi12_tt->Integral());
  jetdelphi12->Draw("hist same ");
  jetdelphi12_tt->Draw("hist same ");


  jetdelphi12->GetXaxis()->SetTitle("Deltaphi12");
  jetdelphi12->GetXaxis()->SetTitle("Deltaphi12");
  jetdelphi12->GetYaxis()->SetTitle("Frequency");

  jetdelphi12->SetLineColor(1);
  jetdelphi12_tt->SetLineColor(4);
  c11->SaveAs("delataphi_of_jet_1_and_jet2.gif");


  TCanvas *c12 = new TCanvas("c12","c12",600,600);
  c12->cd();

  jet1_Pt->Scale(1./jet1_Pt->Integral());
  jet1_Pt_tt->Scale(1./jet1_Pt_tt->Integral());
  jet1_Pt->Draw("hist ");
  jet1_Pt_tt->Draw("hist same ");
 
  jet1_Pt->SetLineColor(1);
  jet1_Pt_tt->SetLineColor(4);

  c12->SaveAs("Pt_of_jet1.gif");
  TCanvas *c13 = new TCanvas("c13","c13",600,600);
  c13->cd();

  jet1mass->Scale(1./jet1mass->Integral());
  jet1mass_tt->Scale(1./jet1mass_tt->Integral());
 
  jet1mass->Draw("hist");
  jet1mass_tt->Draw(" hist same");
 
  jet1mass->GetXaxis()->SetTitle("mass of jet 1");
  jet1mass->GetYaxis()->SetTitle("Frequency");

  jet1mass->SetLineColor(1);
  jet1mass_tt->SetLineColor(4);
  c13->SaveAs("Pt_of_jet_1.gif");

  TCanvas *c14 = new TCanvas("c14","c14",600,600);
  c14->cd();
  Met->Scale(1./Met->Integral());
  Met_tt->Scale(1./Met_tt->Integral());

  Met->Draw("hist");
  Met_tt->Draw(" hist same");

  Met->GetXaxis()->SetTitle("Missing transverse energy");
  Met->GetYaxis()->SetTitle("Frequency");

  Met->SetLineColor(1);
  Met_tt->SetLineColor(4);

  c14->SaveAs("Missing_transverse_energy.gif");

  TCanvas *c15 = new TCanvas("c15","c15",600,600);
  c15->cd();
  delrjet12->Scale(1./delrjet12->Integral());
  delrjet12_tt->Scale(1./delrjet12_tt->Integral());

  delrjet12->Draw("hist");
  delrjet12_tt->Draw(" hist same");

  delrjet12->GetXaxis()->SetTitle("Delta R jet 1 and 2");
  delrjet12_tt->GetYaxis()->SetTitle("Frequency");

  delrjet12->SetLineColor(1);
  delrjet12_tt->SetLineColor(4);

  c15->SaveAs("Deltar_jet_1_and_2.gif");

  TCanvas *c16 = new TCanvas("c16","c16",600,600);
  c16->cd();

  jet1mass->Scale(1./jet1mass->Integral());
  jet1mass_tt->Scale(1./jet1mass_tt->Integral());

  jet1mass->Draw("hist");
  jet1mass_tt->Draw(" hist same");

  jet1mass->GetXaxis()->SetTitle("mass of jet 1");
  jet1mass->GetYaxis()->SetTitle("Frequency");

  jet1mass->SetLineColor(1);
  jet1mass_tt->SetLineColor(4);

  c16->SaveAs("mass_of_jet1.gif");

*/
/*
  histFile->Write();
  histFile->Close();
  return 0;

}
*/
