/*
 * This example shows how to read from a seesaw encoder module.
 * The available encoder API is:
 *      int32_t getEncoderPosition();
        int32_t getEncoderDelta();
        void enableEncoderInterrupt();
        void disableEncoderInterrupt();
        void setEncoderPosition(int32_t pos);
 */
#include "Encoder.hpp"

int pressed_pos = 0;

void buttonPressed();

Encoder encoder(4, &buttonPressed);

void setup()
{
  delay(1000);
  Serial.begin(115200);
  Serial.println("Starting");
}

void loop()
{
  Serial.println("Something");
  // Serial.print(encoder.getPos());
  // Serial.print(" : ");
  // Serial.println(pressed_pos);
  delay(10);
}

void buttonPressed()
{
  pressed_pos = encoder.getPos();
}