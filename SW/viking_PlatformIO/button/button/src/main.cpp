#include <Arduino.h>
#include <Button.h>

#define VIKING_LED_PIN 22
#define BUTTON_UP_PIN 20
#define BUTTON_DOWN_PIN 19

Button button_up(BUTTON_UP_PIN);
Button button_down(BUTTON_DOWN_PIN);

void setup() {
  pinMode(VIKING_LED_PIN, OUTPUT);
}

void loop() {
  if (button_up.pressed()) digitalWrite(VIKING_LED_PIN, HIGH);
  if (button_down.pressed()) digitalWrite(VIKING_LED_PIN, LOW);
}
