#include "rele.h"
#include <Arduino.h> // Inkluderer Arduino-funksjoner som pinMode og digitalWrite

// Variabel for å lagre reléets status
bool releStatus = false;

void setupRele() {
  pinMode(RELE_PIN, OUTPUT);   // Sett GPIO som utgang
  digitalWrite(RELE_PIN, LOW); // Sett reléet AV som standard (avhengig av type)
}

void turnOnRele() {
  digitalWrite(RELE_PIN, HIGH);
  releStatus = true;
  Serial.println("Relé PÅ");
}

void turnOffRele() {
  digitalWrite(RELE_PIN, LOW);
  releStatus = false;
  Serial.println("Relé AV");
}

void toggleRele() {
  if (releStatus) {
    turnOffRele();
  } else {
    turnOnRele();
  }
}

bool isReleOn() { return releStatus; }
