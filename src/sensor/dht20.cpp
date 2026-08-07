#include <Wire.h>
#include <DFRobot_DHT20.h>

#include "sensor/dht20.h"

DFRobot_DHT20 dht20;

void dht20_init()
{
    Wire.begin(16,17);  // SDA = GPIO16, SCL = GPIO17
    dht20.begin();
}

float dht20_get_temperature()
{
    return dht20.getTemperature();
}

float dht20_get_humidity()
{
    return dht20.getHumidity();
}