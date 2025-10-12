//
// Created by bitbyte08 on 25. 10. 12..
//

#ifndef STM32F103_POWER_H
#define STM32F103_POWER_H


class Power {
public:
  explicit Power(int pin);

  void begin();
private:
  int _pin;
  float shunt_R = 0;
  float shunt_V = 0;
  float shunt_W = 0;
};


#endif //STM32F103_POWER_H