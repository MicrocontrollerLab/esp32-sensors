#include <DHT.h>

#define DHTPIN 23       // GPIO - pin 23 on the ESP32 is connected to the DHT sensor
#define DHTTYPE DHT11


static DHT dht(DHTPIN, DHTTYPE);

void dht_init() {
    dht.begin();
}

float dht_get_temperature() {
    float temp = dht.readTemperature();
    if (isnan(temp)) {
        temp = -999; // fallback
    }
    return temp;
}

float dht_get_humidity() {
    float hum = dht.readHumidity();
    if (isnan(hum)) {
        hum = -999; // fallback
    }
    return hum;
}