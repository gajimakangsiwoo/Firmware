#include <Arduino.h>
#include <Wire.h>

#include <INA219.h>
#include <Relay.h>

INA219 ina219(0x40);

Relay sendRelay(D0); // 송신 Relay
Relay receiveRelay(D1); // 수신 Relay

void setup() {
  Serial1.begin(115200);
  if (!Serial1.available()) delay(100);
  Serial1.println("Serial initialized.");

  Wire.begin();

  if (!ina219.begin()) delay(100);
  Serial1.println("INA219 initialized.");
}

void loop() {
  static unsigned long ina219CurrentMillis = millis();

  if (ina219CurrentMillis - millis() >= 500) {
    ina219.read();
    ina219CurrentMillis = millis();
  }

  static unsigned long serialCurrentMillis = millis();

  if (serialCurrentMillis - millis() >= 50) {
    String cmd = Serial1.readStringUntil('\n'); cmd.trim();
    if (cmd == "GET_INA219") Serial1.println(ina219.toCSV());
    if (cmd == "SET_SEND") {
      sendRelay.setState(true);
      receiveRelay.setState(false);
    }
    if (cmd == "SET_RECEIVE") {
      sendRelay.setState(false);
      receiveRelay.setState(true);
    }
    if (cmd == "GET_STATE")
      Serial1.println(sendRelay.getState()?"SEND":
        receiveRelay.getState()?"RECEIVE":"NONE");
  }
}