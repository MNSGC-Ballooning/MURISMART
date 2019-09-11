#include "LatchRelay.h"

LatchRelay::LatchRelay(byte onPin, byte offPin):
  onPin(onPin), offPin(offPin) {
}

void LatchRelay::init() {
  pinMode(onPin, OUTPUT);
  pinMode(offPin, OUTPUT);
}

void LatchRelay::init(bool startState) {
  init();
  setState(startState);
}

void LatchRelay::setState(bool state) {
  if (state) {
    digitalWrite(onPin, HIGH);
    delay(10);
    digitalWrite(onPin, LOW);
  }
  else {
    digitalWrite(offPin, HIGH);
    delay(10);
    digitalWrite(offPin, LOW);
  }
  currentState = state;
}

bool LatchRelay::getState() {
  return currentState;
}