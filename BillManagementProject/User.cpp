//
// Created by Yelsin S on 4/4/2021.
//


#include "User.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <json/value.h>
#include <json/json.h>

using namespace std;

//constructor
User::User() {
    try {
        this->userName = nullptr;
        this->numOfCreditors = 0;
    } catch (exception &e) {
        throw e.what();
    }
}

User::User(string &nUserName) :
        creditorInfo(nullptr){
    // search for file to serve as user database ( named after the userEmail/email )
    // Login should have already created the user database json file.
    try {
        string fileName = nUserName + ".json";
        ofstream inputFile;
        inputFile.open(fileName);

        if(inputFile.is_open()){
            // -look inside database file of user database and use it to fill in User class info
            Json::Value newUserInfo;
            Json::Reader reader; // sticking to deprecated Reader - because don't know how to work with others
            reader.parse(fileName, newUserInfo);

            // assign values to class from file
            Json::FastWriter fastWriter;
            this->userEmail = fastWriter.write(newUserInfo["EMAIL"]);
            this->userName = fastWriter.write(newUserInfo["USER_NAME"]);
            this->numOfCreditors = stoi(fastWriter.write(newUserInfo["NUM_OF_CREDITORS"]));
            this->userPhoneNumber = stoi(fastWriter.write(newUserInfo["USER_PHONE"]));
        }
    } catch (exception &e) {
        throw e.what();
    }
}

//setters
void User::setNumOfCreditors(int n){
    this->numOfCreditors = n;
}

void User::setCreditorNames(vector<string> &creditorNames){
    for (int y; y <= creditorNames.size(); y++){
        this->creditorInfo = creditorNames[y];
    }
}

//getters
vector<string>* User::getCreditorNames() {                    // possible onClick function
    return &creditors;
}

vector<string>* User::getCreditorNames(int creditorNum) const {    // possible onClick function
    try {
        // look inside user database file, find creditor by creditorNum
        // set creditorInfo = the selected creditor info
        // return creditorInfo
    } catch (exception &e) {
        throw e.what();
    }
}

//extra
void User::addNewCreditor(string nCreditorName, long double amountOwed) {
    // Perhaps this functions should belong to another class like creditors ?
    try {
        // check if file doesnt already exist in list of creditors.
        if (find(this->creditors.begin(), this->creditors.end(), nCreditorName) != this->creditors.end()) {
            this->creditors.emplace_back(nCreditorName);

            string fileName = nCreditorName + ".json";
            ofstream outputFile;
            outputFile.open(fileName);

            if(outputFile.is_open()){
                Json::CharReaderBuilder reader;
                Json::Value newCreditorInfo = "{"
                                              "\"NAME\" : " + nCreditorName + ", "
                                              "\"STARTING_BALANCE\" : " + to_string(amountOwed) + ", "
                                              "}";
                outputFile << newCreditorInfo;
            }
        } else {
            cout << "A creditor by the name of " << nCreditorName << " already exist.. " << endl;
            //throw invalid creditorException
        }
    } catch (exception &e) {
        throw e.what();
    }
}