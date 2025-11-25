#ifndef IOT_ELABORATO2_SERVOMOTOR_H
#define IOT_ELABORATO2_SERVOMOTOR_H

#include <Servo.h>

/**
 * Class used to manage the connection and motion of a servo motor
 */
class ServoMotor {
public:
    /**
     * Initializes the servomotor object on the selected pin
     * @param pin the index of the pin connected to the servo
     */
    explicit ServoMotor(int pin);

    /**
     * Attaches the servo
     */
    void on();

    /**
     * Detatches the servo
     */
    void off();

    /**
     * Sets the servo to a specific angle
     * @param angle the angle the servo has to be set to
     */
    void setPosition(int angle);
private:
    int pin;
    Servo motor;
};

#endif