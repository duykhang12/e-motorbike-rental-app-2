#include <iostream>
#include <vector>
#include "Motorbike.h"
#include "member.h"
#include "admin.h"

#define FILENAME "motorbikes.txt"

/*
 * Display welcome screen with project info, instructors, and team members.
 */
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

/*
 * Display the main menu for choosing user type.
 */
void menu()
{
    std::cout << "\nUse the app as: 1. Guest   2. Member   3. Admin   0. Exit\n";
    std::cout << "\nEnter your choice: ";
}

/*
 * Entry point of the program.
 * Handles main menu loop and user role selection.
 */
int main()
{
    int choice;

    displayWelcomeScreen();   // Show project/team info at startup

    do
    {
        Admin admin;  // Admin object manages members, motorbikes, and requests

        // Reload data from files into memory at each loop iteration
        admin.reloadMembers();
        admin.reloadMotorbikes();
        admin.reloadRequests();

        menu();
        std::cin >> choice;

        switch (choice)
        {
        case 1: // Guest user: can only view motorbike list
        {
            admin.showGeneralMotorbike_list();
            break;
        }
        case 2: // Member login
        {
            Member *loggedIn = Member::login("members.txt");
            if (loggedIn)
            {
                // Once logged in, show member menu
                loggedIn->memberMenu(admin);

                // After logout, free memory for this session
                delete loggedIn;
            }
            break;
        }
        case 3: // Admin login
        {
            Admin *loggedIn = admin.login("admins.txt", admin);
            if (loggedIn)
            {
                // If login successful, show admin menu
                loggedIn->adminMenu();
            }
            break;
        }
        case 0: // Exit application
        {
            std::cout << "Exiting application.\n";
            break;
        }
        default: // Invalid input handling
        {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 0); // Loop until user chooses to exit

    return 0;
}
