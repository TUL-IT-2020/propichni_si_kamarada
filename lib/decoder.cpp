#include "decoder.h"

Decoder::Decoder (vector<int> _pins) : pins(_pins) {
    for (int pin : pins) {
        pinMode(pin, OUTPUT);
    }
}

Decoder::~Decoder () {;}

void Decoder::decode (int pin_index) {
    for (int i = 0; i < pins.size(); i++) {
        if (i == pin_index) {
            digitalWrite(pins[i], 1);
        } else {
            digitalWrite(pins[i], 0);
        }
    }
}