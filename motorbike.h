#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include<iostream>
#include <string>
using namespace std;

class Motorbike {
private:
    string brand;
    string model;
    string color;
    int engineSize;     // in cc
    int yearMade;
    string licensePlate;
    string location;   // HCMC or Hanoi

    // Extra fields (not shown to guests)
    double dailyRateCP;       
    double rating;          
    string ownerName; 
    string availableFrom;
    string availableTo; 

public:
    //ructor

    Motorbike(){}
    Motorbike(string brand, string model, string color,
              int engineSize, int yearMade, string licensePlate, 
              string location, double dailyRateCP, double rating,
              string ownerName, string availableFrom, string availableTo);
    
    string toString();
    friend class Member;
    friend class Admin;
};

#endif