#include <Arduino.h>
#include "display/oled_display.h"
#include <sensor/sensor.h>
#include <Wire.h>
#include "mqtt/mqtt.h"

void test() {
    // scan for i2c devices
    Serial.begin(115200);
    Wire.begin(21,22);

    Serial.println("Scan...");

    // trying all possible i2c addresses (1-127)
    for (byte addr=1; addr<127; addr++)
    {
        Wire.beginTransmission(addr);

        // if endTransmission returns 0, it means a device is present at that address
        if (Wire.endTransmission()==0)
        {
            Serial.print("Found: 0x");
            Serial.println(addr,HEX);
        }
    }
}

void setup() {
    // put your setup code here, to run once:
    // baudrate = how fast does esp send data
    Serial.begin(115200);
    Serial.println("OK");

    // initialize everything
    display_init();
    all_sensors_init();
    mqtt_init();

    // test();
}

void loop() {
    // put your main code here, to run repeatedly:
    display_clear();

    //testing for debugging purposes
    //test();

    // size of display text
    char final_text[192] = ""; 

    // all sensor data
    SensorData sensor_data = get_sensor_data();


    // func call to generate text
    build_text(final_text, sizeof(final_text), sensor_data);
    
    // show the entire text on the display
    display_print_text(final_text);
    display_update();

    // keep the mqtt connection alive
    mqtt_publish_sensor_data(sensor_data);
    mqtt_loop();

    // wait for 1 second before the next loop iteration
    delay(3000); 
}

