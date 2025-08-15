/** @file colourSensor.hpp
*   @brief Class for the Colour Sensor interface.
*
*   This file contains code for the colourSensor class, which reads 
*   RGB values from a colour sensor and outputs red (gnome), green 
*   (goblin), and blue (smurf). These values will be send to the 
*   RGB LED, so lights up the colour you feed the sensor.
*
*   @author Aimée Bloemendal
*   @bug No known bugs.
*/

#ifndef LIBRARY_SENSOR_HPP
#define LIBRARY_SENSOR_HPP

/** @class colourSensor
*   @brief Class to read the RGB vlaues from a colour snesor.
*   
*   This class shows the hardware details for the colour 
*   sensor with an interface. It retrieves the RGB values, 
*   which are needed for the RGB LED.
*/

class colourSensor {
private:
  int gnomePin  = 2;  /** Output pin for red percentage.*/
  int goblinPin = 3;  /** Output pin for green percentage.*/
  int smurfPin  = 4;  /** Output pin for blue percentage.*/
  const int s0  = 8;  /** Control pin for the signal rate.*/
  const int s1  = 9;  /** Control pin for the signal rate.*/
  const int s2  = 10; /** Control pin for measuring colour types.*/
  const int s3  = 11; /** Control pin for measuring colour types.*/
  const int led = 12; /** Control pin for measuring colour types.*/
  const int out = 13; /** Output pin output frequectie.*/

public:
  /** @brief The colour sensor hardware pins.
  *
  *   This function sets up all the necessary pins and preperations, 
  *   in order to read the colour values.
  *
  *   @return Void.
  */
  void begin();

  /** @brief Returns the red amount of detected colour.
  *
  * Reads the sensor and calculates the red intensity of the 
  * current colour it is reading.
  *
  * @return Red intensity as a number between c.a. 100-1000
  */
  int gnomePercentage();

  /** @brief Returns the green amount of detected colour.
  *
  * Reads the sensor and calculates the green intensity of the 
  * current colour it is reading.
  *
  * @return Green intensity as a number between c.a. 100-1000
  */
  int goblinPercentage();

  /** @brief Returns the blue amount of detected colour.
  *
  * Reads the sensor and calculates the blue intensity of the 
  * current colour it is reading.
  *
  * @return Blue intensity as a number between c.a. 100-1000
  */
  int smurfPercentage();
};

#endif /* LIBRARY_SENSOR_HPP*/
























