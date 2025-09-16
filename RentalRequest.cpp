#include "RentalRequest.h"
#include "member.h"
#include "Motorbike.h"
#include <sstream>

RentalRequest::RentalRequest(int id, Member* renter, Member* owner, Motorbike* bike, int days)
    : requestID(id), renter(renter), owner(owner), bike(bike), days(days), status(RequestStatus::Pending) {}

int RentalRequest::getRequestID() { return requestID; }
Member* RentalRequest::getRenter() { return renter; }
Member* RentalRequest::getOwner() { return owner; }
Motorbike* RentalRequest::getBike() { return bike; }
int RentalRequest::getDays() { return days; }
RequestStatus RentalRequest::getStatus() { return status; }

void RentalRequest::approve()
{
    this->status = RequestStatus::Approved;
}

void RentalRequest::reject()
{
    this->status = RequestStatus::Rejected;
}

void RentalRequest::showRequest()
{
    std::cout << "Request ID: " << requestID << std::endl;
    std::cout << "Renter: " << renter->username << std::endl;
    std::cout << "Owner: " << owner->username << std::endl;
    std::cout << "Motorbike: " << bike->getBrand() << " " << bike->getModel() << std::endl;
    std::cout << "Days: " << days << std::endl;
    std::cout << "Status: " << (status == RequestStatus::Pending ? "Pending" : (status == RequestStatus::Approved ? "Approved" : "Rejected")) << std::endl;
}

bool RentalRequest::isCompleted() {
    return completed;
}

void RentalRequest::completeRental() {
    this->completed = true;
    this->bike->isRented = false;
}

bool RentalRequest::renterRated() {
    return renterRatingGiven != 0;
}

void RentalRequest::setRenterRating(int rating) {
    this->renterRatingGiven = rating;
}

void RentalRequest::setRenterComment(std::string comment) {
    this->renterComment = comment;
}

std::string RentalRequest::toString()
{
    std::stringstream ss;
    ss << requestID << ","
       << renter->username << ","
       << owner->username << ","
       << bike->getLicensePlate() << ","
       << days << ","
       << static_cast<int>(status) << ","
       << (completed ? "1" : "0") << ","
       << renterRatingGiven << ","
       << renterComment << ","
       << ownerRatingGiven << ","
       << ownerComment;
    return ss.str();
}