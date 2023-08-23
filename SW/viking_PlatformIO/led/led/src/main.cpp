#include <Arduino.h>

#define VIKING_LED_PIN 22
void setup() {
  pinMode(VIKING_LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(VIKING_LED_PIN, HIGH);
  delay(50);
  digitalWrite(VIKING_LED_PIN, LOW);
  delay(1000);
}
