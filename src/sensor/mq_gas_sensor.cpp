#include <Arduino.h>

#include "sensor/mq_gas_sensor.h"

#define MQ_ANALOG_PIN 34

void mq_gas_sensor_init()
{
    pinMode(MQ_ANALOG_PIN, INPUT);
}

/* gets the average raw value */
float mq_gas_sensor_get_raw()
{
    long sum = 0;

    for (int i = 0; i < 10; i++)
    {
        sum += analogRead(MQ_ANALOG_PIN);
        delay(4);
    }

    return sum / 10.0;
}