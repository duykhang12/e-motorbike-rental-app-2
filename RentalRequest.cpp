
#include "RentalRequest.h"
#include <iostream>
using namespace std;

RentalRequest::RentalRequest(string requestID, Member* renter, Member* owner, Motorbike* bike, int days)
    : requestID(requestID), renter(renter), owner(owner), bike(bike), days(days), status(RequestStatus::Pending) {}

string RentalRequest::getRequestID() const {
    return requestID;
}

Member* RentalRequest::getRenter() const {
    return renter;
}

Member* RentalRequest::getOwner() const {
    return owner;
}

Motorbike* RentalRequest::getBike() const {
    return bike;
}

int RentalRequest::getDays() const {
    return days;
}

RequestStatus RentalRequest::getStatus() const {
    return status;
}

void RentalRequest::approve() {
    status = RequestStatus::Approved;
    cout << "Request " << requestID << " approved.\n";
}

void RentalRequest::reject() {
    status = RequestStatus::Rejected;
    cout << "Request " << requestID << " rejected.\n";
}

void RentalRequest::showRequest() const {
    cout << "\n--- Rental Request ---" << endl;
    cout << "Request ID: " << requestID << endl;
    cout << "Renter: " << renter->getName() << endl;
    cout << "Owner: " << owner->getName() << endl;
    cout << "Bike: " << bike->getInfo() << endl;
    cout << "Days: " << days << endl;
    cout << "Status: ";
    switch (status) {
        case RequestStatus::Pending: cout << "Pending"; break;
        case RequestStatus::Approved: cout << "Approved"; break;
        case RequestStatus::Rejected: cout << "Rejected"; break;
    }
    cout << "\n";
}
