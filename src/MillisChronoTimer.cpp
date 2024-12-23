#include "MillisChronoTimer.h"

MillisChronoTimer::MillisChronoTimer(unsigned long millisec)
    : start(std::chrono::high_resolution_clock::now()),
      interval(std::chrono::milliseconds(millisec))
{}

void MillisChronoTimer::reset() {
    start = std::chrono::high_resolution_clock::now();
}

bool MillisChronoTimer::expired() const {
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
    if ( duration >= interval ) return true;
    else return false;
}

double MillisChronoTimer::elapsedSec() const {
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(now - start).count();  // duration in seconds
}

double MillisChronoTimer::elapsed() const {
    return elapsedSec() * 1000;  // Convert to milliseconds
}