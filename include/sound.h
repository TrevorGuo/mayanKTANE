#ifndef SOUND_H
#define SOUND_H

#include <utils.h>

#include <Arduino.h>
#include <HardwareSerial.h>
#include "Adafruit_Soundboard.h"

class sound {
    public:
    sound(HardwareSerial* soundSerial);
    void playSound(int module_enum, bool success);
    void playSound(bool success);
    void playEnd(bool win);

    private:
    int m_sound_rotation = 0;

    HardwareSerial* m_soundSerial;
    String m_success[NUM_MODULES] = {"success_0.wav", "success_1.wav", "success_2.wav"};
    String m_failure[NUM_MODULES] = {"failure_0.wav", "failure_1.wav", "failure_2.wav"};
    String m_win = "win.wav";
    String m_lose = "lose.wav";
};

#endif