#pragma once

struct SensorData {
    float temperature;
    float humidity;
};

void all_sensors_init();

SensorData get_sensor_data();