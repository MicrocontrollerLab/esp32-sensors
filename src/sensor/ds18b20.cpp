#include <sensor/ds18b20.h>

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR1_PIN 1

OneWire oneWire1(SENSOR1_PIN);

DallasTemperature ds18b20_sensor1(&oneWire1);

void ds18b20_init() {
    ds18b20_sensor1.begin();
}

float ds18b20_get_temperature() {

    ds18b20_sensor1.requestTemperatures();
    return ds18b20_sensor1.getTempCByIndex(0);
}