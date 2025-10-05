//
// Created by bitbyte08 on 25. 10. 5..
//
#include "Relay.h"

Relay::Relay(int pin) : _pin(pin), _state(false) {};

void Relay::begin() {
  pinMode(_pin, OUTPUT);
  setState(false);
}

void Relay::setState(bool state) {
  _state = state;
  digitalWrite(_pin, _state);
}

bool Relay::getState() const { return _state; }
