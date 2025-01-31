#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>


const char* ssid = "sirkusPiAP";
const char* password = "sirkussolliledstriper";
const char* ntpServer = "192.168.4.1"; // Raspberry Pi IP

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  timeClient.begin();
}

void loop() {
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
  delay(1000);
}

