#include "InfoContainer.h"
#include <iomanip>
//method definitions:
UserInvestInfo::UserInvestInfo(std::string cname,long double currValue,long double pvalue, long double amt, std::string curr){
	CoinName = cname;
	currency = curr;
	CurrValue = currValue;
	PurchasedValue = pvalue;
	Amt = amt;
	UserInvestInfo::CalcAvgBP();
}
void UserInvestInfo::setCoinName(std::string name){
	CoinName = name;
}
void UserInvestInfo::setCurrValue(long double d){
	CurrValue = d;
}
void UserInvestInfo::setAmt(long double d){
	Amt = d;
}
void UserInvestInfo::setPurchasedValue(long double d){
	PurchasedValue = d;
}
void UserInvestInfo::CalcAvgBP(){
	avgBP=PurchasedValue/Amt;
}
long double UserInvestInfo::getAvgBP(){
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
long double UserInvestInfo::getProfitPercent(){
	long double CP = Amt*CurrValue;
	long double p = abs(CP-PurchasedValue)/PurchasedValue;
	return  p*100;
}
std::string UserInvestInfo::getCname(){
	return CoinName;
}
long double UserInvestInfo::getPurchasedValue(){
	return PurchasedValue;
}
long double UserInvestInfo::getCurrentValue(){
	return Amt*CurrValue;
}
bool UserInvestInfo::ChkProfOrLoss(){ 
	if(CurrValue<=avgBP){
		return true;
	}
	return false;
}
