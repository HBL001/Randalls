//
// PB2 ADC Debug Tool
// Displays raw ADC value using 1 LED - Mr. Ed Mode - accurate 1-bit diagnostic horse
//
// Blink Format:
//   HUNDREDS: slow blinks (400s)
//   TENS:     medium blinks (10s)
//   ONES:     fast blinks (1s)
// Example: ADC = 428 → 4 slow, 2 medium, 8 fast
//
// VCC	Mr.Ed
// 9	431  (4 slow scrapes, 3 medium trots, 1 fast whinny)
// 8	383
// 7	334
// 6	314
// 
// This shows the ADC is actually working, the voltage divider is correct, ADC is in range
//


#include <Arduino.h>

const int PIN_LED = 3;       // PB3 LED
const int PIN_ADC = 2;       // PB2 (digital pin number)
const uint8_t ADC_CHANNEL = 1; // PB2 MAKE SURE THE ADC CHANNEL IS CORRECT

void blinkSlow(int n) {
    for (int i = 0; i < n; i++) {
        digitalWrite(PIN_LED, HIGH); delay(400);
        digitalWrite(PIN_LED, LOW);  delay(400);
    }
}

void blinkMed(int n) {
    for (int i = 0; i < n; i++) {
        digitalWrite(PIN_LED, HIGH); delay(200);
        digitalWrite(PIN_LED, LOW);  delay(200);
    }
}

void blinkFast(int n) {
    for (int i = 0; i < n; i++) {
        digitalWrite(PIN_LED, HIGH); delay(80);
        digitalWrite(PIN_LED, LOW);  delay(80);
    }
}

void setup() {
    // Enable ADC, disable pull-up on PB2
    ADCSRA |= (1 << ADEN);
    pinMode(PIN_ADC, INPUT);
    digitalWrite(PIN_ADC, LOW);

    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, LOW);

    delay(1000);  // stabilise
}

void loop() {
    
    analogRead(ADC_CHANNEL);
    delay(5);  // Settle ADC sampling cap (important for 330k+100k divider)

    int raw = analogRead(ADC_CHANNEL);  // <-- this is what we're testing

    int hundreds = raw / 100;
    int tens     = (raw / 10) % 10;
    int ones     = raw % 10;

    // Show reading
    blinkSlow(hundreds);
    delay(400);

    blinkMed(tens);
    delay(300);

    blinkFast(ones);
    delay(1000); // pause before repeating
}
