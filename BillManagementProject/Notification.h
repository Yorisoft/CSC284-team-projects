/*
//
// Created by Yelsin S on 4/4/2021.
//

#ifndef NOTIFICATION
#define NOTIFICATION

class Notification
private:
string userEmail;
double  userPhone;
boolean textIsActive, emailIsActive;

public:
//constructor
Notification(User nUser) :
textIsActive(false), emailIsActive(false){
userEmail = nUser->getUserEmail();
userPhone = nUser->getuserPhone();
}

//setters
setUserEmail(nEmail){
        userEmail = nEmail;
}
setUserPhone(nPhone){
        userPhone = nPhone;
}
setIsTextActive(bool nStatus){
    textIsActive = nStatus;
}
setIsEmailActive(bool nStatus){
    emailIsActive = nStatus;
}

//getters
getUserEmail() const {
    return userEmail;
}
getUserPhone() const {
    return userPhone;
}
getIsTextActive(bool nStatus) const {
    return textIsActive;
}
getIsEmailActive(bool nStatus) const {
    return emailIsActive;
}

//extra
sendEmailNotification(){
    try{
        if ( emailIsActive == true ){
            // send email notification
        }
    } catch(...){
        throw e;
    }
}
sendTextNotification(){
    try{
        if ( textIsActive == true ){
            // send text notification
        }
    } catch(...){
        throw e;
    }
}

}

#endif NOTIFICATION
*/
