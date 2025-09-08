#include "Member.h"
#include <iostream>
#include <string>
using namespace std;

Member::Member(string username, string password, string fullname, string email, string id_type,
    int id, int phone_number , int licen_number, int expiry_date) :
    username(username), password(password), fullname(fullname), email(email), id_type(id_type),
    id(id), phone_number(phone_number), licen_number(licen_number), expiry_date(expiry_date){}

Member::Member(string username, string password, string fullname, string email, string id_type,
    int id , int phone_number, int licen_number, int expiry_date, Motorbike* ownermotorbike) :
    username(username), password(password), fullname(fullname), email(email), id_type(id_type),
    id(id), phone_number(phone_number), licen_number(licen_number), expiry_date(expiry_date), ownermotorbike(ownermotorbike){}

Member::Member(string username, string password, string fullname, string email, string id_type,
    int id, int phone_number, int licen_number, int expiry_date, double cp, double rating) : 
    username(username), password(password), fullname(fullname), email(email), id_type(id_type),
    id(id), phone_number(phone_number), licen_number(licen_number), expiry_date(expiry_date), cp(cp), rating(rating) {}

bool Member::isStrongPasssword(string password){
    if (password.length() < 8){
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    string specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/";
    
    for (auto i : password) {
        if (isupper(i)){
            hasUpper = true;
        } else if (islower(i)){
            hasLower = true;
        } else if (isdigit(i)){
            hasDigit = true;
        } else if (specialChars.find(i) != string::npos){
            hasSpecial = true;
        }
    }
   
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

string Member::tostring(){
    return username + ", " + password + ", " + fullname + ", " + email + ", " + id_type + ", " + to_string(id) +
           ", " + to_string(phone_number) + ", " + to_string(licen_number) + ", " + to_string(expiry_date) + ", " +
           to_string(cp) + ", " + to_string(rating);
}

void Member::changePassword(){
    string newpass;
    do {
        cout << "Enter your new password: ";
        cin.ignore(1,'\n');
        getline(cin,newpass);
        if (!isStrongPasssword(newpass)){
            cout << "Weak password! Must be at least 8 characters and include uppercase, lowercase, digit, and special character." << endl;
        }
    } while (!isStrongPasssword(newpass));
    this->password = newpass;
    cout << "Your new password has been saved successfully!" << endl;
}
