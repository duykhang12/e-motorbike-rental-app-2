#include "motorbike.h"
#include<iostream>
#include <sstream>
#include <iomanip>
using namespace std;

Motorbike::Motorbike(string brand, string model, string color,
    int engineSize, int yearMade, string licensePlate, 
    string location, double dailyRateCP, double rating,
    string ownerName, string availableFrom, string availableTo) :
    brand(brand), model(model), color(color), engineSize(engineSize), yearMade(yearMade),
    licensePlate(licensePlate), location(location), dailyRateCP(dailyRateCP), rating(rating),
    ownerName(ownerName), availableFrom(availableFrom), availableTo(availableTo){}

string Motorbike::toString(){
    return brand + ", " + model + ", " + color + ", " + to_string(engineSize) + ", " + to_string(yearMade) +
           licensePlate + ", " + location + ", " + to_string(dailyRateCP) + ", " + to_string(rating) + ", " + 
           ownerName + ", " + availableFrom + ", " + availableTo;
    }