#include <Arduino.h>
#include <DHT.h>
#include <sensor/sensor.h>
#include <sensor/dht.h>



void all_sensors_init() {
    dht_init();
}

SensorData get_sensor_data() {
    SensorData data;
    data.temperature = dht_get_temperature();
    data.humidity = dht_get_humidity();
    return data;
}