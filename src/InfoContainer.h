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
		bool ChkProfOrLoss(); //boolean function to check whether current token is in profit or loss
		//mutators:
		void setCoinName(std::string name);
		void setCurrValue(double d);
		void setPurchasedValue(double d);
		void setAmt(double d);
		double getAvgBP();
		void getAdvice();
		std::string getCname();
		double getProfitPercent();
		double getPurchasedValue();
		double getCurrentValue();
	};
