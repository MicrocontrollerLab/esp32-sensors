#include <Arduino.h>
#include <DHT.h>
#include <sensor/sensor.h>
#include <sensor/dht11.h>
#include <sensor/dht20.h>
#include <sensor/ds18b20.h>
#include <sensor/mq_gas_sensor.h>
#include <sensor/ldr.h>


void all_sensors_init() {
    dht11_init();
    dht20_init();
    ds18b20_init();
    mq_gas_sensor_init();
    ldr_init();
}

SensorData get_sensor_data() {
    SensorData data;
    data.dht11_temperature = dht11_get_temperature();
    data.dht11_humidity = dht11_get_humidity();
    data.dht20_temperature = dht20_get_temperature();
    data.dht20_humidity = dht20_get_humidity();
    data.ds18b20_temperature = ds18b20_get_temperature();
    data.gas_raw = mq_gas_sensor_get_raw();
    data.light = ldr_read();
    return data;
}