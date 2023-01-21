//#include <Arduino.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define CODE_LENGTH 4

void setup() {
  // put your setup code here, to run once:
  int vals[CODE_LENGTH];
  for (int i = 0; i < CODE_LENGTH; i++) {
    vals[i] = i;
  }
  for (int i = 0; i < CODE_LENGTH; i++) {
    cout << vals[i] << endl;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}