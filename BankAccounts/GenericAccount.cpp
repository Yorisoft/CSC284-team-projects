// This is the implementation file for GenericAccount.h class

#include "GenericAccount.h"
using namespace std;

// Constructors
GenericAccount::GenericAccount()
: annualInterestRate(this->getAPR()), serviceCharge(0), monthlyOverdraft(0),
  balance(this->getBalance()), numOfWithdrawals(0), numOfDeposits(0),
  accountStatus(this->isActive()) {
    // ...
}
GenericAccount::GenericAccount(long double nBalance, double APR) : GenericAccount(){
	this->setBalance(nBalance);
	this->setAnnualInterestRate(APR);
}

// Setters
void GenericAccount::setBalance(long double nBalance) {
	balance = nBalance;
}
void GenericAccount::setAnnualInterestRate(double APR) {
	annualInterestRate = APR;
}
void GenericAccount::setServiceCharge(double nServiceCharge) {
	serviceCharge = nServiceCharge;
}
void GenericAccount::setMonthlyOverdraft(double overdraftAmount) {
	monthlyOverdraft = overdraftAmount;
}
void GenericAccount::setNumOfWithdrawals(int nNum) {
    numOfWithdrawals = nNum;
}

// Getters
double GenericAccount::getServiceCharge() const {
	return serviceCharge;
}
int GenericAccount::getNumOfWithdrawals() const {
	return numOfWithdrawals;
}
int GenericAccount::getNumOfDeposits() const {
	return numOfDeposits;
}
double long GenericAccount::getBalance() const {
	return balance;
}
double GenericAccount::getMonthlyOverdraft() const {
	return monthlyOverdraft;
}
double GenericAccount::getAPR() const {
    return annualInterestRate;
}

// Extra
bool GenericAccount::isActive() {
	balance < 25 ? accountStatus = false : accountStatus = true;
	return accountStatus;
}
void GenericAccount::deposit(long double nDeposit) {
	balance += nDeposit;
	numOfDeposits++;
}
void GenericAccount::withdraw(long double nWithdraw) {
	balance -= nWithdraw;
	numOfWithdrawals++;
}
void GenericAccount::calcInt() {
	double monthlyInterestRate = (annualInterestRate / 12);
	long double monthlyInterest = (balance * monthlyInterestRate);
	balance += monthlyInterest;
}
void GenericAccount::monthlyProc() {
	balance -= serviceCharge;
	balance -= serviceCharge;
	this->calcInt();
    numOfDeposits = 0;
    numOfWithdrawals = 0;
	monthlyOverdraft = 0;
	accountStatus = isActive();
}