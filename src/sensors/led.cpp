#include "led.h"
#include "Arduino.h"

led::led() {
    m_pin = -1;
}

led::led(int pin) {
    m_pin = pin;
    pinMode(m_pin, OUTPUT);
    digitalWrite(m_pin, LOW);
}

// turn the LED on.
void led::on() {
    digitalWrite(m_pin, HIGH);
}

// turn the LED off.
void led::off() {
    digitalWrite(m_pin, LOW);
}