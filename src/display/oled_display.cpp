#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "display/oled_display.h"

/* Display configuration */
#define SCREEN_WIDTH 128 // pixels
#define SCREEN_HEIGHT 64 // pixels

/* 
* Create display object using I2C (Wire) interface
* I2C allows to connect to multiple devices with only 2 wires.
* -1 means no reset pin is used 
*/
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void display_init() {
    Serial.begin(115200);

    /**
    * Initialize the OLED display at I2C address 0x3C
    * SSD1306_SWITCHCAPVCC enables internal charge pump
    */ 
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    // if fails -> halt system and print error
    Serial.println("Display failed");
    while(true);
    }
    
    display.setTextSize(1);
    display.setTextColor(WHITE);
}

void display_clear() {
    display.clearDisplay();
}

void display_update() {
    display.display();
}

void display_print_text(const char* text) {
    display.setCursor(0, 0);
    display.print(text);
}

void build_text(char* buffer, size_t buffer_size, SensorData sensor_data, float value) {
    // save text in static buffer, without exceeding its size
    snprintf(buffer, buffer_size,
        "ESP32 - Sensor Data\n"
        ".\n"
        "Temp : %.2f C\n"
        "Hum : %.2f %%\n"
        "LDR : %.0f \n"
        "LDR: %.2f %%\n"
        "counter: %.0f\n"
        ".\n", sensor_data.temperature, sensor_data.humidity, 
        sensor_data.light, (sensor_data.light / 4095.0) * 100.0, value);
}