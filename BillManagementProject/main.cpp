//
// Created by Yelsin S on 4/4/2021.
//

#include "Login.h"
#include "User.h"
#include "Notification.h"
#include "Creditor.h"

#include<iostream>

using namespace std;

void printBanner();
void printInterface();
User* getValidUser(Login *newLoginPtr);
User* createValidUser(Login *newLoginPtr);

int main() {

    int loginChoice;
    string choice = "Yes";
    Login *newLoginPtr = nullptr;
    User * newUserPtr = nullptr;
    //Notification *newNotificationPtr = nullptr;
    //Creditor *newCreditorPtr = nullptr;

    // Print User Interface
    printBanner();

    try {
        newLoginPtr = new Login();
        while (!newLoginPtr->getLoginStatus()) {
            cout << "Would you like to Login or create a Login? " << endl
                 << "\t 1." << "Login" << endl
                 << "\t 2." << "Create Login" << endl << endl;

            cin >> loginChoice;
            cin.ignore(100, '\n');

            switch (loginChoice) {
                case 1:
                    cout << "Starting account login.. " << endl;
                    newUserPtr = getValidUser(newLoginPtr);
                    break;
                case 2:
                    cout << "Starting creating account login.. " << endl;
                    newUserPtr = createValidUser(newLoginPtr);
                    break;
                default:
                    break;
            }

        }

        // Print User Interface
        printInterface();

        // Loop while user input is 'yes'
        while (choice[0] == 'Y' || choice[0] == 'y') {


            cout << "Would you like to run the program again? [Y/n]  " << endl;
            getline(cin, choice);
        }
        system("PAUSE");

    } catch (exception &e) {
        throw e;
    }
}

void printBanner() {
    cout << "\t\t        This program simulates the functionality of a      " << endl
         << "\t\t     Finance Managing System, in order to manage bills     " << endl << endl;
}

void printInterface() {
    cout << "Select one of these options: " << endl
         << '\t' << "1. Select " << endl
         << '\t' << "2. Add creditor / Edit Creditor " << endl
         << '\t' << "3. Deposit into Savings Account " << endl
         << '\t' << "4. Withdraw from Savings Account " << endl
         << '\t' << "5. Print out End-Of-Month review message " << endl << endl;
}

User *getValidUser(Login *newLoginPtr) {
    string nUserEmail, nUserPassW;
    try {
        // Login to account
        cout << " What is your login email? : ";
        getline(cin, nUserEmail);

        cout << " What is your login password? : ";
        getline(cin, nUserPassW);

        return newLoginPtr->validateLogin(nUserEmail, nUserPassW);
    } catch (exception &e) {
        throw e.what();
    }
}

User *createValidUser(Login *newLoginPtr) {
    string userName, nUserEmail, nUserPassW;
    int userPhoneNumber;

    try {
        // Login to account
        cout << " What would  you like as your login email? : ";
        getline(cin, nUserEmail);

        cout << " What would  you like as your login password? : ";
        getline(cin, nUserPassW);

        return newLoginPtr->createLogin(nUserEmail, nUserPassW);
    } catch (exception &e) {
        throw e.what();
    }
}

















