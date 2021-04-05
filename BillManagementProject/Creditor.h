/*
#ifndef CREDITOR
#define CREDITOR

#include<string>
#include<vector>
using namespace std;

class Creditor
{
private:
	string creditorName;
	vector<string> transactionHistory;
	long double amountOwed;
	double annualInterestRate;
	int numOfPayments;

public:
	//constructor
	Creditor(string, long double, double);

	//setters
	void setCreditName(string);
	void setAmountOwed(long double);
	void setAnnualInterestRate(double);

	//getters
	string getCreditName() const;
	long double getAmountOwed() const;
	double getAnnualInterestRate() const;

	//extra
	//processTransaction(long double nAmount) {
	//	auto dateStamp;

	//	try {
	//		amountOwed = (this->getAmountOwed() + nAmount);
	//		// print to file 'dateStamp - creditorName - nAmount - amountOwed'
	//	}
	//	catch (...) {
	//		throw e;
	//	}

	//	if (nAmount > 0) {
	//		numOfPayments++;
	//	}


	//}

};

#endif
*/
