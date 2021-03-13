// This is the implementation file for SavingsAccount.h class

#include "SavingsAccount.h"
#include "InactiveAccount.h"
using namespace std;

// Constructor
SavingsAccount::SavingsAccount(long double nBalance, double APR)
	: GenericAccount(nBalance, APR) {
	// ...
}

// Extras
void SavingsAccount::withdraw(long double nWithdrawal) {
	if (this->isActive()) {
		GenericAccount::withdraw(nWithdrawal);
	}
	else {
		throw InactiveAccount();
	}
}
void SavingsAccount::deposit(long double nDeposit) {
	long double tempBalance = this->getBalance();

	if (this->isActive() || ((tempBalance + nDeposit) >= 25)) { // proceed if active
		GenericAccount::deposit(nDeposit);
	}
	else {
		throw InactiveAccount();
	}
}
void SavingsAccount::monthlyProc(){
	int numOfWithdrawals = this->getNumOfWithdrawals();

	
	if (numOfWithdrawals > 4) {
		for (int y = 4; y < numOfWithdrawals; y++) {
			double tempServiceCharge = this->getServiceCharge();
            this->setServiceCharge((tempServiceCharge + 1));
		}
	}
	GenericAccount::monthlyProc();
}