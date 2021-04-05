#include "Login.h"
#include "User.h"
#include <iostream>
#include <json/value.h>
#include <json/json.h>
#include <fstream>

Login::Login() {
    userEmail = "";
    userPsw = "";
    isLoggedIn = false;

}

Login::Login(string nUserEmail, string nUserPass) {

    userEmail = nUserEmail;
    userPsw = nUserPass;
}

void Login::setUserEmail(string nUserEmail) {
    userEmail = nUserEmail;
}

void Login::setUserPass(string nUserPass) {
    userPsw = nUserPass;
}

void Login::setIsLoggedIn(bool nStatus) {
    isLoggedIn = nStatus;
}

string Login::getUserEmail() const {
    return userEmail;
}

string Login::getUserPass() const {
    return userPsw;
}

bool Login::getLoginStatus() const {
    return isLoggedIn;
}

User *Login::validateLogin(string nUserEmail, string tempPassW) {
    string fileName = nUserEmail + ".json";
    ifstream inputFile;
    try {
        // check if the file includes an entry equal to userEmail
        inputFile.open(fileName);
        if (inputFile.good()) {
            Json::Reader reader;    // sticking to deprecated Reader - because don't know how to work with others
            Json::Value passwordOnFile;

            reader.parse(fileName, passwordOnFile);

            // assign values to class from file
            Json::FastWriter fastWriter;

            if (tempPassW == fastWriter.write(passwordOnFile["PASS_WORD"])) {
                this->setIsLoggedIn(true);
                return new User(userEmail); // -> User will check inside .json file for all user related values
            } else {
                this->setIsLoggedIn(false);
                // passwords did not match. throw ..
            }

        } else {
            this->setIsLoggedIn(false);
            throw "User email // password is invalid";
            // Could not open file. throw ..
        }
    } catch (exception &e) {
        throw e;
    }
}

User *Login::createLogin(string nUserEmail, string nUserPsw) {
    int newUserPhoneNumber;
    string nUserName, fileName = nUserEmail + ".json";
    ifstream isInDatabase(fileName);


    isInDatabase.open(fileName);
    try {
        if (!isInDatabase.good()) { // file does not exist and thus we should create one

            cout << " What would you like as your user name? : ";
            getline(cin, nUserName);

            cout << " What would you like as your phone number? : ";
            cin >> newUserPhoneNumber;

            ofstream outputFile(fileName);
            //while (outputFile.good()) { // while file open is successful
                Json::Reader reader;
                Json::StyledWriter styledWriter;
                Json::Value accountInfo ="{"
                                         "\"EMAIL\" : " + nUserEmail += ", "
                                         "\"PASS_WORD\" : " + nUserPsw += ", "
                                         "\"USER_NAME\" : " + nUserName += ", "
                                         "\"USER_PHONE\" : " + to_string(newUserPhoneNumber) +
                                         "}";

                outputFile << styledWriter.write(accountInfo);
                outputFile.close();

                this->setIsLoggedIn(true);
                return new User();
           // }
        } else { // file already exist and user should log in using previous login
            // throw ...
            this->setIsLoggedIn(false);
        }

    } catch (exception &e) {
        this->setIsLoggedIn(false);
        throw e;
    }
}

void Login::forgotPasswordOnClick() {
    string nUserEmail;
    // promt for User Email

    // if no file named after the nUserEmail not exist, promt user to create account
    // if file named after nUserEmail does exist, send promt for new password and replace it in the file
}
