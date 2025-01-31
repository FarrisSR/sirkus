#include "config.h"
#include "network.h"
#include "animations.h"
#include "ntp.h"
#include "rele.h"

void setup() {
    Serial.begin(115200);
    connectToWiFi();  // Setter opp Wi-Fi fra network.cpp
    setupMQTT();      // Konfigurerer MQTT-tilkobling
    syncTime();       // Synkroniserer NTP-tid
    setupLEDs();      // Initialiserer LED-stripe
    setupRele();      // Initialiserer Relet
}
ivoid loop() {
    ensureConnected();  // Sikrer at både Wi-Fi og MQTT er tilkoblet
    handleMQTT();       // Håndterer innkommende MQTT-meldinger
    runAnimation();   // Kjører LED-animasjon
}

