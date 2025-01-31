#ifndef RELE_H
#define RELE_H

// Definer hvilken GPIO som styrer reléet
// #define RELE_PIN 4  // Bruk en digital GPIO på ESP8266

// Funksjonsdeklarasjoner
void setupRele();
void turnOnRele();
void turnOffRele();
void toggleRele();
bool isReleOn();

#endif
