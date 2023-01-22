#include <Adafruit_NeoPixel.h>
#define NUM_PIXELS 24
#define NEOPIXEL_PIN 19

class ring {
    public:
    ring(Adafruit_NeoPixel* strip);
    int updateQuadrant(int quadrant, bool done);
    int incrementClock();
    void updatePixels();
    private:
    Adafruit_NeoPixel* m_strip;
    bool m_quadrants[4]= {false, false, false, false};
    int m_clock_pos = 0;
};