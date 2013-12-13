#include <arduino.h> 
#include "adx.h"
#include <Wire.h>

void adxl::init()
{
  Wire.begin();
  //start the device in correct mode
  writeTo(ADXL345_POWER_CTL, 0x08); 
  writeTo(ADXL345_INT_ENABLE,0x80);
  byte dataForm[1];
  readFrom(Register_DataFormat,1,dataForm);
  dataForm[0] = dataForm[0] | 0x0B;//measurement mode and hi res 16g
  writeTo(Register_DataFormat, dataForm[0]);
}

adxl::adxl()
{
}

rawAxis adxl::getAllAxis()
{
  byte rawData[6];
  readFrom(ADXL345_DATAX0,6, rawData);
  rawAxis raw;
  raw.Xaxis = (rawData[1] << 8) | rawData[0];
  raw.Yaxis = (rawData[3] << 8) | rawData[2];
  raw.Zaxis = (rawData[5] << 8) | rawData[4];

  return raw;
}

bool adxl::isConnected()
{
  byte res[1];
  readFrom(ADXL345_DEVID,1, res);
  Serial.println(res[0],HEX);
  if(res[0] == 0xE5)
  {
    return true;
  }else
  {
    return false;
  }
}

void adxl::readFrom(byte add, int num, byte *buff)
{
  Wire.beginTransmission(ADXL345_Address); // start transmission to device 
  Wire.write(add);             // sends address to read from
  Wire.endTransmission();         // end transmission

  Wire.beginTransmission(ADXL345_Address); // start transmission to device
  Wire.requestFrom(ADXL345_Address, num);    // request 6 bytes from device

  int i = 0;
  while(Wire.available())         // device may send less than requested (abnormal)
  { 
    *(buff + i) = Wire.read();    // receive a byte
    i++;
  }

  Wire.endTransmission();         // end transmission
}



void adxl::writeTo(byte add,byte val)
{
  Wire.beginTransmission(ADXL345_Address); // start transmission to device 
  Wire.write(add);             // send register address
  Wire.write(val);                 // send value to write
  Wire.endTransmission(); 
}

