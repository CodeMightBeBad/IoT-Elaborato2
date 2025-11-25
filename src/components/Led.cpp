#include "Led.h"
#include <Arduino.h>

Led::Led(const int pin) {
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
}

void Led::switchOn() const {
    digitalWrite(this->pin, HIGH);
}

void Led::switchOff() const {
    digitalWrite(this->pin, LOW);
}
