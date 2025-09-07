#include "Motorbike.h"

// Constructor implementation
Motorbike::Motorbike(std::string& brand, std::string& model, std::string& color,
                     int engineSize, int yearMade, std::string& licensePlate, 
                     std::string& location, double dailyRate, double rating,
                     std::string& ownerName)
    : brand(brand), model(model), color(color), engineSize(engineSize), 
      yearMade(yearMade), licensePlate(licensePlate), location(location),
      dailyRate(dailyRate), rating(rating), ownerName(ownerName) {}

std::string Motorbike::getBrand() { return brand; }
std::string Motorbike::getModel() { return model; }
int Motorbike::getEngineSize() { return engineSize; }
std::string Motorbike::getLocation() { return location; }

double Motorbike::getDailyRate() { return dailyRate; }
double Motorbike::getRating() { return rating; }
std::string Motorbike::getOwnerName() { return ownerName; }
