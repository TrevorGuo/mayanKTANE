#include <Adafruit_NeoPixel.h>
#include "ring.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, NEOPIXEL_PIN, NEO_RGBW + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

// ring clock_ring(&strip);

// void setup() {
//   strip.begin();
//   strip.setBrightness(20);
//   strip.show(); // Initialize all pixels to 'off'
// }

// void loop() {
//   for (int i = 0; i < 2; i++) {
//     for (int j = 0; j < 4; j++) {
//       clock_ring.updateQuadrant(j, i);
//       clock_ring.incrementClock();
//       delay(500);
//     }
//   }
// }