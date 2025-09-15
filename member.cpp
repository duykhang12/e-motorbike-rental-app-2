#include "member.h"
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
void Member::ProfileManagement(){
    int choice;
    int YourCP = this->cp;
    do {
        cout << "Profile Management Menu:" << endl;
        cout << "1. View Profile" << endl;
        cout << "2. Change Password" << endl;
        cout << "3.Top up CP balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Profile Information:" << endl;
                cout << "Username: " << username << endl;
                cout << "Full Name: " << fullname << endl;
                cout << "Email: " << email << endl;
                cout << "ID Type: " << id_type << endl;
                cout << "ID Number: " << id << endl;
                cout << "Phone Number: " << phone_number << endl;
                cout << "License Number: " << licen_number << endl;
                cout << "Expiry Date: " << expiry_date << endl;
                cout << "Credit Points: " << cp << endl;
                cout << "Rating: " << rating << endl;
                break;
            case 2:
                changePassword();
                break;
            case 3:
                int topup;
                cout << "Your current CP balance: " << YourCP << endl;
                cout << "Enter amount to top up: ";
                cin >> topup;
                if (topup > 0) {
                    YourCP += topup;
                    this->cp = YourCP;
                    cout << "Top up successful! New CP balance: " << YourCP << endl;
                } else {
                    cout << "Invalid top up amount!" << endl;
                }
                break;    
            case 4:
                cout << "Exiting Profile Management." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
}




