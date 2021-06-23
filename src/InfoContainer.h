#include<iostream>
class UserInvestInfo{
	private:
	std::string CoinName;
	double CurrValue;
	double PurchasedValue;
	double Amt;
	double avgBP;
	double TotalInv();
	public:
	UserInvestInfo(){
	}; //default constructor
	void setCoinName(std::string name);
	void setCurrValue(double d);
	void setPurchasedValue(double d);
	void setAmt(double d);
	void CalcAvgBP();
	double getAvgBP();
	std::string getAdvice();
	std::string getCname();
	double getProfitPercent();
	double getPurchasedValue();
	double getCurrentValue();
};
