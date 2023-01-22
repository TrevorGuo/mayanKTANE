#include <ring.h>

 ring::ring() {
 }

int ring::updateQuadrant(int quadrant, bool done) {
    Serial.println("reached");
    if (quadrant < 0 || quadrant >= NUM_PIXELS) {
        return 1;
    }
    m_quadrants[quadrant] = done;
    updatePixels();
    return 0;
}

void ring::updatePixels() {
    Serial.println("reached2");
    for(int i = 0; i < 4; i++) {
        Serial.print("i: ");
        Serial.println(i);
        if (m_quadrants[i]) {
            strip.fill(strip.Color(255, 0, 60), 6 * i, 6 * i + 5);
        }
        else {
            strip.fill(strip.Color(0, 255, 0), 6 * i, 6 * i + 5);
        }
        Serial.println("Colored");
        strip.setPixelColor(m_clock_pos, strip.Color(255, 255, 0));
        Serial.println("Set Pixel Color");
        strip.show();
        Serial.println("Shown");
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