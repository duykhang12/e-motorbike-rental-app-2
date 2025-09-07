#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <string>

class Motorbike {
private:
    std::string brand;
    std::string model;
    std::string color;
    int engineSize;     // in cc
    int yearMade;
    std::string licensePlate;
    std::string location;   // HCMC or Hanoi

    // Extra fields (not shown to guests)
    double dailyRate;       
    double rating;          
    std::string ownerName;  

public:
    //ructor
    Motorbike(std::string& brand, std::string& model, std::string& color,
              int engineSize, int yearMade, std::string& licensePlate, 
              std::string& location, double dailyRate, double rating,
              std::string& ownerName);

    // Getters (some restricted for guests)
    std::string getBrand();
    std::string getModel();
    int getEngineSize();
    std::string getLocation();

    // For members/admin only
    double getDailyRate();
    double getRating();
    std::string getOwnerName();
};

#endif
