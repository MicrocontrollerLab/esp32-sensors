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
    Wire.begin(21,22);
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

void build_text(char* buffer, size_t buffer_size, SensorData sensor_data) {
    // save text in static buffer, without exceeding its size
    snprintf(buffer, buffer_size,
        "ESP32 - Sensor Data\n"
        ".\n"
        "DHT11 Temp : %.2f C\n"
        "DHT11 Hum : %.2f %%\n"
        "DHT20 Temp: %.2f C\n"
        "DHT20 Hum: %.2f %%\n"
        "ds18b20 Temp: %.2f C\n"
        "Gas Raw: %.2f\n",
        sensor_data.dht11_temperature, 
        sensor_data.dht11_humidity, 
        sensor_data.dht20_temperature, 
        sensor_data.dht20_humidity, 
        sensor_data.ds18b20_temperature, 
        sensor_data.gas_raw
        );
}