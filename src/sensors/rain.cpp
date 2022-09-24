#include <Arduino.h>

#include "sensors.hpp"

#define DIGITALREAD D4
#define ANALOGREAD A0

int value_analog;
// TODO use/test threshold
int threshold_dry =  1000;
int threshold_moist =  800;
int threshold_wet = 500;

void setupRainSensor() {
  pinMode(DIGITALREAD, INPUT);
  pinMode(ANALOGREAD, INPUT);
  Serial.begin(9600);
}

void loopRainSensor() {
  if (digitalRead(DIGITALREAD) == LOW) {
    Serial.println("Digital read: wet");
    delay(10);
  } else {
    Serial.println("Digital read: dry");
    delay(10);
  }
  value_analog = analogRead(value_analog);
  Serial.print("Analog read: ");
  Serial.println(value_analog);
  Serial.println("");
  delay(1000);
}