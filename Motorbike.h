#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <string>
#include <vector>

/*
 * Motorbike class represents a vehicle available for rental.
 * Stores technical details, ownership, availability, and rental state.
 */
class Motorbike
{
private:
    // Basic details
    std::string brand;
    std::string model;
    std::string color;
    int engineSize;
    int yearMade;
    std::string licensePlate;
    std::string location;

    // Rental-related details
    double dailyRate;        // Rental cost per day (in CP)
    double rating;           // Minimum required renter rating
    std::string ownerName;   // Username of the owner
    std::string availableFrom;
    std::string availableTo;

    // Rental state
    bool isRented = false;   // True if currently rented
    std::string rentedFrom;
    std::string rentedTo;

public:
    // Constructors for creating motorbike objects
    Motorbike(std::string brand, std::string model, std::string color,
              int engineSize, int yearMade, std::string licensePlate,
              std::string location, double dailyRate, double rating,
              std::string ownerName, std::string availableFrom, std::string availableTo);
    
    Motorbike(std::string brand, std::string model, std::string color,
              int engineSize, int yearMade, std::string licensePlate,
              std::string location, double dailyRate, double rating,
              std::string ownerName, std::string availableFrom, std::string availableTo,
              bool isRented, std::string rentedFrom, std::string rentedTo);

    // Getters (access private attributes)
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

    // Convert object into CSV string for file saving
    std::string toString();

    // Allow Admin, Member, and RentalRequest to access private data directly
    friend class Admin;
    friend class Member;
    friend class RentalRequest;
};

#endif
