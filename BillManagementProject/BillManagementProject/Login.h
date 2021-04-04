#include<string>
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

	//extra
	Login validateLogin(string, string);

	Login createLogin(string, string);

	void forgotPasswordOnClick();
	
};
			


