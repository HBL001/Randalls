//
// check the hardware can detect a 5V pulse from my NI-6251 NIDAQ
// 25-11-2025
//
// connect to the ST1 pin on the board and this code will test that the IO is working on PB0
// with the right config to detect edges.
//

#include <Arduino.h>

const int PIN_ST1 = 0;   // PB0 - ReadDVRStat (input)
const int PIN_LED = 3;   // PB3 - debug LED

void setup() {
    // PB0 as pure digital input
    pinMode(PIN_ST1, INPUT);
    digitalWrite(PIN_ST1, LOW);    // ensure pull-up is OFF

    // PB3 debug LED
    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, LOW);
}

void loop() {
    static int lastState = LOW;

    int now = digitalRead(PIN_ST1);

    // Rising edge detect
    if (now == HIGH && lastState == LOW) {
        // Flash LED so pulse is visible
        digitalWrite(PIN_LED, HIGH);
        delay(40);      // pulse stretch: adjust 10–100 ms as desired
        digitalWrite(PIN_LED, LOW);
    }

    lastState = now;
}
