//
// Battery Fuel Gauge Demo (ATtiny85 / Digispark)
// Uses your measured ADC readings for PB2
// 
// Steady battery is full
// Slow battery is half
// Fast battery is flat or low
//
//


#include <Arduino.h>

const int PIN_BAT_ADC = 2;       // PB2 (digital pin number)
const int PIN_BAT_LED = 3;       // PB3 LED

// PB2 = ADC1 on Digispark core
const uint8_t ADC_CHANNEL = 1;

// Thresholds based on your measured PB2 ADC readings
const int ADC_FULL  = 380;       // 8.0–9.0 V
const int ADC_HALF  = 330;       // 7.0–8.0 V
const int ADC_LOW   = 300;       // 6.4–7.0 V
// Below 300 → EMPTY

int readADC_PB2()
{
    // Settle ADC capacitor
    analogRead(ADC_CHANNEL);
    delay(5);

    return analogRead(ADC_CHANNEL);
}

void showBatteryStatus(int adc)
{
    if (adc >= ADC_FULL) {
        // FULL – solid ON
        digitalWrite(PIN_BAT_LED, HIGH);
        delay(300);
        return;
    }

    if (adc >= ADC_HALF) {
        // HALF – 2 slow blinks
        for (int i = 0; i < 2; i++) {
            digitalWrite(PIN_BAT_LED, HIGH); delay(400);
            digitalWrite(PIN_BAT_LED, LOW);  delay(400);
        }
        delay(700);
        return;
    }

    if (adc >= ADC_LOW) {
        // LOW – 3 fast blinks
        for (int i = 0; i < 3; i++) {
            digitalWrite(PIN_BAT_LED, HIGH); delay(120);
            digitalWrite(PIN_BAT_LED, LOW);  delay(120);
        }
        delay(500);
        return;
    }

    // EMPTY – critical
    digitalWrite(PIN_BAT_LED, HIGH); delay(70);
    digitalWrite(PIN_BAT_LED, LOW);  delay(70);
}

void setup()
{
    ADCSRA |= (1 << ADEN);        // Ensure ADC enabled

    pinMode(PIN_BAT_ADC, INPUT);  // PB2
    digitalWrite(PIN_BAT_ADC, LOW); // Disable pull-up!

    pinMode(PIN_BAT_LED, OUTPUT);
    digitalWrite(PIN_BAT_LED, LOW);
}

void loop()
{
    int adc = readADC_PB2();
    showBatteryStatus(adc);
}
