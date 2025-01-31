#ifndef CONFIG_H
#define CONFIG_H

// Wi-Fi-innstillinger
#define WIFI_SSID "sirkusPiAP"
#define WIFI_PASSWORD "sirkussolliledstriper"

// MQTT-innstillinger
#define MQTT_SERVER "192.168.4.1"
#define MQTT_PORT 1883
#define MQTT_TOPIC "led/1"

// LED-konfigurasjon
#define NUM_LEDS 60
#define DATA_PIN 2
#define RELE_PIN 5

#define LED_PIN 2
#define BRIGHTNESS 10
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 100

// NTP-konfigurasjon
#define NTP_SERVER "192.168.4.1"
#define TIMEZONE_OFFSET 3600 // UTC+1

#endif
