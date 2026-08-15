#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

#include "mqtt/mqtt.h"
#include <secrets.h>


// Wi-Fi credentials
const char* WIFI_SSID = WIFI_SSID_SECRET;
const char* WIFI_PASSWORD = WIFI_PASSWORD_SECRET;


// IP address of the MQTT broker running on the Ubuntu server
const char* MQTT_BROKER = "192.168.168.2";

// Default MQTT port
const int MQTT_PORT = 1883;


// WiFiClient handles the network connection between the ESP32 and the server.
// PubSubClient uses that connection to communicate using MQTT.
WiFiClient espClient;
PubSubClient mqttClient(espClient);


void mqtt_init()
{
    // Start the Wi-Fi connection
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to Wi-Fi");

    // Wait until the ESP32 has successfully connected to the network
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Wi-Fi connected");

    // Print the IP address assigned to the ESP32
    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());


    // Tell the MQTT client where the MQTT broker is located
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);

    Serial.println("Connecting to MQTT broker...");


    // Keep trying until the ESP32 successfully connects to the broker
    while (!mqttClient.connected())
    {
        // "ESP32-Sensor" is the MQTT client ID.
        // The broker uses this ID to identify this connection.
        if (mqttClient.connect("ESP32-Sensor"))
        {
            Serial.println("MQTT connected");
        }
        else
        {
            // Print the MQTT error code if the connection failed
            Serial.print("MQTT connection failed, state: ");
            Serial.println(mqttClient.state());

            // Wait before trying again
            delay(1000);
        }
    }
}

void mqtt_loop()
{
    // Process incoming and outgoing MQTT communication.
    // This needs to be called regularly from the main loop().
    mqttClient.loop();
}

bool mqtt_is_connected()
{
    return mqttClient.connected();
}

IPAddress wifi_get_ip()
{
    return WiFi.localIP();
}

void mqtt_publish_sensor_data(const SensorData& data)
{
    // Publish all sensor data
    char payload[256];

    snprintf(
        payload,
        sizeof(payload),
        "{"
        "\"dht11_temperature\":%.2f,"
        "\"dht11_humidity\":%.2f,"
        "\"dht20_temperature\":%.2f,"
        "\"dht20_humidity\":%.2f,"
        "\"gas_raw\":%.2f,"
        "\"light\":%.2f"
        "}",
        data.dht11_temperature,
        data.dht11_humidity,
        data.dht20_temperature,
        data.dht20_humidity * 100,  // Convert to percentage
        data.gas_raw,
        data.light
    );

    mqttClient.publish(
        "iot/test/sensors",
        payload
    );
}