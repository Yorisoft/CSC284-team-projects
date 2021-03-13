// Bank Accounts - Project 1 
// This program uses three classes to emulate a Savings and Checking account.
// Prof Carmelito Moreno - CSC 284-H1
// Yelsin Sepulveda

#include<iostream>
#include<string>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "InactiveAccount.h"
using namespace std;

void printBanner();
void printInterface();
void savingDeposit(SavingsAccount* nSavingsAccountPtr);
void savingWithdrawal(SavingsAccount* nSavingsAccountPtr);
void checkingDeposit(CheckingAccount* nCheckingAccountPtr);
void checkingWithdrawal(CheckingAccount* nCheckingAccountPtr);
void printEndOfMonth(CheckingAccount* nCheckingAccountPtr, SavingsAccount* nSavingsAccountPtr,
                     long double& startingCheckingBalance, long double& startingSavingBalance);

int main() {
	string choice = "yes";
	int transaction;
	double APR;
	long double startingCheckingBalance, startingSavingBalance;
	CheckingAccount* CheckingAccountPtr = nullptr;
	SavingsAccount* SavingsAccountPtr = nullptr;

	printBanner();

	cout << "What would you like as your starting balance for your Checking account ?? "
         "( Minimum of $25 to activate account)  ";
	cin >> startingCheckingBalance; cin.ignore(100, '\n');

	cout << "What would you like as your starting balance for your Savings account ?? "
         "( Minimum of $25 to activate account)  ";
	cin >> startingSavingBalance; cin.ignore(100, '\n');

	cout << "What is the annual interest rate for your Savings account?? ";
	cin >> APR; cin.ignore(100, '\n');

	// Initializing new checking and savings account object
	CheckingAccountPtr = new CheckingAccount(startingCheckingBalance, APR);
	SavingsAccountPtr = new SavingsAccount(startingSavingBalance, APR);

	while (choice[0] == 'y' || choice[0] == 'Y') {		
		try {
			printInterface();

			cout << "What transaction would you like to perform ? (1 - 5) ";
			cin >> transaction;

			switch (transaction) {
				case 1:
                    checkingDeposit(CheckingAccountPtr);
					cout << "New Balance: " << CheckingAccountPtr->getBalance() << endl << endl;
					break;
				case 2:
                    checkingWithdrawal(CheckingAccountPtr);
					cout << "New Balance: " << CheckingAccountPtr->getBalance() << endl << endl;
					break;
				case 3:
                    savingDeposit(SavingsAccountPtr);
					cout << "New Balance: " << SavingsAccountPtr->getBalance() << endl << endl;
					break;
				case 4:
                    savingWithdrawal(SavingsAccountPtr);
					cout << "New Balance: " << SavingsAccountPtr->getBalance() << endl << endl;
					break;
				case 5: printEndOfMonth(CheckingAccountPtr, SavingsAccountPtr, startingCheckingBalance, startingSavingBalance);
                    break;
				default: cout << "Invalid selection.. Try again.." << endl << endl;
					break;
			}
		}
		catch (InactiveAccount& e) {
			cout << "Coule not Complete transaction " << endl
				<< '\t' << e.getError() << endl;
		}

		cout << "Would you like to enter another transaction ? [Y/n] ";
		cin.ignore(100, '\n'); getline(cin, choice);
	}

	system("pause");
	return 0;
}

void printBanner() {
	cout << "\t\t        This program emulates the functionality of both a Checking       " << endl
		 << "\t\t && Savings bank account, then prints out an End-Of-Month review message " << endl << endl;
}
void printInterface() {
	cout << "Select one of these options: " << endl
		<< '\t' << "1. Deposit into Checking Account " << endl
		<< '\t' << "2. Withdraw from Checking Account " << endl
		<< '\t' << "3. Deposit into Savings Account " << endl
		<< '\t' << "4. Withdraw from Savings Account " << endl
		<< '\t' << "5. Print out End-Of-Month review message " << endl << endl;
}
void checkingDeposit(CheckingAccount* nCheckingAccountPtr) {
	long double newDeposit;

	cout << "How much would you like to deposit into your checking account ? ";
	cin >> newDeposit;

	nCheckingAccountPtr->deposit(newDeposit);
}
void checkingWithdrawal(CheckingAccount* nCheckingAccountPtr) {
	long double newWithdrawal;

	try {
		cout << "How much would you like to withdraw from your checking account ? ";
		cin >> newWithdrawal;

		nCheckingAccountPtr->withdraw(newWithdrawal);

		cout << "Finished transaction.." << endl;
	}
	catch (InactiveAccount &e) {
		throw e;
	}

}
void savingDeposit(SavingsAccount* nSavingsAccountPtr) {
	long double newDeposit;

	try {
		cout << "How much would you like to deposit into your savings account ? ";
		cin >> newDeposit;

		nSavingsAccountPtr->deposit(newDeposit);
	}
	catch (InactiveAccount& e) {
		throw e;
	}
}
void savingWithdrawal(SavingsAccount* nSavingsAccountPtr) {
	long double newWithdrawal;

	try {
		cout << "How much would you like to withdraw from your savings account ? ";
		cin >> newWithdrawal;

		nSavingsAccountPtr->withdraw(newWithdrawal);

		cout << "Finished transaction.." << endl;
	}
	catch (InactiveAccount& e) {
		throw e;
	}

}
void printEndOfMonth(CheckingAccount* nCheckingAccountPtr, SavingsAccount* nSavingsAccountPtr,
                     long double& startingCheckingBalance, long double& startingSavingBalance) {
	int accountChosen;

	cout << "What account would you like to print?" << endl
		<< "1. Checking " << endl
		<< "2. Savings " << endl;
	cin.ignore(100, '\n'); cin >> accountChosen;

	if (accountChosen == 1) {
		// Checking
		cout << "This is your end of month review: " << endl
             << "\t" << "Checking Account: " << endl
             << "\t\t" << "Starting Balance: " << startingCheckingBalance << endl
             << "\t\t" << "Total Num. of deposits: " << nCheckingAccountPtr->getNumOfDeposits() << endl
             << "\t\t" << "Total Num. of withdrawals: " << nCheckingAccountPtr->getNumOfWithdrawals() << endl;
		nCheckingAccountPtr->monthlyProc();
		cout << "\t\t" << "Service Fees:       -" << nCheckingAccountPtr->getServiceCharge() << endl
			<< "\t\t" << "Monthly Overdrafts: -" << nCheckingAccountPtr->getMonthlyOverdraft() << endl
			<< "\t\t" << "Total in Fees and Overdraft: -" << (nCheckingAccountPtr->getServiceCharge() + nCheckingAccountPtr->getMonthlyOverdraft()) << endl
			<< "\t\t" << "Ending Balance: " << nCheckingAccountPtr->getBalance() << endl << endl;
	}
	else {
		// Savings
		cout << "\t" << "Savings Account: " << endl
             << "\t\t" << "Starting Balance: " << startingSavingBalance << endl
             << "\t\t" << "Total Num. of deposits: " << nSavingsAccountPtr->getNumOfDeposits() << endl
             << "\t\t" << "Total Num. of withdrawals: " << nSavingsAccountPtr->getNumOfWithdrawals() << endl;
		nSavingsAccountPtr->monthlyProc();
		cout << "\t\t" << "Service Fees:      " << nSavingsAccountPtr->getServiceCharge() << endl
			<< "\t\t" << "Monthly Overdrafts: " << nSavingsAccountPtr->getMonthlyOverdraft() << endl
			<< "\t\t" << "Total in Fees and Overdraft: " << (nSavingsAccountPtr->getServiceCharge() + nSavingsAccountPtr->getMonthlyOverdraft()) << endl
			<< "\t\t" << "Ending Balance: " << nSavingsAccountPtr->getBalance() << endl << endl;

	}
}