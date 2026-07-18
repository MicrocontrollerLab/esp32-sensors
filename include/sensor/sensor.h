#pragma once

struct SensorData {
    float ds18b20_temperature1;
    float ds18b20_temperature2;
    float dht_temperature;
    float humidity;
    float light;
};

void all_sensors_init();

SensorData get_sensor_data();