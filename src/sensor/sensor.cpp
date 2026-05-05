#include <Arduino.h>
#include <DHT.h>
#include <sensor/sensor.h>
#include <sensor/dht.h>
#include <sensor/ldr.h>



void all_sensors_init() {
    dht_init();
    ldr_init();
}

SensorData get_sensor_data() {
    SensorData data;
    data.temperature = dht_get_temperature();
    data.humidity = dht_get_humidity();
    data.light = ldr_read();
    return data;
}