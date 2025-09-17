#include "Member.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "admin.h"
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

string Member::toString(){
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

string Member::normalizeDate(string dateStr){
    int d, m, y;
    char sep1, sep2;
    stringstream ss(dateStr);
    ss >> d >> sep1 >> m >> sep2 >> y;
    // format YYYYMMDD
    stringstream out;
    out << setw(4) << setfill('0') << y
    << setw(2) << setfill('0') << m
    << setw(2) << setfill('0') << d;
    return out.str();
}

void Member::searchMotorbikes() {
    Admin ad;
    string startDate, endDate, city;
    cout << "Enter start date (dd/mm/yyyy): ";
    cin >> startDate;
    cout << "Enter end date (dd/mm/yyyy): ";
    cin >> endDate;
    cout << "Enter your city(HCMC or Hanoi): ";
    cin >> city;

    cout << "--- Search Results ---\n";
    for (auto b : ad.Motorbike_list) {
        bool valid = true;

        if (this->rating < b->rating){
            valid = false;
        }
        if (this->cp < b->dailyRateCP){
            valid = false;
        }
        if (b->engineSize > 50 && this->licen_number == 0){
            valid = false;
        }
        if (b->location != city){
            valid = false;
        }
        if (!(normalizeDate(startDate) >= b->availableFrom && normalizeDate(endDate) <= b->availableTo)){
            valid = false;
        }
        if (valid) {
            cout << b->brand << " " << b->model
                 << " | Engine: " << b->engineSize
                 << "cc | Rate: " << b->dailyRateCP << " CP/day"
                 << " | ReqRating: " << b->rating
                 << " | City: " << b->location
                 << " | Available: " << b->availableFrom
                 << " - " << b->availableTo
                 << endl;
        } else {
            cout << "None";
        }
    }
}