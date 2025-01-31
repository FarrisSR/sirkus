#include "config.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void setupMQTT() {
  client.setServer(MQTT_SERVER, MQTT_PORT);
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected!");
      client.subscribe(MQTT_TOPIC);
    } else {
      Serial.print("failed, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}
void ensureConnected() {
  // Sjekk Wi-Fi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi mistet! Koble til på nytt...");
    connectToWiFi();
  }

  // Sjekk MQTT
  if (!client.connected()) {
    Serial.println("MQTT mistet! Koble til på nytt...");
    setupMQTT();
  }
}

void handleMQTT() { client.loop(); }
