// This is the implementation file for SavingsAccount.h class
#include<iostream>
#include "CheckingAccount.h"
#include "InactiveAccount.h"
using namespace std;

// Constructor
CheckingAccount::CheckingAccount(double long nBalance, double nAnnualInterest)
	: GenericAccount(nBalance, nAnnualInterest){

}

// Extra

void CheckingAccount::withdraw(long double nWithdraw) {

	long double tempBalance = this->getBalance();

		if (this->isActive() && ((tempBalance - nWithdraw) >= 0)) {
			GenericAccount::withdraw(nWithdraw);
		}
		else if ((tempBalance - nWithdraw) < 0) {
			cout << "Account was overcharged.. Withdrawal was canceled.." << endl << endl
				<< "Account will be charged $15 for the overcharge.." << endl << endl;

			this->setBalance((tempBalance - 15));

            this->setNumOfWithdrawals((this->getNumOfWithdrawals() + 1));
			this->setMonthlyOverdraft((this->getMonthlyOverdraft() + 15));
		}
		else {
			throw InactiveAccount();
		}
}
void CheckingAccount::monthlyProc() {
	int numOfDeposits = this->getNumOfDeposits();

    this->setServiceCharge((this->getServiceCharge() + 5));
	if (numOfDeposits > 4) {
		for (int y = 0; y < numOfDeposits; y++) {
            this->setServiceCharge(this->getServiceCharge() + 0.10);
		}
	}
	GenericAccount::monthlyProc();
}