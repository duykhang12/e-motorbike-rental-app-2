#ifndef RENTALREQUEST_H
#define RENTALREQUEST_H

#include <string>
#include "Member.h"
#include "Motorbike.h"
using namespace std;

enum class RequestStatus {
    Pending,
    Approved,
    Rejected
};

class RentalRequest {
private:
    string requestID;
    Member* renter;
    Member* owner;
    Motorbike* bike;
    int days; // duration
    RequestStatus status;

public:
    RentalRequest(string requestID, Member* renter, Member* owner, Motorbike* bike, int days);

    string getRequestID() const;
    Member* getRenter() const;
    Member* getOwner() const;
    Motorbike* getBike() const;
    int getDays() const;
    RequestStatus getStatus() const;

    void approve();
    void reject();
    void showRequest() const;
};

#endif
