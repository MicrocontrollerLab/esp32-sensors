#include <HardwareSerial.h>
#include <Wire.h>
void display_test() {
    Serial.begin(115200);

    Wire.begin(21,22);

    Serial.println("Scan");

    for(short i=1;i<127;i++){

        Wire.beginTransmission(i);

        if(Wire.endTransmission()==0){

            Serial.print("Found: 0x");
            Serial.println(i,HEX);
        }
    }
}