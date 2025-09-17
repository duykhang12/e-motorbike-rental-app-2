#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "member.h"
#include "motorbike.h"
#include "RentalRequest.h"

using namespace std;

/*
 * Admin class manages members, motorbikes, and rental requests.
 * Provides features like login, registration, listing, saving, and reloading data.
 */
class Admin
{
private:
    string username, password;
    vector<Member *> Member_list;
    vector<Motorbike *> Motorbike_list;
    std::vector<RentalRequest*> allRequests;

public:
    Admin() {}
    Admin(string username, string password);       // Constructor to initialize admin with credentials

    void regist();                                 // Register a new member
    static Admin *login(const std::string &filename, Admin &admin);  // Authenticate admin
    bool adminMenu();                              // Show admin menu options
    void showGeneralMotorbike_list();              // Display simplified motorbike list
    void showAllMember_List();                     // Display detailed members list
    void showAllMotorbike_List();                  // Display detailed motorbike list

    // Reload data from text files into memory
    bool reloadMembers();
    bool reloadMotorbikes();
    bool reloadRequests();

    // Save in-memory data back to text files
    bool saveMotorbikes();
    bool saveRequests();
    bool saveMembers();

    void addRequest(RentalRequest* req);           // Add rental request to admin’s list

    friend class Member;                           // Member needs access to Admin’s lists
};

#endif
