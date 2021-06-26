#include "InfoContainer.h"
#include <iomanip>
//method definitions:
UserInvestInfo::UserInvestInfo(std::string cname,double currprice,double pvalue, double amt){
	CoinName = cname;
	CurrValue = currprice;
	PurchasedValue = pvalue;
	Amt = amt;
	UserInvestInfo::CalcAvgBP();
}
void UserInvestInfo::setCoinName(std::string name){
	CoinName = name;
}
void UserInvestInfo::setCurrValue(double d){
	CurrValue = d;
}
void UserInvestInfo::setAmt(double d){
	Amt = d;
}
void UserInvestInfo::setPurchasedValue(double d){
	PurchasedValue = d;
}
void UserInvestInfo::CalcAvgBP(){
	avgBP=PurchasedValue/Amt;
}
double UserInvestInfo::getAvgBP(){
	return avgBP;
}
void UserInvestInfo::getAdvice(){
	if(CurrValue<=avgBP){
	std::cout<<"You can buy more at a lower price or hold. If sold at current price, Loss[%] : " << std::fixed << std::setprecision(2) << getProfitPercent();
	}
	else{
	std::cout<<"You can hold or sell this token at the current price. If sold at current price, Profit[%] : " << std::fixed << std::setprecision(2)<< getProfitPercent();
	}
}
double UserInvestInfo::getProfitPercent(){
	double CP = Amt*CurrValue;
	double p = abs(CP-PurchasedValue)/PurchasedValue;
	return  p*100;
}
std::string UserInvestInfo::getCname(){
	return CoinName;
}
double UserInvestInfo::getPurchasedValue(){
	return PurchasedValue;
}
double UserInvestInfo::getCurrentValue(){
	return Amt*CurrValue;
}
bool UserInvestInfo::ChkProfOrLoss(){ 
	if(CurrValue<=avgBP){
		return true;
	}
	return false;
}
