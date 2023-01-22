#ifndef LED_H
#define LED_H

// may need to reallocate these.
#define LED_0 13
#define LED_1 12
#define LED_2 14
#define LED_3 27
#define LED_4 26
#define LED_5 25
#define LED_6 33
#define LED_7 32
#define LED_8 35
#define LED_9 34
#define LED_10 2
#define LED_11 4

#define NUM_LEDS 12

class led {
    public:
    led();
    led(int pin);
    void on();
    void off();

    private:
    int m_pin;
};

#endif