#pragma once
#include <sensor/sensor.h>

void display_init();
void display_clear();
void display_update();

void display_print_text(const char* text);
void build_text(char* buffer, size_t buffer_size, SensorData sensor_data);