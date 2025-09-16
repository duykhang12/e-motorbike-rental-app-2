#include <iostream>
#include <vector>
#include "Motorbike.h"
#include "member.h"
#include "admin.h"

#define FILENAME "motorbikes.txt"

void displayWelcomeScreen()
{
    std::cout << "EEET2482/EEET2653 GROUP PROJECT\n";
    std::cout << "Semester 2, 2025\n";
    std::cout << "E-MOTORBIKE RENTAL APPLICATION\n";
    std::cout << "============================================\n";
    std::cout << "Instructor: Dr Ling Huo Chong, Dr Ushik Shrestha, Dr Tri Huynh\n";
    std::cout << "Group: Group No.14\n";
    std::cout << "s4138880, Trinh Van Khai\n";
    std::cout << "s4140414, Do The Loc\n";
    std::cout << "s3963613, Nguyen Duy Khang\n";
    std::cout << "s4037876, Hoang Ngo Anh Duc\n";
}

void menu()
{
    std::cout << "\nUse the app as: 1. Guest   2. Member   3. Admin   0. Exit\n";
    std::cout << "\nEnter your choice: ";
}

int main()
{
    int choice;

    displayWelcomeScreen();

    do
    {
        Admin admin;
        admin.reloadMembers();
        admin.reloadMotorbikes();
        admin.reloadRequests();
        menu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            admin.showGeneralMotorbike_list();
            break;
        }
        case 2:
        {
            Member *loggedIn = Member::login("members.txt");
            if (loggedIn)
            {
                loggedIn->memberMenu(admin);
                delete loggedIn;
            }
            break;
        }
        case 3:
        {
            Admin *loggedIn = admin.login("admins.txt", admin);
            if (loggedIn)
            {
                loggedIn->adminMenu();
            }
            break;
        }
        case 0:
        {
            std::cout << "Exiting application.\n";
            break;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}