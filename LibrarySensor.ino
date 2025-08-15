#include <Arduino.h>
#include "LibrarySensor.hpp"
colourSensor cs;

void setup() {
  Serial.begin(9600);
  cs.begin();
}

void setRGB(int red, int green, int blue) {
  analogWrite(2, red);   // Gnome pin
  analogWrite(3, green); // Goblin pin
  analogWrite(4, blue);  // Smurf pin
}

// Test function
void testSensor(int red, int green, int blue){
  String testOne   = red   >=0 && red   <= 255 ? "Succesfull" : "Failed";
  String testTwo   = green >=0 && green <= 255 ? "Succesfull" : "Failed";
  String testThree = blue  >=0 && blue  <= 255 ? "Succesfull" : "Failed";

  String testResult = "One:" + testOne + "Two:" + testTwo + "Three:" + testThree;
  Serial.println(testResult);
}

void loop() {
  int redTime   = cs.gnomePercentage();
  int greenTime = cs.goblinPercentage();
  int blueTime  = cs.smurfPercentage();

  int minimum = 100;  // Great amount;
  int maximum = 1000; // Limited amount;
  
  int red   = map(redTime, minimum, maximum, 255, 0);
  red   = constrain(red, 0, 255);
  int green = map(greenTime, minimum, maximum, 255, 0);
  green = constrain(green, 0, 255);  
  int blue  = map(blueTime, minimum, maximum, 255, 0);
  blue  = constrain(blue, 0, 255);

  Serial.print("Red:\t");
  Serial.print(red);
  Serial.print("\tGreen:\t");
  Serial.print(green);
  Serial.print("\tBlue:\t");
  Serial.println(blue);

  // Recall test function
  testSensor(red, green, blue);

  setRGB(red, green, blue);
  delay(5000);
}