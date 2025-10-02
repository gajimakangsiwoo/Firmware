#include <Arduino.h>
#include <Wire.h>

#include <INA219.h>

INA219 ina219(0x40);

void setup() {
  Serial1.begin(115200);
  Wire.begin();

  if (!ina219.begin()) delay(50);
  Serial1.println("INA219 initialized.");
}

void loop() {
  static unsigned long ina219CurrentMillis = millis();
  if (ina219CurrentMillis - millis() >= 500) {
    ina219.read();
    Serial1.println(ina219.toString());
    ina219CurrentMillis = millis();
  }
}