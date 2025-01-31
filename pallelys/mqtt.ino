#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <FastLED.h>

// Wi-Fi og MQTT-innstillinger
const char* ssid = "sirkusPiAP";
const char* password = "sirkussolliledstriper";
const char* mqtt_server = "192.168.4.1"; // Raspberry Pi IP
const char* topic = "led/1";

// LED-innstillinger
#define NUM_LEDS 120
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

// MQTT-klient
WiFiClient espClient;
PubSubClient client(espClient);

// Variabler for animasjon
int rotation_index = 0;
int speed = 100;  // Rotasjonshastighet i ms
CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue};
int num_colors = 3;

void callback(char* topic, byte* payload, unsigned int length) {
  // Eksempel: Parse MQTT-melding for å oppdatere animasjonsparametere
  String message = String((char*)payload);
  if (message.indexOf("circle") >= 0) {
    speed = 100;  // Juster basert på melding
  }
}

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  WiFi.begin(ssid, password);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  // Vent til Wi-Fi er tilkoblet
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  client.connect("ESP8266Client");
  client.subscribe(topic);
}

void loop() {
  client.loop();

  // Roter farger
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = colors[(i + rotation_index) % num_colors];
  }
  FastLED.show();
  delay(speed);
  rotation_index = (rotation_index + 1) % num_colors;
}

