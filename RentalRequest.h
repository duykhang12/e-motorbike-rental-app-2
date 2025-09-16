#ifndef RENTALREQUEST_H
#define RENTALREQUEST_H

#include <iostream>
#include <string>

class Member;
class Motorbike;

enum class RequestStatus
{
    Pending,
    Approved,
    Rejected
};

class RentalRequest
{
public:
    int requestID;
    Member* renter;
    Member* owner;
    Motorbike* bike;
    int days;
    RequestStatus status;
    bool completed = false;

    int renterRatingGiven = 0;
    std::string renterComment = "";
    int ownerRatingGiven = 0;
    std::string ownerComment = "";

    RentalRequest(int id, Member* renter, Member* owner, Motorbike* bike, int days);
    
    int getRequestID();
    Member* getRenter();
    Member* getOwner();
    Motorbike* getBike();
    int getDays();
    RequestStatus getStatus();

    void approve();
    void reject();
    void showRequest();
    bool isCompleted();
    void completeRental();
    
    bool renterRated();
    void setRenterRating(int rating);
    void setRenterComment(std::string comment);
    
    std::string toString();
};

#endif