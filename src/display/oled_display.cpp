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

void build_text(char* buffer, size_t buffer_size, 
    float value_1, float value_2, float value_3) {
    // save text in static buffer, without exceeding its size
    snprintf(buffer, buffer_size,
        "e.g. Sens1: %.2f C\n"
        "e.g. Sens2: %.2f %%\n"
        "e.g. Sens3: %.0f .\n"
        ".\n"
        ".\n"
        ".\n"
        ".\n"
        ".", value_1, value_2, value_3);
}