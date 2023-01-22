#include <Arduino.h>
#include <stdio.h>
#include <iostream>

#include "modules/SymbolSequence/SymbolSequence.h"

using namespace std;

#define CODE_LENGTH 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);

  SymbolSequence symbolSequenceModule;
  symbolSequenceModule.begin();
  Serial.println("LED 0 should be on");
  delay(2000);
  symbolSequenceModule.readInput(0);
  Serial.println("LED 1 should be on");
  delay(2000);
  symbolSequenceModule.readInput(0);
  Serial.println("LED 0 should be on");
  delay(2000);
  symbolSequenceModule.readInput(1);
  Serial.println("BOTH should be on");
  delay(2000);
  symbolSequenceModule.readInput(2);
  Serial.println("LED 0 should be on");
}

void loop() {
  // put your main code here, to run repeatedly:
}