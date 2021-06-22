#include<iostream>
#include<vector>
#include "conio.h" //custom conio funtion for getch() for linux
#include "InfoContainer.h"
std::vector<UserInvestInfo> cont;
std::string uname;
void showHelp(){
	system("clear");
	std::cout<<"<----------------------------------Help-------------------------------------->\n\n";
	std::cout<<" ->Navigate through the menu and select appropriate options\n";
	std::cout<<"          >For eg, answer with 1 in the menu to add an entry\n";
	std::cout<<"          >Then enter the details asked about your investment\n";
	std::cout<<" ->Make sure to keep all the currency related input in the same unit i.e USDT,INR (Just keep it uniform)\n";
	std::cout<<std::endl;
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
                  std::cout<<e.getAdvice();
                  std::cout<<std::endl;
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
	bool quit = false;
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
