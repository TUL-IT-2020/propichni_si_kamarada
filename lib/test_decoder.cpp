#include "decoder.h"
#include "driver.h"
#include <vector>

void test_construktor () {
    vector<int> pins = {1, 2, 3};
    decoder* d = new Decoder(pins);
    delete(d);
}

void test_decode () {
    vector<int> pins = {1, 2, 3};
    decoder* d = new Decoder(pins);

    for (int i = 0; i < pins.size(); i++) {
        // TODO
        continue;
    }

    delete(d);
}

void main () {
    test_decode();
}