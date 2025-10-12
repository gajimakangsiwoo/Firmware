//
// Created by bitbyte08 on 25. 10. 12.
//

#include "Power.h"

Power::Power(int pin, float shuntResistance)
: _pin(pin), _shuntR(shuntResistance), _vShunt(0), _iShunt(0), _pShunt(0) {}

void Power::begin() {
  pinMode(_pin, INPUT_ANALOG);
  analogReadResolution(12);
}

float Power::readVoltage() {
  uint16_t raw = analogRead(_pin);
  float vAdc = (3.3f * raw) / 4095.0f;
  _vShunt = vAdc;
  return _vShunt;
}

float Power::readCurrent() {
  _vShunt = readVoltage();
  _iShunt = _vShunt / _shuntR;
  return _iShunt;
}

float Power::readPower() {
  _iShunt = readCurrent();
  _pShunt = _vShunt * _iShunt;
  return _pShunt;
}
