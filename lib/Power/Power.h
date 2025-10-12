//
// Created by bitbyte08 on 25. 10. 12.
//

#ifndef STM32F103_POWER_H
#define STM32F103_POWER_H

#include <Arduino.h>

class Power {
public:
  explicit Power(int pin, float shuntResistance);

  void begin();
  float readVoltage();
  float readCurrent();
  float readPower();

private:
  int _pin;
  float _shuntR;
  float _vShunt;
  float _iShunt;
  float _pShunt;
};

#endif // STM32F103_POWER_H
