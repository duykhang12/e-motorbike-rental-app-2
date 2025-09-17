#include "RentalRequest.h"
#include "member.h"
#include "Motorbike.h"
#include <sstream>

/*
 * Constructor: create a new rental request with Pending status.
 */
RentalRequest::RentalRequest(int id, Member* renter, Member* owner, Motorbike* bike, int days)
    : requestID(id), renter(renter), owner(owner), bike(bike), days(days), status(RequestStatus::Pending) {}

// -------- Getters --------
int RentalRequest::getRequestID() { return requestID; }
Member* RentalRequest::getRenter() { return renter; }
Member* RentalRequest::getOwner() { return owner; }
Motorbike* RentalRequest::getBike() { return bike; }
int RentalRequest::getDays() { return days; }
RequestStatus RentalRequest::getStatus() { return status; }

// -------- State management --------
/*
 * Approve a rental request.
 */
void RentalRequest::approve()
{
    this->status = RequestStatus::Approved;
}

/*
 * Reject a rental request.
 */
void RentalRequest::reject()
{
    this->status = RequestStatus::Rejected;
}

/*
 * Display request details to console.
 */
void RentalRequest::showRequest()
{
    std::cout << "Request ID: " << requestID << std::endl;
    std::cout << "Renter: " << renter->username << std::endl;
    std::cout << "Owner: " << owner->username << std::endl;
    std::cout << "Motorbike: " << bike->getBrand() << " " << bike->getModel() << std::endl;
    std::cout << "Days: " << days << std::endl;
    std::cout << "Status: "
              << (status == RequestStatus::Pending ? "Pending" :
                  (status == RequestStatus::Approved ? "Approved" : "Rejected"))
              << std::endl;
}

/*
 * Check if rental has been completed.
 */
bool RentalRequest::isCompleted() {
    return completed;
}

/*
 * Mark rental as completed.
 * Also resets bike’s rental state to available.
 */
void RentalRequest::completeRental() {
    this->completed = true;
    this->bike->isRented = false;
}

// -------- Feedback --------
/*
 * Check if renter has already rated the transaction.
 */
bool RentalRequest::renterRated() {
    return renterRatingGiven != 0;
}

/*
 * Set rating given by renter to owner.
 */
void RentalRequest::setRenterRating(int rating) {
    this->renterRatingGiven = rating;
}

/*
 * Set comment provided by renter to owner.
 */
void RentalRequest::setRenterComment(std::string comment) {
    this->renterComment = comment;
}

// -------- Persistence --------
/*
 * Convert request into a CSV line for saving into rental_request.txt.
 */
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
