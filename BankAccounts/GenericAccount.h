#ifndef GENERIC_ACCOUNT
#define GENERIC_ACCOUNT

using namespace std;

class GenericAccount {
private:
	double annualInterestRate, serviceCharge, monthlyOverdraft;
	long double balance;
	int numOfWithdrawals, numOfDeposits;
	bool accountStatus;

public:
	//constructors
	GenericAccount();
	GenericAccount(long double nBalance, double APR);

	//setters
	void setBalance(long double nBalance);
	void setAnnualInterestRate(double APR);
	void setServiceCharge(double nServiceCharge);
	void setMonthlyOverdraft(double overdraftAmount);
	void setNumOfWithdrawals(int nNum);

	//getters
	int getNumOfWithdrawals() const;
	int getNumOfDeposits() const;
	double getServiceCharge() const;
	double long getBalance() const;
	double getMonthlyOverdraft() const;
	double getAPR() const;

	//extra
	bool isActive();
	virtual void deposit(long double nDeposit);
	virtual void withdraw(long double nWithdraw);
	virtual void calcInt();
	virtual void monthlyProc();
};

#endif