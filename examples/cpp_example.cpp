#include <MillisChronoTimer.h>
#include <iostream>

int main() {
    MillisChronoTimer example_timer(15);
    std::cout << "Is Expired: " << example_timer.expired() << "\n";

    // Do some work
    for (int i = 0; i < 1000000; ++i) {
        if ( example_timer.expired() ) {
            std::cout << "Is Expired: " << example_timer.expired() << "\n";
            std::cout << "Elapsed time: " << example_timer.elapsedSec() << " seconds\n";
            std::cout << "Elapsed time: " << example_timer.elapsed() << " milliseconds\n";

            example_timer.reset();
        } 
    }

    return 0;
}