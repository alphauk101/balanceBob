#include <arduino.h>
#include <inttypes.h>
#ifndef motor_h
#define motor_h

#define dirA 8
#define dirB 7

#define pwrA 6
#define pwrB 9

class motor
{
  public:
  void init(void);
  void STOP(void);
  void forward(int);
  void back(int);
};
#endif
