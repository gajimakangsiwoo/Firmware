//
// Created by bitbyte08 on 25. 10. 2..
//
#include "INA219.h"

INA219::INA219(uint8_t address) : ina219(address) {}

bool INA219::begin() {
  if (!ina219.begin()) return false;

  ina219.setCalibration_32V_2A();
  return true;
}

void INA219::read() {
  busVoltage = ina219.getBusVoltage_V();
  shuntVoltage = ina219.getShuntVoltage_mV();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
}

float INA219::getBusVoltage() const { return busVoltage; }

float INA219::getShuntVoltage() const { return shuntVoltage; }

float INA219::getCurrent() const { return current_mA; }

float INA219::getPower() const { return power_mW; }

String INA219::toString() const {
  return String("Bus: "   + String(busVoltage)   + " V, "
                + "Shunt: " + String(shuntVoltage) + " mV, "
                + "Current: " + String(current_mA) + " mA, "
                + "Power: "   + String(power_mW)   + " mW");
}

