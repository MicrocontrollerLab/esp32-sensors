#pragma once

struct SensorData {
    float temperature;
    float humidity;
    float light;
};

void all_sensors_init();

SensorData get_sensor_data();