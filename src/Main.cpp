#include <iostream>
#include <vector>
#include <fstream>
#include "conio.h" //custom conio funtion for getch() for linux
#include "InfoContainer.h"
std::vector<UserInvestInfo> cont;
std::string uname;
bool quit = false;
int count=0;
void DisplayPort();
void showHelp(){
	system("clear");
	std::cout<<"<----------------------------------Help-------------------------------------->\n\n";
	std::cout<<" ->Navigate through the menu and select appropriate options\n";
	std::cout<<"          >For eg, answer with 1 in the menu to add an entry\n";
	std::cout<<"          >Then enter the details asked about your investment\n";
	std::cout<<" ->Make sure to keep all the currency related input in the same unit i.e USDT,INR (Just keep it uniform)\n";
	std::cout<<std::endl;
}
void DispTotalInv(){
	long double sum1=0,sum2=0;
	if(cont.size()!=0){
		for(UserInvestInfo e : cont){
			sum1+=e.getPurchasedValue();
			sum2+=e.getCurrentValue();
		}
	std::cout<<"\n\nTotal amount invested in this Portfolio: "<<sum1<<" ||  Current value of this Portfolio: "<<sum2;
	long double diff = abs(sum1-sum2)/sum1;
	if(sum2>=sum1){
		std::cout<<"\n\nTotal profit: "<<abs(sum1-sum2)<<" and overall profit[%]: "<<diff*100<<"%";
	}
	else{
		std::cout<<"\n\nTotal loss: "<<abs(sum1-sum2)<<" and overall loss[%]: "<<diff*100<<"%";
	}
	}
}
void PrintPort(){
	if(count>0){
		 std::cout<<"\n\nInvalid Path. Please try again.\n";
		 getch();
	}
	system("clear");
	std::cout<<"<---------------------------Save Portfolio Data----------------------------->\n\n";
	std::string f_path = "";
	std::cout<<"Please enter the file path where you would like to save: ";
	std::cin.clear();
	std::cin.ignore(1);
	std::getline(std::cin,f_path);
	std::ofstream f_stream;
	f_stream.open(f_path);
	if(!f_stream){
		count++;
		PrintPort();
	}
	else{
		f_stream<<"\nThis Portfolio belongs to: "<<uname<<" || Current Portfolio Analysis: \n";
		f_stream<<"<--------------------------------------------------------------------------------------->";
		      for(UserInvestInfo e : cont){
                  f_stream<<std::endl;
                  f_stream<<"Coin/Stock Name: "<<e.getCname();
                  f_stream<<std::endl;
                  f_stream<<"Your Average Buying price for "<<e.getCname()<<" is: "<<e.getAvgBP()<<std::endl;
                  f_stream<<e.getAdvice();
                  f_stream<<std::endl;
		      }
		    long double sum1=0,sum2=0;
        if(cont.size()!=0){
                for(UserInvestInfo e : cont){
                        sum1+=e.getPurchasedValue();
                        sum2+=e.getCurrentValue();
                }
        	f_stream<<"\n\nTotal amount invested in this Portfolio: "<<sum1<<" ||  Current value of this Portfolio: "<<sum2;
        long double diff = abs(sum1-sum2)/sum1;
        if(sum2>=sum1){
                f_stream<<"\n\nTotal profit: "<<abs(sum1-sum2)<<" and overall profit[%]: "<<diff*100<<"%";
        }
        else{
                f_stream<<"\n\nTotal loss: "<<abs(sum1-sum2)<<" and overall loss[%]: "<<diff*100<<"%";
        }
        }

		std::cout<<"\nData successfully saved at: "<<f_path<<"\n\n";
		std::cout<<"Press any key to continue.";
		getch();
		system("clear");
	}
	f_stream.close();
}
void DisplayPort(){
	system("clear");
	std::cout<<"\n\nFor user: "<<uname<<", current portfolio analysis: \n";
	std::cout<<"<---------------------------------------------------------------->";
	if(cont.size()!=0){
             for(UserInvestInfo e : cont){
                  std::cout<<std::endl;
                  std::cout<<"Coin/Stock Name: "<<e.getCname();
                  std::cout<<std::endl;
		  std::cout<<"Your Average Buying price for "<<e.getCname()<<" is: "<<e.getAvgBP()<<std::endl;
                  std::cout<<e.getAdvice();
                  std::cout<<std::endl;
                }
	     DispTotalInv();
	     std::cout<<"\n\n\nWould you like to save this information? (y/n): ";
	     char ans;
	     std::cin>>ans;
	     if(ans=='Y' || ans=='y'){
		     PrintPort();
	     }
	     else{
		     system("clear");
	     }
	}
	else{
		std::cout<<"\n\nYour Portfolio has 0 entries. Please add some Entries first!";
	}
}
void addEntry(){
	std::string cname;
	double currprice,amt,pvalue;
	UserInvestInfo I;
	system("clear");
	std::cout<<"\n<------------NEW ENTRY----------->\n\n";
	std::cout<<"Enter the name of Coin/Stock: ";
	std::cin.ignore();
	std::getline(std::cin,cname);
	std::cout<<std::endl;
	std::cout<<"Enter the quantity of "<<cname<<" purchased: ";
	std::cin>>amt;
	std::cout<<"Enter the total amount invested in "<<cname<<": ";
	std::cin>>pvalue;
	std::cout<<"Enter the current value of "<<cname<<": ";
	std::cin>>currprice;
	I.setCoinName(cname);
	I.setCurrValue(currprice);
	I.setPurchasedValue(pvalue);
	I.setAmt(amt);
	I.CalcAvgBP();
	cont.push_back(I);
	//std::cout<<"\n"<<I.getAdvice();
	//std::cout<<"\nYour Average Buying price is: "<<I.getAvgBP();
	std::cout<<"\nWould You like to add more entries? (Y/N): ";
	char ch;
	std::cin>>ch;
	if(ch=='Y' || ch=='y'){
		addEntry();
	}
	else{
		DisplayPort();
		std::cout<<"\n\n";
	}
}
int main(){
	system("clear");
	for(int i=0;i<20;i++)std::cout<<" ";
	std::cout<<std::endl;
	std::cout<<"<-----------------------------Hello and welcome to my portfolio calculator----------------------------->\n";
	std::cout<<"\nPlease enter your name: ";
	std::getline(std::cin,uname);
	std::cout<<std::endl;
	while(!quit){
	std::cout<<"1> Add a new entry\n";
	std::cout<<"2> Show Current Portfolio Info\n";
	std::cout<<"3> Clear Current Portfolio\n";
	std::cout<<"4> Help\n";
	std::cout<<"5> Quit\n";
	int ans;
	std::cout<<"Please enter your response: ";
	std::cin>>ans;
	if(ans==5){
		quit=true;
	}
	else if(ans==1){
		addEntry();
	}
	else if(ans==2){
		DisplayPort();
		std::cout<<"\n\n";
	}
	else if(ans==4){
		std::cout<<std::endl;
		showHelp();
		getch();
	}
	else if(ans==3){
		cont.clear();
		system("clear");
		std::cout<<"\nCleared current Portfolio. Please proceed to add new entries.\n\n";
	}
	else{
		std::cout<<"Invalid Option. Please answer by selecting an appropriate number.\n";
		showHelp();
	}
    }
	getch();
}
