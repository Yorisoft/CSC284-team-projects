#include "Login.h"
#include <json/json.h>
#include <fstream>

Login::Login()
{
	userEmail = "";
	userPsw = "";
	isLoggedIn = false;

}

Login::Login(string nUserEmail, string nUserPass)
{

	userEmail = nUserEmail;
	userPsw = nUserPass;
}

void Login::setUserEmail(string nUserEmail)
{
	userEmail = nUserEmail;
}

void Login::setUserPass(string nUserPass)
{
	userPsw = nUserPass;
}

void Login::setIsLoggedIn(bool nStatus)
{
	isLoggedIn = nStatus;
}

string Login::getUserEmail() const
{
	return userEmail;
}

string Login::getUserPass() const
{
	return userPsw;
}

Login Login::validateLogin(string userEmail, string nUserPsw)
{
	string fileName = userEmail;

	// check if the file includes an entry equal to userEmail

		// if so, get userpassword
			// if passwords match, return isLoggedIn as true;

		// if neither entry or password match up, throw invalid login execption;

	// return User object = new User(nUserName, nUserPsw);

}

Login Login::createLogin(string nUserEmail, string nUserPsw)
{
	Login login = Login(nUserEmail, nUserPsw);
	Json::Reader reader;
	Json::Value account;
	string fileName = userEmail;
	// Example of the structure of our json file 

	const string userAccounts = "{\"UserAccounts\":  "  
		"[ {\"Email\" : \"Yass@gmail.com\"," 
		"\"psw\" : \"ABC\"}" 
		"{\"Email\" : \"ABDI@gmail.com\","
		"\"psw\" : \"EDF\"}" 
		"{\"Email\" : \"Yelsin@gmail.com\"," 
		"\"psw\" : \"XYZ\"}" 
		"]}";
	
	//ifstream userAccounts("userAccounts.json", ifstream::binary);
	if (reader.parse(userAccounts, account))
	{
	// check if the file includes an entry equal to userEmail
		if (account["Email"] = userEmail)
			return login;
		else
		{

		}
	}

		// if not-true, create a new entry named after userEmail and insert userPsw, set isLoggedIn to true 

		// if true, prompt user to enter previous credentials;

	// return User object = new User(nUserName, nUserPsw);
}

void Login::forgotPasswordOnClick()
{
	string nUserEmail;
	// promt for User Email

	// if no file named after the nUserEmail not exist, promt user to create account
	// if file named after nUserEmail does exist, send promt for new password and replace it in the file
}
