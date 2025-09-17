#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include "admin.h"
#include "member.h"
#include "Motorbike.h"
#include "RentalRequest.h"

using namespace std;
#define MYFILE1 "motorbikes.txt"
#define MYFILE2 "members.txt"

// Constructor
Admin::Admin(string username, string password) : username(username), password(password) {}

// Admin login by checking credentials against file
Admin *Admin::login(const std::string &filename, Admin &admin)
{
    std::string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: could not open " << filename << endl;
        return nullptr;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string uname, pass;

        getline(ss, uname, ',');
        if (ss.peek() == ' ')
            ss.ignore();
        getline(ss, pass);

        // Compare input credentials
        if (uname == username && pass == password)
        {
            cout << "\nLogin successful!\n";
            return &admin;
        }
    }

    cout << "Invalid username or password.\n";
    return nullptr;
}

// Admin menu loop
bool Admin::adminMenu()
{
    int choice;
    do
    {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. View Members List\n";
        cout << "2. View Motorbikes List\n";
        cout << "3. Register New Member\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: showAllMember_List(); break;
        case 2: showAllMotorbike_List(); break;
        case 3: regist(); break;
        case 0: cout << "Logging out...\n"; return true;
        default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);
    return false;
}

// Print detailed list of members
void Admin::showAllMember_List()
{
    cout << "\n--------- Members List ---------\n\n";
    cout << left
         << "| " << setw(10) << "Username"
         << "| " << setw(15) << "Password"
         << "| " << setw(15) << "Fullname"
         << "| " << setw(25) << "Email"
         << "| " << setw(10) << "ID.Type"
         << "| " << setw(10) << "ID.Number"
         << "| " << setw(15) << "PhoneNumber"
         << "| " << setw(15) << "LicenseNumber"
         << "| " << setw(10) << "ExpiryDate"
         << "| " << setw(10) << "CP"
         << "| " << setw(10) << "Rating"
         << "| " << endl;

    for (auto i : Member_list)
    {
        cout << left
             << "| " << setw(10) << i->username
             << "| " << setw(15) << i->password
             << "| " << setw(15) << i->fullname
             << "| " << setw(25) << i->email
             << "| " << setw(10) << i->id_type
             << "| " << setw(10) << i->id
             << "| " << setw(15) << i->phone_number
             << "| " << setw(15) << i->licen_number
             << "| " << setw(10) << i->expiry_date
             << "| " << setw(10) << i->cp
             << "| " << setw(10) << i->rating
             << "| " << endl;
    }
}

// Print detailed motorbike list
void Admin::showAllMotorbike_List()
{
    cout << "\n--------- Motorbikes List ---------\n\n";
    cout << left
         << "| " << setw(10) << "Brand"
         << "| " << setw(10) << "Model"
         << "| " << setw(10) << "Color"
         << "| " << setw(10) << "EngineSize"
         << "| " << setw(10) << "YearMade"
         << "| " << setw(15) << "LicensePlate"
         << "| " << setw(10) << "Location"
         << "| " << setw(10) << "CP"
         << "| " << setw(10) << "Rating"
         << "| " << setw(10) << "OwnerName"
         << "| " << setw(15) << "AvailableFrom"
         << "| " << setw(15) << "AvaibleTo"
         << "| " << endl;

    for (auto i : Motorbike_list)
    {
        cout << left
             << "| " << setw(10) << i->getBrand()
             << "| " << setw(10) << i->getModel()
             << "| " << setw(10) << i->color
             << "| " << setw(10) << i->getEngineSize()
             << "| " << setw(10) << i->yearMade
             << "| " << setw(15) << i->licensePlate
             << "| " << setw(10) << i->location
             << "| " << setw(10) << i->getDailyRate()
             << "| " << setw(10) << i->getRating()
             << "| " << setw(10) << i->getOwnerName()
             << "| " << setw(15) << i->getAvailableFrom()
             << "| " << setw(15) << i->getAvailableTo()
             << "| " << endl;
    }
}

// Print simplified motorbike list (for guest browsing)
void Admin::showGeneralMotorbike_list()
{
    cout << "\n--------- General Motorbikes List ---------\n\n";
    cout << left
         << "| " << setw(10) << "Brand"
         << "| " << setw(10) << "Model"
         << "| " << setw(10) << "Size"
         << "| " << setw(10) << "Location"
         << "| " << endl;

    for (auto i : Motorbike_list)
    {
        cout << left
             << "| " << setw(10) << i->getBrand()
             << "| " << setw(10) << i->getModel()
             << "| " << setw(10) << i->getEngineSize()
             << "| " << setw(10) << i->getLocation()
             << "| " << endl;
    }
}

// Register new member
void Admin::regist()
{
    string username, password, fullname, email, id_type;
    string phone_number, id, licen_number, expiry_date;

    cout << "Enter your username: ";
    cin >> username;

    // Ensure password strength
    do
    {
        cout << "Enter your password: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, password);
        if (!Member::isStrongPasssword(password))
        {
            cout << "Weak password! Must be at least 8 characters and include uppercase, lowercase, digit, and special character." << endl;
        }
    } while (!Member::isStrongPasssword(password));

    // Collect member info
    cout << "Enter your full name: ";
    getline(cin, fullname);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your ID type (Citizen ID or Passport): ";
    getline(cin, id_type);
    cout << "Enter your ID number: ";
    getline(cin, id);
    cout << "Enter your phone number: ";
    getline(cin, phone_number);

    // Optional license
    int choice;
    while (true)
    {
        cout << "Do you have license number? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Your answer: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1)
        {
            cout << "Enter your license number: ";
            getline(cin, licen_number);
            cout << "Enter your expiry date: ";
            getline(cin, expiry_date);
            break;
        }
        else if (choice == 2)
        {
            licen_number = "0";
            expiry_date = "0";
            break;
        }
        else
        {
            cout << "Invalid choice. Try again!" << endl;
        }
    }

    // Initial balance and rating
    cout << "Registration fee is 20$. Your CP: 20 (1$=1CP)" << endl;
    cout << "Your default rating is 3.0" << endl;

    Member *newmem = new Member(username, password, fullname, email, id_type, id, phone_number, licen_number, expiry_date, 20.0, 3.0);
    Member_list.push_back(newmem);
    saveMembers();
    cout << "Member registered successfully!" << endl;
}

// -------- Data Reload Functions --------

/*
 * Reload all members from members.txt into memory.
 * Clears old Member_list, deletes allocated memory,
 * then parses file line by line and creates new Member objects.
 */
bool Admin::reloadMembers()
{
    // Clear old list and free memory
    for (auto m : Member_list) delete m;
    Member_list.clear();

    ifstream in(MYFILE2);
    if (!in.is_open())
        return false;

    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        string username, password, fullname, email, id_type;
        string id, phone_number, licen_number, expiry_date;
        double cp, rating;

        // Parse CSV values
        getline(ss, username, ','); ss.ignore();
        getline(ss, password, ','); ss.ignore();
        getline(ss, fullname, ','); ss.ignore();
        getline(ss, email, ','); ss.ignore();
        getline(ss, id_type, ','); ss.ignore();
        getline(ss, id, ','); ss.ignore();
        getline(ss, phone_number, ','); ss.ignore();
        getline(ss, licen_number, ','); ss.ignore();
        getline(ss, expiry_date, ','); ss.ignore();
        ss >> cp; ss.ignore();
        ss >> rating;

        // Add new member to list
        Member_list.push_back(new Member(username, password, fullname, email,
                                         id_type, id, phone_number,
                                         licen_number, expiry_date, cp, rating));
    }
    return true;
}

/*
 * Reload all motorbikes from motorbikes.txt.
 * Each line is parsed and stored in Motorbike_list.
 */
bool Admin::reloadMotorbikes()
{
    // Clear old list and free memory
    for (auto b : Motorbike_list) delete b;
    Motorbike_list.clear();

    ifstream in(MYFILE1);
    if (!in.is_open())
        return false;

    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        string brand, model, color, licensePlate, location;
        string ownerName, availableFrom, availableTo, rentedFrom, rentedTo;
        int engineSize, yearMade, isRentedInt;
        double dailyRate, rating;

        // Parse CSV values
        getline(ss, brand, ',');
        getline(ss, model, ',');
        getline(ss, color, ',');
        ss >> engineSize; ss.ignore();
        ss >> yearMade; ss.ignore();
        getline(ss, licensePlate, ',');
        getline(ss, location, ',');
        ss >> dailyRate; ss.ignore();
        ss >> rating; ss.ignore();
        getline(ss, ownerName, ',');
        getline(ss, availableFrom, ',');
        getline(ss, availableTo, ',');
        ss >> isRentedInt; ss.ignore();
        getline(ss, rentedFrom, ',');
        getline(ss, rentedTo);

        // Add new motorbike object
        Motorbike_list.push_back(
            new Motorbike(brand, model, color, engineSize, yearMade,
                          licensePlate, location, dailyRate, rating,
                          ownerName, availableFrom, availableTo,
                          isRentedInt == 1, rentedFrom, rentedTo)
        );
    }
    return true;
}

/*
 * Reload all rental requests from rental_request.txt.
 * Matches renter, owner, and bike references with existing objects.
 */
bool Admin::reloadRequests()
{
    // Clear old list and free memory
    for (auto r : allRequests) delete r;
    allRequests.clear();

    ifstream in("rental_request.txt");
    if (!in.is_open())
        return false;

    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        string reqIDStr, daysStr, statusStr, completedStr;
        string renterRatingStr, ownerRatingStr;
        string renterName, ownerName, bikePlate;
        string renterComment, ownerComment;

        int reqID, days, status;
        bool completed;
        int renterRatingGiven, ownerRatingGiven;

        // Parse CSV
        getline(ss, reqIDStr, ','); reqID = stoi(reqIDStr);
        getline(ss, renterName, ',');
        getline(ss, ownerName, ',');
        getline(ss, bikePlate, ',');
        getline(ss, daysStr, ','); days = stoi(daysStr);
        getline(ss, statusStr, ','); status = stoi(statusStr);
        getline(ss, completedStr, ','); completed = (completedStr == "1");
        getline(ss, renterRatingStr, ','); renterRatingGiven = stoi(renterRatingStr);
        getline(ss, renterComment, ',');
        getline(ss, ownerRatingStr, ','); ownerRatingGiven = stoi(ownerRatingStr);
        getline(ss, ownerComment);

        // Find corresponding objects
        Member *renter = nullptr, *owner = nullptr;
        Motorbike *bike = nullptr;

        for (auto m : Member_list)
        {
            if (m->username == renterName) renter = m;
            if (m->username == ownerName) owner = m;
        }
        for (auto b : Motorbike_list)
        {
            if (b->licensePlate == bikePlate) bike = b;
        }

        // If references missing, skip this request
        if (!renter || !owner || !bike) continue;

        // Create request and set state
        RentalRequest *req = new RentalRequest(reqID, renter, owner, bike, days);
        if (status == 1) req->approve();
        else if (status == 2) req->reject();
        if (completed) req->completeRental();

        req->setRenterRating(renterRatingGiven);
        req->setRenterComment(renterComment);

        allRequests.push_back(req);
    }
    return true;
}

// -------- Save Functions --------

/*
 * Save motorbikes into motorbikes.txt (overwrite file).
 */
bool Admin::saveMotorbikes()
{
    ofstream out("motorbikes.txt", ios::trunc);
    if (!out) return false;

    for (auto b : Motorbike_list)
        out << b->toString() << "\n";

    return true;
}

/*
 * Save rental requests into rental_request.txt.
 */
bool Admin::saveRequests()
{
    ofstream out("rental_request.txt", ios::trunc);
    if (!out) return false;

    for (auto r : allRequests)
        out << r->toString() << "\n";

    return true;
}

/*
 * Save members into members.txt.
 */
bool Admin::saveMembers()
{
    ofstream out("members.txt", ios::trunc);
    if (!out) return false;

    for (auto m : Member_list)
        out << m->toString() << "\n";

    return true;
}

// -------- Utility --------

/*
 * Add a rental request to admin’s master list (used by Member::makeRentalRequest).
 */
void Admin::addRequest(RentalRequest *req)
{
    allRequests.push_back(req);
}
