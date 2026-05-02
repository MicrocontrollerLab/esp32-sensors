#include <Arduino.h>
#include "display/oled_display.h"

// test
int counter = 0;

void setup() {
    // put your setup code here, to run once:
    // baudrate = how fast does esp send data
    Serial.begin(115200);
    Serial.println("OK");
    display_init();
}

void loop() {
    // put your main code here, to run repeatedly:
    display_clear();

    // size of display text
    char final_text[192]; 

    // sensor data (example)
    float value_1 = 22.5;
    float value_2 = 60.3;

    // small test with counter
    counter++;

    // func call to generate text
    build_text(final_text, sizeof(final_text), value_1, value_2, counter);

    // show the entire text on the display
    display_print_text(final_text);
    display_update();
}