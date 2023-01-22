#include <ring.h>

 ring::ring(Adafruit_NeoPixel* strip) {
    m_strip = strip;
 }

int ring::updateQuadrant(int quadrant, bool done) {
    if (quadrant < 0 || quadrant >= NUM_PIXELS) {
        return 1;
    }
    m_quadrants[quadrant] = done;
    updatePixels();
    return 0;
}

void ring::updatePixels() {
    for(int i = 0; i < 4; i++) {
        if (m_quadrants[i]) {
            m_strip->fill(m_strip->Color(255, 0, 60), 6 * i, 6 * i + 7);
        }
        else {
            m_strip->fill(m_strip->Color(0, 255, 0), 6 * i, 6 * i + 7);
        }
        m_strip->setPixelColor(m_clock_pos, m_strip->Color(255, 255, 0));
        m_strip->show();
    }
}

int ring::incrementClock() {
    m_clock_pos++;
    if (m_clock_pos >= 24) {
        m_clock_pos = 0;
    }
    updatePixels();
    return 0;
}