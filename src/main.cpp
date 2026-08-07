#include <Arduino.h>
#include "display/oled_display.h"
#include <sensor/sensor.h>
#include <Wire.h>

void test() {
    Serial.begin(115200);

    Wire.begin(21,22);

    Serial.println("Scan");

    for (byte i = 1; i < 127; i++)
    {
        Wire.beginTransmission(i);

        if (Wire.endTransmission() == 0)
        {
            Serial.print("Found: 0x");
            Serial.println(i, HEX);
        }
    }
}

void setup() {
    // put your setup code here, to run once:
    // baudrate = how fast does esp send data
    Serial.begin(115200);
    Serial.println("OK");

    // initialize everything
    all_sensors_init();
    display_init();
    test(); // for debugging 
}

void loop() {
    // put your main code here, to run repeatedly:
    display_clear();

    //testing for debugging purposes
    test();

    // size of display text
    char final_text[192]; 

    // all sensor data
    SensorData sensor_data = get_sensor_data();


    // func call to generate text
    build_text(final_text, sizeof(final_text), sensor_data);
    // show the entire text on the display
    display_print_text(final_text);
    display_update();
}

