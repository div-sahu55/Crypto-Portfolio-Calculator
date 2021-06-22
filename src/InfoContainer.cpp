#include<iostream>
#include "InfoContainer.h"
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
std::string UserInvestInfo::getAdvice(){
	std::string adv;
	if(CurrValue<=avgBP){
	adv= "Advised to buy more at a lower price or hold. If sold at current price, Loss% : " + std::to_string(getProfitPercent());
	}
	else{
	adv = "You can hold or sell this token at the current price. If sold at current price, Profit% : " + std::to_string(getProfitPercent());
	}
	return adv;
}
double UserInvestInfo::getProfitPercent(){
	double CP = Amt*CurrValue;
	double p = abs(CP-PurchasedValue)/PurchasedValue;
	return p*100;
}
std::string UserInvestInfo::getCname(){
	return CoinName;
}


