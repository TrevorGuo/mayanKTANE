#ifndef ENC
#define ENC
#include <SPI.h>
// #include "Adafruit_I2CDevice.h"
#include "Adafruit_seesaw.h"
#include <seesaw_neopixel.h>

#define SS_SWITCH 24
#define SS_NEOPIX 6

#define SEESAW_ADDR 0x36

class Encoder
{
public:
    Encoder(int button, void (*isr)());
    int getPos();
    void setLEDColor(uint8_t r, uint8_t g, uint8_t b);
    void setLEDBrightness(uint8_t b);
    Adafruit_seesaw ss;
    seesaw_NeoPixel sspixel = seesaw_NeoPixel(1, SS_NEOPIX, NEO_GRB + NEO_KHZ800);
};

#endif