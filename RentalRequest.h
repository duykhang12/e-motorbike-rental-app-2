#ifndef RENTALREQUEST_H
#define RENTALREQUEST_H

#include <iostream>
#include <string>

// Forward declarations
class Member;
class Motorbike;

/*
 * Enum for rental request status:
 * - Pending: waiting for owner approval
 * - Approved: accepted by owner
 * - Rejected: declined by owner
 */
enum class RequestStatus
{
    Pending,
    Approved,
    Rejected
};

/*
 * RentalRequest represents a transaction between renter and owner.
 * Stores request details, status, completion info, and ratings/comments.
 */
class RentalRequest
{
public:
    int requestID;             // Unique ID for request
    Member* renter;            // Member who wants to rent
    Member* owner;             // Owner of the motorbike
    Motorbike* bike;           // Motorbike being rented
    int days;                  // Number of days requested
    RequestStatus status;      // Current status of request
    bool completed = false;    // True if rental completed

    // Feedback system
    int renterRatingGiven = 0;
    std::string renterComment = "";
    int ownerRatingGiven = 0;
    std::string ownerComment = "";

    // Constructor
    RentalRequest(int id, Member* renter, Member* owner, Motorbike* bike, int days);
    
    // Getters
    int getRequestID();
    Member* getRenter();
    Member* getOwner();
    Motorbike* getBike();
    int getDays();
    RequestStatus getStatus();

    // Request state management
    void approve();
    void reject();
    void showRequest();
    bool isCompleted();
    void completeRental();

    // Feedback setters
    bool renterRated();
    void setRenterRating(int rating);
    void setRenterComment(std::string comment);
    
    // Convert object into CSV for file saving
    std::string toString();
};

#endif
