#pragma once

struct SensorData {

    float dht11_temperature;
    float dht11_humidity;

    float dht20_temperature;
    float dht20_humidity;

    float gas_raw;

    float light;
};

void all_sensors_init();

SensorData get_sensor_data();