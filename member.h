#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include "motorbike.h"
using namespace std;


class Member{
    private:
    string username, password, fullname, email, id_type;
    int id, phone_number, licen_number, expiry_date;
    double cp = 20;
    double rating = 3;
    Motorbike* ownermotorbike;
    public:
    Member(){}

    Member(string username, string password, string fullname, string email, string id_type,
        int id, int phone_number, int licen_number, int expiry_date);

    Member(string username, string password, string fullname, string email, string id_type,
        int id , int phone_number, int licen_number, int expiry_date, Motorbike* ownermotorbike);

    Member(string username, string password, string fullname, string email, string id_type,
        int id, int phone_number, int licen_number, int expiry_date, double cp, double rating);
    
    string toString();
    static bool isStrongPasssword(string password);
    void changePassword();
    // Convert "dd/mm/yyyy" → "YYYYMMDD"
    string normalizeDate(string dateStr);
    void searchMotorbikes();
    friend class Admin;
};

#endif
