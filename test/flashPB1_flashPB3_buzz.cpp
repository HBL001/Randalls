#include <Arduino.h>

// Output pin definitions
const int OUT1 = 1;   // PB1 - Status LED
const int OUT3 = 3;   // PB3 - Battery LED
const int OUT4 = 4;   // PB4 - Relay / Haptic

const int DELAY_MS = 2000;  // 2 seconds

void setup() {
    pinMode(OUT1, OUTPUT);
    pinMode(OUT3, OUTPUT);
    pinMode(OUT4, OUTPUT);

    // turn everything off initially
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT3, LOW);
    digitalWrite(OUT4, LOW);
}

void loop() {

    // PB1 test - 2Second flash
    digitalWrite(OUT1, HIGH);
    delay(DELAY_MS);
    digitalWrite(OUT1, LOW);
    delay(DELAY_MS);

    // PB3 test - 2Second flash
    digitalWrite(OUT3, HIGH);
    delay(DELAY_MS);
    digitalWrite(OUT3, LOW);
    delay(DELAY_MS);

    // PB4 test - second buzz
    digitalWrite(OUT4, HIGH);
    delay(DELAY_MS);
    digitalWrite(OUT4, LOW);
    delay(DELAY_MS);
}
