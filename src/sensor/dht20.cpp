#include <Wire.h>
#include <DFRobot_DHT20.h>

#include "sensor/dht20.h"

DFRobot_DHT20 dht20;

void dht20_init()
{
    //I²C initialization, default pins are SDA = 21, SCL = 22
    Wire.begin(21, 22);
    dht20.begin();
    delay(50);
}

float dht20_get_temperature()
{
    return dht20.getTemperature();
}

float dht20_get_humidity()
{
    return dht20.getHumidity();
}