#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/* Display configuration */
#define SCREEN_WIDTH 128 // pixels
#define SCREEN_HEIGHT 64 // pixels

/* 
* Create display object using I2C (Wire) interface
* -1 means no reset pin is used 
*/
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void init() {
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
}

/**
 * draw function (called repeatedly)
 */
void draw(){
  // set style and text
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,1);
  display.print("ESP32 OLED OK\n1234567890");
  // push buffer to physical display
  display.display();
}