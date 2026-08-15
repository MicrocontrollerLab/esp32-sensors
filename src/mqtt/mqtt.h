#pragma once
#include <sensor/sensor.h>

void mqtt_init();
void mqtt_loop();

bool mqtt_is_connected();
IPAddress wifi_get_ip();

void mqtt_publish_sensor_data(const SensorData& data);