#include <arduino.h> 
#include "motor.h"

void motor::init()
{
  pinMode(OUTPUT, dirA);
  pinMode(OUTPUT, dirB);
  pinMode(OUTPUT, pwrA);
  pinMode(OUTPUT, pwrB);
}

void motor::STOP()
{
  analogWrite(pwrA,0);
  analogWrite(pwrB,0);
}

//moves the both motors forward 
void motor::forward(int spd)
{
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(pwrA,spd);
  analogWrite(pwrB,spd);
}

void motor::back(int spd)
{
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
  analogWrite(pwrA,spd);
  analogWrite(pwrB,spd);
}

