#include <ring.h>

 ring::ring(Adafruit_NeoPixel* strip) {
    m_strip = strip;
 }


void ring::updateClock() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
        updateQuadrant(j, i);
        incrementClock();
        }
    }
}

int ring::updateQuadrant(int quadrant, bool done) {
    Serial.println(quadrant);
    if (done) {
        Serial.println("HELLO");
    }
    Serial.println("reached");
    if (quadrant < 0 || quadrant >= NUM_PIXELS) {
        return 1;
    }
    m_quadrants[quadrant] = done;
    updatePixels();
    m_strip->show();
    Serial.println("Shown");
    return 0;
}

void ring::updatePixels() {
    for(int i = 0; i < 4; i++) {
        Serial.print("i: ");
        Serial.println(i);
        if (m_quadrants[i]) {
            m_strip->fill(m_strip->Color(255, 0, 60), 6 * i, 6 * i + 5);
        }
        else {
            m_strip->fill(m_strip->Color(0, 255, 0), 6 * i, 6 * i + 5);
        }

    }
    m_strip->setPixelColor(m_clock_pos, m_strip->Color(255, 255, 0));
}

int ring::incrementClock() {
    m_clock_pos++;
    if (m_clock_pos >= 24) {
        m_clock_pos = 0;
    }
    updatePixels();
    return 0;
}