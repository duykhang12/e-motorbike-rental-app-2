#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "member.h"
#include "motorbike.h"
using namespace std;

class Admin{
    private:
    vector<Member*> Member_list;
    vector<Motorbike*> Motorbike_list;
    public:
    Admin(){}
    Admin(vector<Member*> Member_list, vector<Motorbike*> Motorbike_list);
    void regist();
    void showGeneralMotorbike_list();
    void showAllMember_List();
    void showAllMotorbike_List();
    bool reloadMembers();
    bool reloadMotorbikes();
    void saveData();
    friend class Member;
};

#endif
