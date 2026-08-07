#include <Arduino.h>

#include "sensor/mq_gas_sensor.h"

#define MQ_ANALOG_PIN 34

void mq_gas_sensor_init()
{
    pinMode(MQ_ANALOG_PIN, INPUT);
}

float mq_gas_sensor_get_raw()
{
    return analogRead(MQ_ANALOG_PIN);
}