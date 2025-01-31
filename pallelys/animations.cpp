#include "colors.h"
#include "config.h"
#include <FastLED.h>

CRGB leds[NUM_LEDS];

void setupLEDs() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
}

void runAnimation() {
  static int index = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = (i == index) ? COLOR_RED : COLOR_BLACK;
  }
  FastLED.show();
  index = (index + 1) % NUM_LEDS;
  delay(100);
}
