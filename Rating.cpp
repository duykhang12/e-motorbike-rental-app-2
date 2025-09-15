#include "Rating.h"
#include <iostream>
#include <numeric> // for accumulate
using namespace std;

Rating::Rating() : average(0.0) {}

void Rating::addScore(int score) {
    if (score >= 1 && score <= 5) {
        scores.push_back(score);
        average = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
    } else {
        cout << "Invalid rating. Score must be between 1 and 5." << endl;
    }
}

double Rating::getAverage() const {
    return average;
}

int Rating::getTotalRatings() const {
    return scores.size();
}

void Rating::showSummary(const string& name) const {
    cout << "\n--- Rating Summary for " << name << " ---" << endl;
    if (scores.empty()) {
        cout << "No ratings yet." << endl;
    } else {
        cout << "Average Rating: " << average << " (from " << scores.size() << " ratings)" << endl;
    }
}
