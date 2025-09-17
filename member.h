#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include "Motorbike.h"
#include "RentalRequest.h"
class Admin;   // Forward declaration, because Member interacts with Admin

using namespace std;

/*
 * Member class represents users who can rent or register motorbikes.
 * Each member has credentials, profile info, credit points (CP), rating, and possibly owned motorbikes.
 */
class Member
{
private:
    // Basic profile details
    string username, password, fullname, email, id_type;
    string id, phone_number, licen_number, expiry_date;

    // Credit points (used as currency) and rating (trust score)
    double cp = 20;
    double rating = 3;

    // Motorbike owned by the member (optional, may register multiple via Admin’s list)
    Motorbike *ownermotorbike;

    // List of rental requests made by this member
    std::vector<RentalRequest*> rentalRequests;

public:
    Member() {}

    // Constructors: Different variations for creating members
    Member(string username, string password, string fullname, string email, string id_type,
           string id, string phone_number, string licen_number, string expiry_date);

    Member(string username, string password, string fullname, string email, string id_type,
           string id, string phone_number, string licen_number, string expiry_date,
           double cp, double rating);
    
    Member(string username, string password, string fullname, string email, string id_type,
           string id, string phone_number, string licen_number, string expiry_date,
           Motorbike *ownermotorbike);

    // Authentication
    static Member* login(const std::string& filename);

    // Convert member object to string (for saving to file)
    string toString();

    // Utility for password strength check
    static bool isStrongPasssword(string password);

    // Profile management features
    void changePassword();
    void ProfileManagement();

    // Member’s menu interface
    void memberMenu(Admin& ad);

    // Motorbike-related features
    void viewMotorbike();
    void registerMotorbike(Admin &ad);
    string normalizeDate(string dateStr);
    void searchMotorbikes(Admin& ad);

    // Rental request features
    void makeRentalRequest(Admin& ad);
    void viewIncomingRequests(Admin& ad);
    void completeRental(Admin& ad);

    friend class Admin;
    friend class RentalRequest;
};
#endif
