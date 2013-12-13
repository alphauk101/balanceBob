#include <Wire.h>
#include "adx.h"
#include "motor.h"

adxl axl;
motor driver;

void setup()
{
  //instantiate the motor class
  driver = motor();
  driver.init();
  
  //instantiate the accel
  axl = adxl();
  axl.init();
  
  
  Serial.begin(9600);
  if(axl.isConnected())
  {
    Serial.println("Connected");
  }
}

void loop()
{
  
}
