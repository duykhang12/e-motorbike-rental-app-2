#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <string>
#include <vector>

class Motorbike
{
private:
    std::string brand;
    std::string model;
    std::string color;
    int engineSize;
    int yearMade;
    std::string licensePlate;
    std::string location;

    double dailyRate;
    double rating;
    std::string ownerName;
    std::string availableFrom;
    std::string availableTo;

    bool isRented = false;
    std::string rentedFrom;
    std::string rentedTo;

public:
    Motorbike(std::string brand, std::string model, std::string color,
              int engineSize, int yearMade, std::string licensePlate,
              std::string location, double dailyRate, double rating,
              std::string ownerName, std::string availableFrom, std::string availableTo);
    
    Motorbike(std::string brand, std::string model, std::string color,
              int engineSize, int yearMade, std::string licensePlate,
              std::string location, double dailyRate, double rating,
              std::string ownerName, std::string availableFrom, std::string availableTo,
              bool isRented, std::string rentedFrom, std::string rentedTo);

    std::string getBrand();
    std::string getModel();
    int getEngineSize();
    std::string getLicensePlate();
    std::string getLocation();
    double getDailyRate();
    double getRating();
    std::string getOwnerName();
    std::string getAvailableFrom();
    std::string getAvailableTo();
    bool getIsRented();
    std::string getRentedFrom();
    std::string getRentedTo();

    std::string toString();
    friend class Admin;
    friend class Member;
    friend class RentalRequest;
};

#endif