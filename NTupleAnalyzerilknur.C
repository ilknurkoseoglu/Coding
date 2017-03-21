
//  -- previous ECFA version -- _P as paper vesion
//undfined DelphMT2W isoTracksP DelphMT
//         MT2W0                MT2W0
///////////////// naturalSUSY - nS /////////////////////
#include "NtupleTools3.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <TLorentzVector.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TBranch.h>


using namespace std;
void NTupleAnalyzerilknur(TString list, TString outname, bool useW=true){
    gROOT->Reset();
        bool DELPH = true;// DelphMet

    TObjArray* arr = list.Tokenize(" ");
    int size=arr->GetEntries();
    if(size%2!=0) {
            cout<<"unbalance file/weight list: "<<list<<endl;
            exit(0);
    }
    vector<TString> files;
    vector<double> weights;
    for(int i=0;i<size;i+=2){
            files.push_back( arr->At(i)->GetName() );
            weights.push_back( atof( arr->At(i+1)->GetName() ) );
    }

//---------Define tree variables-------------------------------
    /*vector<double> ElectronPt;
    vector<double> ElectronEta;
    vector<double> MuonPt;
    vector<double> MuonEta;*/
    vector<double> HT_CUT,HT_CUT_SR0,HT_CUT_SR1,HT_CUT_SR2,HT_CUT_SR3,HT_CUT_SR4,HT_CUT_SR5,HT_CUT_SR6,HT_CUT_SR7,HT_CUT_SR8,HT_CUT_SR9,HT_CUT_SR10;
    vector<double> MET_CUT,MET_CUT_SR0,MET_CUT_SR1,MET_CUT_SR2,MET_CUT_SR3,MET_CUT_SR4,MET_CUT_SR5,MET_CUT_SR6,MET_CUT_SR7,MET_CUT_SR8,MET_CUT_SR9,MET_CUT_SR10;
    vector<double> MT_CUT,MT_CUT_SR0,MT_CUT_SR1,MT_CUT_SR2,MT_CUT_SR3,MT_CUT_SR4,MT_CUT_SR5,MT_CUT_SR6,MT_CUT_SR7,MT_CUT_SR8,MT_CUT_SR9,MT_CUT_SR10;
//    vector<double> LepPT_CUT;
//        vector<double> MT2W_CUT;
    vector<double> METOHT_CUT,METOHT_CUT_SR0,METOHT_CUT_SR1,METOHT_CUT_SR2,METOHT_CUT_SR3,METOHT_CUT_SR4,METOHT_CUT_SR5,METOHT_CUT_SR6,METOHT_CUT_SR7,METOHT_CUT_SR8,METOHT_CUT_SR9,METOHT_CUT_SR10; // MET over HT
//    vector<double> JET_Multp;
 

//----------------------Normalizing--------------------------------------------
       Double_t norm = 1;
       //h->Scale(norm, "width");


    //Define an outputTree:ilknur
    //TFile *OutFile=new TFile("OutTreeNtupleilknur.root","RECREATE");
    //TBranch *MuPT;
    
    TTree *TreeB0= new TTree("TreeB0","Background DiBoson Tree");
    TTree *TreeB1= new TTree("TreeB1","Background BosonJets Tree");
    TTree *TreeB2= new TTree("TreeB2","Background TTbar Tree");
    TTree *TreeB3= new TTree("TreeB3","Background TopJets Tree");
    
    TTree *TreeSR0= new TTree("TreeSR0"," Region0");
    TTree *TreeSR1= new TTree("TreeSR1","Signal Region1");
    TTree *TreeSR2= new TTree("TreeSR2","Signal Region2");
    TTree *TreeSR3= new TTree("TreeSR3","Signal Region3");
    TTree *TreeSR4= new TTree("TreeSR4","Signal Region4");
    TTree *TreeSR5= new TTree("TreeSR5","Signal Region5");
    TTree *TreeSR6= new TTree("TreeSR6","Signal Region6");
    TTree *TreeSR7= new TTree("TreeSR7","Signal Region7");
    TTree *TreeSR8= new TTree("TreeSR8","Signal Region8");
    TTree *TreeSR9= new TTree("TreeSR9","Signal Region9");
    TTree *TreeSR10= new TTree("TreeSR10","Signal Region10");
    /*TreeS->Branch("MuonPt",&MuonPt);
    OutTree->Branch("MuonEta",&MuonEta);
    OutTree->Branch("ElectronPt",&ElectronPt);
    OutTree->Branch("ElectronEta",&ElectronEta);*/
//    TreeS->Branch("MT2W",&MT2W_CUT);
//    TreeS->Branch("JET_Multp",&JET_Multp);


    
    
    TreeB0->Branch("HT",&HT_CUT);
    TreeB0->Branch("MET",&MET_CUT);
    TreeB0->Branch("MT",&MT_CUT);
    //    TreeB->Branch("LepPT",&LepPT_CUT);
    TreeB0->Branch("METOHT",&METOHT_CUT);
    
    
    TreeB1->Branch("HT",&HT_CUT);
    TreeB1->Branch("MET",&MET_CUT);
    TreeB1->Branch("MT",&MT_CUT);
    //    TreeB->Branch("LepPT",&LepPT_CUT);
    TreeB1->Branch("METOHT",&METOHT_CUT);
    
    
    TreeB2->Branch("HT",&HT_CUT);
    TreeB2->Branch("MET",&MET_CUT);
    TreeB2->Branch("MT",&MT_CUT);
    //    TreeB->Branch("LepPT",&LepPT_CUT);
    TreeB2->Branch("METOHT",&METOHT_CUT);

    TreeB3->Branch("HT",&HT_CUT);
    TreeB3->Branch("MET",&MET_CUT);
    TreeB3->Branch("MT",&MT_CUT);
//    TreeB->Branch("LepPT",&LepPT_CUT);
    TreeB3->Branch("METOHT",&METOHT_CUT);
//    TreeB->Branch("MT2W",&MT2W_CUT);
//    TreeB->Branch("JET_Multp",&JET_Multp);
    

    TreeSR0->Branch("HT",&HT_CUT_SR0);
    TreeSR0->Branch("MET",&MET_CUT_SR0);
    TreeSR0->Branch("MT",&MT_CUT_SR0);
	//    TreeSR1->Branch("LepPT",&LepPT_CUT_SR1);
    TreeSR0->Branch("METOHT",&METOHT_CUT_SR0);
	//    TreeSR1->Branch("MT2W",&MT2W_CUT_SR1);
	//    TreeSR1->Branch("JET_Multp",&JET_Multp_SR1);


    TreeSR1->Branch("HT",&HT_CUT_SR1);
    TreeSR1->Branch("MET",&MET_CUT_SR1);
    TreeSR1->Branch("MT",&MT_CUT_SR1);
//    TreeSR1->Branch("LepPT",&LepPT_CUT_SR1);
    TreeSR1->Branch("METOHT",&METOHT_CUT_SR1);
//    TreeSR1->Branch("MT2W",&MT2W_CUT_SR1);
//    TreeSR1->Branch("JET_Multp",&JET_Multp_SR1);


    TreeSR2->Branch("HT",&HT_CUT_SR2);
    TreeSR2->Branch("MET",&MET_CUT_SR2);
    TreeSR2->Branch("MT",&MT_CUT_SR2);
//    TreeSR2->Branch("LepPT_SR2",&LepPT_CUT_SR2);
    TreeSR2->Branch("METOHT",&METOHT_CUT_SR2);
//    TreeSR2->Branch("MT2W",&MT2W_CUT_SR2);
//    TreeSR2->Branch("JET_Multp",&JET_Multp_SR2);

    TreeSR3->Branch("HT",&HT_CUT_SR3);
    TreeSR3->Branch("MET",&MET_CUT_SR3);
    TreeSR3->Branch("MT",&MT_CUT_SR3);
//    TreeSR3->Branch("LepPT_SR3",&LepPT_CUT_SR3);
    TreeSR3->Branch("METOHT",&METOHT_CUT_SR3);
//    TreeSR3->Branch("MT2W",&MT2W_CUT);
//    TreeSR3->Branch("JET_Multp",&JET_Multp);


    TreeSR4->Branch("HT",&HT_CUT_SR4);
    TreeSR4->Branch("MET",&MET_CUT_SR4);
    TreeSR4->Branch("MT",&MT_CUT_SR4);
//    TreeSR4->Branch("LepPT",&LepPT_CUT);
    TreeSR4->Branch("METOHT",&METOHT_CUT_SR4);
//    TreeSR4->Branch("MT2W",&MT2W_CUT);
//    TreeSR4->Branch("JET_Multp",&JET_Multp)


    TreeSR5->Branch("HT",&HT_CUT_SR5);
    TreeSR5->Branch("MET",&MET_CUT_SR5);
    TreeSR5->Branch("MT",&MT_CUT_SR5);
//    TreeSR5->Branch("LepPT",&LepPT_CUT_SR5);
    TreeSR5->Branch("METOHT",&METOHT_CUT_SR5);
//    TreeSR5->Branch("MT2W",&MT2W_CUT_SR1);
//    TreeSR5->Branch("JET_Multp",&JET_Multp_SR1);


    TreeSR6->Branch("HT",&HT_CUT_SR6);
    TreeSR6->Branch("MET",&MET_CUT_SR6);
    TreeSR6->Branch("MT",&MT_CUT_SR6);
//    TreeSR6->Branch("LepPT_SR6",&LepPT_CUT_SR6);
    TreeSR6->Branch("METOHT",&METOHT_CUT_SR6);
//    TreeSR6->Branch("MT2W",&MT2W_CUT_SR2);
//    TreeSR6->Branch("JET_Multp",&JET_Multp_SR2);

    TreeSR7->Branch("HT",&HT_CUT_SR7);
    TreeSR7->Branch("MET",&MET_CUT_SR7);
    TreeSR7->Branch("MT",&MT_CUT_SR7);
//    TreeSR7->Branch("LepPT_SR3",&LepPT_CUT_SR3);
    TreeSR7->Branch("METOHT",&METOHT_CUT_SR7);
//    TreeSR7->Branch("MT2W",&MT2W_CUT);
//    TreeSR7->Branch("JET_Multp",&JET_Multp);


    TreeSR8->Branch("HT",&HT_CUT_SR8);
    TreeSR8->Branch("MET",&MET_CUT_SR8);
    TreeSR8->Branch("MT",&MT_CUT_SR8);
//    TreeSR8->Branch("LepPT",&LepPT_CUT);
    TreeSR8->Branch("METOHT",&METOHT_CUT_SR8);
//    TreeSR8->Branch("MT2W",&MT2W_CUT);
//    TreeSR8->Branch("JET_Multp",&JET_Multp)


    TreeSR9->Branch("HT",&HT_CUT_SR9);
    TreeSR9->Branch("MET",&MET_CUT_SR9);
    TreeSR9->Branch("MT",&MT_CUT_SR9);
//    TreeSR7->Branch("LepPT_SR3",&LepPT_CUT_SR3);
    TreeSR9->Branch("METOHT",&METOHT_CUT_SR9);
//    TreeSR7->Branch("MT2W",&MT2W_CUT);
//    TreeSR7->Branch("JET_Multp",&JET_Multp);


    TreeSR10->Branch("HT",&HT_CUT_SR10);
    TreeSR10->Branch("MET",&MET_CUT_SR10);
    TreeSR10->Branch("MT",&MT_CUT_SR10);
//    TreeSR8->Branch("LepPT",&LepPT_CUT);
    TreeSR10->Branch("METOHT",&METOHT_CUT_SR10);
//    TreeSR8->Branch("MT2W",&MT2W_CUT);
//    TreeSR8->Branch("JET_Multp",&JET_Multp)

//---------------------------------------------------------------------------------------------------       

    //after baseline selection
    TH1F* hLepMuonPt= new TH1F("hLepMuonPt","MuonPt after muon baseline.",50,0,7000);
    TH1F* hLepMuonEta=new TH1F("hLepMuonEta","MuonEta after muon baseline.",100,-3,3);
    TH1F* hLepElePt= new TH1F("hLepElePt","ElectronPt after elect. baseline.",50,0,7000);
    TH1F* hLepEleEta=new TH1F("hLepEleEta","ElectronEta after elect baseline.",100,-3,3);

    TH1F* hLepMuonPt2= new TH1F("hLepMuonPt2","MuonPt before muon prese.",50,0,7000);
    TH1F* hLepMuonEta2=new TH1F("hLepMuonEta2","MuonEta before muon prese.",100,-3,3);
    TH1F* hLepElePt2= new TH1F("hLepElePt2","ElectronPt before elect. prese.",50,0,7000);
    TH1F* hLepEleEta2=new TH1F("hLepEleEta2","ElectronEta before elect prese.",100,-3,3);


    //after MET_CUT
    TH1F*  hMET2= new TH1F("hMET2","after (D)MET>250 cut",50,0,5000);
    TH1F*  apMET= new TH1F("apMET","after Nbjet>2 & after Single Lepton selection MET and Njet_tight>2 MET",50,0,5000);
    TH1F*  apDMET= new TH1F("apDMET","after Nbjet>2 & after Single Lepton selection MET and Njet_tight>2 MET",50,0,5000);
    TH1F*  bpMET= new TH1F("bpMET","before Nbjet>2 & after Single Lepton selection MET and Njet_tight>2 MET",50,0,5000);
    TH1F*  bpDMET= new TH1F("bpDMET","before Nbjet>2 & after Single Lepton selection and Njet_tight>2 MET",50,0,5000);

     //at 1lep 4jets 1b
    TH1F* aDphi      = new TH1F("aDphi","#Delta#phi (JetMETdPhi) after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,4);
    TH1F* aDelphDphi = new TH1F("aDelphDphi","Delphes #Delta#phi (DelphdPhi) after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,4);
    
    
    TH2F* hDelPhi_LpWpt = new TH2F("hDelPhi_LpWpt","DelPhi_LpWpt after Njet>2 Nbjet>2 & Single Lepton selec.",10,-1.,1.,100,0.,2.);
    hDelPhi_LpWpt->GetYaxis()->SetTitle("P_{T}(lep)/P_{T}(W)");
    hDelPhi_LpWpt->GetXaxis()->SetTitle("cos(#Delta #phi (W,lep))");
    TH1F* hWpt = new TH1F("histWpt","Wpt after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);
    hWpt->GetXaxis()->SetTitle("P_T (W) [GeV]");
    TH1F* hWpt2 = new TH1F("histWpt2","Wpt2 after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);
    TH1F* hCosDelPhiWlep = new TH1F("histCosDelPhiWlep","CosDelPhiWlep after Njet>2 Nbjet>2 & Single Lepton selec.",100,-1., 1.);
    hCosDelPhiWlep->GetXaxis()->SetTitle("cos(#Delta #phi (W,lep))");
    TH1F* hRatio = new TH1F("hRatio","Ratio after Njet>2 Nbjet>2 & Single Lepton selec.",100,0.,10.);
    hRatio->GetXaxis()->SetTitle("P_{T}(lep)/P_{T}(W)");
    TH1F* hLp = new TH1F("histLp","Lp after Njet>2 Nbjet>2 & Single Lepton selec.",500,-5,5);
    hLp->GetXaxis()->SetTitle("Lp");
    
    
    
    TH2F* hDelPhi_LpWpt_ep = new TH2F("hDelPhi_LpWpt_ep","DelPhi_LpWpt secondlargest after Njet>2 Nbjet>2 & Single Lepton selec.",10,-1.,1.,100,0.,2.);
    hDelPhi_LpWpt_ep->GetYaxis()->SetTitle("P_{T}(lep)/P_{T}(W)");
    hDelPhi_LpWpt_ep->GetXaxis()->SetTitle("cos(#Delta #phi (W,lep))");
    TH1F* hWpt_ep = new TH1F("histWpt_ep","Wpt secondlargest after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);
    hWpt_ep->GetXaxis()->SetTitle("P_T (W) [GeV]");
    TH1F* hWpt2_ep = new TH1F("histWpt2_ep","Wpt2 secondlargest after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,2500);
    TH1F* hCosDelPhiWlep_ep = new TH1F("histCosDelPhiWlep_ep","CosDelPhiWlep secondlargest after Njet>2 Nbjet>2 & Single Lepton selec.",100,-1., 1.);
    hCosDelPhiWlep_ep->GetXaxis()->SetTitle("cos(#Delta #phi (W,lep))");
    TH1F* hRatio_ep = new TH1F("hRatio_ep","Ratio secondlargest after Njet>2 Nbjet>2 & Single Lepton selec.",100,0.,5.);
    hRatio_ep->GetXaxis()->SetTitle("P_{T}(lep)/P_{T}(W)");
    TH1F* hLp_ep = new TH1F("histLp_ep","Lp secondlargest after Njet>2 Nbjet>2 & Single Lepton selec.",500,-5,5);
    hLp_ep->GetXaxis()->SetTitle("Lp");
    
    
    TH1F* CosPhiSFOS2= new TH1F("CosPhiSFOS2","cos(#Delta#phi) SameFlavour OS -El+El after preselection",100,-1,1);
    TH1F* CosPhiSFOS1= new TH1F("CosPhiSFOS1","cos(#Delta#phi) Same Flavour OS Mu-mu after preselection",100,-1,1);
    
    TH1F* CosPhiSFSS2= new TH1F("CosPhiSFSS2","cos(#Delta#phi) SameFlavour SS mu+ mu+ after preselection",100,-1,1);
    TH1F* CosPhiSFSS1= new TH1F("CosPhiSFSS1","cos(#Delta#phi) Same Flavour SS e+e+ after preselection",100,-1,1);
    TH1F* CosPhiSFSS3= new TH1F("CosPhiSFSS3","cos(#Delta#phi) Same Flavour SS e+mu+ after preselection",100,-1,1);
    
    TH1F* CosPhiOFOS3= new TH1F("CosPhiOFOS3","cos(#Delta#phi) OFOS -Mu+El",100,-1,1);
    TH1F* CosPhiOFOS4= new TH1F("CosPhiOFOS4","cos(#Delta#phi) OFOS Mu-El",100,-1,1);
    
    
    
    TH1F* CosThetaSFOS1=new TH1F("CosThetaSFOS1","cos(#theta) Same Flavour OS el-el", 100,-1,1);
    TH1F* CosThetaSFOS2=new TH1F("CosThetaSFOS2","cos(#theta) Same Flavour OS mu -mu", 100,-1,1);
    TH1F* CosThetaOFOS3=new TH1F("CosThetaOFOS3","cos(#theta) Opposite Flavour OS mu -el", 100,-1,1);
    TH1F* CosThetaOFOS4=new TH1F("CosThetaOFOS4","cos(#theta) Opposite Flavour OS el -mu", 100,-1,1);
    
    TH1F* CosThetaSFSS1=new TH1F("CosThetaSFSS1","cos(#theta) Same Flavour SS el+el", 100,-1,1);
    TH1F* CosThetaSFSS2=new TH1F("CosThetaSFSS2","cos(#theta) Same Flavour SS mu+mu", 100,-1,1);
    TH1F* CosThetaSFSS3=new TH1F("CosThetaSFSS3","cos(#theta) Same Flavour SS mu+el", 100,-1,1);
    
    
    TH1F* aMET       = new TH1F("aMET","MET after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);
    TH1F* aDelphMET  = new TH1F("aDelphMET","Delphes MET after Njet>2 Nbjet>2 & Single Lepton selec. ",100,0,5000);

    TH1F* aMT        = new TH1F("aMT","MT if MT!=0 after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);
    TH1F* aDelphMT   = new TH1F("aDelphMT","DMT if DMT!=0 after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);
    TH1F* aMT2       = new TH1F("aMT2","MT if MT!=0 after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);
    TH1F* aDelphMT2  = new TH1F("aDelphMT2","Delphes MT after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);


    TH1F* aMT2W       = new TH1F("aMT2W","MT2W (if MT2W>0&&MT2W<499) after Njet>2 Nbjet>2 & Single Lepton selec.",20,0,600);
    TH1F* aDelphMT2W  = new TH1F("aDelphMT2W","Delphes MT2W if(DMT2W>0&&DMT2W<499) after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,500);
    TH1F* aMT2W2      = new TH1F("aMT2W2","MT2W after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,1000);
    TH1F* aDelphMT2W2 = new TH1F("aDelphMT2W2","Delphes MT2W if(DMT2W>0&&DMT2W<499) after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,500);

    TH1F* aHT        = new TH1F("aHT","HT40 after Njet>2 Nbjet>2 & Single Lepton selec.",400,0,7000);
    TH1F* aLepPt     = new TH1F("aLepPt","single lep Pt after Njet>2 Nbjet>2 & Single Lepton selec.",200,0,7000);
    TH1F* aLepEta     = new TH1F("aLepEta","single lep Eta after Njet>2 Nbjet>2 & Single Lepton selec.",100,-3,3);
    TH1F* a1JetPt    = new TH1F("a1JetPt","highest jet Pt after baseline selection for jets",50,0,5000);
    TH1F* a1bJetPt   = new TH1F("a1bJetPt","highest bjet Pt",50,0,5000);
    TH1F* an1bJetPt   = new TH1F("an1bJetPt","2bd and more highest bjets Pt",100,0,5000);

    TH1F* hMET   = new TH1F("hMET","before DMET>250 after MT>150 cut",50,0,5000);
    TH1F* hMET_2   = new TH1F("hMET_2","after DMET>250 cut",50,0,5000);
    TH1F* MET_1   = new TH1F("MET_1","MET before MET cuts after Njet>2 Nbjet>2 & Single Lepton selec.",200,0,5000);
    TH1F* MET_2   = new TH1F("MET_2","after HT>500 & (d)phi>0.8 & (D)MET>250 cut",200,0,7000);
    TH1F* MET_3   = new TH1F("MET_3","MET after all cuts",200,0,2000);
//    TH1F* MET_hist   = new TH1F("MET_hist","MET after all cuts",200,0,2000);

    TH1F* MT_1   = new TH1F("MT_1","MT before cuts after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,5000);
    TH1F* MT_2   = new TH1F("MT_2","after HT>500 & DMET>250 & (d)phi>0.8 cut",100,0,5000);
    TH1F* MT_3   = new TH1F("MT_3","after all cuts",100,0,5000);


    TH1F* MT2W_1   = new TH1F("MT2W_1","before cuts after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,1000);
    TH1F* MT2W_2   = new TH1F("MT2W_2","after HT>500 & (d)phi>0.8 & (D)MET>250 cut",100,0,1000);
    TH1F* MT2W_3   = new TH1F("MT2W_3","after all cuts",100,200,600);

    TH1F* hMT    = new TH1F("hMT","before MT>200 after HT>500 & (d)phi>0.8 & (D)MET>250 cut",100,0,5000);
    TH1F* hMT_2    = new TH1F("hMT_2","after MT>200 cut (after all cuts)",100,0,5000);
    
    TH1F* hMT2Wpre  = new TH1F("hMT2Wpre","MT2W w/o MET,MT req.",100,0,1000);
    TH1F* hMT2WDelph_pre  = new TH1F("hMT2WDelph_pre","MT2W w/o MET,MT req. from Delph",100,0,500);
    TH1F* hMT2W  = new TH1F("hMT2W","MT2W",100,0,1000);
    TH1F* hMT2W_2  = new TH1F("hMT2W_2","after MT2W>250 cut",100,0,1000);
    TH1F* hMETMeff  = new TH1F("hMETMeff","MET/(MET+HT)",100,0,1);
    
    TH1F* hHT    = new TH1F("hHT","HT40 before HT>500 after (d)phi>0.8 & (D)MET>250 & MT>150 cut",40,0,8000);
    TH1F* hHT_2   = new TH1F("hHT_2","HT40 after HT>500 & (d)phi>0.8 & (D)MET>250 cut",50,0,8000);
    TH1F* HT_1    = new TH1F("HT_1","just Before single lepton selection",100,0,10000);
    TH1F* HT_2    = new TH1F("HT_2","after DMET>250 before (d)phi>0.8 cut",100,0,7000);
    TH1F* HT_3    = new TH1F("HT_3","after all Cuts",100,0,7000);



    TH1F* hDphi  = new TH1F("hDphi","#Delta#phi before dPhi>0.8f cut",100,0,4);
    TH1F* hDphi_2  = new TH1F("hDphi_2","#Delta#phi after dPhi>0.8 cut",100,0,4);
    TH1F* hDelphdphi  = new TH1F("hDelphdphi","#Delta#phi (Delphdphi) before dPhi>0.8f cut",100,0,4);
    TH1F* hDelphdphi_2  = new TH1F("hDelphdphi_2","#Delta#phi after dPhi>0.8 cut",100,0,4);
    TH1F* hAllHT = new TH1F("hAllHT","before all cuts HT40",100,0,9000);
    TH1F* hAllLepPt = new TH1F("hAllLepPt","single lep Pt after single lepton selection",40,0,5000);


    TH1F* hLepPtJb = new TH1F("hLepPtJb","PT of lepton after Njet>2 & Nbjet>2 ",400,0,4000);
    TH1F* hLepPtM = new TH1F("hLepPtM","lep Pt before HT>500 after (d)phi>0.8 & (D)MET>250 cut",100,0,5000);
    TH1F* hLepPtMM = new TH1F("hLepPtMM","lep Pt after all cuts",200,0,5000);
    TH1F* hLepEtaJb = new TH1F("hLepEtaJb","#eta of lepton after Njet>2 & Nbjet>2",100,-3.0,3.0);
    TH1F* hLepEtaM = new TH1F("hLepEtaM","#eta of lep before HT>500 after (d)phi>0.8 & (D)MET>250 cut",100,-4.5,4.5);
    TH1F* hLepEtaMM = new TH1F("hLepEtaMM","eta after all cuts",100,-4.5,4.5);

    TH1F* LepPtt = new TH1F("LepPtt","after all Quality Cuts",100,0,7000);
    TH1F* IsoElectron=new TH1F("IsoElectron","IsoElectron",100,0,1000);

    TH1F* abasym   = new TH1F("abasym","(bjetsPt-lepPt)/(bjetsPt+lepPt) after Njet>2 Nbjet>2 & Single Lepton selec.",100,-1,1);
    TH1F* hbasym   = new TH1F("hbasym","(bjetsPt-lepPt)/(bjetsPt+lepPt) after if(basym>-0.2) ",100,-1,1);
    TH1F* aC      = new TH1F("aC","centrality before MET>250 cut after Njet>2 Nbjet>2 & Single Lepton selec.",100,0,10);
    TH1F* hC      = new TH1F("hC","centrality after MT>150 cut",100,0,5);
    
    // nS //
    TH1F* atop = new TH1F("atop","topness",100,-21,21);
    TH1F* atop0 = new TH1F("atop0","topness Delph MET",100,-21,21);
    TH1F* htop = new TH1F("htop","topness",100,-21,21);
    TH1F* htop0 = new TH1F("htop0","topness Delph MET",100,-21,21);

    TH1F* htHT    = new TH1F("htHT","topness HT40",100,0,7000);
    TH1F* htDphi  = new TH1F("htDphi","topness #Delta#phi",100,0,4);

    TH1F* Beta= new TH1F("Beta","Pt/Et",100,0,1000);
    
    TH1I* hNel = new TH1I("hNel","N good(30) before Njet>2 Nbjet>2 Lepton check",10,0,10);
    TH1I* hNel_2 = new TH1I("hNel_2","Single after Njet>2 Nbjet>2Lepton check",10,0,10);
    TH1I* hNmu = new TH1I("hNmu","N good(30) mu",10,0,10);
    TH1I* hNmu_2 = new TH1I("hNmu_2","N good(30) mu after Njet>2 Nbjet>2Lepton check ",10,0,10);
    TH1I* hNlep = new TH1I("hNlep","N good(30) mu+el",10,0,10);
    TH1I* hNlep_2 = new TH1I("hNlep_2","N good(30) mu+el",10,0,10);
    TH1I* hNtj = new TH1I("hNtj","N good(40), before njtes>2",15,0,15);
    TH1I* hNtj_2 = new TH1I("hNtj_2","after N jets>2",15,0,15);
    TH1I* hNbjet = new TH1I("hNbjet","#bjets before Nbjet>2",15,0,15);
    TH1I* hNbjet_2 = new TH1I("hNbjet_2","#bjet after Nbjet>2",15,0,15);

    EasyChain* tree = new EasyChain("delphTree");
    
    for(unsigned i=0;i<files.size();i++){
               tree->AddSmartW(files[i],weights[i]);
        cout<<"add: "<<files[i]<<" "<<weights[i]<<endl;
    }

    int Nevents=tree->GetEntries();
    cout<<">>>>>>>>>>>>>>>>>>>>>>> total number of events:\t" << Nevents <<endl;

    // CutFlow variables
    const int CutNumb = 25;
/*
    const char * CutList[CutNumb] = {"Presel","sngl. lep.","tau veto",
                     "nJets >= 3","nJets >= 4","bjets == 1/2",
                                         "MET>500","dphi12 > 0.5",
                     "HT>1000",
                                         "MT>120",
                                         "--MT2W>250",
                                         " HT>1250"," HT>1500"," Meff>0.2"," Meff>0.3",
                     " top=9.5 ",
                                         " basym>-0.2",
                                         " HT>1250"," HT>1500"," Meff>0.2"," Meff>0.3",
                                         "C<3"
                                         " HT>1250"," HT>1500"," Meff>0.2"," Meff>0.3",
                                         };
*/
    const char * CutList[CutNumb] = {"Presel","sngl. lep.","tau veto",
                     "nJets >= 3","nJets >= 4","bjets == 1/2",
                                         "MET>250","dphi12 > 0.5",
                     "HT>500",
                                         "MT>200",
                                         "--MT2W>250",
                                         " MT2W>250","MT2W> 250"
                                         };
    double CFCounter[CutNumb];
    int   iCFCounter[CutNumb];

    for (int i=0;i < CutNumb; i++){
      CFCounter[i] = 0;
     iCFCounter[i] = 0;
    }
    TH1D* CutFlow= new TH1D("CutFlow","Cut Flow",CutNumb,0.5,CutNumb+0.5);
    // label bins
        for(int cj = 0; cj < CutNumb; cj++)
              CutFlow->GetXaxis()->SetBinLabel(cj+1,CutList[cj]);
              //double muonpt=1;
    //MuonPt.clear();
    for(int entry=0; entry < Nevents; entry+=1){

        /*MuonPt.clear();
        MuonEta.clear();
        ElectronEta.clear();
        ElectronPt.clear();*/
   //     cout<<"Dongu basladdiiiii****************************"<<endl;
        HT_CUT.clear();
        MET_CUT.clear();
        MT_CUT.clear();
        HT_CUT_SR0.clear();HT_CUT_SR1.clear();HT_CUT_SR2.clear();HT_CUT_SR3.clear();HT_CUT_SR4.clear();HT_CUT_SR5.clear();HT_CUT_SR6.clear();HT_CUT_SR7.clear();HT_CUT_SR8.clear();HT_CUT_SR9.clear();HT_CUT_SR10.clear();
        MET_CUT_SR0.clear();MET_CUT_SR1.clear();MET_CUT_SR2.clear();MET_CUT_SR3.clear();MET_CUT_SR4.clear();MET_CUT_SR5.clear();MET_CUT_SR6.clear();MET_CUT_SR7.clear();MET_CUT_SR8.clear();MET_CUT_SR9.clear();MET_CUT_SR10.clear();
        MT_CUT_SR0.clear();MT_CUT_SR1.clear();MT_CUT_SR2.clear();MT_CUT_SR3.clear();MT_CUT_SR4.clear();MT_CUT_SR5.clear();MT_CUT_SR6.clear();MT_CUT_SR7.clear();MT_CUT_SR8.clear();MT_CUT_SR9.clear();MT_CUT_SR10.clear();
        METOHT_CUT_SR0.clear();METOHT_CUT_SR1.clear();METOHT_CUT_SR2.clear();METOHT_CUT_SR3.clear();METOHT_CUT_SR4.clear();METOHT_CUT_SR5.clear();METOHT_CUT_SR6.clear();METOHT_CUT_SR7.clear();METOHT_CUT_SR8.clear();METOHT_CUT_SR9.clear();METOHT_CUT_SR10.clear();
        
//        LepPT_CUT.clear();
//        JET_Multp.clear();
//        MT2W_CUT.clear();
        METOHT_CUT.clear();
        progressT();
        double fw = tree->GetEntryW(entry); // the applied with AddSmartW for the current file/dir

        double EvWeight = 1;
        if(useW) EvWeight = tree->Get(EvWeight,"EventWeight");
        EvWeight *= fw * 1000;

      //  double MTT   = tree->Get(MTT,"MT0");
        double MT  = tree->Get(MT,"MT");
    //    cout<<"MT baslangic"<<MT<<endl;
        double HT   = tree->Get(HT,"HT");   //      double top   = tree->Get(top,"top");
       // cout<<"top"<<top<<endl;
    //    double top0   =tree->Get(top0,"top0");
        
        hAllHT->Fill(HT,EvWeight);
        
        // 0. CF presel
         CFCounter[0]+= EvWeight;
        iCFCounter[0]++;
        
        std::vector<TLorentzVector> &Electrons = tree->Get(&Electrons,"Electrons");
        std::vector<TLorentzVector> &Muons = tree->Get(&Muons,"Muons");
        std::vector<int> &ElectronCh = tree->Get(&ElectronCh,"ElectronCh");
        std::vector<int> &MuonCh     = tree->Get(&MuonCh,"MuonCh");

        // 1. Lepton veto
        // etamin in ntupler 2.5, ptmin 10
        Int_t    Nel_tight = 0;
        Int_t    Nmu_tight = 0;
        Int_t    Nel_loose = Electrons.size();
        Int_t    Nmu_loose = Muons.size();
        
        
        // 
        TLorentzVector* Lep=0;
        TLorentzVector* TElectron=0;
       TLorentzVector* TMuon=0;
        vector<TLorentzVector> LTElectron;
        vector<TLorentzVector> LTMuon;
        vector<TLorentzVector> LTLepton;
        int TMuonCh=0;
        int TEleCh=0;
        double lepPt=0;
        double lepEta=0;
        double ElPt=0;
        double ElEta=0;
        double MuPt=0;
        double MuEta=0;
        vector<int> Ch_Muon;
        vector<int> Ch_Electron;
        vector<int> Ch_Lepton;
        double max=0;
        double secondlargest=0;
        double phi1=0;
        double phi2=0;
        int count1=0;
        int count2=0;
        double eta1=0;
        double eta2=0;
        int Charge1=0;
        int Charge2=0;
        double theta1=0;
        double theta2=0;
        double secondPx=0;
        double secondPy=0;
        double leadingPx=0;
        double leadingPy=0;
//        double LepPt=0;
        //MuonPt.clear();
  //      cout<<"MT baslangic2222"<<MT<<endl;
	for(Int_t i=0;i<Nmu_loose;++i) {
        hLepMuonPt2->Fill(Muons[i].Pt());
	hLepMuonEta2->Fill(Muons[i].Eta());
    		if(fabs(Muons[i].Eta())<=2.4&&Muons[i].Pt()>20 ){   //SUS-16-028-pas.pdf
                Nmu_tight++;
                lepPt=Muons[0].Pt();
                lepEta=Muons[0].Eta();
              
                hLepMuonPt->Fill(lepPt,EvWeight);
                hLepMuonEta->Fill(lepEta,EvWeight);
                Lep=&Muons[0];
                TMuon=&Muons[i];
                TMuonCh=MuonCh[i];
           //     cout<<"TMuonCh"<<TMuonCh<<endl;
             //   cout<<TMuon[i].Pt()<<endl;
             //   cout<<"TMuon[i].Phi()"<<TMuon[i].Phi()<<endl;
               LTMuon.push_back(*TMuon);
                Ch_Muon.push_back(TMuonCh);
                LTLepton.push_back(*TMuon);
                Ch_Lepton.push_back(TMuonCh*13);
              //  cout<<"LTElectron.Print()"<<LTElectron.Print()<<endl;
              //  cout<<"Nmu_tight"<<Nmu_tight<<endl;
          //      cout<<"LTMuon[i]"<<endl;
           //     LTMuon[i].Print();
            //   cout<<"Ch_Muon[i]"<<Ch_Muon[i]*13<<endl;
            }
    //    cout<<"Bitti"<<endl;
        }
        
 //       cout<<"MT baslangic3333"<<MT<<endl;
        for(Int_t i=0;i<Nel_loose;++i) {
	hLepElePt2->Fill(Electrons[i].Pt());
	hLepEleEta2->Fill(Electrons[i].Eta());
            if(fabs(Electrons[i].Eta())<=2.4&&Electrons[i].Pt()>20 ){     //SUS-16-028-pas.pdf
                Nel_tight++;
                lepPt=Electrons[0].Pt();
                lepEta=Electrons[0].Eta();
                hLepElePt->Fill(lepPt,EvWeight);
                hLepEleEta->Fill(lepEta,EvWeight);
                Lep=&Electrons[0];
                TElectron=&Electrons[i];
                TEleCh=ElectronCh[i];
                LTElectron.push_back(*TElectron);
                Ch_Electron.push_back(TEleCh);
                LTLepton.push_back(*TElectron);
                Ch_Lepton.push_back((TEleCh*11));
          //      cout<<"LTElecrotn[i]"<<endl;
            //    LTElectron[i].Print();
            //    cout<<"Ch_Electron[i]"<<Ch_Electron[i]*11<<endl;
           //     cout<<"TElectron.pt"<<TElectron[i].Pt()<<endl;
           //     cout<<"TElectron.phi"<<TElectron[i].Phi()<<endl;
            }
        }
        for(int k=0;k<(Nel_tight+Nmu_tight);++k){
         //   cout<<"k"<<k<<endl;
         //   cout<<"LTLEpton[k]"<<endl;
         //   LTLepton[k].Print();
         //   cout<<"Ch_Lepton[k]"<<Ch_Lepton[k]<<endl;
        }
        int tmu_size=LTMuon.size();
        int tel_size=LTElectron.size();
        
       // cout<<"max"<<max<<endl;
        for (int a=0; a<(Nel_tight+Nmu_tight); ++a) {
       //     cout<<"max"<<max<<endl;
            count1++;
          //  cout<<"LTLepton[a].Pt()"<<LTLepton[a].Pt()<<endl;
            if(max<=LTLepton[a].Pt()){
                max=LTLepton[a].Pt();
                phi1=LTLepton[a].Phi();
                eta1=LTLepton[a].Eta();
                Charge1=Ch_Lepton[a];
        //        cout<<"Charge1"<<Charge1<<endl;
                theta1=LTLepton[a].Theta();
                leadingPx=LTLepton[a].Px();
                leadingPy=LTLepton[a].Py();
            }
        //    cout<<"phi1"<<phi1<<endl;
        //    cout<<"count1"<<count1<<endl;
        }
       // cout<<"count1"<<count1<<endl;
       // largest=max;
  //      cout<<"MT baslangic4444"<<MT<<endl;
        if (count1>2) {
          //  cout<<"count1"<<count1<<endl;
            for (int b=0; b<(Nel_tight+Nmu_tight); ++b) {
                count2++;
           //     cout<<"max"<<max<<endl;
           //     cout<<"LTLepton[b].Pt()"<<LTLepton[b].Pt()<<endl;
                if (LTLepton[b].Pt()!=max) {
                    if(secondlargest<=LTLepton[b].Pt()){
            //            cout<<"if dngusundeyim"<<endl;
            //            cout<<"2ndlargest"<<secondlargest<<endl;
                        secondlargest=LTLepton[b].Pt();
            //            LTLepton[b].Print();
            //            cout<<LTLepton[b].Pt()<<endl;
                        phi2=LTLepton[b].Phi();
            //            cout<<"phi2"<<phi2<<endl;
                        eta2=LTLepton[b].Eta();
                        Charge2=Ch_Lepton[b];
            //            cout<<"Charge2"<<Charge2<<endl;
                        theta2=LTLepton[b].Theta();
                        secondPx=LTLepton[b].Px();
                        secondPy=LTLepton[b].Py();
                      //  cout<<"Theate"<<LTLepton[b].Theta();
                    }
              //       cout<<"phi2"<<phi2<<endl;
                }
            }
        }
        if (count1==2) {
            for(int aa=0;aa<(Nel_tight+Nmu_tight);++aa){
                if(aa!=(Nel_tight+Nmu_tight)){
                secondlargest=TMath::Min(LTLepton[aa].Pt(),LTLepton[aa+1].Pt());
                phi2=LTLepton[aa].Phi();
                eta2=LTLepton[aa].Eta();
                    theta2=LTLepton[aa].Theta();
                    secondPx=LTLepton[aa].Px();
                    secondPy=LTLepton[aa].Py();
                    //LTLepton[aa].Print();
                }
            }
        }
   //     cout<<"MT baslangic5555"<<MT<<endl;
        if(Charge1+Charge2==0 && Charge1%13==0){
            CosPhiSFOS1->Fill(cos(phi1-phi2));
            CosThetaSFOS2->Fill(cos(theta1-theta2));
        }
        if(Charge1+Charge2==22){
            CosPhiSFSS1->Fill(cos(phi1-phi2));
            CosThetaSFSS1->Fill(cos(theta1-theta2));
        }
        
        if(Charge1+Charge2==26){
            CosPhiSFSS2->Fill(cos(phi1-phi2));
            CosThetaSFSS2->Fill(cos(theta1-theta2));
        }
            
        if(Charge1+Charge2==24){
            CosPhiSFSS3->Fill(cos(phi1-phi2));
            CosThetaSFSS3->Fill(cos(theta1-theta2));
        }
        
        if(Charge1+Charge2==0 && Charge1%11==0){
            CosPhiSFOS2->Fill(cos(phi1-phi2));
            CosThetaSFOS1->Fill(cos(theta1-theta2));
        }
        
        if(Charge1+Charge2==-2){
            CosPhiOFOS3->Fill(cos(phi1-phi2));
            CosThetaOFOS4->Fill(cos(theta1-theta2));
        }
        
        if(Charge1+Charge2==2){
            CosPhiOFOS4->Fill(cos(phi1-phi2));
            CosThetaOFOS3->Fill(cos(theta1-theta2));
        }
        
        double deltaR=0;
        deltaR=sqrt((phi1-phi2)*(phi1-phi2)+(eta2-eta1)*(eta2-eta1));


             HT_1->Fill(HT,EvWeight);
//cout<<"MT baslangic6666"<<MT<<endl;
    //    cout<<"Nel_tight+Nmu_tigh"<<Nel_tight+Nmu_tight<<endl;
        // exactly 2 hard lepton, no other loose
       
        
        hNlep->Fill(Nel_tight+Nmu_tight);
        hNel->Fill(Nel_tight);
         hNmu->Fill(Nmu_tight);
      if((Nel_tight+Nmu_tight) != 1) continue;
   //     cout<<"Nel_loose+Nmu_loose after single selection=  "<<Nel_loose+Nmu_loose<<endl;
     //   cout<<"Nel_loose+Nmu_loose after single selection bef=  "<<Nel_loose+Nmu_loose<<endl;
     
        if((Nel_loose+Nmu_loose > 1)) continue;
        hNmu_2->Fill(Nmu_tight);
           hNel_2->Fill(Nel_tight);
        
        hNlep_2->Fill(Nel_tight+Nmu_tight);
    //    cout<<"Nel_loose+Nmu_loose after single selection2=  "<<Nel_loose+Nmu_loose<<endl;
    //    hNel_2->Fill(Nel_tight,EvWeight);    
         CFCounter[1]+= EvWeight;
        iCFCounter[1]++;
    //     cout<<"MT baslangic7777"<<MT<<endl;
        //burayı ben komut satırına aldım Ntau'yu daha sonra kullanacağında aç
        /*int Ntaujet   = tree->Get(Ntaujet,"Ntaujet"); 
        if(Ntaujet>0) continue;
        */ CFCounter[2]+= EvWeight;
        iCFCounter[2]++;
        
        hAllLepPt->Fill(lepPt,EvWeight);
        // 2. nJets >= 3,4
        vector<TLorentzVector> &Jets = tree->Get(&Jets,"Jets");
        int Njet_loose = tree->Get(Njet_loose,"Njet");
        int Njet_tight = 0;
        for(int i = 0;i  < Njet_loose; i++)
            if(Jets[i].Pt() > 20) Njet_tight++;
        
        hNtj->Fill(Njet_tight);
        if(Njet_tight < 1) continue;
         CFCounter[3]+= EvWeight;
        iCFCounter[3]++;
//        cout<<" eger Njet_tight < 1"<<Njet_tight<<endl;

        if(Njet_tight < 2) continue;
         CFCounter[4]+= EvWeight;
        iCFCounter[4]++;
//            cout<<" eger Njet_tight < 2"<<Njet_tight<<endl;
  
        hNtj_2->Fill(Njet_tight);
//           cout<<" eger Njet_tight <= 1"<<Njet_tight<<endl;
    //    JET_Multp.push_back(Njet_tight);    
        // 3. Btag cut
        
        double bjetpt=0;
        int Nbjet = 0;
        bool hardB = false;
        vector<int> &JetB = tree->Get(&JetB,"JetB");        
        for(unsigned i=0;i<Jets.size();i++) {
            if(JetB[i]>0&&Jets[i].Pt() > 20) {
                if(Nbjet==0) {
                    a1bJetPt->Fill(Jets[i].Pt());
                    bjetpt=Jets[i].Pt();
                }
                else         an1bJetPt->Fill(Jets[i].Pt());
                Nbjet++;
            }
            if(JetB[i]>0&&Jets[i].Pt() > 250) hardB=true;
        }
        
        
        hNbjet->Fill(Nbjet);
        if(Nbjet<=1) continue;
    //    cout<<"Nbjet"<<Nbjet<<endl;
        
        hNbjet_2->Fill(Nbjet);
        double MET  = tree->Get(MET,"MET");
        double DMET  = tree->Get(DMET,"DelphMET");
        bpMET->Fill(MET,EvWeight);
        bpDMET->Fill(DMET,EvWeight);
        apMET->Fill(MET,EvWeight);
        apDMET->Fill(DMET,EvWeight);
//        if(Nbjet<1||Nbjet>2) continue;        
         CFCounter[5]+= EvWeight;
        iCFCounter[5]++;

    //    HT_2->Fill(HT,EvWeight);
        hLepPtJb->Fill(lepPt,EvWeight);
        hLepEtaJb->Fill(lepEta,EvWeight);
//        aMuPt->Fill(MuPt,EvWeight);
//        aMuEta->Fill(MuEta,EvWeight);
//        aElPt->Fill(ElPt,EvWeight);
//        aElEta->Fill(ElEta,EvWeight);
                // distributions at 1lep4jet1b
        
        
//--------------Polarization of W ----
        double MET_Phi  = tree->Get(MET_Phi,"MET_Phi");
        double lepPhi=phi1;
        double DelPhiMetLep=fabs(MET_Phi-lepPhi);
        if (DelPhiMetLep > TMath::Pi()) DelPhiMetLep-=TMath::Pi();
        double Wpt = TMath::Sqrt( TMath::Power(MET,2) + TMath::Power(max,2) + 2*max*MET*TMath::Cos(DelPhiMetLep));
       // cout<<"Wpt"<<Wpt<<endl;
        double MetPx = MET*TMath::Cos(MET_Phi);
        double MetPy = MET*TMath::Sin(MET_Phi);
        double Wpt2 = TMath::Sqrt(pow((MetPx + leadingPx),2) + pow(MetPy + leadingPy,2));
        double Wphi = TMath::ATan( (MetPy + leadingPy) / (MetPx + leadingPx ) );
        double DelPhiWlep = fabs(Wphi - lepPhi);
        if (DelPhiWlep > TMath::Pi()) DelPhiWlep-=TMath::Pi();
        
        double coss =  TMath::Cos(DelPhiWlep);
        double ratio = max / Wpt;
        double Lp = (max/ Wpt) * TMath::Cos(DelPhiWlep);
        
            hWpt->Fill(Wpt, EvWeight);
            hWpt2->Fill(Wpt2,EvWeight);
            hCosDelPhiWlep->Fill(coss,EvWeight);
            hRatio->Fill(ratio,EvWeight);
            hDelPhi_LpWpt->Fill(TMath::Cos(DelPhiWlep),ratio,EvWeight);
            hLp->Fill(Lp,EvWeight);
    
        double lepPhi2=phi2;
        double DelPhiMetLep2=fabs(MET_Phi-lepPhi2);
        if (DelPhiMetLep2 > TMath::Pi()) DelPhiMetLep2-=TMath::Pi();
        double Wpt_sec = TMath::Sqrt( TMath::Power(MET,2) + TMath::Power(secondlargest,2) + 2*secondlargest*MET*TMath::Cos(DelPhiMetLep2));
        // cout<<"Wpt"<<Wpt<<endl;
        double Wpt2_sec = TMath::Sqrt(pow((MetPx + secondPx),2) + pow(MetPy + secondPy,2));
        double Wphi2 = TMath::ATan( (MetPy + secondPy) / (MetPx + secondPx ) );
        double DelPhiWlep2 = fabs(Wphi2 - lepPhi2);
        if (DelPhiWlep2 > TMath::Pi()) DelPhiWlep2-=TMath::Pi();
        
        double coss2 =  TMath::Cos(DelPhiWlep2);
        double ratio2 = secondlargest / Wpt_sec;
        double Lp2 = (secondlargest/ Wpt_sec) * TMath::Cos(DelPhiWlep2);
        
        
   
        hWpt_ep->Fill(Wpt_sec, EvWeight);
        hWpt2_ep->Fill(Wpt2_sec,EvWeight);
        hCosDelPhiWlep_ep->Fill(coss2,EvWeight);
        hRatio_ep->Fill(ratio2,EvWeight);
        hDelPhi_LpWpt_ep->Fill(TMath::Cos(DelPhiWlep2),ratio2,EvWeight);
        hLp_ep->Fill(Lp2,EvWeight);
        
      
        
        //----------------------------------------------------------
        
                double basym = (bjetpt-lepPt)/(bjetpt+lepPt);
                abasym->Fill(basym);
                
                vector<double> &JetMETdPhi = tree->Get(&JetMETdPhi,"JetMETdPhi");
                double dPhi = TMath::Min(JetMETdPhi[0],JetMETdPhi[1]);
                aDphi->Fill(dPhi,EvWeight);

                double DelphMET_Phi  = tree->Get(DelphMET_Phi,"DelphMET_Phi");
                double DelphdPhi = TMath::Min(acos(cos(Jets[0].Phi()-DelphMET_Phi)),acos(cos(Jets[1].Phi()-DelphMET_Phi)));
                aDelphDphi->Fill(DelphdPhi,EvWeight);
        
        // use of DelphMET or MET 
        /*
        double D_MET = 0.0;
        if(DELPH) D_MET  = tree->Get(D_MET,"DelphMET"); 
        else      D_MET  = tree->Get(D_MET,"MET");
        */
                
        
                aMET->Fill(MET,EvWeight);
                MET_1->Fill(MET,EvWeight);
        
                aDelphMET->Fill(DMET,EvWeight);
        //                
                double MT2W  = tree->Get(MT2W,"MT2W");
           //     cout<<"MT2W"<<MT2W<<endl;
                aMT2W2->Fill(MT2W,EvWeight);
                if(MT2W>0&&MT2W<499)aMT2W->Fill(MT2W,EvWeight);
        MT2W_1->Fill(MT2W,EvWeight);
        // nS //
        // for naturalSUSY 
        // double DMT2W  = tree->Get(DMT2W,"DelphMT2W");
        // for susyhit 
        double DMT2W  = tree->Get(DMT2W,"MT2W0");
                
        aDelphMT2W2->Fill(DMT2W,EvWeight);
                if(DMT2W>0&&DMT2W<499)aDelphMT2W->Fill(DMT2W,EvWeight);

      //   double MT  = tree->Get(MT,"MT");
   //     cout<<"MT"<<MT<<endl;
            aMT2->Fill(MT,EvWeight);
                if(MT!=0)aMT->Fill(MT,EvWeight);
                MT_1->Fill(MT,EvWeight);
        // nS //

        // for naturalSUSY
        //double DMT  = tree->Get(DMT,"DelphMT");
        // for susyhit
        double DMT  = tree->Get(DMT,"MT0");
  //      cout<<"DMT after get ree"<<DMT<<endl;
                aDelphMT2->Fill(DMT,EvWeight);
          //      cout<<"DMT degil MT"<<MT<<endl;
                if(DMT!=0)aDelphMT->Fill(DMT,EvWeight);
                aHT->Fill(HT,EvWeight);
                aLepPt->Fill(lepPt,EvWeight);
                aLepEta->Fill(lepEta,EvWeight);
                if(Jets[0].Pt()>30 && fabs(Jets[0].Eta())<2.4) a1JetPt->Fill(Jets[0].Pt(),EvWeight);
    
               // Centrality
        
        double METx,METy;
        if(DELPH){
        METx = cos(DelphMET_Phi)*DMET;
            METy = sin(DelphMET_Phi)*DMET;
        }else{
        METx = cos(MET_Phi)*MET;
            METy = sin(MET_Phi)*MET;
        }
                TLorentzVector a=Jets[0]+(*Lep);
                TLorentzVector b=Jets[1]+(*Lep);
                TLorentzVector c=b;
                b.SetPx(b.Px()+METx);
                b.SetPy(b.Py()+METy);
                double deta1=fabs(a.Eta()-b.Eta());
                a.SetPx(b.Px()+METx);
                a.SetPy(b.Py()+METy);
                double deta2=fabs(a.Eta()-c.Eta());
                double C=TMath::Max(deta1,deta2);
        aC->Fill(C,EvWeight);
        if(DELPH){ if(DMT2W>0)hMT2WDelph_pre->Fill(DMT2W,EvWeight);}
        else if(MT2W>0) hMT2Wpre->Fill(MT2W,EvWeight);
        
 //       cout<<"burda if önce"<<endl;
        //MT CUT
  //      cout<<"MT"<<MT<<endl;
    //    cout<<"MET"<<MET<<endl;
      //  cout<<"DMET"<<DMET<<endl;

    if(MT<150 || DMT<150) continue;
        //  MET/Meff
        hC->Fill(C,EvWeight);
//        cout<<"burda MT sonra--------------------------------------------------"<<endl;

                double Meff = DMET + HT;  //burasi MET+HT idi ben DMET yaptim
        if(DELPH)  Meff = DMET + HT;
        if(DELPH) { if(DMET>0)hMETMeff->Fill(DMET/Meff,EvWeight); } // don't remove the curly bracket!
        else  if(MET>0)hMETMeff->Fill(MET/Meff,EvWeight);
    //    cout<<"1.MetCUttan once Njet_tight"<<Njet_tight<<endl;    
        // 1. MET cut
  //      cout<<"1.denemee--------------------------------------------------"<<endl;
        MT_CUT_SR0.push_back(MT);
        HT_CUT_SR0.push_back(HT);
		MET_CUT_SR0.push_back(DMET);
		METOHT_CUT_SR0.push_back(MET/sqrt(HT));
        htHT->Fill(HT,EvWeight);
        
	if(DELPH){
         hMET->Fill(DMET,EvWeight);
    //     cout<<"1.MetCUttan Delph icinde Njet_tight"<<Njet_tight<<endl;
         if(DMET< 250) continue;
        hMET2->Fill(DMET);
   //     cout<<"2.denemee--------------------------------------------------"<<endl;
     //   cout<<"DMET 250CUT"<<DMET<<endl;
        
       //   cout<<"1.DMET>=250 Delph icinde Njet_tight"<<Njet_tight<<endl;
      //    cout<<"DMET"<<DMET<<endl;
        }
    
    else{
         hMET->Fill(MET,EvWeight);
      //  cout<<"MET degeri"<<MET<<endl;
         if(MET<250) continue;
         hMET2->Fill(MET);
      //  cout<<"MET degeri if den sonra"<<MET<<endl;
        }
    //    cout<<"MET=="<<MET<<endl;
    //    cout<<"1.MetCUttan sonra Njet_tight"<<Njet_tight<<endl;
        if(DMET< 250) continue;
        if(MET<250) continue;
//        cout<<"MET 250CUT"<<MET<<endl;
        
        //Assume Signal Region 1
        MT_CUT_SR1.push_back(MT);
  //      cout<<"MTaaaa"<<MT<<endl;
        HT_CUT_SR1.push_back(HT);
//        cout<<"HT"<<HT<<endl;
        MET_CUT_SR1.push_back(DMET);
//        LepPT_CUT_SR1.push_back(LepPt);
        METOHT_CUT_SR1.push_back(MET/sqrt(HT));
   //     cout<<"MET/sqrt(HT)"<<MET/sqrt(HT)<<endl;
 //  cout<<"3.denemee--------------------------------------------------"<<endl;
        
 //       cout<<"burda"<<endl;


    //    cout<<"jet_tight==3 && MT2W<200Den once Njet_tight"<<Njet_tight<<endl;
    //    cout<<"jet_tight==3 && MT2W<200Den once MT2W "<<MT2W<<endl;

        //SR2 Signal Region2
        if((DMET>250 && DMET<350) || (MET>250 && MET<350)){
            if(Njet_tight==3 && MT2W>200)  
            {
            //    cout<<" 250<DMET<350 || 250<MET<350"<<DMET<<endl;
            //    cout<<"jet_tight==3 && MT2W<200"<<Njet_tight<<endl;
                MT_CUT_SR2.push_back(MT);
                HT_CUT_SR2.push_back(HT);
                MET_CUT_SR2.push_back(DMET);
//                LepPT_CUT_SR2.push_back(LepPt);
                METOHT_CUT_SR2.push_back(MET/sqrt(HT));
            }
        
    
            //SR3 Signal Region 3
            if(Njet_tight>=4 && MT2W<=200)  
            {
            //    cout<<"Njet_tight>=4 && MT2W<=200"<<Njet_tight<<endl;
                MT_CUT_SR3.push_back(MT);
                HT_CUT_SR3.push_back(HT);
                MET_CUT_SR3.push_back(DMET);
//                LepPT_CUT_SR3.push_back(LepPt);
                METOHT_CUT_SR3.push_back(MET/sqrt(HT));
            }
        
            ////SR4 Signal Region 4
            if(Njet_tight>=4 && MT2W>200)  
            {
            //    cout<<"Njet_tight>=4 && MT2W>200"<< Njet_tight<<endl;
            //    cout<<"Njet_tight>=4 && MT2W>200"<< MT2W<<endl;
                MT_CUT_SR4.push_back(MT);
                HT_CUT_SR4.push_back(HT);
                MET_CUT_SR4.push_back(DMET);
//                LepPT_CUT_SR4.push_back(LepPt);
                METOHT_CUT_SR4.push_back(MET/sqrt(HT));
            }
        }



        if((DMET>350 && DMET<450) || (MET>350 && MET<450)){
            if(Njet_tight==3 && MT2W>200)  
            {
            //    cout<<" 350<DMET<450 || 350<MET<450"<<DMET<<endl;
            //    cout<<"jet_tight==3 && MT2W<200"<<Njet_tight<<endl;
                MT_CUT_SR5.push_back(MT);
                HT_CUT_SR5.push_back(HT);
                MET_CUT_SR5.push_back(DMET);
//                LepPT_CUT_SR5.push_back(LepPt);
                METOHT_CUT_SR5.push_back(MET/sqrt(HT));
            }
        
    
            //SR3 Signal Region 3
            if(Njet_tight>=4 && MT2W<=200)  
            {
            //    cout<<"Njet_tight>=4 && MT2W<=200"<<Njet_tight<<endl;
                MT_CUT_SR6.push_back(MT);
                HT_CUT_SR6.push_back(HT);
                MET_CUT_SR6.push_back(DMET);
//                LepPT_CUT_SR6.push_back(LepPt);
                METOHT_CUT_SR6.push_back(MET/sqrt(HT));
            }
        
            ////SR4 Signal Region 4
            if(Njet_tight>=4 && MT2W>200)  
            {
            //    cout<<"Njet_tight>=4 && MT2W>200"<< Njet_tight<<endl;
            //    cout<<"Njet_tight>=4 && MT2W>200"<< MT2W<<endl;
                MT_CUT_SR7.push_back(MT);
                HT_CUT_SR7.push_back(HT);
                MET_CUT_SR7.push_back(DMET);
//                LepPT_CUT_SR7.push_back(LepPt);
                METOHT_CUT_SR7.push_back(MET/sqrt(HT));
            }
        }

        if(DMET<450 || MET<450){
            if(Njet_tight==3 && MT2W<200)  
            {
            //    cout<<" 250<DMET<350 || 250<MET<350"<<DMET<<endl;
            //    cout<<"jet_tight==3 && MT2W<200"<<Njet_tight<<endl;
                MT_CUT_SR8.push_back(MT);
                HT_CUT_SR8.push_back(HT);
                MET_CUT_SR8.push_back(DMET);
//                LepPT_CUT_SR8.push_back(LepPt);
                METOHT_CUT_SR8.push_back(MET/sqrt(HT));
            }
        
    
            //SR3 Signal Region 3
            if(Njet_tight>=4 && MT2W<=200)  
            {
            //    cout<<"Njet_tight>=4 && MT2W<=200"<<Njet_tight<<endl;
                MT_CUT_SR9.push_back(MT);
                HT_CUT_SR9.push_back(HT);
                MET_CUT_SR9.push_back(DMET);
//                LepPT_CUT_SR9.push_back(LepPt);
                METOHT_CUT_SR9.push_back(MET/sqrt(HT));
            }
        
            ////SR4 Signal Region 4
            if(Njet_tight>=4 && MT2W>200)  
            {
            //    cout<<"Njet_tight>=4 && MT2W>200"<< Njet_tight<<endl;
            //    cout<<"Njet_tight>=4 && MT2W>200"<< MT2W<<endl;
                MT_CUT_SR10.push_back(MT);
                HT_CUT_SR10.push_back(HT);
                MET_CUT_SR10.push_back(DMET);
//                LepPT_CUT_SR10.push_back(LepPt);
                METOHT_CUT_SR10.push_back(MET/sqrt(HT));
            }
        }
        
     //   cout<<"burda"<<endl;
         CFCounter[6]+= EvWeight;
        iCFCounter[6]++;
        hMET_2->Fill(DMET,EvWeight);
        HT_2->Fill(HT,EvWeight);
        
        
        // 6. dPhi  - had been inverted in first version
        if(DELPH){
         hDelphdphi->Fill(DelphdPhi,EvWeight);
         if(DelphdPhi <= 0.8) continue; //buradaki degerler 0.5 idi
        }else{
         hDphi->Fill(dPhi,EvWeight);
         if(dPhi <= 0.8f) continue; //burdaki deger de 0.5 idi
        }
        hDphi_2->Fill(DelphdPhi,EvWeight);
        hDelphdphi_2->Fill(DelphdPhi,EvWeight);
         CFCounter[7]+= EvWeight;
        iCFCounter[7]++;
        
        hLepPtM->Fill(lepPt,EvWeight);
        hLepEtaM->Fill(lepEta,EvWeight);

        // 8. HT cut
     //   cout<<"MTCUTT"<<MT<<endl;
        hHT->Fill(HT,EvWeight);
        if(HT<500) continue; //HT<=800 idi sadece
         CFCounter[8]+= EvWeight;
        iCFCounter[8]++;
        hHT_2->Fill(HT,EvWeight);
        MET_2->Fill(MET,EvWeight);
        MT_2->Fill(MT,EvWeight);
        MT2W_2->Fill(MT2W,EvWeight);
        // 5. MT cut
        //double MT  = tree->Get(MT,"MT");
        if(DELPH){
         hMT->Fill(MT,EvWeight);  //bu satir DMT idi MT yaptim
         if(MT<200) continue;  //DMT<=200 yi MT yaptim asagidaki 3 satiri ben komut satiri yaptim
        }/*else{
         hMT->Fill(MT,EvWeight);
         if(MT<=200) continue;
        }*/
        hMT_2->Fill(MT,EvWeight);
         CFCounter[9]+= EvWeight;
        iCFCounter[9]++;
        
        double flagMT2W=true;
        if(DELPH){
         if(DMT2W>0) hMT2W->Fill(DMT2W,EvWeight); 
          if(DMT2W>170) continue; //DMT2W<250
         }else{
         if(MT2W>0) hMT2W->Fill(MT2W,EvWeight);
     //   cout<<"burdaaaa"<<endl;
          if(MT2W<250) /*flagMT2W=false;*/ continue; //MT2W<250
         }
//        hNtj_2->Fill(Njet_tight,EvWeight);
        //DONT CHANGE THE ORDER OF 3 LINES AS SEEN IN BELOW
        double LepPt=0;
//        LepPt=MuPt+ElPt;
        HT_3->Fill(HT,EvWeight);
        MET_3->Fill(DMET,EvWeight);
        MT_3->Fill(MT,EvWeight);
        MT2W_3->Fill(MT2W,EvWeight);
        hMT2W_2->Fill(MT2W,EvWeight);
        LepPtt->Fill(lepPt,EvWeight);
  //      cout<<"MT"<<MT<<endl;
        MT_CUT.push_back(MT/*ML2_140PU_weight*/);
        HT_CUT.push_back(HT/*ML2_140PU_weight*/);
        MET_CUT.push_back(DMET/*ML2_140PU_weight*/);
//        LepPT_CUT.push_back(LepPt);
        METOHT_CUT.push_back(MET/sqrt(HT));
//        MT2W_CUT.push_back(MT2W/*ML2_140PU_weight*/);
    //    JET_Multp.push_back(Njet_tight*EvWeight);



    //    TreeB3 ->Fill();
       TreeSR0->Fill();
        TreeSR1->Fill();
        TreeSR2->Fill();
        TreeSR3->Fill();
        TreeSR4->Fill();
        TreeSR5->Fill();
        TreeSR6->Fill();
        TreeSR7->Fill();
        TreeSR8->Fill();
        TreeSR9->Fill();
        TreeSR10->Fill();



         //if(flagMT2W)    //asagidaki 3 satiri komuta aldim
         /*if(DMT2W<250) continue;
         CFCounter[10]+= EvWeight;
        iCFCounter[10]++; */    
        hLepPtMM->Fill(lepPt,EvWeight);
        hLepEtaMM->Fill(lepEta,EvWeight);
     //   htop->Fill(top,EvWeight);
 //       htop0->Fill(top0,EvWeight);

        //HT_1->Scale(1,"width");
        //TreeB background doldurulacağında aşağıdaki 2 satırın command'i kaldırılır
        //MT2W_CUT.push_back(MT2W*1.45);
        //TreeB->Fill();    
    /*    if(top!=0)htop->Fill(top,EvWeight);
        if(top0!=0)htop0->Fill(top0,EvWeight);
        if(DELPH){
          if(top0<=9.5) continue;
         }else{
          if(top<=9.5) continue;
         }
         CFCounter[11]+= EvWeight;
        iCFCounter[11]++;
        if(DMT2W>300){
         CFCounter[12]+= EvWeight;
        iCFCounter[12]++;
        }
        if(DMT2W>350){
         CFCounter[13]+= EvWeight;
        iCFCounter[13]++;
        }
               
          if(top0<=12.5) continue;
         CFCounter[14]+= EvWeight;
        iCFCounter[14]++;
*/
        // 21. topness cut
        
        
        // 22. b lep pt asym
                  if(basym<=-0.2) continue;
        hbasym->Fill(basym,EvWeight);

        if(HT>1250){
         CFCounter[17]+= EvWeight;
        iCFCounter[17]++;
        }
        if(HT>1500){
         CFCounter[18]+= EvWeight;
        iCFCounter[18]++;
        }
        if(MET/Meff>0.2){
         CFCounter[19]+= EvWeight;
        iCFCounter[19]++;
        }
        if(MET/Meff>0.3){
         CFCounter[20]+= EvWeight;
        iCFCounter[20]++;
        }
        
        if(C>=3) continue;
         CFCounter[21]+= EvWeight;
        iCFCounter[21]++;
        
        if(HT>125){
         CFCounter[22]+= EvWeight;
        iCFCounter[22]++;
        }
        if(HT>1500){
         CFCounter[23]+= EvWeight;
        iCFCounter[23]++;
        }
        if(MET/Meff>0.2){
         CFCounter[24]+= EvWeight;
        iCFCounter[24]++;
        }
        if(MET/Meff>0.3){
         CFCounter[25]+= EvWeight;
        iCFCounter[25]++;
        }

//TreeS->Fill();    
    }

    // ^loop end^
    
    //OutTree->Fill();
    //cout<<"Nmu_tight :"<<Nmu_tight<<endl;
    double hnmuentries=hNmu->GetEntries();    
    cout<<"hnmuentries :"<<hnmuentries<<endl;

    ofstream tfile;
    if(DELPH)tfile.open("DeepSingle+DelphMET_"+outname+".txt");
    else tfile.open("DeepSingle+MET_"+outname+".txt");
    tfile << "########################################" << endl;
    tfile << "Cut efficiency numbers:" << endl;
/*    for(int ci = 0; ci < CutNumb; ci++)
    {
        tfile << "After cut " << CutList[ci] <<  "\t\t\t"
              << CFCounter[ci]  << "\t events left\t"<< iCFCounter[ci] <<" cnt\t"<< endl;
        CutFlow->SetBinContent(1+ci,CFCounter[ci]);
    }
*/
    TFile * outf;
    if(DELPH) outf  = new TFile("DeepSingle+DelphMET_"+outname+"_his.root","RECREATE");
    else  outf  = new TFile("DeepSingle+MET_"+outname+"_his.root","RECREATE");


    hLepElePt->Write();
    hLepMuonPt->Write();
    hLepMuonEta->Write();
    hLepEleEta->Write();
    
    
    
    IsoElectron->Write();
    CosPhiSFOS2->Write();
    CosPhiSFOS1->Write();
    CosPhiOFOS4->Write();
    CosPhiOFOS3->Write();
 
    CosThetaSFOS2->Write();
    CosThetaSFOS1->Write();
    CosThetaOFOS3->Write();
    CosThetaOFOS4->Write();
    
    hLepElePt2->Write();
    hLepMuonPt2->Write();
    hLepMuonEta2->Write();
    hLepEleEta2->Write();
    
    CosPhiSFSS1->Write();
    CosPhiSFSS2->Write();
    CosPhiSFSS3->Write();
    
    CosThetaSFSS1->Write();
    CosThetaSFSS2->Write();
    CosThetaSFSS3->Write();


    hMET2->Write();
    apMET->Write();
    bpMET->Write();
    apDMET->Write();
    bpDMET->Write();

    hDphi->Write();
    hDphi_2->Write();
    hDelphdphi->Write();
    hDelphdphi_2->Write();
    hHT->Write();
    hHT_2->Write();
    hAllHT->Write();
    hMETMeff->Write();
    hMET->Write();
    hMET_2->Write();
    hMT->Write();
    hMT_2->Write();
    hMT2W->Write();
    hMT2W_2->Write();
    hNel->Write();
    hNel_2->Write();
    hNlep_2->Write();
    hNmu->Write();
    hNtj->Write();
    hNtj_2->Write();
    hNel->Write();
    hNmu->Write();
    hNmu_2->Write();
    hNlep->Write();
    hNbjet->Write();
    hNbjet_2->Write();
 
    hLp_ep->Write();
    
    hWpt->Write();
    hWpt2->Write();
    hRatio->Write();
    hDelPhi_LpWpt->Write();
    hCosDelPhiWlep->Write();
    
    hWpt_ep->Write();
    hWpt2_ep->Write();
    hRatio_ep->Write();
    hDelPhi_LpWpt_ep->Write();
    hCosDelPhiWlep_ep->Write();
    

    HT_1->Write();    
    HT_2->Write();
    HT_3->Write();

    MT_1->Write();
        MT_2->Write();
        MT_3->Write();

    
    Beta->Write();
    MET_1->Write();
        MET_2->Write();
        MET_3->Write();

    MT2W_1->Write();
        MT2W_2->Write();
        MT2W_3->Write();

    hLp->Write();

    hAllLepPt->Write();
    hLepPtJb->Write();
    hLepPtM->Write();
    hLepPtMM->Write();
    hLepEtaJb->Write();
    hLepEtaM->Write();
    hLepEtaMM->Write();

    hMT2WDelph_pre->Write();
    hMT2Wpre->Write();

    LepPtt->Write();
        aDphi->Write();
        aDelphDphi->Write();

        aMET->Write();
        aDelphMET->Write();

        aMT->Write();
        aMT2->Write();
        aDelphMT->Write();
        aDelphMT2->Write();

        aMT2W->Write();
        aMT2W2->Write();
        aDelphMT2W->Write();
        aDelphMT2W2->Write();

        aHT->Write();
        aLepPt->Write();
        aLepEta->Write();
        a1JetPt->Write();
        a1bJetPt->Write();
        an1bJetPt->Write();

        atop->Write();      
    atop0->Write();
    htop->Write();
    htop0->Write();
    htHT->Write();
    htDphi->Write();
    abasym->Write();
    hbasym->Write();
    aC->Write();
    hC->Write();
//    for(int i=0;i<check.size();i++){
//        cout<<check[i]<<" "<<CutList[i]<<endl;
//    }

/*Int_t sizeofMuonpt=MuonPt.size();
for(Int_t a=0;a<MuonPt.size();a++){
cout<<"MuonPt[a]"<<MuonPt[a]<<endl;
}
//cout<<"muonpt"<<muonpt<<endl;
cout<<"sizeofMuonpt:"<<sizeofMuonpt<<endl;
//OutTree->Fill();
//OutTree->Print();*/
    TreeB0->Write();
    TreeB1->Write();
    TreeB2->Write();
TreeB3->Write();
TreeSR0->Write();
TreeSR1->Write();
TreeSR2->Write();
TreeSR3->Write();
TreeSR4->Write();
TreeSR5->Write();
TreeSR6->Write();
TreeSR7->Write();
TreeSR8->Write();
TreeSR9->Write();
TreeSR10->Write();
/*for(Int_t a=0;a<MuonPt.size();a++){
MuPT[a]->Fill();
}*/
//OutFile->Close();
//OutTree->Fill();
}
