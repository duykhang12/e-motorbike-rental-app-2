#include <iostream>
#include <vector>
#include "Motorbike.h"
#include "Guest.h"

#define FILENAME "motorbikes.txt"

void displayWelcomeScreen() {
    std::cout << "EEET2482/EEET2653 GROUP PROJECT\n";
    std::cout << "Semester 2, 2025\n";
    std::cout << "E-MOTORBIKE RENTAL APPLICATION\n";
    std::cout << "============================================\n";
    std::cout << "Instructor: Dr Ling Huo Chong, Dr Ushik Shrestha, Dr Tri Huynh\n";
    std::cout << "Group: Group No.14\n";
    std::cout << "XXXXX, Student Name\n";
    std::cout << "XXXXX, Student Name\n";
    std::cout << "XXXXX, Student Name\n";
    std::cout << "XXXXX, Student Name\n";
}

void menu() {
    std::cout << "\nUse the app as: 1. Guest   2. Member   3. Admin   4. Exit\n";
    std::cout << "\nEnter your choice: ";
}

int main() {
    Guest system;

    if(system.loadMotorbikes(FILENAME) == false)
        std::cout << "There's no data to be reloaded.\n";

    int choice;
    bool exit = false;

    displayWelcomeScreen();

    while (!exit) {
        menu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                system.list();
                break;
            }
            case 2:
                std::cout << "Member flow (to be implemented)...\n";
                break;
            case 3:
                std::cout << "Admin flow (to be implemented)...\n";
                break;
            case 4:
                std::cout << "Exiting application.\n";
                exit = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        if (!exit) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
    }

    return 0;
}
