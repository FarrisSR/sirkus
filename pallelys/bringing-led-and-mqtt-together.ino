#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define NUM_LEDS 120
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

WiFiClient espClient;
PubSubClient client(espClient);

CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue};
int num_colors = 3;
int speed = 100;  // Hastighet på rotasjonen
unsigned long start_time = 0;
unsigned long last_update = 0;
int rotation_index = 0;


const char* ssid = "sirkusPiAP";
const char* password = "sirkussolliledstriper";
const char* mqtt_server = "192.168.4.1"; // Raspberry Pi IP
const char* topic = "led/1";

void callback(char* topic, byte* payload, unsigned int length) {
  String message = String((char*)payload);
  if (message.indexOf("circle") >= 0) {
    speed = 100;  // Juster hastighet (fra meldingen)
    start_time = millis();  // Start animasjonen
  }
}

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  WiFi.begin("SSID", "PASSWORD");
  client.setServer("192.168.1.10", 1883);
  client.setCallback(callback);
}

void loop() {
  unsigned long now = millis();

  // Oppdater LED-ene basert på animasjonslogikk
  if (now - last_update > speed) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = colors[(i + rotation_index) % num_colors];
    }
    FastLED.show();
    rotation_index = (rotation_index + 1) % num_colors;
    last_update = now;
  }

  client.loop();  // Hold MQTT-tilkoblingen aktiv
}

