#include "Guest.h"
#include <iostream>
#include <fstream>
#include <sstream>

Guest::Guest(){}

bool Guest::loadMotorbikes(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << "\n";
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; // skip blank lines

        std::stringstream ss(line);
        std::string brand, model, color, licensePlate, location, ownerName;
        int engineSize, yearMade;
        double dailyRate, rating;

        std::getline(ss, brand, ',');
        std::getline(ss, model, ',');
        std::getline(ss, color, ',');
        ss >> engineSize; ss.ignore();
        ss >> yearMade; ss.ignore();
        std::getline(ss, licensePlate, ',');
        std::getline(ss, location, ',');
        ss >> dailyRate; ss.ignore();
        ss >> rating; ss.ignore();
        std::getline(ss, ownerName, ',');

        motorbikes.emplace_back(brand, model, color, engineSize, yearMade, licensePlate,
                           location, dailyRate, rating, ownerName);
    }

    file.close();
    return true;
}

void Guest::list() {
    std::cout << "\n--- Motorbikes List ---\n";
    for (auto& bike : motorbikes) {
        std::cout << "Brand: " << bike.getBrand()
             << " | Model: " << bike.getModel()
             << " | Engine: " << bike.getEngineSize() << "cc"
             << " | Location: " << bike.getLocation() << std::endl;
    }
    std::cout << "-----------------------------\n";
}
