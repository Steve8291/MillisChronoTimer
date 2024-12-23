#ifndef MILLISCHRONOTIMER_H
#define MILLISCHRONOTIMER_H

#include <chrono>

/*!
*   A simple non-blocking timer library
*   Uses the high_resolution_clock from the chrono C++ Standard Template Library.
*   Create multiple timer instances to act as task schedulers on a millisecond time frame.
*   Allows for timer reset, checking elapsed time and if timer has expired.
*/
class MillisChronoTimer {
public:
    MillisChronoTimer(unsigned long millisec);

    // Reset the timer
    void reset();

    // Returns true if timer has expired
    bool expired() const;

    // Returns elapsed time in seconds
    double elapsedSec() const;

    // Returns elapsed time in milliseconds
    double elapsed() const;

private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::milliseconds interval;
};

#endif