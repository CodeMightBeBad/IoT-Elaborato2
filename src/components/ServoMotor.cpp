#include "ServoMotor.h"

ServoMotor::ServoMotor(const int pin) {
    this->pin = pin;
}

void ServoMotor::on() {
    motor.attach(this->pin);
}

void ServoMotor::off() {
    motor.detach();
}

void ServoMotor::setPosition(const int angle) {
    motor.write(angle);
}
