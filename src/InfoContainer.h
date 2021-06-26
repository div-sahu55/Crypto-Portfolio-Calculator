#include<iostream>
class UserInvestInfo{
	private:
		std::string CoinName;
		double CurrValue;
		double PurchasedValue;
		double Amt;
		double avgBP;
	public:
		UserInvestInfo(){
		}; //default constructor
		UserInvestInfo(std::string cname, double currprice, double pvalue, double amt); //parameterized constructor for initializing values
		void CalcAvgBP();
		//mutators:
		void setCoinName(std::string name);
		void setCurrValue(double d);
		void setPurchasedValue(double d);
		void setAmt(double d);
		double getAvgBP();
		std::string getAdvice();
		std::string getCname();
		double getProfitPercent();
		double getPurchasedValue();
		double getCurrentValue();
};
