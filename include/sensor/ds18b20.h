#pragma once
#ifndef DS18B20_H
#define DS18B20_H

#include <OneWire.h>
#include <DallasTemperature.h>

void ds18b20_init();

float ds18b20_get_temperature1();
float ds18b20_get_temperature2();

#endif