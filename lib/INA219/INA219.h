//
// Created by bitbyte08 on 25. 10. 2..
//

#ifndef STM32F103_INA219_H
#define STM32F103_INA219_H

#include <Adafruit_INA219.h>

class INA219 {
public:
  explicit INA219(uint8_t address);

  bool begin();
  void read();

  float getBusVoltage()   const;
  float getShuntVoltage() const;
  float getCurrent()      const;
  float getPower()        const;

  String toString() const;
  String toCSV() const;

private:
  Adafruit_INA219 ina219;
  float busVoltage   = 0;
  float shuntVoltage = 0;
  float current_mA   = 0;
  float power_mW     = 0;
};

#endif // STM32F103_INA219_H
