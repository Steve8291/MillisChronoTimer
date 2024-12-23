#include <Arduino.h>
#include <MillisChronoTimer.h>

// Create two instances of MillisChronoTimer
MillisChronoTimer example_timer1(100);  // 100ms timer
MillisChronoTimer example_timer2(50);   // 50ms timer


void setup() {
    Serial.begin(115200);
    Serial.println("\n-------------------------------\n");
}


void loop() {
    // Reset the timers
    example_timer1.reset();
    example_timer2.reset();

    // Do some work
    for (int i = 0; i < 10000; ++i) {
        if ( example_timer1.expired() ) {
            Serial.print("Timer1 Elapsed: ");
            Serial.print(example_timer1.elapsed(), 4);  // Print 4 decimal places
            Serial.println(" milliseconds");

            Serial.print("Timer1 Elapsed: ");
            Serial.print(example_timer1.elapsedSec(), 7);  // Print 7 decimal places
            Serial.println(" seconds");

            example_timer1.reset();
        }

        // Example of using a second timer concurrently.
        if ( example_timer2.expired() ) {
            Serial.print("   - Timer2 Elapsed Time: ");
            Serial.print(example_timer2.elapsed());
            Serial.println(" milliseconds");
            example_timer2.reset();
        }
    }

    Serial.println("\n-------------------------------\n");
    delay(10000);
}