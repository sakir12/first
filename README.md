# first
test
// use this to get information on underflow and overflow
//gStyle->SetOptStat(


float PI = 3.14159;

float delr(float etaj,float etal,float phil, float phij){
  float deleta = etaj-etal;
  float delphi = phil-phij;

  if(delphi>PI) {delphi = delphi - PI*2;
  }// end of first if statement
  if( delphi<-PI) {delphi = delphi +2*PI;
  }// end of second if statement

  return sqrt(deleta*deleta + delphi*delphi);

}// end of function calculating delr to be used below

float delr13;  float jet1M;    float jet1ET; float jet2ET; float jet1PT;  float delPHI12=- 100; float jet_ETA = 0;  float jet_PHI = 0;  float lep_ETPT;  float n_lep20 = 0;
float DRmin =10; float delr12; float jet_ETPT; float fillm; float njet_20 = 0;  float njet_40 = 0; float COM_Pt; float met; float jetETPT; float COM_Pt_lep;


int lepton(TString input_file ="  mc_167740.WenuWithB.root"){
  // mc_167740.WenuWithB.root

  // mc_110899.ZPrime400.root
// TTree for storing variables

// create  connectionto store varibales in my TTree
  TFile * Rootfile = new TFile(input_file);
  Rootfile->ls();
  // create a variable of T type to attach to mini
  TObject * lep_object = Rootfile->Get("mini");
  TTree * attach = (TTree*)lep_object;
  if(!attach){
    std::cout<< "Expect a crash as tree was not obtained"<<std::endl;
  }


  unsigned int jetZ_n; 
  unsigned int lepZ_n; 

  float jetZ_pt[150],jetZ_eta[150],jetZ_phi[150],jetZ_E[150],jetZ_jvf[150];

  float jetZ_MV1[200];
  float lepZ_pt[150],lepZ_eta[150],lepZ_phi[150],lepZ_E[150];

  TH1F * jet_invariant = new TH1F("jet_invariant","jet of Z prime to calculate total invariant", 100,0,600000);

  TH1F *jet_invariant_tt = new TH1F("jet_invariant_tt","jet of Z prime to calculate total invariant fot ttba jets", 100,0,600000);
  TH1F *jet_Pt = new TH1F("jet_Pt","jet_Pt",50,0,60000);

  TH1F *Jet_eta  = new TH1F("Jet_eta", "values of eta after cut",50,-4,4);
  TH1F *jet_phi = new TH1F("jet_phi","values of phi",50,-4,6);
  TH1F *jet_EtPt = new TH1F("jet_EtPt","ratio of Et of jet to Pt",50,0,8);
  TH1F *jet_N = new TH1F("jet_N","jet number with Et>20GeV",50, 0,40);
  TH1F *jet_N40 = new TH1F("jet_N40","jet number with Et>40GeV",50, 0,12);
  TH1F *jet1_Et =new TH1F("jet1_Et","jet 1 Et",50,0,1000000);
  TH1F *lep_N = new TH1F("lep_N","lep_N",50, 0,40);
  TH1F * jet2_Et = new TH1F("jet2_Et","jet 2 Et",50,0,1000000);
  TH1F * jet1_Pt = new TH1F("jet1_Pt","jet 1 Pt",50,0,1000000);
  TH1F * jet2_Pt = new TH1F("jet2_Pt","jet 2 Pt",50,0,1000000);
  TH1F * jet1_Eta = new TH1F("jet1_Eta","jet 1 Eta",50,-4,4);
  TH1F * jetdelphi12 = new TH1F("delphi12","difference of phi between jet 1 and jet 2",50 ,0,4);
  TH1F *delrjet12 = new TH1F("delrjet12", "delta R of jet 1 and 2", 50,-5,5);
  TH1F *delrjet13 = new TH1F("delrjet13", "delta R of jet 1 and 3", 50,-5,5);
  TH1F *jet1mass = new TH1F("jet1mass","mass of jet1",50,0,200000);
  TH1F *DRMIN = new TH1F("DRMIN", "minimum alue of Delta R",50,0,100);
  TH1F *Met = new TH1F("Met","Met",50,0.,100000);
  TH1F *Pt_lep = new TH1F("Pt_lep","Pt_lep",50,0,1000000);
  // use T object to get TTree values ond store nenetries
  int nentries = attach->GetEntries();
  int a = 1*1.2;

  attach->SetBranchAddress("alljet_n",&jetZ_n);
  attach->SetBranchAddress("jet_pt",&jetZ_pt);
  attach->SetBranchAddress("jet_eta",&jetZ_eta);
  attach->SetBranchAddress("jet_phi",&jetZ_phi);
  attach->SetBranchAddress("jet_E",&jetZ_E);
  attach->SetBranchAddress("jet_jvf" ,&jetZ_jvf);
  attach->SetBranchAddress("lep_n" ,&lepZ_n);
  attach->SetBranchAddress("lep_pt",&lepZ_pt);
  attach->SetBranchAddress("lep_eta",&lepZ_eta);
  attach->SetBranchAddress("lep_phi",&lepZ_phi);
  attach->SetBranchAddress("lep_E",&lepZ_E);
  attach->SetBranchAddress("met_et",&met);
  attach->SetBranchAddress("jet_MV1",&jetZ_MV1);
  // create  connectionto store varibales in my TTree

  // set branch to fill TTree for all variables

  TFile *cutsZ400 = new TFile((string("variables_")+input_file).Data(),"RECREATE");// file for putting in my TTree
  TTree *variables = new TTree("myvariables","myvariables");
  // attach->Scan("jet_MV1");


  variables->Branch("fillm", &fillm);
  variables->Branch("COM_Pt", &COM_Pt);
  variables->Branch("jet_ETA", &jet_ETA);
  variables->Branch("jet_PHI", &jet_PHI);
  variables->Branch("njet_20", &njet_20);
  variables->Branch("njet_40", &njet_40);
  variables->Branch("jet1ET", &jet1ET);
  variables->Branch("jet2ET", &jet2ET);
  variables->Branch("jet1PT", &jet1PT);
  //  variables->Branch("jetETPT", &jetETPT);
  variables->Branch("n_lep20", &n_lep20);
  variables->Branch("delPHI12", &delPHI12);
  variables->Branch("met", &met);
  variables->Branch("delr12", &delr12);
  //  variables->Branch("delr13", &delr13);
  variables->Branch("jet1M", &jet1M);
  variables->Branch("COM_Pt_lep", &COM_Pt_lep);

  //  variables->Branch("DRmin", &DRmin);


  // create a float function to calculate delr to be used multiple times below with four arguments
    for (unsigned int ientry = 0; ientry < nentries; ientry++){
    // Read and fill variables like jet_n or jet_pt
    attach->GetEntry(ientry);
    //now I want to print variables of eta,phi pt energy to test weather we have the corret values selected from the tree.
    unsigned int lepZ_list_n = 0;

    // create a loop of the lepton eta minus jet eta from array to calaculated delta eta

  
    for(unsigned int jeti =0; jeti<jetZ_n; jeti++){
      for(unsigned int lepi  =0; lepi<lepZ_n; lepi++){

	float DR = delr(jetZ_eta[jeti],lepZ_eta[lepi],jetZ_phi[jeti],lepZ_phi[lepi]);
	if(DRmin<DR)
	  {
	    DRmin=DR;}// end of if statement to reduce the DRmin
      }// End of jet i.j loop
    }// End of lep i,j loop



        if (ientry % 100 == 0)
	  //          std::cout<< "Entry "<< ientry << "has" << jetZ_n << "jets"<<std::endl;
     
    //this line prints out the variable and its values after cuts 
    for (unsigned int j = 0; j< jetZ_n; j++) {
      //  std::cout<<"jet"<< j << "has value pt phi eta E"<<jetZ_pt[j]<< " " <<jetZ_eta[j]<< " " <<jetZ_phi[j]<< " " << jetZ_E[j]<< " "<< std::endl;
     }
    
    //create class so entries will be in four vector format of 6 entries for the posiible quarks and their jets
    TLorentzVector jetZ_list[6];
       //cretae integer if we skip a jet that fails the cut
    unsigned int jetZ_list_n = 0;
    delr12 =0; delr13=0;        
    float delrjet_lep = 0;
    for(unsigned int drjl =0; drjl<jetZ_n; drjl++){
      if(jetZ_n>=1 && lepZ_n>=1){
        delrjet_lep = delr(jetZ_eta[drjl],lepZ_eta[0],jetZ_phi[drjl],lepZ_phi[0]);


      } // end of if statement to select 1st and second jet

    }// end of loop for delrjet_lep



    for(unsigned int dr1 =0; dr1<jetZ_n; dr1++){
      if(jetZ_n>=2 && jetZ_pt[dr1]>20000 && jetZ_jvf[dr1]>0.4 && delrjet_lep>0.3){
	delr12 = delr(jetZ_eta[0],jetZ_eta[1],jetZ_phi[0],jetZ_phi[1]);
      } // end of if statement to select 1st and second jet
    }// end of loop for delr12

    for(unsigned int dr3 =0; dr3<jetZ_n; dr3++){
      if(jetZ_n>=2){
        delr13 = delr(jetZ_eta[0],jetZ_eta[2],jetZ_phi[0],jetZ_phi[2]);

      } // end of if statement to select 1st and second jet

    }// end of loop for delr13

    //create nested for loops top count jet number  from  ntuple bnefore constraining the jet number for creating the TLorentz Vector class for other calaculations
    unsigned int bjet=0;
  
    unsigned int njet_30=0;
 
    njet_20= 0; njet_40 =0; n_lep20 =0;  
    // creating a loop to calculate a the lepton number     

    for(unsigned int I_L = 0;I_L<lepZ_n; I_L++ ){
      if(lepZ_pt[I_L]>20000){
	n_lep20++;
      }// end of if statement for cuts on pt and met for lepton number
    }// end of loop for counting lepton number after pt and met cut                                                                                                                               \


    TLorentzVector zjet;  // frst set the TLorentzVector to calculate the Et
    for(unsigned int j = 0; j< jetZ_n; j++){
      if(jetZ_n>=1 && lepZ_n>=1 )
	{delrjet_lep = delr(jetZ_eta[j],lepZ_eta[0],jetZ_phi[j],lepZ_phi[0]);}
      if( delrjet_lep>0.3 && jetZ_pt[j]> 20000 &&jetZ_jvf[j]> 0.4/*could have more cuts here*/ ){
	zjet.SetPtEtaPhiE(jetZ_pt[j],jetZ_eta[j],jetZ_phi[j],jetZ_E[j]);// now fill the four verctor with this
	// calculate the jet number before I constrain the jet number to fill the TLorentzVector for 6 jets
		
	if(zjet.Et()>20000  ){
	  	  njet_20++;
		}// end of counting jet number for Et>20GeV
		 if (zjet.Et()>30000) {
		  njet_30++;
		}// end of counting for jes wih Et> 30GeV      
		 if(zjet.Et()>40000 ){
	         njet_40++;
	 }// end of counting jet number for Et>40GeV


	   
      }// end of of cut for Et>40000 and jvf cut
    }// end of loop for creating variables from the array with correct eta,ph,E and pt

    for(unsigned int b_count = 0; b_count< jetZ_n; b_count++){ 
      if(jetZ_n>=1 && lepZ_n>=1 )
        {delrjet_lep = delr(jetZ_eta[ b_count],lepZ_eta[0],jetZ_phi[ b_count],lepZ_phi[0]);}
      if (jetZ_MV1[ b_count]>0.7 &&  delrjet_lep>0.3){
      bjet++;  


      }// end of if statement

      
    }// end of loop over jet number per event




    //  std::cout<<bjet<<std::endl;

    TLorentzVector zjet1[90];
  
    for(unsigned int Jeta = 0; Jeta< jetZ_n; Jeta++){
      if(jetZ_n>=1 && lepZ_n>=1 )
        {delrjet_lep = delr(jetZ_eta[Jeta],lepZ_eta[0],jetZ_phi[Jeta],lepZ_phi[0]);}
      if(delrjet_lep>0.3 &&jetZ_pt[Jeta]> 20000 &&jetZ_jvf[Jeta]> 0.4/*could have more cuts here*/ ){
	        zjet1[Jeta].SetPtEtaPhiE(jetZ_pt[Jeta],jetZ_eta[Jeta],jetZ_phi[Jeta],jetZ_E[Jeta]);
        // calculate the jet number and other things  before I constrain the jet number to fill the TLorentzVector for 6 jets
     
	

	 
	if( jetZ_n>=1 ){
	  jet1ET = zjet1[0].Et();
	  jet1PT= zjet1[0].Pt();
	  jet1M= zjet1[0].M();
     	  jet2ET =  zjet1[1].Et();
	}// end of condition for second jet

	       }// end of of cut for Et>30000 and jvf cut
    }// end of loop for creating variables from the array with correct eta,ph,E and pt to be used

    // creating variable to fill histogram with variables for jet 1 and 2

    
  // if  we have the entries sum up the four vector for the invariant mass
    for(unsigned int zj = 0; zj< jetZ_n; zj++){
      if(jetZ_n>=1 && lepZ_n>=1 )
        {delrjet_lep = delr(jetZ_eta[zj],lepZ_eta[0],jetZ_phi[zj],lepZ_phi[0]);}
      if(delrjet_lep>0.3 &&jetZ_pt[zj]> 20000 &&jetZ_jvf[zj]> 0.4/*could have more cuts here*/ ){
	jetZ_list[jetZ_list_n++].SetPtEtaPhiE(jetZ_pt[zj],jetZ_eta[zj],jetZ_phi[zj],jetZ_E[zj]);// now fill the four verctor with this
	if(jetZ_list_n >= 4){
	  break;// this stops the loop if we filled the 6 jets from our nine jet entries
	}// end of if statement for jet number > 6
      }// end of of cut for Pt>2000 and jvf cut
    }// end of loop for creating variables from the array with correct eta,ph,E and pt

    TLorentzVector sum_fourvector;
    if(jetZ_list_n == 4){
      
      for(unsigned int k = 0; k<jetZ_n; k++){
	sum_fourvector += jetZ_list[k];



      }// end of if statement from the accepted jets
    }// end of condition for 6 jets 
      // now fill the four verctor with this

      // creating variable to fill histogram with Et of jet 1 
     
    //    std::cout<<sum_fourvector.M()<<std::endl;
   
    for(unsigned int del = 0; del< jetZ_n; del++){
      if(jetZ_n>=1 && lepZ_n>=1 )
        {delrjet_lep = delr(jetZ_eta[del],lepZ_eta[0],jetZ_phi[del],lepZ_phi[0]);
	}     
	if(jetZ_n>=2 && jetZ_pt[del]> 20000 &&jetZ_jvf[del]> 0.4 ){
	   

	  delPHI12 = jetZ_phi[1]-jetZ_phi[0];
	
	  if(delPHI12>PI){delPHI12 =  delPHI12 - 2*PI;
	  }// end of if statement for grater than 2PI
	  if(delPHI12<-PI){delPHI12 =  delPHI12 + 2*PI;

	      }// end of if statement for less than 2 PI
	}	 
}// end of if statement for condition pn delPHI12
	//	float fillm =0;   float COM_Pt =0; 
	  
      // now create a float variable to fill the histogram that has the calculated invariant mass Pt,Et,Phi Eta and other TLorentz vector vraiables to be used later 
   fillm = sum_fourvector.M();
   COM_Pt =  sum_fourvector.Pt();
  
   /*   if(fillm<0){
     std::cout<<fillm<<std::endl;


     std::cout<<COM_Pt <<std::endl;
   }

   */
   jet_ETA = 0;   jet_PHI = 0;
   float jetETPT =0;
   float jet_Et =0;
   jet_Et = sum_fourvector.Et();
   jet_ETPT = jet_Et/COM_Pt;

  
  TLorentzVector lepZ_list[2];
  // create integer if we skip a jet that fails the cut                                                                                                                                                          


  
  

  



  for(unsigned int jlep = 0; jlep< lepZ_n; jlep++){
    if(lepZ_pt[jlep]> 2000/*could have more cuts here*/ ){
      lepZ_list[lepZ_list_n++].SetPtEtaPhiE(lepZ_pt[jlep],lepZ_eta[jlep],lepZ_phi[jlep],lepZ_E[jlep]);// now fill the four verctor with this                                                                   TLorentzVector sum_vector_leptt;    
      if(lepZ_list_n >= 1){
	break;// this stops the loop if we filled the 6 jets from our nine jet entries                                                                                                                            
      }// end of if statement for number of leptons > 2                                                                                                                                            
    }// end of cut for Pt>2000                                                                                                                                                                     
 }// end of loop for creating the four vector variables                                                                                                                                                          
  
   //if  we have the entries sum up the four vector for the invariant mass                                                                                                                                    
      TLorentzVector sum_vector_lep;
  if(lepZ_list_n == 1){
  
    for(unsigned int  kle = 0; kle<lepZ_list_n; kle++){
      sum_vector_lep += lepZ_list[kle];
    }// end of if statement for leptons>2                                                                                                                                                                        
  } // end of condition for 2 leptoos
     // now create variables to fill the histograms                                                                                                                                                                
    float fill_lep = sum_vector_lep.M();
    COM_Pt_lep =  sum_vector_lep.Pt();
    float lep_ETA = sum_vector_lep.Eta();
    float lep_PHI = sum_vector_lep.Phi();
    float lep_Et = sum_vector_lep.Et();
    float lep_ETPT = lep_Et/COM_Pt_lep;

    //    std::cout<<bjet<<std::endl;  
  

                        
 // print out the binformation for centre of with pt cut
  //  std::cout<< "The six  jets after passing the cut with centre of mass pt ="  << COM_Pt << "with mass"  << fill << std::endl;
  // fill the Histogram with the calculated invariant mass and other variables

               if(njet_20>=4 && n_lep20 ==1 && delrjet_lep>0.3 && jet1ET>50000 && met>30000 && fillm>=0 && bjet>1){   
 variables->Fill();

  }
  jet_invariant ->Fill(fillm);

  jet_Pt->Fill(COM_Pt);
  for(unsigned int etA =0; etA<jetZ_n; etA++){
    jet_ETA = jetZ_eta[etA];
    Jet_eta->Fill(jet_ETA);
  }// end ogf loop for storing eta from the jets in a float variable  
  for(unsigned int phI =0; phI<jetZ_n; phI++){
    jet_PHI = abs(jetZ_phi[phI]);
    jet_phi->Fill(jet_PHI);
  }// end of loop for storing phi from the jets in a float variable
  for(unsigned int etA1 =0; etA1<jetZ_n; etA1++){
}



  jet_phi->Fill(jet_PHI);

  jet_EtPt->Fill(jet_ETPT); 
  jet_N->Fill(njet_20);
  jet_N40->Fill(njet_40);

  jet2_Et->Fill(jet2ET);
  jet1_Pt->Fill(jet1PT);
  lep_N->Fill(n_lep20);  
  //jet1_Eta->Fill(jet1ETA);
  jetdelphi12->Fill(delPHI12);
  Met->Fill(met);
  delrjet12->Fill(delr12);
  delrjet13->Fill(delr13);
  jet1mass->Fill(jet1M);
  DRMIN->Fill(DRmin);
  Pt_lep->Fill(COM_Pt_lep);
  // connect vaiables to the branch in TTree

  

    }// End of loop over entries from tree for Z prime400
   
    variables->Print();
    std::cout<<variables->GetEntries()<<std::endl;    


    cutsZ400->Write();
    cutsZ400->Close();



   
   


   

   


    // project the vraibales from the ntuple for isolated tracks for lepton et and pt on to my histogram
    attach->Project("lep_pt30","lep_ptcone30");



    attach->Project("lep_et20","lep_etcone20");



 


    TCanvas *c1 = new TCanvas("c1","c1",600,600);
    c1->cd();
    jet_invariant->Scale(1./jet_invariant->Integral());




    jet_invariant->Draw();
    // Draw creates the filled histogram as c1

    //Draw creates the filled histogram for 500 GeV aswell as ttbar to jets then plots it on c1
  
    //now we use the Set commands to change the aesthetics of the diagram
    jet_invariant->SetLineColor(kGreen);
    jet_invariant->SetLineWidth(3);
    jet_invariant->SetLineStyle(1);
    jet_invariant->GetXaxis()->SetTitle("invariant mass of Z prime squared Mev ");//set x axis as" ... "
    jet_invariant->GetYaxis()->SetTitle("frequency");// set Y axis as "..."


    c1->SaveAs("lepton_eta_at_50_bins.jpg");// save canvas  as "..."
    TCanvas *c2 =new TCanvas("c2","c2",600,600);
    c2->cd();

    // here I scale my plots to fit the screen

     jet_Pt->Scale(1./jet_Pt->Integral());


    jet_Pt->GetXaxis()->SetTitle("Pt,MeV");
    jet_Pt->GetYaxis()->SetTitle("frequency");

    jet_Pt->SetLineColor(1);

    jet_Pt->SetLineWidth(3);



    jet_Pt->Draw("hist  ");

 

    jet_Pt->GetXaxis()->SetTitle("Pt,MeV");
    jet_Pt->GetYaxis()->SetTitle("frequency");

    



 c2->SaveAs("backgrounds_rejection.png");

  TCanvas *c3 =new TCanvas("c3","c3",600,600);
 c3->cd();

 Jet_eta->Scale(1./Jet_eta->Integral());



 Jet_eta->Draw("hist ");

 
 

  Jet_eta->GetXaxis()->SetTitle("etavalues after cut");


 Jet_eta->SetLineColor(1);




  c3->SaveAs("backgrounds_eta_rejetion.png");


  TCanvas *c4 =new TCanvas("c4","c4",600,600);
  c4->cd();
  jet_phi->Scale(1./jet_phi->Integral());


  
  jet_phi->Draw("hist ");


  jet_phi->GetXaxis()->SetTitle("phi values ");
  jet_phi->GetYaxis()->SetTitle("frequency");
 
  jet_phi->SetLineColor(1);


  c4->SaveAs("backgrounds_phi_rejetion.png");



  TCanvas *c5 = new TCanvas("c5","c5",600,600);
  c5->cd();
  jet_EtPt->Scale(1./jet_EtPt->Integral());


  jet_EtPt->Draw("hist  ");



  jet_EtPt->GetXaxis()->SetTitle("Et/Pt ");
  jet_EtPt->GetYaxis()->SetTitle("frequency");


  jet_EtPt->SetLineColor(1);


  c5->SaveAs("the_ratio_of_Et_and_Pt.png");
  TCanvas *c6 = new TCanvas("c6","c6",600,600);
  c6->cd();

  jet_N->Scale(1./jet_N->Integral());


  jet_N->Draw("hist  ");
  


  jet_N->GetXaxis()->SetTitle("Jet number ");
  jet_N->GetYaxis()->SetTitle("frequency");

  jet_N->Draw("hist");


  jet_N->SetLineColor(1);




  c6->SaveAs("The_jet_number_with_Et>20_GeV.png");

  TCanvas *c7 = new TCanvas("c7","c7",600,600);
  c7->cd();

  jet_N40->Scale(1./jet_N40->Integral());


  jet_N40->Draw("hist ");



  jet_N40->GetXaxis()->SetTitle("Jet number Et>40GeV ");
  jet_N40->GetYaxis()->SetTitle("frequency");

  jet_N40->SetLineColor(1);




  c7->SaveAs("The_jet_number_with_Et>40_GeV.png");

    TCanvas *c11 = new TCanvas("c11","c11",600,600);
  c11->cd();
  lep_N->Scale(1./lep_N->Integral());

  lep_N->Draw("hist");



  lep_N->SetLineColor(1);


  lep_N->GetXaxis()->SetTitle("Lepton Number ");
  lep_N->GetYaxis()->SetTitle("frequency");

 
  
 

  c11->SaveAs("lepton_Number_per_event.png");
  TCanvas *c12 = new TCanvas("c12","c12",600,600);
  c12->cd();

  jet2_Et->Scale(1./jet2_Et->Integral());


  jet2_Et->Draw("hist ");


  jet2_Et->GetXaxis()->SetTitle("ET of Jet 2");
  jet2_Et->GetYaxis()->SetTitle("frequency");


  jet2_Et->SetLineColor(1);


  c12->SaveAs("Et_of_jet_2 .png");
 

    TCanvas *c13 = new TCanvas("c13","c13",600,600);
  c13->cd();
  
  jetdelphi12->Scale(1./jetdelphi12->Integral());


  jetdelphi12->Draw("hist ");


  jetdelphi12->GetXaxis()->SetTitle("Deltaphi12");
  jetdelphi12->GetYaxis()->SetTitle("Frequency");


  jetdelphi12->SetLineColor(1);



  c13->SaveAs("delataphi_of_jet_1_and_jet2.png");

  TCanvas *c19 = new TCanvas("c19","c19",600,600);
  c19->cd();

  delrjet13->Scale(1./delrjet13->Integral());


  delrjet13->Draw("hist ");


  delrjet13->GetXaxis()->SetTitle("Deltaphi13");
  delrjet13->GetYaxis()->SetTitle("Frequency");


  delrjet13->SetLineColor(1);



  c19->SaveAs("delataphi_of_jet_1_and_jet3.png");


  TCanvas *c14 = new TCanvas("c14","c14",600,600);
  c14->cd();

  jet1_Pt->Scale(1./jet1_Pt->Integral());


  jet1_Pt->Draw("hist ");


  jet1_Pt->GetXaxis()->SetTitle("Pt of jet 1");
  jet1_Pt->GetYaxis()->SetTitle("Frequency");


  jet1_Pt->SetLineColor(1);

  c14->SaveAs("Pt_of_jet_1.png");

  TCanvas *c15 = new TCanvas("c15","c15",600,600);
  c15->cd();
  Met->Scale(1./Met->Integral());

  
  Met->Draw("hist");



    Met->GetXaxis()->SetTitle("Missing transverse energy");
  Met->GetYaxis()->SetTitle("Frequency");

  Met->SetLineColor(1);


    c15->SaveAs("Missing_transverse_energy.png");

    TCanvas *c16 = new TCanvas("c16","c16",600,600);
    c16->cd();
    delrjet12->Scale(1./delrjet12->Integral());


    delrjet12->Draw("hist");



    delrjet12->GetXaxis()->SetTitle("Delta R jet 1 and 2");


    delrjet12->SetLineColor(1);


    c16->SaveAs("Deltar_jet_1_and_2.png");
   
    TCanvas *c17 = new TCanvas("c17","c17",600,600);
    c17->cd();

    jet1mass->Scale(1./jet1mass->Integral());


    jet1mass->Draw("hist");



    jet1mass->GetXaxis()->SetTitle("mass of jet 1");
    jet1mass->GetYaxis()->SetTitle("Frequency");

    jet1mass->SetLineColor(1);


    c17->SaveAs("mass_of_jet1.png");

    TCanvas *c18 = new TCanvas("c18","c18",600,600);
    c18->cd();

    DRMIN->Scale(1./DRMIN->Integral());


    DRMIN->Draw("hist");



    DRMIN->GetXaxis()->SetTitle("Minimum value of R of jets");
    DRMIN->GetYaxis()->SetTitle("Frequency");

    DRMIN->SetLineColor(1);


    c18->SaveAs("Minimum_value_of_R.png");
    TCanvas *c119 = new TCanvas("c119","c119",600,600);
    c119->cd();


    Pt_lep->Scale(1./ Pt_lep->Integral());

    Pt_lep->Draw("hist");

    Pt_lep->GetXaxis()->SetTitle("Pt of lepton");
    Pt_lep->GetYaxis()->SetTitle("frequency");

      Pt_lep->SetLineColor(1);

    c119->SaveAs("Pt_lepton.png");


return 0;



}
