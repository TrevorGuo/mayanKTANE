#include <sound.h>
#include <HardwareSerial.h>

sound::sound(HardwareSerial* soundSerial) {
    m_soundSerial = soundSerial;
}

void sound::playSound(int module_enum, bool success) {
    String command_name;
    if (success)
        command_name = "P" + m_success[module_enum] + "\n";
    else
        command_name = "P" + m_failure[module_enum] + "\n";
    m_soundSerial->println(command_name);
}

// Overloaded method rotates through the success and failure sounds
void sound::playSound(bool success) {
    String command_name;
    if (success)
        command_name = "P" + m_success[m_sound_rotation] + "\n";
    else
        command_name = "P" + m_failure[m_sound_rotation] + "\n";
    m_sound_rotation++;
    if (m_sound_rotation >= NUM_MODULES)
        m_sound_rotation = 0;
    m_soundSerial->println(command_name);
}

void sound::playEnd(bool win) {
    String command_name;
    if (win)
        command_name = "P" + m_win + "\n";
    else
        command_name = "P" + m_lose + "\n";
    m_soundSerial->println(command_name);
}