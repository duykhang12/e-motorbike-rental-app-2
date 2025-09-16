#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "member.h"
#include "motorbike.h"
#include "RentalRequest.h"

using namespace std;

class Admin
{
private:
    string username, password;
    vector<Member *> Member_list;
    vector<Motorbike *> Motorbike_list;
    vector<RentalRequest*> allRequests;

public:
    Admin() {}
    Admin(string username, string password);

    void regist();
    static Admin *login(const std::string &filename, Admin &admin);
    bool adminMenu();
    void showGeneralMotorbike_list();
    void showAllMember_List();
    void showAllMotorbike_List();

    bool reloadMembers();
    bool reloadMotorbikes();
    bool reloadRequests();
    bool saveMotorbikes();
    bool saveRequests();
    bool saveMembers();
    void addRequest(RentalRequest* req);

    friend class Member;
};

#endif
