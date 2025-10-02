#include <Arduino.h>
void setup() {
// write your initialization code here
  SerialUSB.begin(115200);
  pinMode(PC13, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
// write your code here
  digitalWrite(PC13, LOW);
  delay(1000);
}