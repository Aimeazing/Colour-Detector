#include <Arduino.h>
#include "LibrarySensor.hpp"

void colourSensor::begin() {
  pinMode(gnomePin, OUTPUT);
  pinMode(goblinPin, OUTPUT);
  pinMode(smurfPin, OUTPUT);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(out, INPUT);

  // Signal Rate 0%, 2%, 20%, [100%];
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}

int colourSensor::gnomePercentage() {
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  // Longer result means less colour and vice versa;
  return pulseIn(out, LOW);
}

int colourSensor::goblinPercentage() {
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  // Longer result means less colour and vice versa;
  return pulseIn(out, LOW);
}

int colourSensor::smurfPercentage() {
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  // Longer result means less colour and vice versa;
  return pulseIn(out, LOW);
}