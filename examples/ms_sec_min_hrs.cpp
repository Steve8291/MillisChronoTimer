#include <Arduino.h>
#include <MillisChronoTimer.h>

const unsigned long BAUD_RATE = 115200;
MillisChronoTimer example_timer(60000);   // 1 min timer


void setup() {
    Serial.begin(BAUD_RATE);
    while(!Serial.available()) {
        Serial.println("Press any key to begin...");
        delay(1000);
    }
    example_timer.reset();
}


void loop() {
    if (example_timer.expired()) {
        Serial.print("Timer Expired (ms): ");
        Serial.print(example_timer.elapsed());
        Serial.print("   (sec): ");
        Serial.print(example_timer.elapsedSec());
        Serial.print("  (min): ");
        Serial.print(example_timer.elapsedMin());
        Serial.print("  (hrs): ");
        Serial.print(example_timer.elapsedHrs());
        Serial.println("\n");
    } else {
        Serial.print("Elapsed (sec): ");
        Serial.print(example_timer.elapsedSec()); 
        Serial.println("\n");
    }

    delay(1000); // 1 sec delay
}