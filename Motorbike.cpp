#include "Motorbike.h"
#include <numeric>
#include <sstream>

/*
 * Constructor for registering a new motorbike without rental state info.
 */
Motorbike::Motorbike(std::string brand, std::string model, std::string color,
                     int engineSize, int yearMade, std::string licensePlate,
                     std::string location, double dailyRate, double rating,
                     std::string ownerName, std::string availableFrom, std::string availableTo)
    : brand(brand), model(model), color(color), engineSize(engineSize),
      yearMade(yearMade), licensePlate(licensePlate), location(location),
      dailyRate(dailyRate), rating(rating), ownerName(ownerName),
      availableFrom(availableFrom), availableTo(availableTo) {}

/*
 * Constructor including rental state information (used when reloading from file).
 */
Motorbike::Motorbike(std::string brand, std::string model, std::string color,
                     int engineSize, int yearMade, std::string licensePlate,
                     std::string location, double dailyRate, double rating,
                     std::string ownerName, std::string availableFrom, std::string availableTo,
                     bool isRented, std::string rentedFrom, std::string rentedTo)
    : brand(brand), model(model), color(color), engineSize(engineSize),
      yearMade(yearMade), licensePlate(licensePlate), location(location),
      dailyRate(dailyRate), rating(rating), ownerName(ownerName),
      availableFrom(availableFrom), availableTo(availableTo),
      isRented(isRented), rentedFrom(rentedFrom), rentedTo(rentedTo) {}

// -------- Getters --------
std::string Motorbike::getBrand() { return brand; }
std::string Motorbike::getModel() { return model; }
int Motorbike::getEngineSize() { return engineSize; }
std::string Motorbike::getLicensePlate() { return licensePlate; }
std::string Motorbike::getLocation() { return location; }
double Motorbike::getDailyRate() { return dailyRate; }
double Motorbike::getRating() { return rating; }
std::string Motorbike::getOwnerName() { return ownerName; }
std::string Motorbike::getAvailableFrom() { return availableFrom; }
std::string Motorbike::getAvailableTo() { return availableTo; }
bool Motorbike::getIsRented() { return isRented; }
std::string Motorbike::getRentedFrom() { return rentedFrom; }
std::string Motorbike::getRentedTo() { return rentedTo; }

/*
 * Convert motorbike data into a CSV string for file persistence.
 * Includes rental state (isRented, rentedFrom, rentedTo).
 */
std::string Motorbike::toString()
{
  return brand + "," + model + "," + color + "," + std::to_string(engineSize) + "," +
         std::to_string(yearMade) + "," + licensePlate + "," + location + "," +
         std::to_string(dailyRate) + "," + std::to_string(rating) + "," + ownerName + "," +
         availableFrom + "," + availableTo + "," + (isRented ? "1" : "0") + "," +
         rentedFrom + "," + rentedTo;
}
