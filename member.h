#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include "Motorbike.h"
#include "RentalRequest.h"
class Admin;
using namespace std;

class Member
{
private:
    string username, password, fullname, email, id_type;
    string id, phone_number, licen_number, expiry_date;
    double cp = 20;
    double rating = 3;
    Motorbike *ownermotorbike;
    std::vector<RentalRequest*> rentalRequests;
public:
    Member() {}
    Member(string username, string password, string fullname, string email, string id_type,
           string id, string phone_number, string licen_number, string expiry_date);

    Member(string username, string password, string fullname, string email, string id_type,
           string id, string phone_number, string licen_number, string expiry_date,
           double cp, double rating);
    
    Member(string username, string password, string fullname, string email, string id_type,
           string id, string phone_number, string licen_number, string expiry_date,
           Motorbike *ownermotorbike);

    static Member* login(const std::string& filename);
    string toString();
    static bool isStrongPasssword(string password);
    void changePassword();
    void ProfileManagement();
    void memberMenu(Admin& ad);
    void viewMotorbike();
    void registerMotorbike(Admin &ad);
    string normalizeDate(string dateStr);
    void searchMotorbikes(Admin& ad);
    void makeRentalRequest(Admin& ad);
    void viewIncomingRequests(Admin& ad);
    void completeRental(Admin& ad);

    friend class Admin;
    friend class RentalRequest;
};
#endif