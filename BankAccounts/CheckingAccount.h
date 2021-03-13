#ifndef CHECKING_ACCOUNT
#define CHECKING_ACCOUNT

#include "GenericAccount.h"
using namespace std;

class CheckingAccount : public GenericAccount<CheckingAccount*>{
private:

public:
	//constructor
	CheckingAccount(double long nBalance, double nAnnualInterest);

	//extra
	void withdraw(long double nWithdraw);//override
    void monthlyProc(); //override

};

#endif