//
// Created by Yelsin S on 4/4/2021.
//

#ifndef USER
#define USER

#include <string>
#include <vector>

using namespace std;

class User {
private:
    string userName, userEmail, creditorInfo;
    int numOfCreditors, userPhoneNumber;
    vector<string> creditors;

public:
//constructor
    User();
    User(string &nUserName);

//setters
    void setNumOfCreditors(int n);
    void setCreditorNames(vector<string> &creditorNames);

//getters
    vector<string>* getCreditorNames();

    vector<string>* getCreditorNames(int creditorNum) const;

//extra
    void addNewCreditor(string nCreditorName, long double amountOwed);
};

#endif
