#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <curl/curl.h>
#include "conio.h" //custom conio funtion for getch() for linux
#include "version.h"
#include "InfoContainer.h"
//global variables
std::vector<UserInvestInfo> cont;
std::string uname,currency=" dollars";
bool quit = false,flg=true,chkCurr=true,menu=false;
int count=0,ans=0,Curr=0;
long double x =0;
//function declarations:
void showHelp();
// void showVersion();
void DisplayPort();
void DispTotalInv();
void PrintPort();
void addEntry();
//function definitions:
size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata){
    std::ostringstream *stream = (std::ostringstream*)userdata;
    size_t count = size * nmemb;
    stream->write(ptr, count);
    return count;
}
void apiCall(std::string id){
	menu=false;
	CURL *curl = curl_easy_init();
    std::ostringstream stream;
	std::string get_curr="usd";
	if(currency==" rupees"){
		get_curr="inr";
	}
	std::string req_url = "https://api.coingecko.com/api/v3/coins/markets?vs_currency=" + get_curr + "&ids=" + id + "&order=market_cap_desc&per_page=100&page=1&sparkline=false";
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream);
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
	curl_easy_setopt(curl, CURLOPT_URL, req_url.c_str());
	
	CURLcode ret = curl_easy_perform(curl);
	std::string output = stream.str();
	std::string name = "current_price";
	size_t found = output.find(name);
	found+=15;
	std::string str1;
	while(output[found]!=','){
		str1 += output[found++];
	}
	if(str1.length()<100){
		str1+=currency;
	std::cout<<"\n\t>Current Value of "<<id<<": "<<str1<<std::endl;
	x = stold(str1);
}
	else{
	std::cout<<"\tInvalid format for coin name.";
	showHelp();
	menu = true;
	system("clear");
	}
}
void getCurrency(){
	system("clear");
	for(int i=0;i<5;i++){
	std::cout<<"\t";
	}
	std::cout<<"<-------------------------- PLEASE ENTER YOUR PREFFERED CURRENCY ---------------------> ";
	std::cout<<"\n\n\t\t1> US Dollars (USD)";
	std::cout<<"\n\t\t2> Indian National Rupee (INR)";
	std::cout<<"\n\n\tPlease enter your response(1/2): ";
	std::cin>>Curr;
	if(Curr==2){
		currency = " rupees";
	}
}
void showHelp(){
	system("clear");
	std::cout<<std::endl;
	for(int i=0;i<5;i++){
		std::cout<<"\t";
	}
	std::cout<<"<---------------------------------- Help -------------------------------------->\n\n";
	std::cout<<"\t->Navigate through the menu and select appropriate options\n\n";
	std::cout<<"\t\t>>Answer with 1 in the menu to add an entry\n\n";
	std::cout<<"\t\t\t>>>Then enter the details asked about your investment\n\n";
	std::cout<<"\t\t>>Answer with 2 for displaying details of the current portfolio.\n\n";
	std::cout<<"\t\t>>Answer with 3 to clear all the entries in the portfolio.\n\n";
	std::cout<<"\t\t>>Answer with 4 to check current version.\n\n";
	std::cout<<"\t\t>>Answer with 6 to quit\n\n";
	std::cout<<" \t->Make sure to keep all the currency related input in the same unit i.e USDT,INR (Just keep it uniform)\n\n";
	std::cout<<std::endl;
	std::cout<<"\t Press any key to Continue.";
	getch();
}
void showVersion(){
		system("clear");
		std::cout << "\n\tPortfolio-Calculator version: " << portcalc_VERSION_MAJOR << "." << portcalc_VERSION_MINOR  << "."<< portcalc_VERSION_REVISION << "\n";
		std::cout << "\nPress any key to continue.";
		getch();
}
void DisplayPort(){
	system("clear");
	std::cout<<std::endl;
	for(int i=0;i<5;i++){
		std::cout<<"\t";
	}
	std::cout<<"For user: "<<uname<<", current portfolio analysis: \n";
	std::cout<<"\t\t\t\t<---------------------------------------------------------------->\n";
	if(cont.size()!=0){
             for(UserInvestInfo e : cont){
                std::cout<<std::endl;
                std::cout<<"\t>Coin/Stock Name: "<<e.getCname()<<"\n\n";
		  	    std::cout<<"\t\t>>Your Average Buying price for "<<e.getCname()<<" is: "<< std::fixed << std::setprecision(2) << e.getAvgBP()<<currency<<"\n\n";
                std::cout<<"\t\t>>";
				e.getAdvice();
                std::cout<< "%" <<std::endl;
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
		std::cout<<"\n\n\t\tYour Portfolio has 0 entries. Please add some Entries first!";
	}
}
void DispTotalInv(){
	long double sum1=0,sum2=0;
	if(cont.size()!=0){
		for(UserInvestInfo e : cont){
			sum1+=e.getPurchasedValue();
			sum2+=e.getCurrentValue();
		}
	long double diff = abs(sum1-sum2)/sum1;
	std::cout<<"\n\n\t<----------------------------------------------------------------------------------------------------------------->";
	std::cout<<"\n\n\tTotal amount invested in this Portfolio: "<< std::fixed << std::setprecision(2) << sum1<<currency<<"  ||  Current value of this Portfolio: "<< std::setprecision(2) << sum2 <<currency;
	if(sum2>=sum1){
		std::cout<<"\n\n\tTotal profit: " << std::fixed << std::setprecision(2) <<abs(sum1-sum2)<< currency << " and overall profit[%]: "<< std::setprecision(2) <<diff*100<<"%";
	}
	else{
		std::cout<<"\n\n\tTotal loss: "<< std::fixed << std::setprecision(2) << abs(sum1-sum2)<< currency <<" and overall loss[%]: "<< std::setprecision(2) << diff*100<<"%";
	 }
	}
}
void PrintPort(){        //function to write portfolio info in a text file
	if(count>0){
		 std::cout<<"\n\nInvalid Path. Please try again.\n";
		 getch();
	}
	system("clear");
	for(int i=0;i<5;i++){
		std::cout<<"\t";
	}
	std::cout<<"<--------------------------- Save Portfolio Data ----------------------------->\n\n";
	std::string f_path = "";
	std::cout<<"\t\t>Please enter the file path where you would like to save: ";
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
		f_stream<<std::endl;
		for(int i=0;i<5;i++){
			f_stream<<"\t";
		}
		f_stream<<"This Portfolio belongs to: "<<uname<<" || Current Portfolio Analysis: \n";
		f_stream<<"\t\t\t\t<--------------------------------------------------------------------------------------->";
		      for(UserInvestInfo e : cont){
                  f_stream<<std::endl;
                  f_stream<<"\t>Coin/Stock Name: "<<e.getCname()<<"\n\n";
                  f_stream<<"\t\t>>Your Average Buying price for "<<e.getCname()<<" is: "<< std::fixed << std::setprecision(2) << e.getAvgBP()<<currency<<"\n\n";
                  f_stream<<"\t\t>>";
				  if(e.ChkProfOrLoss()){
					  f_stream<<"You can buy more at a lower price or hold. If sold at current price, Loss[%] : " << std::fixed << std::setprecision(2) << e.getProfitPercent() << "%";
				  }
				  else{
					  f_stream<<"You can hold or sell this token at the current price. If sold at current price, Profit[%] : " << std::fixed << std::setprecision(2)<< e.getProfitPercent() << "%";
				  }
                  f_stream<<std::endl;
		      }
		    long double sum1=0,sum2=0;
        if(cont.size()!=0){
                for(UserInvestInfo e : cont){
                        sum1+=e.getPurchasedValue();
                        sum2+=e.getCurrentValue();
                }
			f_stream<<"\n\n\t<---------------------------------------------------------------------------------------------------------->";
        	f_stream<<"\n\n\tTotal amount invested in this Portfolio: "<< std::fixed << std::setprecision(2) << sum1 << currency <<"  || Current value of this Portfolio: "<< std::fixed << std::setprecision(2) << sum2 << currency;
        long double diff = abs(sum1-sum2)/sum1;
        if(sum2>=sum1){
                f_stream<<"\n\n\tTotal profit: "<< std::fixed<< std::setprecision(2) << abs(sum1-sum2) << currency <<" and overall profit[%]: "<<std::fixed<< std::setprecision(2) <<diff*100<<"%";
        }
        else{
                f_stream<<"\n\n\tTotal loss: "<< std::fixed<< std::setprecision(2) << abs(sum1-sum2)<< currency << " and overall loss[%]: "<< std::fixed << std::setprecision(2) << diff*100<<"%";
        }
        }
		f_stream.close();
		std::cout<<"\n      Data successfully saved at: "<<f_path<<"\n\n";
		std::cout<<"        Press any key to continue.";
		getch();
		system("clear");
	}

}
void addEntry(){ //function to add new token info
	if(chkCurr){
		getCurrency();
	}
	chkCurr=false;
	std::string cname;
	char ch;
	long double currprice,amt,pvalue;
	if(flg){
	 system("clear");
	}
	std::cout<<std::endl;
	for(int i=0;i<5;i++){
		std::cout<<"\t";
	}
	std::cout<<"<------------ NEW ENTRY ----------->\n\n";
	std::cout<<"\t>Enter the name of Coin/Stock: ";
	std::cin.ignore();
	std::getline(std::cin,cname);
	apiCall(cname);
	if(menu){
	   return;
	}
	std::cout<<std::endl;
	std::cout<<"\t>Enter the quantity of "<<cname<<" purchased: ";
	std::cin>>amt;
	std::cout<<std::endl;
	std::cout<<"\t>Enter the total amount invested in "<<cname<<" in"<<currency<<": ";
	std::cin>>pvalue;
	std::cout<<std::endl;
	UserInvestInfo I(cname,x,pvalue,amt,currency);
	cont.push_back(I);
	std::cout<<"\n\tWould You like to add more entries? (Y/N): ";
	std::cin>>ch;
	if(ch=='Y' || ch=='y'){
		flg=false;
		addEntry();
	}
	else{
		DisplayPort();
		std::cout<<"\n\n";
	}
}
int main(){
	system("clear");
	std::cout<<std::endl;
	for(int i=0;i<5;i++){
		std::cout<<"\t";
	}
	std::cout<<"<-------------------------- Hello and Welcome to my portfolio calculator -------------------------->\n";
	std::cout<<"\n\n\t>Please enter your name: ";
	std::getline(std::cin,uname);
	std::cout<<std::endl;
	std::cout<<"\t\t\t>>Welcome "<<uname<<", Please answer with the appropriate number to continue.\n\n";
	while(!quit){
	std::cout<<std::endl;
	for(int i=0;i<5;i++){
		std::cout<<"\t";
	}//main menu display:
	std::cout<<"<------------------------------------- Main Menu ------------------------------------->\n\n";
	std::cout<<"\t\t\t\t1> Add a new entry\n\n";
	std::cout<<"\t\t\t\t2> Show Current Portfolio Info\n\n";
	std::cout<<"\t\t\t\t3> Clear Current Portfolio\n\n";
	std::cout<<"\t\t\t\t4> Check Current Version\n\n";
	std::cout<<"\t\t\t\t5> Help\n\n";
	std::cout<<"\t\t\t\t6> Quit\n\n";
	std::cout<<"\t>Please enter your response: ";
	std::cin>>ans;
	if(ans==6){
		system("clear");
		quit=true;
	}
	else if(ans==1){
		chkCurr=true;
		addEntry();
	}
	else if(ans==2){
		DisplayPort();
		std::cout<<"\n\n";
	}
	else if(ans==3){
		cont.clear(); //deleting all present entries
		system("clear");
		std::cout<<"\nCleared current Portfolio. Please proceed to add new entries.\n\n";
	}
	else if(ans==4){
		showVersion();
		getch();
		system("clear");
	}
	else if(ans==5){
		std::cout<<std::endl;
		showHelp();
		getch();
	}
	else{
		std::cout<<"\nInvalid Option. Please answer by selecting an appropriate number.\n\n";
		quit = true;
	}
  }
	getch();
}