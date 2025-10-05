//
// Created by bitbyte08 on 25. 10. 5..
//

#ifndef STM32F103_RELAY_H
#define STM32F103_RELAY_H

#include <Arduino.h>

class Relay {
public:
  explicit Relay(int pin);

  void begin();
  void setState(bool state);
  bool getState() const;
private:
  uint32_t _pin;
  bool _state;
};

#endif //STM32F103_RELAY_H