#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Red;
        FastLED.show();
        delay(50);
        leds[i] = CRGB::Black;
    }
}

