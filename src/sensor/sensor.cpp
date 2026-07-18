#include <Arduino.h>
#include <DHT.h>
#include <sensor/sensor.h>
#include <sensor/dht.h>
#include <sensor/ldr.h>
#include <sensor/ds18b20.h>



void all_sensors_init() {
    ds18b20_init();
    dht_init();
    ldr_init();
}

SensorData get_sensor_data() {
    SensorData data;
    data.ds18b20_temperature1 = ds18b20_get_temperature1();
    data.ds18b20_temperature2 = ds18b20_get_temperature2();
    data.dht_temperature = dht_get_temperature();
    data.humidity = dht_get_humidity();
    data.light = ldr_read();
    return data;
}