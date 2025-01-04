#include <Arduino.h>
#include <MillisChronoTimer.h>

/*
    * Example of modifying a pre-existing timer.
    * Useful when using a rotary encoder to change timer value.
    * .modify() method does not reset timer. call .reset() if needed.
*/


MillisChronoTimer example_modify(20);  // 20ms timer


void setup() {
    Serial.begin(115200);
    Serial.println("\n-------------------------------\n");
}


void loop() {
    Serial.println("20ms timer elapsed count:");
    example_modify.reset();
    while (!example_modify.expired()) {
        Serial.print(example_modify.elapsed());
        Serial.print(" ");
    }
    Serial.println("\n");

    Serial.println("5ms timer elapsed count:");
    example_modify.modify(5);  // Modify timer to be 5ms rather than original 1000ms.
    example_modify.reset();
    while (!example_modify.expired()) {
        Serial.print(example_modify.elapsed());
        Serial.print(" ");
    }
    Serial.println();

    Serial.println("\n-------------------------------\n");
    delay(10000);

}