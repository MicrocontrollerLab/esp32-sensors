#include <sensor/ds18b20.h>

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR1_PIN 1
#define SENSOR2_PIN 3

OneWire oneWire1(SENSOR1_PIN);
OneWire oneWire2(SENSOR2_PIN);

DallasTemperature ds18b20_sensor1(&oneWire1);
DallasTemperature ds18b20_sensor2(&oneWire2);

void ds18b20_init() {
    ds18b20_sensor1.begin();
    ds18b20_sensor2.begin();
}

float ds18b20_get_temperature1() {

    ds18b20_sensor1.requestTemperatures();
    return ds18b20_sensor1.getTempCByIndex(0);
}

float ds18b20_get_temperature2() {

    ds18b20_sensor2.requestTemperatures();
    return ds18b20_sensor2.getTempCByIndex(0);
}