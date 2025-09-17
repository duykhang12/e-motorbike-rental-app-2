#include "Member.h"
#include "admin.h"
#include "RentalRequest.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <vector>
#include <cctype>

using namespace std;

// -------- Constructors --------
Member::Member(string username, string password, string fullname, string email, string id_type,
               string id, string phone_number, string licen_number, string expiry_date)
    : username(username), password(password), fullname(fullname), email(email), id_type(id_type),
      id(id), phone_number(phone_number), licen_number(licen_number), expiry_date(expiry_date) {}

Member::Member(string username, string password, string fullname, string email, string id_type,
               string id, string phone_number, string licen_number, string expiry_date,
               Motorbike *ownermotorbike)
    : username(username), password(password), fullname(fullname), email(email), id_type(id_type),
      id(id), phone_number(phone_number), licen_number(licen_number), expiry_date(expiry_date),
      ownermotorbike(ownermotorbike) {}

Member::Member(string username, string password, string fullname, string email, string id_type,
               string id, string phone_number, string licen_number, string expiry_date,
               double cp, double rating)
    : username(username), password(password), fullname(fullname), email(email), id_type(id_type),
      id(id), phone_number(phone_number), licen_number(licen_number), expiry_date(expiry_date),
      cp(cp), rating(rating) {}


// -------- Authentication --------
/*
 * Login function: asks for username and password,
 * searches the file for a matching record,
 * returns a new Member object if found.
 */
Member *Member::login(const std::string &filename)
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
        string uname, pass, fullname, email, id_type;
        string id, phone, licen, expiry;
        double cp, rating;

        // Parse CSV
        getline(ss, uname, ','); ss.ignore();
        getline(ss, pass, ','); ss.ignore();
        getline(ss, fullname, ','); ss.ignore();
        getline(ss, email, ','); ss.ignore();
        getline(ss, id_type, ','); ss.ignore();
        getline(ss, id, ','); ss.ignore();
        getline(ss, phone, ','); ss.ignore();
        getline(ss, licen, ','); ss.ignore();
        getline(ss, expiry, ','); ss.ignore();
        ss >> cp; ss.ignore();
        ss >> rating;

        // Compare with input
        if (uname == username && pass == password)
        {
            cout << "\nLogin successful. Welcome, " << fullname << "!\n";
            return new Member(uname, pass, fullname, email, id_type,
                              id, phone, licen, expiry, cp, rating);
        }
    }

    cout << "Invalid username or password.\n";
    return nullptr;
}

// -------- Utilities --------
/*
 * Checks if password is strong:
 * - At least 8 characters
 * - Contains uppercase, lowercase, digit, and special char
 */
bool Member::isStrongPasssword(string password)
{
    if (password.length() < 8) return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    string specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/";

    for (auto i : password)
    {
        if (isupper(i)) hasUpper = true;
        else if (islower(i)) hasLower = true;
        else if (isdigit(i)) hasDigit = true;
        else if (specialChars.find(i) != string::npos) hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Convert member object to a CSV string (for saving to file)
string Member::toString()
{
    return username + ", " + password + ", " + fullname + ", " + email + ", " + id_type + ", " +
           id + ", " + phone_number + ", " + licen_number + ", " +
           expiry_date + ", " + to_string(cp) + ", " + to_string(rating);
}

// -------- Profile Management --------
/*
 * Change password with strength validation.
 */
void Member::changePassword()
{
    string newpass;
    do
    {
        cout << "Enter your new password: ";
        cin.ignore(1, '\n');
        getline(cin, newpass);
        if (!isStrongPasssword(newpass))
        {
            cout << "Weak password! Must be at least 8 characters and include uppercase, lowercase, digit, and special character." << endl;
        }
    } while (!isStrongPasssword(newpass));
    this->password = newpass;
    cout << "Your new password has been saved successfully!" << endl;
}

/*
 * Menu for viewing/changing profile details
 */
void Member::ProfileManagement()
{
    int choice;
    do
    {
        cout << "\nProfile Management Menu:" << endl;
        cout << "1. View Profile" << endl;
        cout << "2. Change Password" << endl;
        cout << "3. Top up CP balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Show profile info
            cout << "\nProfile Information:" << endl;
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
        case 2: changePassword(); break;
        case 3: // Top up CP
        {
            double topup;
            cout << "Your current CP balance: " << cp << endl;
            cout << "Enter amount to top up: ";
            cin >> topup;
            if (topup > 0)
            {
                this->cp += topup;
                cout << "Top up successful! New CP balance: " << this->cp << endl;
            }
            else
            {
                cout << "Invalid top up amount!" << endl;
            }
            break;
        }
        case 4: cout << "Exiting Profile Management." << endl; break;
        default: cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
}

// -------- Member Menu --------
/*
 * Member’s main menu: links to profile, motorbike, and rental features.
 */
void Member::memberMenu(Admin &ad)
{
    int choice;
    do
    {
        cout << "\n--- Member Menu ---\n";
        cout << "1. Profile Management\n";
        cout << "2. Motorbike Listing\n";
        cout << "3. Register Motorbike\n";
        cout << "4. Search Motorbikes\n";
        cout << "5. Make Rental Request\n";
        cout << "6. View My Motorbike Requests\n";
        cout << "7. View/Return Motorbike & Give Ratings\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: ProfileManagement(); break;
        case 2: viewMotorbike(); break;
        case 3: registerMotorbike(ad); break;
        case 4: searchMotorbikes(ad); break;
        case 5: makeRentalRequest(ad); break;
        case 6: viewIncomingRequests(ad); break;
        case 7: completeRental(ad); break;
        case 0: cout << "Logging out...\n"; break;
        default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);
}
// -------- Motorbike-related features --------

/*
 * View motorbikes listed by this member.
 * Reads from motorbikes.txt and filters by owner’s username.
 */
void Member::viewMotorbike()
{
    cout << "\n--- Your Listed Motorbikes ---\n";
    ifstream file("motorbikes.txt");
    if (!file.is_open())
    {
        cout << "Error: Unable to open motorbikes.txt for reading.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line))
    {
        stringstream ss(line);
        string brand, model, color, plate, location, ownerName, temp;
        int size, year;
        double dailyRate, minRating;

        // Parse CSV values
        getline(ss, brand, ',');
        getline(ss, model, ',');
        getline(ss, color, ',');
        getline(ss, temp, ','); size = stoi(temp);
        getline(ss, temp, ','); year = stoi(temp);
        getline(ss, plate, ',');
        getline(ss, location, ',');
        getline(ss, temp, ','); dailyRate = stod(temp);
        getline(ss, temp, ','); minRating = stod(temp);
        getline(ss, ownerName, ',');

        // Display only if bike belongs to this member
        if (ownerName == this->username)
        {
            found = true;
            cout << "------------------------------------\n";
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Color: " << color << endl;
            cout << "Engine Size: " << size << "cc" << endl;
            cout << "Year Made: " << year << endl;
            cout << "License Plate: " << plate << endl;
            cout << "Location: " << location << endl;
            cout << "Daily Rate: " << dailyRate << " CP" << endl;
            cout << "Avg Renter Rating: " << minRating << endl;
            cout << "------------------------------------\n";
        }
    }
    if (!found)
    {
        cout << "You have no motorbikes listed.\n";
    }
    file.close();
}

/*
 * Normalize date into format YYYYMMDD (for easier comparisons).
 * Input format: dd/mm/yyyy
 */
string Member::normalizeDate(string dateStr)
{
    int d, m, y;
    char sep1, sep2;
    stringstream ss(dateStr);
    ss >> d >> sep1 >> m >> sep2 >> y;

    // Format YYYYMMDD using padding
    stringstream out;
    out << setw(4) << setfill('0') << y
        << setw(2) << setfill('0') << m
        << setw(2) << setfill('0') << d;
    return out.str();
}

/*
 * Register a new motorbike.
 * Collects details from user, creates a Motorbike object,
 * saves it into Admin’s list and updates motorbikes.txt.
 */
void Member::registerMotorbike(Admin &ad)
{
    string brand, model, color, plate, location;
    int size, year;
    double dailyRate, minRating;
    string availableFrom, availableTo;

    cout << "Enter motorbike brand: ";
    getline(cin, brand);
    cout << "Enter model: ";
    getline(cin, model);
    cout << "Enter color: ";
    getline(cin, color);
    cout << "Enter engine size (cc): ";
    cin >> size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter year made: ";
    cin >> year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter license plate: ";
    getline(cin, plate);
    cout << "Enter registration location: ";
    getline(cin, location);
    cout << "Enter daily rate (CP): ";
    cin >> dailyRate;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter minimum required renter rating: ";
    cin >> minRating;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter rental available from (dd/mm/yyyy): ";
    getline(cin, availableFrom);
    cout << "Enter rental available to (dd/mm/yyyy): ";
    getline(cin, availableTo);

    // Normalize date format
    availableFrom = normalizeDate(availableFrom);
    availableTo = normalizeDate(availableTo);

    // Create new motorbike object and save
    Motorbike *newBike = new Motorbike(brand, model, color, size, year, plate,
                                       location, dailyRate, minRating,
                                       this->username, availableFrom, availableTo);
    ad.Motorbike_list.push_back(newBike);
    ad.saveMotorbikes();
    cout << "Motorbike registered successfully!\n";
}

/*
 * Search motorbikes (basic: just show general list).
 */
void Member::searchMotorbikes(Admin &ad)
{
    ad.showGeneralMotorbike_list();
}

// -------- Rental Request Features --------

/*
 * Make a rental request for a motorbike.
 * Ensures:
 * - Bike exists
 * - Bike is not owned by this member
 * - Owner exists
 * - Renter’s rating is high enough
 */
void Member::makeRentalRequest(Admin &ad)
{
    string plate, from;
    int day;

    cout << "Enter license plate of the motorbike you want to rent: ";
    getline(cin, plate);
    cout << "Rented from? (dd/mm/yyyy): ";
    getline(cin, from);
    cout << "Rented for how many days?: ";
    cin >> day;

    Motorbike *bike = nullptr;
    for (auto b : ad.Motorbike_list)
    {
        if (b->licensePlate == plate)
        {
            bike = b;
            break;
        }
    }

    if (bike == nullptr)
    {
        cout << "Motorbike with license plate " << plate << " not found." << endl;
        return;
    }
    if (bike->ownerName == this->username)
    {
        cout << "You cannot rent your own motorbike." << endl;
        return;
    }

    // Find owner in member list
    Member *owner = nullptr;
    for (auto m : ad.Member_list)
    {
        if (m->username == bike->ownerName)
        {
            owner = m;
            break;
        }
    }
    if (owner == nullptr)
    {
        cout << "Owner of the motorbike not found." << endl;
        return;
    }

    // Check renter’s rating
    if (this->rating < bike->getRating())
    {
        cout << "Your rating is too low to rent this motorbike." << endl;
        return;
    }

    // Create rental request
    RentalRequest *newReq = new RentalRequest(ad.allRequests.size() + 1, this, owner, bike, day);
    ad.addRequest(newReq);
    ad.saveRequests();
    cout << "Rental request sent successfully." << endl;
}

/*
 * View rental requests incoming for this member’s motorbikes.
 * Member can approve or reject them.
 */
void Member::viewIncomingRequests(Admin &ad)
{
    cout << "\n--- Requests of Your Motorbike ---\n";
    bool found = false;

    for (auto req : ad.allRequests)
    {
        if (req->getOwner()->username == this->username &&
            req->getStatus() == RequestStatus::Pending)
        {
            req->showRequest();
            found = true;
            cout << "Do you want to approve this request? (y/n): ";
            char c;
            cin >> c;
            if (c == 'y' || c == 'Y')
                req->approve();
            else
                req->reject();
        }
    }

    if (!found)
        cout << "No incoming rental requests." << endl;

    ad.saveRequests();
}

/*
 * Complete rental:
 * - Renter views their requests
 * - If approved, renter can return the bike
 * - Renter gives rating + comment to owner
 */
void Member::completeRental(Admin &ad)
{
    cout << "\n--- Your Rental Request ---\n";
    bool found = false;

    for (auto req : ad.allRequests)
    {
        if (req->getRenter()->username == this->username &&
            !req->isCompleted())
        {
            req->showRequest();
            found = true;

            if (req->getStatus() == RequestStatus::Approved)
            {
                cout << "Do you want to return motorbike now? (y/n): ";
                char c;
                cin >> c;
                if (c == 'y' || c == 'Y')
                {
                    int rating;
                    cout << "Enter rating for the owner (1-5): ";
                    cin >> rating;
                    string comment;
                    cout << "Enter comment: ";
                    cin.ignore();
                    getline(cin, comment);

                    // Save rating & comment
                    req->setRenterRating(rating);
                    req->setRenterComment(comment);

                    // Update owner’s rating
                    Member *owner = req->getOwner();
                    if (owner)
                        owner->rating = (owner->rating + rating) / 2.0;

                    req->completeRental();
                    std::cout << "Rental completed successfully." << std::endl;
                }
            }
        }
    }

    if (!found)
        cout << "No rental requests found." << endl;

    ad.saveRequests();
}