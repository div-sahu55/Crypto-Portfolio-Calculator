#include <iostream>
class UserInvestInfo{
	private:
		std::string CoinName;
		long double CurrValue;
		long double PurchasedValue;
		long double Amt;
		long double avgBP;
	public:
		UserInvestInfo(){
		}; //default constructor
		UserInvestInfo(std::string cname, long double currprice, long double pvalue, long double amt); //parameterized constructor for initializing values
		void CalcAvgBP();
		bool ChkProfOrLoss(); //boolean function to check whether current token is in profit or loss
		//mutators:
		void setCoinName(std::string name);
		void setCurrValue(long double d);
		void setPurchasedValue(long double d);
		void setAmt(long double d);
		long double getAvgBP();
		void getAdvice();
		std::string getCname();
		long double getProfitPercent();
		long double getPurchasedValue();
		long double getCurrentValue();
	};
