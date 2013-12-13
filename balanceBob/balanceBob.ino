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
  //get the xaxis
  rawAxis raw = axl.getAllAxis();
  int axis = raw.Xaxis;
  
  axis = map(axis, 0, 280, 0, 255);
  
  Serial.println(axis);
  
  driver.forward(axis);
  
  
}
