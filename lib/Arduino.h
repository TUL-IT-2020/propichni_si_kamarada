#pragma once

typedef enum pin_value {
    HIGH,
    LOW
}

typedef enum pin_mode {
    INPUT, 
    OUTPUT, 
    INPUT_PULLUP
}

class Arduino {
public:
    int NUMBER_OF_DIGITAL_PINS = 14;
    pin_value digital_pins[NUMBER_OF_DIGITAL_PINS];
    pin_mode digital_modes[NUMBER_OF_DIGITAL_PINS];
}