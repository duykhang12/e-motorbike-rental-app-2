#ifndef RATING_H
#define RATING_H

#include <string>
#include <vector>
using namespace std;

class Rating {
private:
    vector<int> scores;     // Store all rating scores (1–5)
    double average;         // Average rating

public:
    Rating();

    void addScore(int score);                // Add a new score (1–5)
    double getAverage() const;               // Get current average
    int getTotalRatings() const;             // Get how many ratings so far
    void showSummary(const string& name) const; // Show summary (used in Member)
};

#endif
