#include "Encoder.hpp"

Encoder::Encoder(int button, void (*isr)())
{

    if (!ss.begin(SEESAW_ADDR) || !sspixel.begin(SEESAW_ADDR))
    {
        Serial.println("Couldn't find seesaw on default address");
        sspixel.setPixelColor(0, sspixel.Color(0, 255, 0));
        while (1)
        {
            sspixel.setBrightness(20);
            sspixel.show();
            delay(500);
            sspixel.setBrightness(0);
            sspixel.show();
            delay(500);
        }
    }

    uint32_t version = ((ss.getVersion() >> 16) & 0xFFFF);
    if (version != 4991)
    {
        Serial.print("Wrong firmware loaded? ");
        Serial.println(version);
        sspixel.setPixelColor(0, sspixel.Color(255, 0, 0));
        while (1)
        {
            sspixel.setBrightness(20);
            sspixel.show();
            delay(500);
            sspixel.setBrightness(0);
            sspixel.show();
            delay(500);
        }
    }

    // set not so bright!
    sspixel.setBrightness(20);
    sspixel.show();

    // use a pin for the built in encoder switch
    ss.pinMode(SS_SWITCH, INPUT_PULLUP);

    Serial.println("Turning on interrupts");
    delay(10);
    ss.setGPIOInterrupts((uint32_t)1 << SS_SWITCH, 1);
    ss.enableEncoderInterrupt();
    pinMode(4, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(4), isr, FALLING);
}

int Encoder::getPos()
{
    return (ss.getEncoderPosition() / 3) % 8;
}

void Encoder::setLEDColor(uint8_t r, uint8_t g, uint8_t b)
{
    sspixel.setPixelColor(0, sspixel.Color(r, g, b));
    sspixel.show();
}

void Encoder::setLEDBrightness(uint8_t b)
{
    sspixel.setBrightness(20);
    sspixel.show();
}
