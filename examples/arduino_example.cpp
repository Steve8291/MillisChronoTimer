#include <Arduino.h>
#include <MillisChronoTimer.h>

// Create instance of MillisChronoTimer
MillisChronoTimer example_timer(15);  // 15ms timer


void setup() {
    Serial.begin(115200);
    // Delay to show that timer begins with instantiation.
    delay(5000);
    Serial.println("\n\n**********************************");
    Serial.print("Elapsed Time: ");
    Serial.print(example_timer.elapsed());
    Serial.println(" milliseconds");
    Serial.print("Is Expired: ");
    Serial.println(example_timer.expired());
    Serial.println("**********************************\n");
}


void loop() {
    // Reset the timer
    example_timer.reset();

    // Do some work
    for (int i = 0; i < 10000; ++i) {
        if ( example_timer.expired() ) {
            Serial.print("Timer Elapsed: ");
            Serial.print(example_timer.elapsed(), 4);  // Print 4 decimal places
            Serial.println(" milliseconds");

            Serial.print("Timer Elapsed: ");
            Serial.print(example_timer.elapsedSec(), 7);  // Print 7 decimal places
            Serial.println(" seconds");

            example_timer.reset();
        }
    }

    Serial.println("\n-------------------------------\n");
    delay(10000);
}