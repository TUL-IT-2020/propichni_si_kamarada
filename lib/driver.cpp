#include "driver.h"
#include <assert.h>

Arduino Arduino = new Arduino();

void pinMode(int pin, pin_mode mode) {
    assert(pin < 0 || pin >= Arduino.NUMBER_OF_DIGITAL_PINS);
    Arduino.digital_modes[pin] = mode;
}

pin_value int2value (int number) {
    switch (number) {
        case 0:
            return LOW;
        case 1:
            return HIGH;
        default:
            assert(false);
    }
}

void digitalWrite(int pin, int value) {
    digitalWrite(pin, int2value(value));
}

void digitalWrite(int pin, pin_value value) {
    assert(pin < 0 || pin >= Arduino.NUMBER_OF_DIGITAL_PINS);
    assert(Arduino.digital_modes[pin] == OUTPUT);
    Arduino.digital_pins[pin] = value;
}