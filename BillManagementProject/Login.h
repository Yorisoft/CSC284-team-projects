#include<string>
#include "User.h"
using namespace std;

class Login
{
private:
	string userEmail;
	string userPsw;
	bool isLoggedIn;

public:
	//constructor
	Login();
	Login(string, string);

	//setters
	void setUserEmail(string);
	void setUserPass(string);
	void setIsLoggedIn(bool);

	//getters
	string getUserEmail()const;
	string getUserPass() const;
    bool getLoginStatus() const;

	//extra
    User* validateLogin(string nUserEmail, string tempPassW);
    User* createLogin(string nUserEmail, string tempPassW);

	void forgotPasswordOnClick();
	
};
			


