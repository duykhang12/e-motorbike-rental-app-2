#include <iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include "admin.h"
#include "member.h"
using namespace std;
#define MYFILE1 "motorbikes.txt"
#define MYFILE2 "members.txt"


void Admin::showAllMember_List(){
    cout << left 
         << "| " << setw(10) << "Username"
         << "| " << setw(10) << "Password"
         << "| " << setw(15) << "Fullname"
         << "| " << setw(10) << "Email"
         << "| " << setw(10) << "ID.Type"
         << "| " << setw(10) << "ID.Number"
         << "| " << setw(10) << "PhoneNumber"
         << "| " << setw(10) << "LicenseNumber"
         << "| " << setw(10) << "ExpiryDate"
         << "| " << setw(10) << "CP"
         << "| " << setw(10) << "Rating"
         << "| " << endl;
    for (auto i : Member_list){
        cout << left 
             << "| " << setw(10) << i->username
             << "| " << setw(10) << i->password
             << "| " << setw(15) << i->fullname
             << "| " << setw(10) << i->email
             << "| " << setw(10) << i->id_type
             << "| " << setw(10) << i->id
             << "| " << setw(10) << i->phone_number
             << "| " << setw(10) << i->licen_number
             << "| " << setw(10) << i->expiry_date
             << "| " << setw(10) << i->cp
             << "| " << setw(10) << i->rating;
    }
}

void Admin::showAllMotorbike_List(){
    cout << left 
         << "| " << setw(10) << "Brand"
         << "| " << setw(10) << "Model"
         << "| " << setw(10) << "Color"
         << "| " << setw(10) << "EngineSize"
         << "| " << setw(10) << "YearMade"
         << "| " << setw(10) << "LicensePlate"
         << "| " << setw(10) << "Location"
         << "| " << setw(10) << "CP"
         << "| " << setw(10) << "Rating"
         << "| " << setw(10) << "OwnerName"
         << "| " << setw(10) << "AvailableFrom"
         << "| " << setw(10) << "AvaibleTo"
         << "| " << endl;
    for (auto i : Motorbike_list){
        cout << left 
             << "| " << setw(10) << i->brand
             << "| " << setw(10) << i->model
             << "| " << setw(10) << i->color
             << "| " << setw(10) << i->engineSize
             << "| " << setw(10) << i->yearMade
             << "| " << setw(10) << i->licensePlate
             << "| " << setw(10) << i->location
             << "| " << setw(10) << i->dailyRateCP
             << "| " << setw(10) << i->rating
             << "| " << setw(10) << i->ownerName
             << "| " << setw(10) << i->availableFrom
             << "| " << setw(10) << i->availableTo;
    }
}

void Admin::showGeneralMotorbike_list(){
    cout << left 
         << "| " << setw(10) << "Brand"
         << "| " << setw(10) << "Model"
         << "| " << setw(10) << "Size"
         << "| " << setw(10) << "Location"
         << "| " << endl;
    for (auto i : Motorbike_list){
        cout << left 
             << "| " << setw(10) << i->brand
             << "| " << setw(10) << i->model
             << "| " << setw(10) << i->engineSize
             << "| " << setw(10) << i->location;
    }
}

void Admin::regist(){
    string username, password, fullname, email, id_type;
    int phone_number, id, licen_number, expiry_date;
    cout << "Enter your username: ";
    cin >> username;
    do {
        cout << "Enter your password: ";
        cin >> password;
        if (!Member::isStrongPasssword(password)){
            cout << "Weak password! Must be at least 8 characters and include uppercase, lowercase, digit, and special character." << endl;
        }
    } while (!Member::isStrongPasssword(password));

    cout << "Enter your full name: ";
    cin.ignore(1, '\n');
    getline(cin, fullname);
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your ID type (Citizen ID or Passport): ";
    cin.ignore(1, '\n');
    getline(cin, id_type);
    cout << "Enter your ID number: ";
    cin >> id;

    int choice;
    while (true){
        cout << "Do you have license number? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Your answer: ";
        cin >> choice;
        if(choice == 1){
            cout << "Enter your license number: ";
            cin >> licen_number;
            cout << "Enter your expiry date: ";
            cin >> expiry_date;
            break;
        } else if (choice ==2) {
            licen_number = 0;
            expiry_date = 0;
            break;
        } else {
            cout << "Invalid choice. Try again!" << endl;
        }
    }
    cout << "Registration fee is 20$. Your CP: 20 (1$=1CP)" << endl;
    cout << "Your default rating is 3.0";
    Member newmem(username, password, fullname, email, id_type, phone_number, id, licen_number, expiry_date);
    Member_list.push_back(&newmem);
}

bool Admin::reloadData(){
    ifstream myfile1;
    myfile1.open(MYFILE1);
    if (!myfile1){
        return false;
    } else {
        string brand;
        string model;
        string color;
        string engineSizestr;
        int engineSize;
        string yearmadestr;     
        int yearMade;
        string licensePlate;
        string location;
        string dailyRateCPstr;
        double dailyRateCP; 
        string ratingstr;      
        double rating;          
        string ownerName; 
        string availableFrom;
        string availableTo; 
        while(myfile1.peek()!= EOF){
            getline(myfile1,brand,',');
            getline(myfile1,model,',');
            getline(myfile1,color,',');
            getline(myfile1,engineSizestr,',');
            engineSize = stod(engineSizestr);
            getline(myfile1,yearmadestr,',');
            yearMade = stod(yearmadestr);
            getline(myfile1,licensePlate,',');
            getline(myfile1,location,',');
            getline(myfile1,dailyRateCPstr,',');
            dailyRateCP = stod(dailyRateCPstr);
            getline(myfile1,ratingstr,',');
            rating = stod(ratingstr);
            getline(myfile1,ownerName,',');
            getline(myfile1,availableFrom,',');
            getline(myfile1,availableTo,',');
            
            Motorbike motors(brand, model, color, engineSize, yearMade, licensePlate, location, dailyRateCP, rating, ownerName, availableFrom, availableTo);
            Motorbike_list.push_back(&motors);
        }
        myfile1.close();
        return true;
    }

    ifstream myfile2;
    myfile2.open(MYFILE2);
    if (!myfile2){
        return false;
    } else {
        string username, password, fullname, email, id_type;
        string phonestr, idstr, licenstr, expirystr, cpstr, ratingstr;
        int id, phone_number, licen_number, expiry_date, cp, rating;
        while(myfile2.peek()!= EOF){
            getline(myfile2,username,',');
            getline(myfile2,password,',');
            getline(myfile2,fullname,',');
            getline(myfile2,email,',');
            getline(myfile2,id_type,',');
            getline(myfile2,idstr,',');
            id = stod(idstr);
            getline(myfile2,phonestr,',');
            phone_number = stod(phonestr);
            getline(myfile2,licenstr,',');
            licen_number = stod(licenstr);
            getline(myfile2,expirystr,',');
            expiry_date = stod(expirystr);
            getline(myfile2,cpstr,',');
            cp = stod(cpstr);
            getline(myfile2,ratingstr,',');
            rating = stod(ratingstr);

            Member mems(username, password, fullname, email, id_type, id, phone_number, licen_number, expiry_date, cp, rating);
            Member_list.push_back(&mems);
        }
        myfile2.close();
        return true;
    }

    for (auto i : Member_list){
        for (auto j : Motorbike_list){
            if (i->fullname.compare(j->ownerName) == 0){
                j = i->ownermotorbike;
            }
        }
    }
    return true;
}

void Admin::saveData(){
    ofstream myfile1;
    myfile1.open(MYFILE1);
    if (!myfile1){
        cerr << "Problem with the file" << endl;
        return;
    }
    if (Motorbike_list.empty()){
        cout << "Motorbikes list is empty. 0 motorbike is saved" << endl;
    } else {
        for (auto i : Motorbike_list){
            myfile1 << i->tostring() << endl;
        }
    }
    myfile1.close();

    ofstream myfile2;
    myfile2.open(MYFILE2);
    if (!myfile2){
        cerr << "Problem with the file" << endl;
        return;
    }
    if (Member_list.empty()){
        cout << "Motorbikes list is empty. 0 motorbike is saved" << endl;
    } else {
        for (auto i : Member_list){
            myfile1 << i->tostring() << endl;
        }
    }
    myfile2.close();
}

