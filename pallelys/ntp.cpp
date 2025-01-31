#include "config.h"
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_SERVER, TIMEZONE_OFFSET);

void syncTime() {
  timeClient.begin();
  timeClient.update();
  Serial.print("NTP Time: ");
  Serial.println(timeClient.getFormattedTime());
}

unsigned long getEpochTime() { return timeClient.getEpochTime(); }
