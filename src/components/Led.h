#ifndef IOT_ELABORATO2_LED_H
#define IOT_ELABORATO2_LED_H


class Led {
public:
    explicit Led(int pin);
    void switchOff() const;
    void switchOn() const;
private:
    int pin;
};


#endif