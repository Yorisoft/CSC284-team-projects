#ifndef CHECKING_ACCOUNT
#define CHECKING_ACCOUNT

#include "GenericAccount.h"
using namespace std;

class CheckingAccount : public GenericAccount {
private:

public:
	//constructor
	CheckingAccount(double long nBalance, double nAnnualInterest);

	//extra
	void monthlyProc() override;
	void withdraw(long double nWithdraw) override;

};

#endif