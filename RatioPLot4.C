
//To execute root -l 'RatioPLot.C("HT","KNN",0.1,0.15,0.2,0.5,"topjets","50PU","ForSignal")' 
#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include "TPad.h"    
#include "TAttFill.h" 
#include "TAttPad.h"
#include "TAttLine.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TAttText.h"
#include "TLatex.h"
void RatioPLot4(TString variable,TString method,Float_t ct1,Float_t ct2,Float_t ct3,Float_t ct4,TString filen,TString PU,TString sigbck)
{
    gROOT->Reset();
    //gROOT->Reset();
    gROOT->SetStyle("Plain");
    gStyle->SetOptStat(kFALSE);
    //aşağıdaki satırda "t" yazmazsam algılamıyor alttaki satır başlıktaki yazının boyutu
    gStyle->SetTitleSize(0.04,"t"); //0.33
    gStyle->SetTitleBorderSize(0); //başlığın etrafındaki çerçeve kalınlığı
    gStyle->SetTitleX(0.08); //graph title X location
    gStyle->SetTitleY(0.97); //graph title Y location 
    gStyle->SetPadBorderMode(0);
    gStyle->SetFrameBorderMode(0);
    //gStyle->SetLineStyleString(5,"400 200");
    //gStyle->SetLineStyleString(5,"20 12 4 12");
   ////


    TCanvas* c1 = new TCanvas("c1","stack_"+sigbck,65,52,489,590) ;

    TLegend *pl = new TLegend(0.55, 0.7, 0.9, 0.87); 
    pl->SetTextSize(0.04); 
    pl->SetFillColor(0);
    pl->SetBorderSize(0);


    TLegend *pl2 = new TLegend(0.574949, 0.657671, 0.765914, 0.923845); 
    pl2->SetTextSize(0.1); 
    pl2->SetFillColor(0);
    pl2->SetBorderSize(0);



    TLine *l=new TLine(50.0,1.0,2100.0,1.0);
    l->SetLineColor(kBlue);
    l->SetLineStyle(7);

    TString Fsct1=" ";
    TString sct1=Form("%f",ct1); //float to stirng ct
    TString Fsct1=sct1(0,4);

    TString Fsct2=" ";
    TString sct2=Form("%f",ct2); //float to stirng ct
    TString Fsct2=sct2(0,4);
    
    TString Fsct3=" ";
    TString sct3=Form("%f",ct3); //float to stirng ct
    TString Fsct3=sct3(0,4);


    TString Fsct4=" ";
    TString sct4=Form("%f",ct4); //float to stirng ct
    TString Fsct4=sct4(0,4);

    TH1F* Signal1,Signal1a;
    TFile *bkg1 = TFile::Open(variable+"_"+method+"_"+Fsct1+"_"+filen+"_"+PU+sigbck+".root");
    Signal1= (TH1F*) bkg1->Get("htemp");
    Signal1->SetLineColor(kRed);
	
    TH1F* Signal2;
    TFile *bkg2 = TFile::Open(variable+"_"+method+"_"+Fsct2+"_"+filen+"_"+PU+sigbck+".root");
    Signal2= (TH1F*) bkg2->Get("htemp");
    Signal2->SetLineColor(kBlue);

    TH1F* Signal3,Signal3a;
    TFile *bkg3 = TFile::Open(variable+"_"+method+"_"+Fsct3+"_"+filen+"_"+PU+sigbck+".root");
    Signal3= (TH1F*) bkg3->Get("htemp");
    Signal3->SetLineColor(kGreen);

    TH1F* Signal4;
    TFile *bkg4 = TFile::Open(variable+"_"+method+"_"+Fsct4+"_"+filen+"_"+PU+sigbck+".root");
    Signal4= (TH1F*) bkg4->Get("htemp");
    Signal4->SetLineColor(kYellow);
   
    pl->AddEntry(Signal4,method+">"+Fsct4 ,  "lpf");
    pl->AddEntry(Signal3, method+">"+Fsct3,"lpf");
    pl->AddEntry(Signal2,method+">"+Fsct2 ,  "lpf");
    pl->AddEntry(Signal1,method+">"+Fsct1 ,  "lpf");
    pl2->AddEntry(Signal1,method+"_{"+Fsct1+"}/^{}"+method+"_{"+Fsct2+"}" ,  "lpf");
    pl2->AddEntry(Signal3,method+"_{"+Fsct3+"}/^{}"+method+"_{"+Fsct2+"}" ,  "lpf");
    pl2->AddEntry(Signal4,method+"_{"+Fsct4+"}/^{}"+method+"_{"+Fsct2+"}" ,  "lpf");
    pl->SetLineColor(0.5);
  
/*    TH1F* histos[3]={Signal1,Signal2,Signal3};
    for(int i=0;i<3;++i)
    {
        histos[i]->Sumw2();
    }
*/     


	TPad *pad2 = new TPad("pad2","pad2",0,0.05,1,0.3);
	pad2->SetTopMargin(0.05);
	pad2->SetBottomMargin(0.2);
	pad2->SetGridx();
	pad2->Draw();
	pad2->cd();

	 TH1F *Signal1_Clone =(TH1F*)Signal1->Clone("Signal1_Clone");
	 TH1F *Signal2_Clone =(TH1F*)Signal2->Clone("Signal2_Clone");
	 TH1F *Signal3_Clone =(TH1F*)Signal3->Clone("Signal3_Clone");    
	 TH1F *Signal4_Clone =(TH1F*)Signal4->Clone("Signal4_Clone");

	
         Signal1_Clone->SetFillColorAlpha(kRed-4,0.80);
	 Signal1_Clone->SetFillStyle(3001);
         Signal3_Clone->SetFillColorAlpha(kGreen+3,0.4);
	//Signal3_Clone->SetFillStyle(3001);
	 Signal4_Clone->SetFillColorAlpha(kYellow,0.8);
	 Signal4_Clone->SetFillStyle(3001);

	Double_t  Signal1_Error=0;
	Double_t  Signal2_Error=0;
	Double_t  Signal3_Error=0;
	Double_t  Signal4_Error=0;

	Double_t  Signal1_Content=0;
	Double_t  Signal2_Content=0;
	Double_t  Signal3_Content=0;
	Double_t  Signal4_Content=0;

	Double_t  A=0;
	Double_t  B=0;
	Double_t  C=0;

	Double_t  error_prop3=0;
	Double_t  error_prop2=0;
	Double_t  error_propA=0;
	Double_t  error_prop1=0;
	Double_t  error_prop4=0;
	Double_t  error_propB=0;
	Double_t  error_propC=0;
	
	//c1->Update();//update işlemi zorunlu
	 Signal1_Clone->SetLineWidth(2);
	 Signal3_Clone->SetLineWidth(2);
	 Signal4_Clone->SetLineWidth(2);
  for (Int_t i=1; i< Signal1_Clone->GetNbinsX(); i++)
	{
  	  Signal1_Content=Signal1_Clone->GetBinContent(i);
  	  Signal2_Content=Signal2_Clone->GetBinContent(i);
  	  Signal3_Content=Signal3_Clone->GetBinContent(i);
	  Signal4_Content=Signal4_Clone->GetBinContent(i);

  	  A=Signal3_Content/Signal2_Content;
  	  B=Signal1_Content/Signal2_Content;
	  C=Signal4_Content/Signal2_Content;

  	  Signal1_Error=Signal1_Clone->GetBinError(i);
  	  Signal2_Error=Signal2_Clone->GetBinError(i);
  	  Signal3_Error=Signal3_Clone->GetBinError(i);
	  Signal4_Error=Signal4_Clone->GetBinError(i);

  	  error_prop3= (Signal3_Error/Signal3_Content)*(Signal3_Error/Signal3_Content);
  	  error_prop2= (Signal2_Error/Signal2_Content)*(Signal2_Error/Signal2_Content);
  	  error_prop1= (Signal1_Error/Signal1_Content)*(Signal1_Error/Signal1_Content);
	  error_prop4= (Signal4_Error/Signal4_Content)*(Signal4_Error/Signal4_Content);

  	  error_propA=sqrt((error_prop3+error_prop2)*A*A);
  	  error_propB=sqrt((error_prop1+error_prop2)*B*B);
	  error_propC=sqrt((error_prop4+error_prop4)*C*C);

    //Zaten asagıda bolucem o yuzden burada bincontent ayarlamaya gerek yok 
  	//  Signal3_Clone->SetBinContent(i,A);
  	  Signal1_Clone->SetBinError(i,error_propB);
  	//  Signal1_Clone->SetBinContent(i,B);
  	  Signal3_Clone->SetBinError(i,error_propA);
	  Signal4_Clone->SetBinError(i,error_propC);
}
	Signal1_Clone->Divide(Signal2_Clone);
	Signal3_Clone->Divide(Signal2_Clone);
	Signal4_Clone->Divide(Signal2_Clone);

	Signal1_Clone->Draw("e3");
	Signal3_Clone->Draw("same e3");
	Signal4_Clone->Draw("same e3");	

	l->Draw();  


	
	 Signal1_Clone->GetYaxis()->SetRangeUser(0,2);
	 Signal1_Clone->SetTitle("");
	 Signal1_Clone->GetYaxis()->SetLabelSize(0.08);
	 Signal1_Clone->GetXaxis()->SetLabelSize(0.08);
	 Signal1_Clone->GetYaxis()->SetTitle("Ratio Plot for"+sigbck);
	 Signal1_Clone->GetYaxis()->CenterTitle();
	 Signal1_Clone->GetXaxis()->SetTitle(variable+" [GeV]");
         Signal1_Clone->GetYaxis()->SetTitleOffset(0.4);
         Signal1_Clone->GetXaxis()->SetTitleSize(0.1);
	 Signal1_Clone->GetYaxis()->SetTitleSize(0.1);

    //c1->SaveAs("/home/cakir/Desktop/PlottingTool/StorageHist/stack_"+scene+"_"+samp+".gif");
	pl2->Draw("same");
 
        c1->cd();
	 TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
	//pad1->SetLogy();
	pad1->SetBottomMargin(0.005);
 	pad1->Draw();
	pad1->cd();
	c1->Update();
	pad1->SetLogy();
   // Signal1->SetStats(0);          // No statistics on upper plot
    Double_t norm1 = Signal1->GetEntries();
    Signal1->Scale(1/norm1);
   // Signal2->SetStats(0); 
    Double_t norm2 = Signal2->GetEntries();
    Signal2->Scale(1/norm2);
   // Signal3->SetStats(0);
    Double_t norm3 = Signal3->GetEntries();
    Signal3->Scale(1/norm3);
    Double_t norm4 = Signal4->GetEntries();
    Signal4->Scale(1/norm4);
	Signal1->Draw();
	Signal2->Draw("same");
	Signal3->Draw("same");
	Signal4->Draw("same");
	pl->Draw("same");        
	// c1->cd();    
        
    c1->SaveAs(sigbck+variable+"_"+method+"_"+Fsct1+"and"+Fsct2+".pdf");
    c1->SaveAs(sigbck+variable+"_"+method+"_"+Fsct1+"and"+Fsct2+".root");


}
