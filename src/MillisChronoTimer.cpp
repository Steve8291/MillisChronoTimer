#include <MillisChronoTimer.h>

MillisChronoTimer::MillisChronoTimer(unsigned long millisec)
    : start(std::chrono::high_resolution_clock::now()),
      interval(std::chrono::milliseconds(millisec))
{}

void MillisChronoTimer::reset() {
    start = std::chrono::high_resolution_clock::now();
    _force_expire = false;
}

void MillisChronoTimer::forceExpire() {
    _force_expire = true;
}

void MillisChronoTimer::modify(unsigned long millisec) {
    interval = std::chrono::milliseconds(millisec);
    _force_expire = false;
}

bool MillisChronoTimer::expired() const {
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
    if ( duration >= interval || _force_expire) {
        return true;
    } else return false;
}

double MillisChronoTimer::elapsed() const {
    return elapsedSec() * 1000;  // Convert to milliseconds
}

double MillisChronoTimer::elapsedSec() const {
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(now - start).count();  // duration in seconds
}

double MillisChronoTimer::elapsedMin() const {
    return elapsedSec() / 60.0;  // Convert to minutes
}

double MillisChronoTimer::elapsedHrs() const {
    return elapsedSec() / 3600.0;  // Convert to hours
}