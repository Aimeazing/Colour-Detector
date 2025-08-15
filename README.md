# Library
## Colour Sensor with LED
This project is a custom-built Arduino library designed for a colour sensor. the library was written from scratch  
using only standard Arduino libraries and a datasheet. It retrieves RGB values from the colour sensor, which are   
then displayed by te LED. This library is very easy to use: you only need to plug in the Arduino connected to both   
the colour sensor and the RGB LED.

## How the sensor works
The colour sensor works by shining red, green, and blue light onto the object in front of it. The sensor then   
measures how much of each colour is reflected back. It does not directly return a "colour value" or a percentage.   
Instead, it returns timing data. Specifically, the sensor outputs a pulse duration for each colour channel. The   
brighter the reflected colour, the shorter the pulse duration, meaning: lower time = more of that colour is present.  

In the case of this library, the colour sensor begins by measuring the red channel. It times how long it takes to   
detect the reflected red light, then proceeds to green, and finally to blue. Once all three colour channels have   
been measured, the values are printed to the serial monitor.  

These raw timing values varies from around 100 to 1000. A lower value (e.g. 100) means a strong presence of that   
colour, while a higher value (e.g. 1000) means less of that colour is reflected. This entails the following; lower   
timing = more colour.  

### Author's note  
The way this sensor works really intrueged me. At first, I thought the sensor would light all three colours at the   
same time and retur a value between 0 and 255. That would have been practical, since my RGB LED expects values in   
that range.  

However, the sensor actually returns values between approximately 100 and 1000. because of this, I needed to convert   
the timing values into the correct range. My solution want to use the 'map()' function and constrain the result to   
the 0 to 255 range. This allowed me to send the correct values directly to the RGB LED without any issues.  

## Test function  
A test function is implemented in the code to verify whether the calculated RGB values fall within the expected range.  
> LibrarySensor.ino    

void testSensor(int red, int green, int blue){  
String testOne   = red   >=0 && red   <= 250 ? "Succesfull" : "Failed";  
String testTwo   = green >=0 && green <= 250 ? "Succesfull" : "Failed";  
String testThree = blue  >=0 && blue  <= 250 ? "Succesfull" : "Failed";  

String testResult = "One:" + testOne + "Two:" + testTwo + "Three:" + testThree;  
Serial.println(testResult);  
}   

This function runs automatically and prints a simple success/failure report for each RGB value to the serial monitor.   
It helps validate that the colour mapping behaves as expected.  
If you want to disable this function, you can comment out the function call in the loop():  
> LibrarySensor.ino  

VoidLoop(){  
...  
// Call test function  
// testSensor(red, green, blue);  
}  

## The project structure
!Depending on the version this structure might not match.
LibrarySensor/  
-- PVA.md  
 Approved project plan  
-- LibrarySensor.hpp   
 Header file for the sensor class  
-- LibrarySensor.cpp  
 Implementation file for th sensor  
-- LibrarySensor.ino  
 Main application using the sensor and RGB lED  
-- ReflectionReport.md  
 Final reflection report after assessment  
-- README.md  
 This file  
-- Doxyfile  
 File for doxygen-generated comments  

## Software Requirements
- Arduino IDE (most recent version recommended)
- Libraries used:
    - 'Arduino.h' (default)
