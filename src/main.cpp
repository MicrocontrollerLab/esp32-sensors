#include <Arduino.h>
#include "display/oled_display.h"

void setup() {
  // put your setup code here, to run once:
  // baudrate = how fast does esp send data
  Serial.begin(115200);
  Serial.println("OK");
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.println("tick");
  draw();
}