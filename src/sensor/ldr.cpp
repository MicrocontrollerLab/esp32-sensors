#include <Arduino.h>
#include "sensor/ldr.h"

// gpix (input only) 
#define LDR_PIN 36

void ldr_init() {
    // full usage of 3,3V range for better resolution
    analogSetPinAttenuation(LDR_PIN, ADC_11db);
}


int ldr_read() {
    int sum = 0;

    // take multiple readings and average them to reduce noise
    for(int i = 0; i < 4; i++) {
        sum += analogRead(LDR_PIN);
        delay(5);
    }

    // invert the result (higher light means lower resistance and thus lower voltage)
    // dependent on module
    return 4095 - (sum / 4);
}